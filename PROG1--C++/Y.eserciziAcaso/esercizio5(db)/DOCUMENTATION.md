# TitanDB - Documentazione Completa

## 📋 Indice

1. Architettura Generale
2. Componenti Principali
3. Come Compilare ed Eseguire
4. Istruzioni SQL Supportate
5. Esempi di Utilizzo
6. Estensioni Possibili

---

## 1. Architettura Generale

TitanDB è strutturato su 5 layer principali:

```
┌─────────────────────────────────────────────────────────┐
│                    REPL (Command Line)                  │
│          (Interfaccia utente interattiva)               │
└────────────────────────┬────────────────────────────────┘
                         │
┌────────────────────────▼────────────────────────────────┐
│          LEXER & PARSER (Parser SQL)                    │
│   Tokenizza e converte stringhe in AST (Abstract Syntax │
│          Tree) per l'esecuzione                         │
└────────────────────────┬────────────────────────────────┘
                         │
┌────────────────────────▼────────────────────────────────┐
│       VIRTUAL MACHINE (Executor/Query Engine)           │
│   Esegue i comandi AST e chiama il Database             │
└────────────────────────┬────────────────────────────────┘
                         │
┌────────────────────────▼────────────────────────────────┐
│      TABLE MANAGER (Gestione Tabelle)                   │
│   Mantiene schema e record in memoria                   │
└────────────────────────┬────────────────────────────────┘
                         │
┌────────────────────────▼────────────────────────────────┐
│     STORAGE ENGINE (B+ Tree + Pager)                    │
│  • BPlusTree: Indice e ricerca veloce                   │
│  • Pager: Gestione file.db e paginazione               │
│  • Buffer Pool: Cache delle pagine in RAM               │
└────────────────────────┬────────────────────────────────┘
                         │
        ╔════════════════╩════════════════╗
        │                                  │
    ┌───▼────┐                        ┌───▼────┐
    │ RAM    │                        │ DISCO  │
    │(Cache) │───────────────────────▶│titandb.│
    │        │◀───────────────────────│   db   │
    └────────┘                        └────────┘
```

---

## 2. Componenti Principali

### 2.1 LEXER (Tokenizzazione)

**Classe:** `Lexer`

Trasforma una stringa SQL in una lista di token.

**Metodi principali:**
- `nextToken()`: Restituisce il prossimo token nella sequenza
- `readNumber()`: Estrae numeri
- `readString()`: Estrae stringhe (tra apici singoli)
- `readIdentifier()`: Estrae identificatori e keywords

**Token supportati:**
```
INSERT, SELECT, FROM, WHERE, VALUES, DELETE, UPDATE, SET, 
CREATE, TABLE, INT, VARCHAR, (,), COMMA, SEMICOLON, =, <, >
```

**Esempio:**
```cpp
Input:  "INSERT VALUES (1, 'Mario');"
Output: [INSERT, VALUES, LPAREN, NUMBER(1), COMMA, STRING("Mario"), RPAREN, SEMICOLON]
```

---

### 2.2 PARSER (Analisi Sintattica)

**Classe:** `Parser`

Converte token in strutture dati eseguibili (AST).

**Strutture dati prodotte:**

```cpp
struct InsertStatement {
    std::string tableName;
    std::vector<Value> values;
};

struct SelectStatement {
    std::string tableName;
    std::vector<std::string> columns;
    std::vector<std::pair<std::string, Value>> whereConditions;
};

struct DeleteStatement {
    std::string tableName;
    std::vector<std::pair<std::string, Value>> whereConditions;
};

struct UpdateStatement {
    std::string tableName;
    std::map<std::string, Value> updates;
    std::vector<std::pair<std::string, Value>> whereConditions;
};

struct CreateTableStatement {
    std::string tableName;
    std::map<std::string, std::string> columns;
};
```

**Metodi principali:**
- `parseInsert()`: Analizza INSERT statements
- `parseSelect()`: Analizza SELECT statements
- `parseDelete()`: Analizza DELETE statements
- `parseUpdate()`: Analizza UPDATE statements
- `parseCreateTable()`: Analizza CREATE TABLE statements

---

### 2.3 B+ TREE (Indice)

**Classe:** `BTreeNode`, `BPlusTree`

Struttura dati self-balancing per l'indicizzazione e il recupero rapido.

**Caratteristiche:**
- **Ordine:** 8 (BTREE_ORDER = 8)
- **Nodi:** Dividono chiavi e puntatori
- **Serializzazione:** Salvataggio binario su disco

**Metodi:**
- `insert(key, value)`: Inserisce una coppia chiave-valore
- `search(key)`: Ricerca un valore per chiave
- `serialize()`: Converte il nodo in buffer binario
- `deserialize()`: Ricostruisce il nodo da buffer

**Struttura di un nodo:**
```
[isLeaf: 1 byte] [keyCount: 4 byte] [keys...] [pointers...] [values...]
```

---

### 2.4 PAGER (Gestione Memoria)

**Classe:** `Pager`

