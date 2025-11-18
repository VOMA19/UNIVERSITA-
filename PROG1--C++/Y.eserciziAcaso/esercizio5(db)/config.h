// ============================================================================
// CONFIG.H - Configurazione TitanDB
// ============================================================================

#ifndef TITANDB_CONFIG_H
#define TITANDB_CONFIG_H

#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

/**
 * @file config.h
 * @brief Configurazione centralizzata per TitanDB
 * 
 * Modifica questi parametri per ottimizzare le prestazioni
 * per il tuo use case specifico.
 */

// ============================================================================
// STORAGE CONFIGURATION
// ============================================================================

/** Dimensione di una pagina su disco (4KB è standard) */
static constexpr uint32_t PAGE_SIZE = 4096;

/** Numero massimo di pagine in memoria (RAM limit) */
static constexpr uint32_t MAX_PAGES_IN_MEMORY = 1000;

/** Numero massimo totale di pagine su disco */
static constexpr uint32_t MAX_TOTAL_PAGES = 10000;

/** Path di default per il database */
static constexpr const char* DEFAULT_DB_FILE = "titandb.db";

// ============================================================================
// B+ TREE CONFIGURATION
// ============================================================================

/** Ordine del B+ Tree (m)
 * 
 * Ogni nodo ha al massimo m-1 chiavi e m puntatori.
 * Valori tipici:
 * - 4-8: per piccoli dataset, meno memoria
 * - 16-32: standard per database piccoli
 * - 64-256: per dataset grandi, meno livelli
 * 
 * Trade-off:
 * - Più alto: meno livelli, meno I/O
 * - Più basso: meno memoria per nodo
 */
static constexpr uint32_t BTREE_ORDER = 8;

/** Numero massimo di chiavi per nodo */
static constexpr uint32_t BTREE_MAX_KEYS = BTREE_ORDER - 1;

/** Numero massimo di puntatori interni */
static constexpr uint32_t BTREE_MAX_CHILDREN = BTREE_ORDER;

/** Numero minimo di chiavi per nodo (eccetto root) */
static constexpr uint32_t BTREE_MIN_KEYS = (BTREE_ORDER / 2) - 1;

// ============================================================================
// MEMORY CONSTRAINTS
// ============================================================================

/** Lunghezza massima di una chiave (bytes) */
static constexpr uint32_t MAX_KEY_SIZE = 256;

/** Lunghezza massima di un valore (bytes) */
static constexpr uint32_t MAX_VALUE_SIZE = 1024;

/** Lunghezza massima di una stringa VARCHAR */
static constexpr uint32_t MAX_VARCHAR_SIZE = 512;

/** Numero massimo di colonne per tabella */
static constexpr uint32_t MAX_COLUMNS = 32;

/** Numero massimo di tabelle nel database */
static constexpr uint32_t MAX_TABLES = 256;

// ============================================================================
// QUERY EXECUTION
// ============================================================================

/** Timeout per una query (millisecondi) */
static constexpr uint32_t QUERY_TIMEOUT_MS = 30000;

/** Numero massimo di risultati per SELECT */
static constexpr uint32_t MAX_RESULT_ROWS = 1000000;

/** Batch size per operazioni bulk */
static constexpr uint32_t BULK_INSERT_BATCH_SIZE = 1000;

// ============================================================================
// BUFFER POOL STRATEGY
// ============================================================================

enum class BufferPoolStrategy {
    LRU,      // Least Recently Used (più comune)
    FIFO,     // First In First Out
    CLOCK,    // Clock replacement algorithm
    LFU       // Least Frequently Used
};

static constexpr BufferPoolStrategy BUFFER_STRATEGY = BufferPoolStrategy::LRU;

/** Percentuale di hit rate target */
static constexpr double TARGET_HIT_RATE = 0.95;

// ============================================================================
// LOGGING & DEBUG
// ============================================================================

/** Enable debug logging */
static constexpr bool DEBUG_MODE = false;

/** Enable query profiling */
static constexpr bool PROFILE_QUERIES = false;

/** Enable memory profiling */
static constexpr bool PROFILE_MEMORY = false;

/** Log file path (per debug) */
static constexpr const char* LOG_FILE = "titandb.log";

// ============================================================================
// OPTIMIZATION FLAGS
// ============================================================================

/** Abilita query caching */
static constexpr bool ENABLE_QUERY_CACHE = true;

/** Abilita index caching */
static constexpr bool ENABLE_INDEX_CACHE = true;

/** Abilita B+ tree compression */
static constexpr bool ENABLE_COMPRESSION = false;

/** Abilita lazy deletion */
static constexpr bool ENABLE_LAZY_DELETE = false;

// ============================================================================
// PERFORMANCE TUNING
// ============================================================================

/** Numero di thread per query parallele (futures) */
static constexpr uint32_t NUM_QUERY_THREADS = 4;

/** Threshold per parallelizzare una query (rows) */
static constexpr uint32_t PARALLEL_THRESHOLD = 100000;

/** Dimensione del buffer di I/O (bytes) */
static constexpr uint32_t IO_BUFFER_SIZE = 65536;

// ============================================================================
// DATA TYPE LIMITS
// ============================================================================

/** Massimo valore INT */
static constexpr int32_t MAX_INT = 2147483647;

/** Minimo valore INT */
static constexpr int32_t MIN_INT = -2147483648;

/** Precisione per FLOAT */
static constexpr uint32_t FLOAT_PRECISION = 6;

// ============================================================================
// VALIDATION SETTINGS
// ============================================================================

/** Abilita strict schema validation */
static constexpr bool STRICT_SCHEMA = true;

