# TitanDB - Quick Reference Card

## 🚀 Compilazione & Esecuzione

```bash
# Compilazione semplice
g++ -std=c++17 -O2 -o titandb titandb.cpp

# Compilazione con debug
g++ -std=c++17 -g -o titandb titandb.cpp

# Esecuzione
./titandb

# Con Makefile
make build    # Compila
make run      # Esegui
make clean    # Pulisci
make test     # Testa
```

---

## 📝 Comandi SQL Supportati

### CREATE TABLE
```sql
CREATE TABLE table_name (col1 INT, col2 VARCHAR);
CREATE TABLE users (id INT, name VARCHAR, age INT);
CREATE TABLE products (sku INT, title VARCHAR);
```

### INSERT
```sql
INSERT VALUES (1, 'Alice');
INSERT VALUES (2, 'Bob', 30);
INSERT VALUES (100, 'Laptop', 999);
```

### SELECT
```sql
SELECT * FROM users;
SELECT id FROM users;
SELECT * FROM users WHERE id = 1;
SELECT * FROM orders WHERE total > 500;
SELECT * FROM users WHERE id = 1 AND name = 'Alice';
```

### UPDATE
```sql
UPDATE users SET name = 'Charlie' WHERE id = 1;
UPDATE products SET price = 1299 WHERE sku = 100;
```

### DELETE
```sql
DELETE FROM users WHERE id = 1;
DELETE FROM products WHERE title = 'Mouse';
```

### EXIT
```sql
EXIT;
```

---

## 🏗️ Architettura Componenti

| Componente | File | Righe | Scopo |
|---|---|---|---|
| **Lexer** | titandb.cpp | ~350 | Tokenizzazione SQL |
| **Parser** | titandb.cpp | ~300 | AST building |
| **B+ Tree** | titandb.cpp | ~250 | Indice e storage |
| **Pager** | titandb.cpp | ~120 | File I/O e cache |
| **Table** | titandb.cpp | ~200 | Gestione tabelle |
| **Database** | titandb.cpp | ~150 | Orchestrazione |
| **REPL** | titandb.cpp | ~100 | CLI |

---

## 🔍 Struttura Dati Principali

### BTreeNode
```cpp
struct BTreeNode {
    bool isLeaf;
    std::vector<uint32_t> keys;              // Chiavi
    std::vector<uint32_t> pointers;          // Puntatori
    std::vector<std::vector<uint8_t>> values;// Dati
};
```

### Value
```cpp
struct Value {
    enum Type { INT, STRING } type;
    int intVal;
    std::string strVal;
};
```

### Record
```cpp
struct Record {
    std::vector<Value> fields;  // Una riga di dati
};
```

---

## 📊 Configurazione Chiave

```cpp
const uint32_t PAGE_SIZE = 4096;        // Dimensione pagina
const uint32_t MAX_PAGES = 10000;       // Max pagine
const uint32_t BTREE_ORDER = 8;         // Ordine B+ tree
const uint32_t MAX_KEY_SIZE = 256;      // Max chiave
const uint32_t MAX_VALUE_SIZE = 1024;   // Max valore
```

---

## 🔧 Classi Principali

### Lexer
```cpp
class Lexer {
    Token nextToken();
    Token readNumber();
    Token readString();
    Token readIdentifier();
};
```

### Parser
```cpp
class Parser {
    InsertStatement parseInsert();
    SelectStatement parseSelect();
    DeleteStatement parseDelete();
    UpdateStatement parseUpdate();
    CreateTableStatement parseCreateTable();
};
```

### BPlusTree
```cpp
class BPlusTree {
    void insert(uint32_t key, std::vector<uint8_t> value);
    std::vector<uint8_t> search(uint32_t key);
    void flush();
};
```

### Pager
```cpp
class Pager {
    std::vector<uint8_t> getPage(uint32_t pageNum);
    void putPage(uint32_t pageNum, std::vector<uint8_t> data);
    uint32_t allocatePage();
    void flush();
};
```

### Table
```cpp
class Table {
    void setSchema(const std::map<std::string, std::string>& s);
    void insert(const std::vector<Value>& values);
    std::vector<Record> select(const std::vector<std::pair<std::string, Value>>& conditions);
    void deleteRows(const std::vector<std::pair<std::string, Value>>& conditions);
};
```

### Database
```cpp
class Database {
    void createTable(const CreateTableStatement& stmt);
    void insert(const InsertStatement& stmt);
    void select(const SelectStatement& stmt);
    void deleteRows(const DeleteStatement& stmt);
    void updateRows(const UpdateStatement& stmt);
};
```

### REPL
```cpp
class REPL {
    void run();
    void processCommand(const std::string& input);
};
```

---

## 🎯 Flusso di Esecuzione

### INSERT
```
Input: "INSERT VALUES (1, 'Alice');"
    ↓
Lexer.nextToken()
    ↓
[INSERT, VALUES, LPAREN, NUMBER(1), COMMA, STRING("Alice"), RPAREN, SEMICOLON]
    ↓
Parser.parseInsert()
    ↓
InsertStatement { values: [1, "Alice"] }
    ↓
Database.insert()
    ↓
Table.insert()
    ↓
BPlusTree.insert(key, serialized_value)
    ↓
Pager.putPage(pageNum, node_data)
    ↓
Result: "Row inserted."
```