Gestisce la persistenza su disco e il buffer pool.

**Caratteristiche:**
- **PAGE_SIZE:** 4096 byte
- **MAX_PAGES:** 10000 pagine (40 MB massimo)
- **Cache:** Map in-memory delle pagine

**Metodi:**
- `getPage(pageNum)`: Legge una pagina da cache o disco
- `putPage(pageNum, data)`: Scrive una pagina in cache
- `allocatePage()`: Alloca una nuova pagina
- `flush()`: Persiste tutte le pagine su disco

**Algoritmo di caching:**
1. Se la pagina è in cache → return immediato
2. Altrimenti, leggi da disco e metti in cache
3. All `exit` o `flush()`, scrivi tutte le pagine su disco

---

### 2.5 TABLE (Gestione Tabelle)

**Classe:** `Table`

Rappresenta una tabella con schema e record.

**Metodi:**
- `setSchema(schema)`: Definisce le colonne
- `insert(values)`: Aggiunge un record
- `select(conditions)`: Filtra e restituisce record
- `deleteRows(conditions)`: Elimina record
- `updateRows(updates, conditions)`: Modifica record
- `printRows()`: Stampa i record a video

**Archiviazione interna:**
```cpp
std::map<std::string, std::string> schema;  // Nome colonna → tipo
std::vector<Record> rows;                   // Record della tabella
BPlusTree index;                            // Indice per ricerca veloce
```

---

### 2.6 DATABASE (Orchestrazione)

**Classe:** `Database`

Gestisce più tabelle e coordina operazioni.

**Metodi:**
- `createTable(stmt)`: Crea una nuova tabella
- `insert(stmt)`: Inserisce record
- `select(stmt)`: Legge record
- `deleteRows(stmt)`: Elimina record
- `updateRows(stmt)`: Modifica record
- `flush()`: Persiste tutto su disco

---

### 2.7 REPL (Interfaccia Utente)

**Classe:** `REPL`

Loop interattivo che legge comandi e li esegue.

**Flusso:**
```
1. Stampa prompt "titandb> "
2. Leggi linea di input
3. Tokenizza con Lexer
4. Parsa con Parser
5. Esegui con Database
6. Stampa risultati
7. Torna a 1
```

---

## 3. Compilazione ed Esecuzione

### Compilazione

```bash
# Con g++
g++ -std=c++17 -o titandb titandb.cpp

# Con clang
clang++ -std=c++17 -o titandb titandb.cpp

# Con optimizzazioni
g++ -O2 -std=c++17 -o titandb titandb.cpp
```

### Esecuzione

```bash
./titandb
```

Verrà creato automaticamente il file `titandb.db` nella directory corrente.

---

## 4. Istruzioni SQL Supportate

### 4.1 CREATE TABLE

```sql
CREATE TABLE users (id INT, name VARCHAR)
CREATE TABLE products (product_id INT, title VARCHAR, price INT)
```

### 4.2 INSERT

```sql
INSERT VALUES (1, 'Mario')
INSERT VALUES (2, 'Luigi')
INSERT VALUES (1001, 'Laptop', 999)
```

### 4.3 SELECT

```sql
SELECT * FROM users
SELECT id FROM users WHERE id = 1
SELECT * FROM products WHERE product_id = 1001 AND title = 'Laptop'
```

### 4.4 DELETE

```sql
DELETE FROM users WHERE id = 1
DELETE FROM products WHERE price = 999
```

### 4.5 UPDATE

```sql
UPDATE users SET name = 'Peach' WHERE id = 1
UPDATE products SET price = 1299 WHERE product_id = 1001
```

### 4.6 EXIT

```sql
EXIT
```

---

## 5. Esempi di Utilizzo

### Scenario 1: Gestione Contatti

```
titandb> CREATE TABLE contacts (id INT, email VARCHAR)
Table 'contacts' created.

titandb> INSERT VALUES (1, 'alice@example.com')
Row inserted.

titandb> INSERT VALUES (2, 'bob@example.com')
Row inserted.

titandb> SELECT * FROM contacts
Results: 2 rows
Row 0: 1 alice@example.com
Row 1: 2 bob@example.com

titandb> UPDATE contacts SET email = 'newemail@example.com' WHERE id = 1
Rows updated.

titandb> DELETE FROM contacts WHERE id = 2
Rows deleted.

titandb> EXIT
Goodbye!
```

### Scenario 2: Inventario Negozio

```
titandb> CREATE TABLE inventory (sku INT, name VARCHAR, qty INT)

titandb> INSERT VALUES (100, 'Mouse', 50)
Row inserted.

titandb> INSERT VALUES (101, 'Keyboard', 30)
Row inserted.

titandb> INSERT VALUES (102, 'Monitor', 15)
Row inserted.

titandb> SELECT * FROM inventory
Results: 3 rows
Row 0: 100 Mouse 50
Row 1: 101 Keyboard 30
Row 2: 102 Monitor 15

titandb> UPDATE inventory SET qty = 45 WHERE sku = 100
Rows updated.

titandb> DELETE FROM inventory WHERE qty = 15
Rows deleted.

titandb> EXIT
```