/** Abilita type checking */
static constexpr bool STRICT_TYPES = true;

/** Abilita foreign key constraints */
static constexpr bool ENABLE_FK_CONSTRAINTS = false;

/** Abilita transaction support */
static constexpr bool ENABLE_TRANSACTIONS = false;

// ============================================================================
// FUNCTIONS FOR TUNING
// ============================================================================

/**
 * Calcola il numero di nodi stimato per n records
 */
inline uint32_t estimateTreeNodes(uint32_t numRecords) {
    if (numRecords == 0) return 1;
    
    uint32_t nodes = 1;
    uint32_t capacity = BTREE_ORDER - 1;
    
    while (capacity < numRecords) {
        nodes += (numRecords + capacity - 1) / capacity;
        capacity *= BTREE_ORDER;
    }
    
    return nodes;
}

/**
 * Calcola l'utilizzo di memoria stimato
 */
inline uint32_t estimateMemoryUsage(uint32_t numRecords, uint32_t avgRecordSize) {
    uint32_t nodes = estimateTreeNodes(numRecords);
    return nodes * PAGE_SIZE;
}

/**
 * Calcola il numero di livelli del B+ tree
 */
inline uint32_t calculateTreeDepth(uint32_t numRecords) {
    if (numRecords == 0) return 0;
    
    uint32_t depth = 0;
    uint32_t capacity = 1;
    
    while (capacity < numRecords) {
        capacity *= BTREE_ORDER;
        depth++;
    }
    
    return depth;
}

/**
 * Calcola I/O operations stimate per una ricerca
 */
inline uint32_t estimateSearchIO(uint32_t numRecords) {
    // Una I/O per ogni livello del tree
    return calculateTreeDepth(numRecords);
}

// ============================================================================
// PRESET CONFIGURATIONS
// ============================================================================

/** Presets per diversi use cases */
namespace Presets {
    
    /** Per database piccoli (< 10K records) */
    struct SmallDB {
        static constexpr uint32_t BTREE_ORDER = 4;
        static constexpr uint32_t MAX_PAGES = 100;
        static constexpr bool ENABLE_COMPRESSION = false;
    };
    
    /** Per database medi (10K - 1M records) */
    struct MediumDB {
        static constexpr uint32_t BTREE_ORDER = 16;
        static constexpr uint32_t MAX_PAGES = 1000;
        static constexpr bool ENABLE_COMPRESSION = true;
    };
    
    /** Per database grandi (> 1M records) */
    struct LargeDB {
        static constexpr uint32_t BTREE_ORDER = 64;
        static constexpr uint32_t MAX_PAGES = 10000;
        static constexpr bool ENABLE_COMPRESSION = true;
    };
    
    /** Per OLTP (many inserts/updates) */
    struct OLTPConfig {
        static constexpr uint32_t BTREE_ORDER = 8;
        static constexpr bool ENABLE_LAZY_DELETE = true;
        static constexpr uint32_t NUM_QUERY_THREADS = 8;
    };
    
    /** Per OLAP (many queries) */
    struct OLAPConfig {
        static constexpr uint32_t BTREE_ORDER = 64;
        static constexpr bool ENABLE_QUERY_CACHE = true;
        static constexpr uint32_t NUM_QUERY_THREADS = 4;
    };
    
    /** Per sistema embedded (memoria limitata) */
    struct EmbeddedConfig {
        static constexpr uint32_t BTREE_ORDER = 4;
        static constexpr uint32_t MAX_PAGES = 50;
        static constexpr uint32_t MAX_TABLES = 10;
        static constexpr uint32_t MAX_COLUMNS = 16;
    };
}

// ============================================================================
// RUNTIME CONFIG CLASS (non-const per config dinamica)
// ============================================================================

class RuntimeConfig {
public:
    uint32_t btreeOrder = BTREE_ORDER;
    uint32_t maxPages = MAX_PAGES_IN_MEMORY;
    bool debugMode = DEBUG_MODE;
    bool enableQueryCache = ENABLE_QUERY_CACHE;
    
    /** Carica preset */
    void loadPreset(const string& preset) {
        if (preset == "small") {
            btreeOrder = 4;
            maxPages = 100;
        } else if (preset == "medium") {
            btreeOrder = 16;
            maxPages = 1000;
        } else if (preset == "large") {
            btreeOrder = 64;
            maxPages = 10000;
        }
    }
    
    /** Stampa config corrente */
    void print() const {
        cout << "TitanDB Runtime Configuration:\n";
        cout << "  B+ Tree Order: " << btreeOrder << "\n";
        cout << "  Max Pages: " << maxPages << "\n";
        cout << "  Debug Mode: " << (debugMode ? "ON" : "OFF") << "\n";
        cout << "  Query Cache: " << (enableQueryCache ? "ON" : "OFF") << "\n";
    }
};

#endif // TITANDB_CONFIG_H

// ============================================================================
// USAGE EXAMPLES
// ============================================================================

/*

// In main.cpp:

#include "config.h"

int main() {
    // Usa configurazione default
    Database db("titandb.db");
    
    // O crea configurazione custom
    RuntimeConfig config;
    config.btreeOrder = 16;
    config.debugMode = true;
    config.loadPreset("medium");
    config.print();
    
    // Estima memoria per 1M records
    uint32_t estimatedMemory = estimateMemoryUsage(1000000, 256);
    cout << "Estimated memory: " << (estimatedMemory / 1024 / 1024) 
              << " MB\n";
    
    // Estima I/O per ricerca
    uint32_t ioOps = estimateSearchIO(1000000);
    cout << "Estimated I/O ops per search: " << ioOps << "\n";
}

*/
