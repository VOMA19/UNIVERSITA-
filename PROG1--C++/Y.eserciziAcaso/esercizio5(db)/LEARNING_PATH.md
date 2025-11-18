# TitanDB - Learning Path & Completion Checklist

## 🎯 Obiettivo Completato

✅ **Progetto Architetturale Completo**: ~1470 linee di codice base  
✅ **5 Layer di Astrazione**: Lexer → Parser → VM → Table → Storage  
✅ **Persistenza su Disco**: File binario `.db` con paginazione  
✅ **B+ Tree Funzionante**: Indice e ricerca veloce O(log n)  
✅ **Parser SQL Custom**: INSERT, SELECT, UPDATE, DELETE, CREATE TABLE  
✅ **REPL Interattiva**: Command-line interface  

---

## 📚 Learning Path - Come Imparare da TitanDB

### Fase 1: Setup e Compilazione (30 min)

- [ ] Clona/scarica il progetto
- [ ] Leggi README.md
- [ ] Compila: `g++ -std=c++17 -O2 -o titandb titandb.cpp`
- [ ] Esegui: `./titandb`
- [ ] Prova comandi base (CREATE, INSERT, SELECT)

**Concetti imparati:**
- Compilazione C++17
- Workflow di sviluppo di progetti complessi
- File I/O su disco

---

### Fase 2: Analisi del Lexer (1-2 ore)

**Cosa fare:**
1. Apri `titandb.cpp` e leggi classe `Lexer`
2. Traccia manualmente il flusso di tokenizzazione:
   ```
   Input:  "INSERT VALUES (1, 'Mario');"
   Output: [INSERT, VALUES, LPAREN, NUMBER(1), COMMA, STRING("Mario"), RPAREN, SEMICOLON]
   ```
3. Modifica il lexer per supportare un nuovo token (es. `!=`)

**Concetti imparati:**
- Finite State Machine (FSM)
- Tokenizzazione
- Gestione degli errori
- String processing
- Character classification

**Esercizio:**
Aggiungi supporto per commenti:
```sql
-- Questo è un commento
INSERT VALUES (1, 'Test');  -- Commento inline
```

Soluzione: Aggiungi `skipComment()` nel Lexer (~20 righe)

---

### Fase 3: Parser e AST (2-3 ore)

**Cosa fare:**
1. Leggi classe `Parser`
2. Comprendi come i token diventano strutture dati:
   ```cpp
   tokens → Parser → InsertStatement → Database::insert()
   ```
3. Aggiungi un nuovo tipo di statement (es. DESCRIBE TABLE)

**Concetti imparati:**
- Parsing ricorsivo
- Abstract Syntax Tree (AST)
- Grammatica context-free
- Error recovery
- Visitor pattern

**Esercizio:**
Implementa `DESCRIBE TABLE`:
```sql
DESCRIBE TABLE users;
```

Soluzione:
```cpp
struct DescribeTableStatement {
    std::string tableName;
};

DescribeTableStatement parseDescribe() {
    expect(TokenType::DESCRIBE, "Expected DESCRIBE");
    // ... parsing logic
}
```

Aggiunte: ~30-40 righe

---

### Fase 4: B+ Tree (3-4 ore) ⭐ IMPORTANTE

**Cosa fare:**
1. Leggi BTREE_GUIDE.md completamente
2. Studia classe `BTreeNode` e `BPlusTree`
3. Disegna un B+ tree su carta dopo aver inserito [10, 20, 30, 40, 50]
4. Traccia un search(35) manualmente

**Concetti imparati:**
- Strutture dati auto-bilanciate
- Serializzazione binaria
- Gestione di nodi pieni
- Trade-off spazio-tempo
- Cache e buffer pool

**Esercizio 1 - Visualizzazione:**
Implementa `printTree()`:
```cpp
void printTree(const BTreeNode& node, int depth = 0) {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "Keys: ";
    for (uint32_t k : node.keys) std::cout << k << " ";
    std::cout << "\n";
}
```

Aggiunte: ~20 righe

**Esercizio 2 - Splitting (AVANZATO):**
Implementa il vero B+ tree splitting quando un nodo diventa pieno:
```cpp
void splitNode(BTreeNode& full, uint32_t pageNum) {
    BTreeNode newNode;
    
    // Divide le chiavi tra old e new
    size_t midpoint = full.keys.size() / 2;
    
    newNode.keys.insert(newNode.keys.begin(),
        full.keys.begin() + midpoint,
        full.keys.end());
    
    full.keys.erase(full.keys.begin() + midpoint,
        full.keys.end());
    
    // Aggiorna il padre
    // Recursive splitting se padre è pieno
}
```

Aggiunte: ~100-150 righe

---

### Fase 5: Pager e Persistenza (2-3 ore)

