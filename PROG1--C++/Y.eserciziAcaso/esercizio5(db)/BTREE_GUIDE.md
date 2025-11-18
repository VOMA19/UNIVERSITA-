# B+ Tree Implementation Deep Dive

## Introduzione

Un **B+ Tree** è una struttura dati self-balancing usata in SQLite, MySQL, e altri database. Ottimizza l'I/O da disco mantenendo i dati ordinati e minimizzando il numero di accessi al disco.

## Proprietà del B+ Tree

### Definizione (Ordine m = 8 in TitanDB)

1. **Ogni nodo ha al massimo m-1 chiavi** (7 in TitanDB)
2. **Ogni nodo interno ha al massimo m figli** (8 in TitanDB)
3. **Ogni nodo ha almeno ⌈m/2⌉ - 1 figli** (3 in TitanDB)
4. **Tutti i dati risiedono nelle foglie** (leaf nodes)
5. **I nodi interni contengono solo chiavi di separazione**

## Confronto: Strutture Alternative

```
┌──────────────────┬──────────────┬──────────────┬──────────────┐
│ Struttura        │ Inserimento  │ Ricerca      │ Range Query  │
├──────────────────┼──────────────┼──────────────┼──────────────┤
│ Array ordinato   │ O(n)         │ O(log n)     │ O(k)         │
│ Red-Black Tree   │ O(log n)     │ O(log n)     │ O(log n + k) │
│ B+ Tree          │ O(log n)     │ O(log n)     │ O(log n + k) │
│ Hash Table       │ O(1)         │ O(1)         │ O(n)         │
└──────────────────┴──────────────┴──────────────┴──────────────┘

k = numero di elementi ritornati
```

**Vantaggio del B+ Tree per database**: Range query efficienti grazie al collegamento tra foglie!

## Visualizzazione Struttura

### Piccolo B+ Tree (Ordine = 3, max 2 chiavi per nodo)

```
                         [15 | 30]              (Nodo interno)
                        /    |     \
                       /     |      \
            [10|12]  [20|25]  [35|40]  (Foglie collegate)
             /  \      /  \      /  \
          10 12  20 25  35 40   → (next)
          
Ricerca 25:
1. Parte da radice [15 | 30]
2. 25 > 15 e 25 < 30 → vai al nodo medio
3. Trova 25 nel nodo foglia [20|25]
4. Ritorna valore associato

Complessità: O(log n) = O(log 1000) ≈ 10 accessi
```

### B+ Tree Più Grande (Ordine = 8)

```
                              [40]
                        /      |      \
                       /       |       \
            [20|30]  [50|60]  [80]
            / | | \   / | | \   / | \
            ...foglie con collegamento...
```

## Operazioni Fondamentali

### 1. SEARCH (Ricerca)

```cpp
Value search(uint32_t key) {
    Node* current = root;
    
    while (!current->isLeaf) {
        int i = 0;
        // Trova il child pointer corretto
        while (i < current->keyCount && key > current->keys[i]) {
            i++;
        }
        current = current->children[i];
    }
    
    // Linear search nella foglia
    for (int i = 0; i < current->keyCount; i++) {
        if (current->keys[i] == key) {
            return current->values[i];
        }
    }
    
    return NOT_FOUND;
}

Complessità: O(log n)
```

### 2. INSERT (Inserimento)

#### Caso Semplice (Nodo non pieno)

```
Prima:  [10 | 25 | 40]

Inserisci 30:
→ Trova posizione: 25 < 30 < 40
→ Inserisci: [10 | 25 | 30 | 40]

Dopo: [10 | 25 | 30 | 40]
```

#### Caso Complesso (Nodo pieno → SPLIT)

```
Massimo chiavi (ordine 8): 7
Nodo pieno: [10 | 20 | 30 | 40 | 50 | 60 | 70]

Inserisci 65:
1. Dovrebbe andare a destra di 60
2. Nodo è PIENO → deve splitarsi

Split:
Nodo sinistro:  [10 | 20 | 30]
Chiave media:   40
Nodo destro:    [50 | 60 | 65 | 70]

Aggiorna padre:
Prima: [100]
Dopo:  [40 | 100]
```

Pseudocodice:

```cpp
void insert(uint32_t key, Value val) {
    Node* leaf = findLeaf(key);
    
    if (!leaf->isFull()) {
        // Caso semplice
        leaf->insertKey(key, val);
    } else {
        // Caso complesso: split
        Node* newNode = leaf->split();
        
        // Ricorsivamente propaga il split al padre
        if (leaf->parent) {
            insertIntoParent(leaf->parent, newNode);
        } else {
            // leaf era root → crea nuovo root
            createNewRoot(leaf, newNode);
        }
    }
}

Complessità media: O(log n)
Complessità worst case: O(n) se molti split
```

### 3. DELETE (Eliminazione)

#### Caso Semplice (Nodo ha abbastanza chiavi)

```
Nodo: [10 | 25 | 40 | 50]
Elimina 25:
→ [10 | 40 | 50]
```

#### Caso Complesso (Underflow)

```
Nodo: [25]  ← Solo 1 chiave (minimo è 3 per ordine 8)

Opzioni:
1. Rubare dal fratello
2. Merge con fratello

Rubare:
Nodo sinistro: [10 | 20 | 30]
Nodo corrente: [25]
→ Sposta 30 a sinistra, 25 a destra
→ Risultato: [10 | 20 | 25] [30]

Merge (se fratello non ha extra):
[10 | 20] [25]
→ Unisci: [10 | 20 | 25]
```

Pseudocodice:

```cpp
void remove(uint32_t key) {
    Node* leaf = findLeaf(key);
    leaf->removeKey(key);
    
    if (leaf->isUnderflow()) {
        if (leaf->borrowFromSibling()) {
            // Borrow succeeded
        } else if (leaf->canMerge()) {
            leaf->mergeWithSibling();
            // Propagate up if needed
        }
    }
}
```

