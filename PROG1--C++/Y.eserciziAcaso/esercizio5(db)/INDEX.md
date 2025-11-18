# 📚 TitanDB - Index & Getting Started

## 📖 Come Iniziare (5 min)

### Passo 1: Leggi questo primo
```
START HERE: EXECUTIVE_SUMMARY.md
├─ Cosa è TitanDB?
├─ Architettura overview
└─ Performance characteristics
(5 minuti)
```

### Passo 2: Setup
```
g++ -std=c++17 -O2 -o titandb titandb.cpp
./titandb
```

### Passo 3: Testa comandiSQL
```sql
CREATE TABLE users (id INT, name VARCHAR);
INSERT VALUES (1, 'Alice');
SELECT * FROM users;
EXIT;
```

---

## 📚 Documentazione Completa

### Per Beginners 👶
1. **README.md** - Guida utente (lettura: 10 min)
   - Quick start
   - Compilazione
   - Esempi di utilizzo
   - Struttura file

2. **EXECUTIVE_SUMMARY.md** - Panoramica (lettura: 15 min)
   - Cosa è TitanDB
   - Architettura
   - Funzionalità
   - Performance

3. **QUICKREF.md** - Cheat sheet (lettura: 5 min)
   - Comandi SQL veloci
   - Struttura dati
   - Debug tips

### Per Developers 👨‍💻
4. **DOCUMENTATION.md** - Guida tecnica (lettura: 30 min)
   - Componenti dettagliati
   - Classi principali
   - Flusso di esecuzione
   - Configurazione

5. **BTREE_GUIDE.md** - B+ Tree profondo (lettura: 45 min)
   - Teoria B+ Tree
   - Visualizzazioni
   - Operazioni (search, insert, delete)
   - Performance analysis
   - Serializzazione

6. **LEARNING_PATH.md** - Roadmap formativo (lettura: 1 ora)
   - 8 fasi di apprendimento
   - Esercizi pratici
   - Roadmap estensioni
   - Checklist completamento

### Per Implementatori 🔧
7. **config.h** - Configurazione centralizzata
   - Costanti del progetto
   - Tuning parameters
   - Preset configurations
   - Helper functions

8. **Makefile** - Build automation
   - Compilazione
   - Debug build
   - Testing
   - Profiling

9. **test.sh** - Test suite automatica
   - Test CREATE
   - Test INSERT/SELECT
   - Test UPDATE/DELETE
   - Stress test

---

## 🎯 Percorso di Apprendimento (Tempo Totale: ~6-8 ore)

### Giorno 1: Foundation (2 ore)
```
1. EXECUTIVE_SUMMARY.md (15 min)
2. README.md (15 min)
3. Compila e testa (20 min)
4. QUICKREF.md (10 min)
5. Prova comandi (30 min)
   └─ CREATE TABLE
   └─ INSERT VALUES
   └─ SELECT *
   └─ UPDATE/DELETE
6. Leggi DOCUMENTATION.md (30 min)
```

### Giorno 2: B+ Tree (2.5 ore)
```
1. BTREE_GUIDE.md sezione 1-3 (30 min)
2. Disegna tree su carta (20 min)
3. Traccia search() manualmente (20 min)
4. BTREE_GUIDE.md sezione 4-7 (30 min)
5. Esercizi visualizzazione (20 min)
6. Analizza performance (20 min)
```

### Giorno 3: Deep Dive (2.5 ore)
```
1. LEARNING_PATH.md Fase 2 (30 min)
   └─ Analizza Lexer
2. LEARNING_PATH.md Fase 3 (30 min)
   └─ Analizza Parser
3. LEARNING_PATH.md Fase 4 (30 min)
   └─ Esercizi B+ Tree
4. LEARNING_PATH.md Fase 5-7 (60 min)
   └─ Pager, Table, Database
```

### Giorno 4+: Estensioni (3-5 ore)
```
1. Scegli 2-3 estensioni da LEARNING_PATH.md
2. Implementa B+ Tree splitting
3. Aggiungi Aggregate functions
4. Testa performance
5. Documenta il tuo codice
```

---

## 🗂️ File del Progetto

### Codice Sorgente
```
titandb.cpp               1470 righe, tutte le componenti
config.h                   200 righe, configurazione centralizzata
Makefile                    80 righe, build automation
test.sh                     80 righe, test suite
```

### Documentazione
```
README.md                   Guida utente principale
EXECUTIVE_SUMMARY.md        Panoramica tecnica
DOCUMENTATION.md            Architettura dettagliata
BTREE_GUIDE.md             B+ Tree approfondito
LEARNING_PATH.md           Esercizi e roadmap
QUICKREF.md                Quick reference card
INDEX.md                   Questo file
```

### Generated
```
titandb.db                 File database (generato)
titandb                    Eseguibile compilato
*.o                        Object files
```

---

## 🎓 Roadmap di Studio Consigliato

### Week 1: Basics
```
Mon: EXECUTIVE_SUMMARY + README
Tue: Compilazione e testing base
Wed: QUICKREF + DOCUMENTATION fase 1-2
Thu: DOCUMENTATION fase 3-4
Fri: Prova comandi SQL vari
```

### Week 2: Core Concepts
```
Mon: BTREE_GUIDE sezioni 1-3
Tue: BTREE_GUIDE sezioni 4-6
Wed: Disegna tree, esercizi
Thu: LEARNING_PATH Fase 2-3
Fri: LEARNING_PATH Fase 4-5
```