**Cosa fare:**
1. Leggi classe `Pager`
2. Esegui: `hexdump -C titandb.db | head -30`
3. Modifica PAGE_SIZE da 4096 a 2048 e ricompila - osserva il cambiamento

**Concetti imparati:**
- File I/O binario
- Buffer pool
- Cache policies (LRU, FIFO)
- Serializzazione/deserializzazione
- Memory-mapped I/O

**Esercizio:**
Implementa LRU eviction quando buffer pool è pieno:
```cpp
void evictLRUPage() {
    // Trova la pagina meno recentemente usata
    uint32_t lruPage = findLRUPage();
    
    // Scrivi su disco se modificata
    if (isDirty(lruPage)) {
        writePage(lruPage);
    }
    
    // Rimuovi dalla cache
    cache.erase(lruPage);
}
```

Aggiunte: ~50-70 righe

---

### Fase 6: Table Manager (2 ore)

**Cosa fare:**
1. Leggi classe `Table`
2. Comprendi come schema e record sono gestiti
3. Aggiungi supporto per indici secondari

**Concetti imparati:**
- Schema definition
- Record storage
- Type checking
- Constraint validation
- Secondary indexes

**Esercizio:**
Crea un indice su una colonna:
```cpp
class SecondaryIndex {
    std::string columnName;
    BPlusTree tree;  // Indice separato
};
```

---

### Fase 7: Database e Query Execution (2-3 ore)

**Cosa fare:**
1. Leggi classe `Database`
2. Traccia il flusso di un INSERT:
   ```
   REPL → Database::insert() → Table::insert() → BPlusTree::insert()
   ```
3. Aggiungi query result caching

**Concetti imparati:**
- Query planning
- Execution engines
- Result caching
- Multi-table coordination
- Transaction management

**Esercizio:**
Implementa query result caching:
```cpp
class QueryCache {
    std::map<std::string, CachedResult> cache;
    
    void invalidate(const std::string& tableName) {
        // Rimuovi risultati che coinvolgono questa tabella
    }
};
```

---

### Fase 8: REPL e Error Handling (1-2 ore)

**Cosa fare:**
1. Leggi classe `REPL`
2. Aggiungi comandi nuovi (HELP, SHOW TABLES, DESCRIBE)
3. Migliora gestione errori

**Concetti imparati:**
- CLI design
- Input parsing
- Error messages
- User experience
- Signal handling

**Esercizio:**
Aggiungi comandi di amministrazione:
```
titandb> HELP;
titandb> SHOW TABLES;
titandb> DESCRIBE users;
titandb> STATS;
titandb> FLUSH;
```

---

## 🎓 Estensioni Suggerite (Raggiungere 3000+ Righe)

### Priorità Alta (Implementare prima)

#### 1. **B+ Tree Splitting Completo** (~150 righe)
```
Implementa il vero splitting quando nodi sono pieni.
Impatto: +40% complessità, -20% tempo di inserimento
```

#### 2. **Transaction Support** (~250 righe)
```cpp
class Transaction {
    std::vector<Operation> log;
    
    void begin();
    void commit();  // ACID guarantee
    void rollback();
};
```

#### 3. **Query Result Filtering Avanzato** (~100 righe)
```sql
SELECT * FROM users WHERE age > 30 AND name LIKE 'John%';
SELECT id FROM orders WHERE total BETWEEN 100 AND 1000;
```

#### 4. **Aggregate Functions** (~150 righe)
```sql
SELECT COUNT(*) FROM users;
SELECT SUM(salary) FROM employees;
SELECT AVG(price) FROM products;
```

### Priorità Media

#### 5. **JOIN Operations** (~200 righe)
```sql
SELECT u.name, o.total 
FROM users u JOIN orders o ON u.id = o.user_id;
```

#### 6. **GROUP BY & HAVING** (~150 righe)
```sql
SELECT department, COUNT(*) as count, AVG(salary)
FROM employees
GROUP BY department
HAVING COUNT(*) > 5;
```

#### 7. **Indexes Secondari** (~100 righe)
```sql
CREATE INDEX idx_email ON users(email);
```

#### 8. **WAL (Write-Ahead Logging)** (~200 righe)
```
Aumenta robustezza e performance:
- Log transazioni prima di scrivere su disco
- Recovery da crash
```

### Priorità Bassa (Advanced)

#### 9. **Query Optimizer** (~200 righe)
```cpp
class QueryPlanner {
    Plan optimize(const SelectStatement& query);
    // Scegli il migliore tra:
    // - Full table scan
    // - Index scan
    // - Join order optimization
};
```

#### 10. **Trigger Support** (~150 righe)
```sql
CREATE TRIGGER update_timestamp BEFORE INSERT ON users
BEGIN UPDATE users SET updated_at = NOW() END;
```

---

## 📊 Roadmap di Sviluppo