## Serializzazione (Persistenza su Disco)

### Formato Binario di un Nodo

```
Offset   Field              Size    Descrizione
0        isLeaf             1 byte  1 = foglia, 0 = interno
1        keyCount           4 byte  Numero di chiavi
5        keys[0]            4 byte  
9        keys[1]            4 byte
...
         pointers[0]        4 byte  Child pointers
         pointers[1]        4 byte
...
         values[0]          VAR     Dati serializzati
         ...

Totale: ≤ 4096 byte (una pagina)
```

### Esempio Serializzazione

```cpp
// Nodo: isLeaf=1, chiavi=[10, 20, 30]
uint8_t buffer[4096];
uint32_t offset = 0;

// 1. Scrivi flag
buffer[offset++] = 1; // isLeaf

// 2. Scrivi conteggio
uint32_t count = 3;
memcpy(buffer + offset, &count, 4);
offset += 4;

// 3. Scrivi chiavi
uint32_t keys[] = {10, 20, 30};
memcpy(buffer + offset, keys, 12);
offset += 12;

// Resto: pointers, values...
```

## Analisi delle Prestazioni

### Complessità Temporale

| Operazione | Migliore | Media | Peggiore |
|---|---|---|---|
| Search | O(1) | O(log n) | O(log n) |
| Insert | O(1) | O(log n) | O(n) |
| Delete | O(1) | O(log n) | O(n) |
| Range Query | O(log n) | O(log n + k) | O(log n + k) |

k = numero di elementi nel range

### Utilizzo Disco

Per n = 1,000,000 record:
```
Albero binario bilanciato: ~20 livelli × 1 accesso = 20 I/O
B+ Tree (ordine 8):        ~8 livelli × 1 accesso = 8 I/O
B+ Tree (ordine 256):      ~3 livelli × 1 accesso = 3 I/O
```

**Riduzione: 85% meno accessi a disco!**

## Implementazione in TitanDB

### Classe BTreeNode

```cpp
struct BTreeNode {
    bool isLeaf;                       // Type
    std::vector<uint32_t> keys;        // Chiavi
    std::vector<uint32_t> pointers;    // Child pages o value pointers
    std::vector<std::vector<uint8_t>> values; // Dati
    
    bool isFull() const {
        return keys.size() >= BTREE_ORDER - 1;
    }
    
    void serialize(uint8_t* buffer);
    void deserialize(const uint8_t* buffer);
};
```

### Classe BPlusTree

```cpp
class BPlusTree {
    Pager pager;          // I/O da disco
    uint32_t rootPageNum;
    
public:
    void insert(uint32_t key, std::vector<uint8_t> value);
    std::vector<uint8_t> search(uint32_t key);
    void remove(uint32_t key);
};
```

## Ottimizzazioni Possibili

### 1. Fanout Tuning

```cpp
// Aumenta ordine per range queries frequenti
const uint32_t BTREE_ORDER = 256; // Meno livelli

// Diminuisci per inserimenti frequenti
const uint32_t BTREE_ORDER = 4;   // Meno split
```

### 2. Lazy Deletion

```cpp
// Marca chiavi come deleted, ripulisc dopo
void lazyDelete(uint32_t key) {
    node->markAsDeleted(key);  // O(1)
}

void compact() {
    // Background cleanup
}
```

### 3. Bulk Loading

```cpp
// Carica milioni di record velocemente
void bulkLoad(std::vector<Record> sorted_records) {
    // Crea bottom-up invece che incrementale
    // ~1000x più veloce per large datasets
}
```

## Visualizzazione Dinamica

### Inserimento Passo per Passo

```
Step 1: Insert 10
[10]

Step 2: Insert 20
[10 | 20]

Step 3: Insert 30
[10 | 20 | 30]

Step 4: Insert 40 (SPLIT!)
         [20]
        /    \
    [10]    [30 | 40]

Step 5: Insert 5
          [20]
         /    \
    [5|10]   [30|40]

Step 6: Insert 50
          [20]
         /    \
    [5|10]  [30|40|50]

Step 7: Insert 60 (SPLIT!)
             [20 | 40]
            /    |     \
       [5|10] [30] [50|60]
```

## Comparazione con Alternative

### vs Array Ordinato

```
Array: [1, 5, 10, 15, 20, 25, 30]
Search 25: O(log n) = 3 confronti ✓
Insert 12: O(n) shift = 6 operazioni ✗
```

### vs Binary Search Tree

```
BST Unbilanciato:
            1
             \
              5
               \
                10 ← Worst case O(n)

B+ Tree sempre bilanciato:
         5
        / \
       1   10 ← Sempre O(log n)
```

### vs Hash Table

```
Hash:
Search 25: O(1) media ✓
Range [10-20]: O(n) deve scansionare tutto ✗

B+ Tree:
Search 25: O(log n) ✓
Range [10-20]: O(log n + k) ottimale ✓
```

## Buffer Pool Caching

Il Pager mantiene una cache delle pagine:

```cpp
std::map<uint32_t, std::vector<uint8_t>> cache;

// Hit ratio importante!
Hit Ratio = (Cache Hits) / (Total Requests)

Tipico: 90-99% hit ratio
```

## Conclusione

Il B+ Tree è la spina dorsale dei database moderni perché:

1. ✅ **Efficiente su disco** - Minimizza I/O
2. ✅ **Range queries** - Perfetto per SQL WHERE
3. ✅ **Auto-bilanciamento** - Operazioni prevedibili
4. ✅ **Scalabile** - Milioni di record senza degradazione

**TitanDB implementa una versione semplificata ma funzionale di questi principi!**