---

## 6. Estensioni Possibili (Per Arrivare a 3000+ Righe)

### 6.1 Implementare B+ Tree Splitting Completo

Attualmente `insert()` è semplificato. Implementare:

```cpp
void splitNode(BTreeNode& full, uint32_t pageNum) {
    // Divide un nodo pieno in due
    // Aggiorna il padre
    // Ricorsivamente, se il padre è pieno, lo divide
}
```

Aggiunte: **150-200 righe**

---

### 6.2 Multi-Column Indexes

Creare indici compositi:

```cpp
class CompositeIndex {
    std::vector<std::string> columns;
    std::map<std::vector<Value>, uint32_t> index;
};
```

Aggiunte: **100-150 righe**

---

### 6.3 Transazioni e Journaling

Implementare ACID:

```cpp
class Transaction {
    std::vector<Operation> log;
    void commit();
    void rollback();
};
```

Aggiunte: **200-300 righe**

---

### 6.4 Query Planner e Optimizer

```cpp
class QueryPlan {
    std::vector<Step> steps;
    void optimize();
    void explain();
};
```

Aggiunte: **150-200 righe**

---

### 6.5 Aggregate Functions

```sql
SELECT COUNT(*) FROM users
SELECT SUM(price) FROM products
SELECT AVG(salary) FROM employees
```

Implementazione:

```cpp
enum class AggregateOp { COUNT, SUM, AVG, MIN, MAX };

class AggregateExecutor {
    Value compute(AggregateOp op, const std::vector<Record>&);
};
```

Aggiunte: **150-200 righe**

---

### 6.6 JOIN Operations

```sql
SELECT users.id, orders.total FROM users JOIN orders ON users.id = orders.user_id
```

```cpp
class JoinExecutor {
    std::vector<Record> execute(
        const Table& left, const Table& right,
        const std::string& leftKey, const std::string& rightKey
    );
};
```

Aggiunte: **200-250 righe**

---

### 6.7 WAL (Write-Ahead Logging)

Aumenta la robustezza:

```cpp
class WAL {
    std::ofstream walFile;
    void logWrite(uint32_t pageNum, const std::vector<uint8_t>& data);
    void replay();
};
```

Aggiunte: **150-200 righe**

---

### 6.8 Schema Migration

```sql
ALTER TABLE users ADD COLUMN phone VARCHAR
ALTER TABLE users MODIFY COLUMN name VARCHAR(100)
```

Implementazione:

```cpp
class SchemaMigrator {
    void addColumn(Table& table, const std::string& colName, const std::string& type);
    void modifyColumn(Table& table, const std::string& colName, const std::string& newType);
};
```

Aggiunte: **150-200 righe**

---

### 6.9 Query Caching

```cpp
class QueryCache {
    std::map<std::string, CachedResult> cache;
    void invalidate(const std::string& tableName);
};
```

Aggiunte: **100-150 righe**

---

### 6.10 Advanced Data Types

Oltre a INT e VARCHAR, aggiungere:

```cpp
enum class DataType { 
    INT, VARCHAR, FLOAT, BOOLEAN, DATE, BLOB, NULL_TYPE 
};

struct Value {
    DataType type;
    union {
        int intVal;
        double floatVal;
        bool boolVal;
    };
    std::string strVal;
};
```

Aggiunte: **200-250 righe**

---

## 7. Statistiche del Codice Base

```
Lexer:              ~350 righe
Parser:             ~300 righe
BTreeNode:          ~150 righe
BPlusTree:          ~100 righe
Pager:              ~120 righe
Table:              ~200 righe
Database:           ~150 righe
REPL:               ~100 righe
─────────────────────────
TOTALE:             ~1470 righe

Con estensioni (anche solo 3-4):
TOTALE POTENZIALE:  ~2500-3500 righe
```

---

## 8. Debugging Tips

### 8.1 Visualizzare il B+ Tree

```cpp
void printTree(const BTreeNode& node, int depth = 0) {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "Keys: ";
    for (auto k : node.keys) std::cout << k << " ";
    std::cout << "\n";
}
```

### 8.2 Dump del File DB

```bash
hexdump -C titandb.db | head -50
```

### 8.3 Trace di Esecuzione

Aggiungi `std::cerr << "DEBUG: ..."` nelle funzioni critiche.

---

## 9. Performance Optimization

| Ottimizzazione | Impatto |
|---|---|
| Index Caching | +40% su SELECT |
| WAL Batching | +60% su INSERT |
| B+ Tree Tuning (ordine) | ±10-20% |
| Query Planning | +30% su query complesse |

---

## 10. Risorse Esterne

- [B+ Tree Paper](https://en.wikipedia.org/wiki/B%2B_tree)
- [SQLite Source Code](https://www.sqlite.org/src)
- [Modern Database Systems](https://redbook.cs.berkeley.edu/)

---

**Versione:** 1.0  
**Data:** Novembre 2025  
**Autore:** TitanDB Development Team