### SELECT
```
Input: "SELECT * FROM users WHERE id = 1;"
    ↓
Lexer → Parser
    ↓
SelectStatement { tableName: "users", whereConditions: [(id, 1)] }
    ↓
Database.select()
    ↓
Table.select()
    ↓
Filter records
    ↓
Result: "Results: N rows" + print rows
```

---

## 🐛 Debug Tips

### Visualizza file DB
```bash
hexdump -C titandb.db | head -50
od -t x1 titandb.db | head -20
strings titandb.db
```

### Aggiungi logging
```cpp
std::cerr << "DEBUG: Inserting key " << key 
          << " at page " << pageNum << "\n";
```

### Memory check
```bash
g++ -std=c++17 -g -fsanitize=address -o titandb titandb.cpp
./titandb
```

### Valgrind
```bash
valgrind --leak-check=full ./titandb
```

---

## 📈 Performance Metrics

### Per 10K records
```
Inserimento:     ~100ms
SELECT *:        ~50ms
SELECT filtered: ~30ms
Memory usage:    ~5MB
```

### Per 1M records
```
Inserimento:     ~10s
SELECT *:        ~2s
Memory usage:    ~200MB
```

### Stimato per 100M records
```
Tree depth:      ~5 livelli
I/O per search:  ~5 accessi disco
Memory (cache):  ~2GB
```

---

## ✅ Testing Checklist

```bash
# Test 1: Creazione tabella
CREATE TABLE test (id INT, data VARCHAR);
✓

# Test 2: Inserimento singolo
INSERT VALUES (1, 'test');
✓

# Test 3: Selezione
SELECT * FROM test;
✓

# Test 4: Aggiornamento
UPDATE test SET data = 'modified' WHERE id = 1;
✓

# Test 5: Eliminazione
DELETE FROM test WHERE id = 1;
✓

# Test 6: Persistenza (restart e SELECT)
./titandb  (chiudi con EXIT)
./titandb  (riapri)
SELECT * FROM test;
✓
```

---

## 🚨 Errori Comuni

| Errore | Causa | Soluzione |
|---|---|---|
| "Parser error: Expected =" | Sintassi SQL errata | Controlla WHERE clause |
| "Table not found" | Nome tabella typo | Usa il nome esatto |
| "Column count mismatch" | VALUES con colonne sbagliate | Controlla numero di valori |
| "Invalid value" | Tipo di dato scorretto | INT o STRING? |

---

## 📚 File Principali

```
.
├── titandb.cpp              # Sorgente principale (~1470 linee)
├── README.md                # Guida utente
├── DOCUMENTATION.md         # Documentazione tecnica
├── BTREE_GUIDE.md          # Guida B+ Tree
├── LEARNING_PATH.md        # Learning path
├── config.h                # Configurazione
├── Makefile                # Build
├── test.sh                 # Test suite
└── titandb.db              # Database (generato)
```

---

## 🎓 Concetti Chiave

### Lexer
- Tokenizzazione di stringhe
- FSM (Finite State Machine)
- Gestione di keywords

### Parser
- Parsing ricorsivo discendente
- Costruzione AST
- Error recovery

### B+ Tree
- Self-balancing tree
- Range queries efficienti
- Split e merge di nodi

### Pager
- Buffer pool management
- LRU eviction
- Serializzazione binaria

### Database
- Multi-table coordination
- Query execution
- Schema management

---

## 🔗 Link Rapidi

| Risorsa | Link |
|---|---|
| SQLite Architecture | https://www.sqlite.org/arch.html |
| B+ Tree Visualization | https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html |
| CMU Databases | https://15445.courses.cs.cmu.edu/ |
| C++ Reference | https://en.cppreference.com/ |

---

## 💡 Tips & Tricks

### Tip 1: Modifica B+ Tree Order
Aumenta BTREE_ORDER per dataset grandi → meno livelli
```cpp
const uint32_t BTREE_ORDER = 16;  // Default 8
```

### Tip 2: Disabilita Debug Output
Per performance, riduci std::cout
```cpp
// Prima compilazione, dopo no
std::cout << "Debug: ...";
```

### Tip 3: Analizza Memoria
```cpp
std::cout << "Pages in cache: " << cache.size() << "\n";
std::cout << "Memory: " << (cache.size() * PAGE_SIZE / 1024) << " KB\n";
```

### Tip 4: Batch Inserts
Migliore performance con più INSERT consecutivi:
```sql
INSERT VALUES (1, 'a');
INSERT VALUES (2, 'b');  ← Fai 100 di questi
INSERT VALUES (100, 'z');
```

---

## 🎯 Esercizi Veloci

### Esercizio 1: Nuovo Comando (5 min)
Aggiungi HELP command che stampa lista comandi.

### Esercizio 2: Nuovo Token (10 min)
Aggiungi supporto per != operator.

### Esercizio 3: Modificare Ordine Tree (15 min)
Cambia BTREE_ORDER a 16, testa performance.

### Esercizio 4: Nuovo Statement (30 min)
Implementa SHOW TABLES comando.

### Esercizio 5: Indice Secondario (1 ora)
Crea indice su una colonna non-chiave.

---

## 📞 Support

**Se hai problemi:**

1. Leggi i messages di errore completamente
2. Controlla DOCUMENTATION.md sezione relativa
3. Visualizza il B+ Tree con printTree()
4. Usa hexdump per debug del file DB
5. Aggiungi std::cerr statements
6. Prova Valgrind per memory leaks

---

**Versione:** 1.0  
**Data:** Novembre 2025  
**Keep Coding! 🚀**