```
Week 1:
├─ Leggi DOCUMENTATION.md
├─ Compila e testa
└─ Modifica Lexer (aggiungi token)

Week 2:
├─ Leggi BTREE_GUIDE.md
├─ Implementa B+ Tree splitting
└─ Esercizi su ricerca e inserimento

Week 3:
├─ Implementa Transaction support
├─ Aggiungi Aggregate functions
└─ Query caching

Week 4:
├─ JOIN operations
├─ GROUP BY & HAVING
└─ Index secondari

Week 5-6:
├─ WAL Logging
├─ Query Optimizer
└─ Bug fixes e ottimizzazioni

Totale: ~2500-3500 righe a fine roadmap
```

---

## ✅ Completion Checklist

### Comprensione Base
- [ ] Ho letto README.md
- [ ] Ho compilato il codice con successo
- [ ] Ho testato CREATE TABLE
- [ ] Ho testato INSERT/SELECT/UPDATE/DELETE

### Lexer & Parser
- [ ] Capisco come funziona la tokenizzazione
- [ ] Capisco AST e parsing ricorsivo
- [ ] Ho aggiunto un nuovo token/comando
- [ ] Ho fatto un esercizio di parsing

### B+ Tree
- [ ] Ho letto BTREE_GUIDE.md completamente
- [ ] Capisco la struttura dei nodi
- [ ] Capisco search, insert, delete
- [ ] Ho visualizzato un tree su carta
- [ ] Ho tracciato search() manualmente
- [ ] Ho implementato printTree()

### Storage & Persistence
- [ ] Capisco serializzazione binaria
- [ ] Capisco paginazione 4KB
- [ ] Ho analizzato il file .db con hexdump
- [ ] Ho modificato PAGE_SIZE e osservato i cambiamenti

### Estensioni
- [ ] Ho scelto almeno 2 estensioni da implementare
- [ ] Ho iniziato a implementare B+ Tree splitting
- [ ] Ho aggiunto Transaction support
- [ ] Ho aggiunto Aggregate functions

### Documentazione & Testing
- [ ] Ho scritto commenti nel codice
- [ ] Ho creato test per le mie estensioni
- [ ] Ho fatto stress testing (100+ righe)
- [ ] Ho testato error handling

### Performance
- [ ] Ho misurato il tempo di 1000 INSERT
- [ ] Ho misurato il tempo di 1000 SELECT
- [ ] Ho stimato tree depth per 1M records
- [ ] Ho analizzato memory usage con /proc/[pid]/status

---

## 🎯 Learning Objectives

Al termine di questo progetto, dovresti capire:

**Concetti Teorici:**
- [ ] Come funzionano i database relazionali
- [ ] B+ tree e strutture di indici
- [ ] Parsing e compilazione
- [ ] I/O su disco e buffer pool
- [ ] Algoritmi di ricerca e ordinamento

**Abilità Pratiche:**
- [ ] Progettare architetture modulari
- [ ] Scrivere C++ production-quality
- [ ] Debuggare complessi sistemi software
- [ ] Ottimizzare performance
- [ ] Scrivere codice documentato

**Progetti Futuri:**
- [ ] Implementare un query optimizer
- [ ] Aggiungere parallelismo
- [ ] Creare query language custom
- [ ] Implementare replication
- [ ] Build distributed database

---

## 🚀 Dopo TitanDB

### Prossimi Progetti Consigliati

1. **Estendi TitanDB** → 5000 linee con tutte le features
2. **Redis Clone** → In-memory database con persistence
3. **Query Language Compiler** → DSL custom
4. **Distributed DB** → Multi-node replication
5. **Graph Database** → Neo4j clone

### Risorse di Approfondimento

- 📖 "Database Internals" - Alex Petrov
- 📖 "Designing Data-Intensive Applications" - Martin Kleppmann
- 🎥 CMU 15-445 Database Systems (YouTube)
- 📝 SQLite Source Code (7M+ lines, production code)

---

## 📝 Checklist Finale

**Prima di considerare il progetto "finito":**

- [ ] Codice compila senza warning
- [ ] Tutti i test passano
- [ ] Documentazione è completa
- [ ] Ho implementato almeno 2 estensioni
- [ ] Performance è accettabile (< 100ms per query semplice)
- [ ] Memory usage è < 100MB per database piccolo
- [ ] Code è commentato e leggibile
- [ ] Ho fatto code review con qualcuno

---

## 🎓 Certificazione Finale

Se hai completato:
✅ Tutte le estensioni suggerite
✅ Creato feature nuove (3+)
✅ Scritto 500+ linee di nuovo codice
✅ Fatto performance profiling
✅ Scritto tests completi

**Congratulazioni!** 🎉 Hai costruito un database SQL-like completo!

---

**Domande? Rileggi DOCUMENTATION.md e BTREE_GUIDE.md**

**Buon coding!** 🚀