### Week 3: Implementation
```
Mon: LEARNING_PATH Fase 6-8
Tue: Analizza Lexer a fondo
Wed: Analizza Parser a fondo
Thu: Analizza B+ Tree splitting
Fri: Esercizi di modifica
```

### Week 4+: Extensions
```
Scegli dalle estensioni:
- B+ Tree splitting completo
- Transaction support
- Aggregate functions
- JOIN operations
```

---

## ❓ FAQ

### Q: Devo leggere tutta la documentazione?
**A:** No! Start con EXECUTIVE_SUMMARY + README, poi procedi in base agli interessi.

### Q: Quanto tempo ci vuole per capirlo?
**A:** ~6-8 ore per il core, +3-5 ore per estensioni.

### Q: Posso usarlo come database vero?
**A:** Sì per piccoli dataset (<100K record), no per production grandi.

### Q: Come aggiungo nuove feature?
**A:** Leggi LEARNING_PATH.md sezione "Estensioni Suggerite".

### Q: Che risorse mi servono?
**A:** Solo C++17 compiler (g++, clang) e bash per test.

---

## 🚀 Quick Commands

```bash
# Compilazione veloce
g++ -std=c++17 -o titandb titandb.cpp

# Con debug
g++ -std=c++17 -g -o titandb titandb.cpp

# Esecuzione
./titandb

# Test automatici
./test.sh

# Pulizia
rm -f titandb *.o titandb.db

# Con Makefile
make build
make run
make test
make clean
```

---

## 📊 Veloce Overview Componenti

| Componente | Righe | Tempo Studio |
|---|---|---|
| Lexer | 350 | 1 ora |
| Parser | 300 | 1 ora |
| B+ Tree | 250 | 2 ore |
| Pager | 120 | 30 min |
| Table | 200 | 45 min |
| Database | 150 | 30 min |
| REPL | 100 | 20 min |
| **TOTALE** | **1470** | **6-7 ore** |

---

## 🎯 Checklist Getting Started

- [ ] Ho scaricato/clonato il progetto
- [ ] Ho letto EXECUTIVE_SUMMARY.md
- [ ] Ho letto README.md
- [ ] Ho compilato con successo
- [ ] Ho testato CREATE TABLE
- [ ] Ho testato INSERT VALUES
- [ ] Ho testato SELECT *
- [ ] Ho testato UPDATE
- [ ] Ho testato DELETE
- [ ] Ho testato persistenza (restart)
- [ ] Ho letto QUICKREF.md
- [ ] Ho iniziato DOCUMENTATION.md
- [ ] Ho letto BTREE_GUIDE.md
- [ ] Ho scelto estensioni da implementare
- [ ] Ho completato 1 esercizio

---

## 🏆 Milestones

**Milestone 1:** Setup & Basic Testing (1 ora)
- Compila ✓
- Testa comandi base ✓

**Milestone 2:** Understand Core (3 ore)
- Capisce Lexer/Parser ✓
- Capisce B+ Tree ✓
- Capisce Storage ✓

**Milestone 3:** Hands-on (2 ore)
- Modifica Lexer ✓
- Aggiunge token nuovo ✓
- Traccia execution ✓

**Milestone 4:** Extension (3-5 ore)
- Implementa estensione ✓
- Testa performance ✓
- Documenta ✓

---

## 💡 Pro Tips

### Tip 1: Stampa il B+ Tree
Aiuta a capire cosa succede:
```cpp
printTree(root_node);
```

### Tip 2: Usa hexdump
Visualizza il file DB:
```bash
hexdump -C titandb.db | head -30
```

### Tip 3: Batch Inserts
Meglio performance:
```bash
for i in {1..1000}; do
  echo "INSERT VALUES ($i, 'test');"
done | ./titandb
```

### Tip 4: Memory Profiling
```bash
g++ -std=c++17 -g -fsanitize=address -o titandb titandb.cpp
./titandb
```

---

## 🤝 Comunità & Support

Se hai domande:
1. Rilleggi la sezione relativa di DOCUMENTATION.md
2. Cerca in QUICKREF.md
3. Prova esempi da LEARNING_PATH.md
4. Debugga con hexdump e printf

---

## 📝 Modifiche Recenti

```
v1.0 (Novembre 2025):
├─ Initial release
├─ Codice base ~1470 linee
├─ Full documentation (~40 pagine)
├─ Test suite included
└─ Ready for learning
```

---

## 🎓 Risorse Esterne

| Risorsa | Link | Tipo |
|---|---|---|
| SQLite Architecture | https://www.sqlite.org/arch.html | 📖 |
| B+ Tree Visualization | https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html | 🎮 |
| CMU Databases | https://15445.courses.cs.cmu.edu/ | 🎥 |
| Database Internals Book | Alex Petrov | 📚 |

---

## ✨ Prossimi Passi

1. **Leggi EXECUTIVE_SUMMARY.md** (15 min)
2. **Compila il codice** (5 min)
3. **Testa comandi SQL** (10 min)
4. **Leggi DOCUMENTATION.md** (30 min)
5. **Studia BTREE_GUIDE.md** (1 ora)
6. **Completa esercizi** (2+ ore)
7. **Implementa estensioni** (3-5 ore)

---

**Pronti a iniziare? → Apri EXECUTIVE_SUMMARY.md** 🚀

---

**TitanDB Learning Suite v1.0**  
*Imparare il design dei database costruendo uno da zero*
