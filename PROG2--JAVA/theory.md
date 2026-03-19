# Appunti del Corso OOP

> *Generato automaticamente dai commenti del codice sorgente.*

# Indice

- [Lezione 01](#lezione-01)
  - [1-intro_slides](#1-intro_slides)
  - [2-ripasso](#2-ripasso)
- [Lezione 02](#lezione-02)
  - [V1](#v1)
  - [V2](#v2)
  - [V3](#v3)
  - [V_enums](#v_enums)
- [Lezione 03](#lezione-03)
  - [Ackages](#ackages)
  - [Final_mod](#final_mod)
  - [Static_globals](#static_globals)
- [Lezione 04](#lezione-04)
- [Lezione 05](#lezione-05)
  - [Inheritance](#inheritance)
- [Lezione 06](#lezione-06)
  - [Abstracts](#abstracts)
  - [Overloading](#overloading)
  - [Overriding](#overriding)
- [Lezione 07](#lezione-07)
  - [Defaults](#defaults)
  - [Interfaces](#interfaces)
- [Lezione 08](#lezione-08)
  - [Strategy](#strategy)
- [Lezione 09lab1](#lezione-09lab1)
- [Lezione 10](#lezione-10)
  - [Arguments](#arguments)
  - [Bindings](#bindings)
- [Lezione 11](#lezione-11)
  - [Bad](#bad)
  - [Exercise](#exercise)
  - [Templatemethod](#templatemethod)
- [Lezione 12lab2](#lezione-12lab2)
- [Lezione 13](#lezione-13)
  - [Exceptions](#exceptions)
  - [Tables](#tables)
- [Lezione 14](#lezione-14)
  - [Examples](#examples)
- [Lezione 15](#lezione-15)
  - [Factory_method](#factory_method)
  - [State](#state)
- [Lezione 16lab3](#lezione-16lab3)

---

# Lezione 01

**Argomenti Trattati**
- [1-intro_slides](#1-intro_slides)
- [2-ripasso](#2-ripasso)

---

## 1-intro_slides

---

## 2-ripasso

### 📄 `lecture_01.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture01/2-ripasso/lecture_01.cpp)


#### Lezione 1: Recap delle nozioni di Programmazione 1


#### Introduzione

Fin'ora avete fatto "programming in the small": piccole procedure, familiarizzazione col coding  
In questo corso vediamo "programming in the large"  
- Suddivisione del lavoro tra persone/gruppi (divide et impera)  
- Manutenibilità (che succede se voglio cambiare qualcosa tra un mese/un anno/…)  
- Robustezza  
Programming in the large si ottiene tramite:  
- Ingegneria del software (vedi altri corsi UNITN)  
- Buone tecniche di programmazione (es. commenti aggiornati)  
- Supporto dal linguaggio: OO -> Questo è il focus del corso  
Di seguito facciamo un recap delle nozioni di P1, programming in the small, per costruire una notional machine corretta sulla quale montare i concetti di questo corso  

#### Notional Machine

La notional machine è un concetto di pedagogia, nello specifico di didattica della programmazione, è l'astrazione che ognuno di noi si crea nella propria testa per quanto riguarda la semantica di un linguaggio (il runtime, se vogliamo)  
Bloom's Taxonomy: https://bpb-us-e1.wpmucdn.com/wordpressua.uark.edu/dist/a/315/files/2013/09/Blooms_Taxonomy_pyramid_cake-style-use-with-permission.jpg?bid=315  
BT: tutto Remember  

#### Primo argomento: variabili

Le variabili hanno un tipo e si possono inizializzare.  
Non inizializzare le variabili è un problema, i linguaggi seri forzano l'inizializzazione  
Lo `scopè definisce la visibilità di una variabile.  
Se una variabile è visibile da tutto il programma, è globale.  
Se una variabile è visibile solo all'interno di una funzione (o di una sottoparte della funzione), è locale  

#### Secondo argomento: stack frame

Ogni volta che chiamiamo una funzione viene creato un 'allocation record' o 'stack frame', che contiene:  
- parametri attuali,  
- variabili locali,  
- indirizzo di ritorno  
Visualizziamo lo stack di allocation records  
`fact` è una funzione ricorsiva, perchè?  

#### Terzo argomento: puntatori

I puntatori sono indirizzi in memoria, data una variabile si può prendere un puntatore con l'operazione `&` e si può seguire un puntatore con l'operazione `*`  
La funzione `test_puntatori()` definisce puntatori (int * -- scritti comunemente male ma vabbè)  
La funzione `test_puntatori2()` passa un puntatore a `incrementa_ptr` e può farlo perchè `x` è ancora viva sullo stack  

#### Quarto argomento: memoria

Un programma ha diverse zone:  
- la zona di codice, dove si trovano le istruzioni di ogni funzione, tipicamente in RX  
- la zona dei globali, con le variabili globali  
- lo stack e la heap  
Nella funzione `test_mem_static()` la variabile `x` è locale, quindi viene allocata sullo stack, all'interno dello stack frame di `test_mem_static`  
Nella funzione `test_mem_dyn()` la variabile `px` è locale ma viene creata con la keyword `new`, che la alloca sulla heap.  
Esistono 3 modi di gestire l'allocazione della memoria:  
- manuale (C),  
- garbage collection (Java, ...)  
- ownership (Rust)  

### 📄 `test_memoria.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture01/2-ripasso/test_memoria.cpp)

### 📄 `test_puntatori.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture01/2-ripasso/test_puntatori.cpp)

> 📱 **Quiz:** cosa viene stampato?  

### 📄 `test_stack_frame.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture01/2-ripasso/test_stack_frame.cpp)

> 📱 **Quiz:** qual è l'ultima operazione fatta nella riga sopra prima del return?  

### 📄 `test_vars.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture01/2-ripasso/test_vars.cpp)

> 📱 **Quiz:** che valori stampa?  
> 📱 **Quiz:** che valori stampa?  
> 📱 **Quiz:** che valori stampa?  
> 📱 **Quiz:** che valori stampa?  

### 📂 `2-ripasso/cmake-build-debug/CMakeFiles/3.22.3/CompilerIdCXX`

#### 📄 `CMakeCXXCompilerId.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture01/2-ripasso/cmake-build-debug/CMakeFiles/3.22.3/CompilerIdCXX/CMakeCXXCompilerId.cpp)

---

# Lezione 02

**Argomenti Trattati**
- [V1](#v1)
- [V2](#v2)
- [V3](#v3)
- [V_enums](#v_enums)

---

### 📄 File: `Lecture2.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture02/Lecture2.java)


#### Lezione 2


#### Introduzione all'OO


#### Motivazione

Programming in the large.  
Differentemente dal programming in the small, vogliamo creare un progetto come l'unione delle sue sottoparti e seguire l'evoluzione del progetto  
Il codice evolve nel tempo (cambio di funzionalità), e nei manutentori (persone che ci lavorano)  
Vogliamo massimizzare riuso del codice: questo permette di minimizzare errori  
Per studiare i principi OO usiamo Java, con cenni a come altri linguaggi implementano gli stessi principi.  
Java è semplice ed espressivo.  
Java ha degli obiettivi di design: è fortemente tipato (anche se sballa con gli array), è modulare, non è il massimo dell'efficienza (ma spesso questo si lascia a un buon compilatore)  

#### Concetti chiave

Quali sono i concetti fondanti del paradigma OO  
- oggetti : hanno uno stato / hanno un comportamento (messaggi / metodi), hanno un id, hanno una locazione in memoria,  
- incapsulamento : interfacce / information hiding / implementazioni non visibili  
- classificazione (ereditarietà): gli oggetti appartengono a piu classi  
- specializzazione (ereditarietà) : permette l'aggiunta di stato & comportamento  
- polimorfismo : permette ad uno stesso oggetto di essere usato in contesti (di tipo) diversi  

#### Terminologia

In oop, usiamo termini ben definiti  
- classe : tipo definito dall'utente. Schema per creare oggetti che condividono comportamento e stessa forma di stato -- memory footprint  
- oggetto : istanza di una classe. Ha una nozione di stato che varia da oggetto a oggetto  
- metodo : comportamento definito da una classe, invocabile su un oggetto (con parametri)  
- funzione : funzionalità che non si chiama su un oggetto  
- campo/variabile d'istanza : parte dello stato di un oggetto  
- firma : tipo di input e di output di un metodo (o di una funzione)  

#### Esempi

Un tipico esempio di classe è lo stampino dei biscotti: tutti i biscotti hanno la stessa forma  
Il correlato esempio di oggetto sono biscotti che sono decorati in maniera diversa l'uno dall'altro.  
Questi biscotti hanno la stessa forma (classe), ma possono avere caratteristiche diverse.  
L'esempio che seguiamo in questo corso è quello di Minecraft.  
Tutti i blocchi sono simili in Minecraft, per esempio hanno lo stesso comportamento (puoi scavarli)  
Però ogni blocco è diverso. Ogni blocco di terra è scollegato dagli altri blocchi di terra, e scavarne uno non tocca gli altri.  
E ancora di più, i blocchi di tipo diverso hanno comportamento diverso.  

#### Idea del corso

In questo corso useremo Minecraft come progetto per capire i principi OO.  
Partiremo dalla definizione di alcuni blocchi di Minecraft per capire come strutturare questa nozione in classi, e per capire che i blocchi sono oggetti.  
Scriveremo metodi e campi per definire il comportamento di questi oggetti  
Applicheremo le nozioni di incapsulamento per prevenire comportamenti non voluti.  
Utilizzeremo l'ereditarietà per modularizzare il progetto e minimizzare la scrittura del codice, e allo stesso tempo permettere comportamenti spefici per blocchi di tipo diverso.  
Ci baseremo sul polimorfismo (parametrico e di sottotipo) per favorire il riuso di codice.  
Andremo poi ad aggiungere le eccezioni per la gestione degli errori.  
Utilizzeremo due framework di Java: collections (per organizzare i blocchi in strutture dati), e javafx (per dotare il nostro progetto di una GUI).  
Infine, integreremo diversi design patterns nel progetto per semplificare la gestione del codice, minimizzarne la scrittura e massimizzarne il riuso.  

#### Struttura dei file e del main

Siamo dentro al package `lecture02`, una struttura con un significato semantico che vedremo dopo  
Per ora considerate i package come un modo per fare ordine all'interno di un grande progetto  
Le righe di `import` di sotto le evitiamo, ne parliamo insieme ai package più avanti  
Tutto in Java è una classe, non esistono metodi scollegati ad una classe  
Per questo dichiariamo una classe `Lecture2`  
Di sotto dichiariamo il metodo `main`.  
`main` è un nome speciale, Java sa che può cominciare l'esecuzione da questo medoto e quando l'esecuzione parte, il Runtime di Java crea un processo che inizia da qui.  
Ci possono essere più metodi `main` in uno stesso progetto.  
Per ora evitiamo di parlare delle keyword `public` e `static`.  
Il metodo `main` ha una firma: `String[] -> void` cioè prende in input un array di `String` e non restituisce nessun valore (`void`)  
BT: Remember & Understand  

#### Oggetti e Classi --- La classe TNT (dentro v1)

Java conosce una serie di Tipi Primitivi, alcuni sono forniti dal linguaggio come `int` e `boolean` e `char` e `double ` mentre altri sono forniti dalla libreria di base come `String` o `Date `.  
In ogni progetto però, dobbiamo modellare un dominio specifico.  
In questo progetto (cioè in questo corso), il dominio è quello di Minecraft.  
Quindi dobbiamo poter definire dei tipi nostri, con un comportamento che decidiamo noi  
Questo è quanto facciamo con la classe `TNT`  
Aggiungiamo il package `v1` e dentro a quella directory aggiungiamo il file `TNT.java `  
Questo file contiene la definizione della classe `TNT`  
Definendo la nostra classe stiamo aggiungendo un nuovo tipo al programma, il tipo `TNT`, che sarà diverso da `Zombie `, `Cobblestone `, `String`, `int`, ...  

#### Nota: statico VS dinamico

Il codice ha per sua caratteristica fondante due aspetti: quello statico e quello dinamico.  
Gli aspetti statici del codice catturano quello che è il codice prima di essere eseguito, quando è scritto dal programmatore.  
Gli aspetti dinamici del codice catturano quello che è il codice in esecuzione, cioè a runtime.  
Questi due aspetti permeano tutte le nozioni di programmazione, ma ancora di più in OO.  
Per esempio, classi e oggetti sono aspetti statici e dinamici del programma.  
Il programmatore scrive classi, e a runtime queste vengono istanziate in oggetti.  
Non vi sono oggetti prima del runtime, non si scrivono classi a runtime.  

#### Allocazione di oggetti

Questo metodo crea un nuovo oggetto di tipo TNT tramite la keyword `new` e lo salva in una variabile locale `tnt1`.  
Il tipo `TNT` all'inizio della riga definisce il tipo della variabile.  
Possono esistere più istanze della stessa classe, cioè più oggetti di quel tipo, per esempio il secondo oggetto viene salvato nella variabile `tnt2`  

#### I Campi (nelle classi) e lo stato (degli oggetti)

Col termine stato identifichiamo i dati contenuti dentro un oggetto.  
Per permettere agli oggetti di avere uno stato, la loro classe deve avere dei campi  
Ogni oggetto ha la propria istanziazione dei campi dichiarati nella classe, e modificare il contenuto dei campi di un oggetto non modifica altri oggetti.  
Questo perchè oggetti diversi occupano aree di memoria diverse.  

#### La classe TNT (dentro v2)

La classe `TNT` nel package `v2` estende la precedente con 3 campi  
Ogni campo ha un modificatore di visibilità (per ora `public`), in tipo ed un nome.  
Il metodo `fieldsExample()` crea due blocchi, poi modifica lo stato di uno, e ne stampa i valori.  
> 📱 **Quiz:** cosa viene stampato?  

#### I costruttori

I costruttori sono metodi speciali che si usano per inizializzare i campi di un oggetto, si identificano dal nome, che è uguale a quello della classe, e dall'assenza di un tipo di ritorno, in quanto ritornano una istanza della classe  
La classe `TNT` dentro a `v2` contiene due costruttori.  
Ogni classe può contenere quanti costruttori vuole, purchè di firma diversa.  
Il primo inizializza i campi a dei valori, il secondo richiama il primo (via `this()`) e inizializza un campo ad un valore passato.  

#### Costruttori e valori di default

In assenza di costruttori, il compilatore crea un costruttore di default, che non prende parametri, e che inizializza ogni campo al suo valore di default.  
Per questo abbiamo potuto creare un v1.TNT anche senza costruttore.  
Ogni tipo ha un valore di default, per es., int ha 0, boolean ha false, e per gli oggetti (e gli array) il valore è `null`.  
`null` è una parola chiave che indica l'assenza di un valore vero e proprio  
Il metodo `constructorsExample()` crea due oggetti con il costruttore base, e due con il costruttore che inizializza il campo `explosionPower` a un valore dato in input.  
> 📱 **Quiz:** che valore contiene la variabile `blockÈ?  

#### La parola chiave `this`

La keyword `this` si usa per disambiguare e far riferimento allo stato dell'oggetto sul quale si opera.  
All'interno dei costruttori la si usa per identificare lo stato dell'oggetto che si sta creando.  
Nei metodi lo si usa per identificare l'oggetto su cui è chiamato un metodo.  
Vediamo ora i Metodi  

#### Metodi e comportamento

I Metodi definiscono cosa possono fare gli oggetti, cioè il loro comportamento  
I metodi sono simili alle funzioni: hanno un nome, una lista di parametri (tipati) ed un tipo di ritorno.  
In sostanza, hanno una firma.  
Differentemente dalle funzioni, i metodi si chiamano su oggetti, pertanto al loro interno possono usare la keyword `this` per riferirsi allo stato dell'oggetto su cui sono invocati.  
Un metodo appartiene alla classe che lo definisce, quindi lo si può chiamare solo su oggetti di quella classe.  
Per invocare un metodo si usa la 'dot notation' cioè:  `oggetto.metodo(parametri ...)`.  
L'invocazione di un metodo e l'accesso a un campo si differenziano sintatticamente per la presenza di parentesi (e degli eventuali parametri nel caso di un metodo)  
I metodi permettono di raggruppare un certo tipo di logica coerentemente.  
Inoltre lasciano la definizione del comportamento all'implementatore, e non all'utilizzatore  

#### Nota: chiamante e chiamato

È importante capire due visioni dell'esecuzione del codice: quella del chiamante e quella del chiamato.  
Per esempio, il metodo `ignitè di `TNT` dentro a `v3` controlla se una `TNT` è già innescata, e se non lo è la innesca.  
Questa logica è giusto che rimanga dentro al metodo, e quindi dentro alla classe `TNT`, perchè è chi definisce `TNT` che sa cosa bisogna fare quando la si innesca.  
Questa logica è nel codice 'chiamato'.  
Non avrebbe senso mettere questa logica dentro al metodo `methodsExample `.  
Innanzitutto perchè non è detto che chi scrive `methodsExample ` sappia cosa controllare quando si innesca una TNT.  
Inoltre, se ci fossero 100 oggetti di tipo TNT, non vorremmo mettere 100 controlli dentro a `methodsExample `  

#### La classe `TNT` (v3)

La classe `TNT` dentro al package `v3` estende la precedente con 3 metodi.  
Per convenienza abbiamo eliminato i costruttori.  
Il metodo `methodsExample()` crea una `TNT`, la innesca, poi simula 20 tick di gioco per farla scoppiare  
> ❓ **Domanda:** *Esercizio: provate a chiamare `ignite()` più volte sullo stesso oggetto* 
---  
> ❓ **Domanda:** *Esercizio: provate a creare più oggetti con fusi di lunghezza diversa e a chiamare `tick` su tutti.* 

#### Enums

Enum è una keyword che sta per 'enumerazione'  
Ogni enum ha delle varianti, che si scrivono in `UPPER_CASE ` per convenzione  
Le enums servono per evitare l'antipattern dei Magic Numbers  
In linguaggi vecchi, spesso si usavano `int` per elencare opzioni:  
0=North, 1=East, 2=South, 3=West  
Questo è pericoloso, per esempio se uno scrive `5`, il compilatore non avvisa che si è inserita una direzione inesistente, ma questo lo scoprirete solo a runtime, cioè, avrete dei bug  
Con le enums, si spostano questo tipo di errori e controlli a compile time, cioè staticamente  
Non si può inserire un valore che non faccia parte delle Varianti di una Enum  

#### La Enum `Direction`

È una enum standard, elenca diverse varianti per le direzioni di un gioco  
Il metodo `enumExample()` fa vedere l'utilizzo errato di magic numbers, e quello corretto di enums  
problema 1: leggibilità. Cosa significa 0?  
problema 2: sicurezza. Cosa succede?  
> 📱 **Quiz:** posso decommentare questa riga?  
---  
Il metodo `movePlayer()` è 'cattivo': usa magic numbers  
Il metodo `movePlayerEnum()` è 'buono': usa le enums  
Le enums si analizzano tramite switch  
Ci sono 2 modi, uno switch statement e una switch expression  
> 📱 **Quiz:** Differenza tra statement ed expressions?  
---  
Le switch expressions devono essere esaustive, volendo con un default case  

#### La enum `ToolTier`

Le enums sono classi vere e proprie, possono avere campi, metodi e costruttori  
Ogni variante (es, WOOD o DIAMOND) definisce un oggetto di cui esiste una sola istanza  
Il costruttore delle enums è privato, esternamente si crea una variante, e questo chiama il costruttore come definito dentro all'enum  
Questo è per evitare che si possano aggiungere varianti all'enum  
Le enums possono contenere campi e metodi  
Questo evita di scrivere metodi di lookup come questo  
```if (tool == "Wood") speed = 2.0; if (tool == "Gold") speed = 12.0;```  
Questo codice è terribile e separa i dati di Gold.  
Le enums permettono di unire tutti i dati e la logica delle varianti in un solo luogo  
> 📱 **Quiz:** cosa viene stampato?  

#### Link Utili

- null, il billion-dollar mistake: https://news.ycombinator.com/item?id=12427069  
-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


#### Classi in altri linguaggi


#### Nominal VS structural typing


---

## V1

### 📄 `TNT.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture02/v1/TNT.java)

La classe TNT è la più semplice possibile, al momento serve solo per definire un nome (`TNT`), non contiene nè comportamento (metodi) ne stato (campi) rappresenta solo il concetto di `TNT`  
La keyword `public` è un modificatore di accesso che dice che la classe `TNT` è visibile a tutto il progetto. Parleremo dei modificatori di accesso in dettaglio più avanti.  

---

## V2

### 📄 `TNT.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture02/v2/TNT.java)

Tre campi, di tipo `int`, `double ` e `boolean`  
Un campo può avere un valore iniziale, come `fuseLength` altrimenti questo valore è inizializzato nel costruttore, oppure settato al valore di default, che dipende dal tipo del campo.  
Un costruttore semplice, senza parametri  
Un costruttore con un parametro, che richiama l'altro.  

---

## V3

### 📄 `TNT.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture02/v3/TNT.java)

Questo metodo innesca la TNT.  
Se è già innescata, allora ritorna anticipatamente.  
Questo metodo simula un tick del gioco e riduce il fuso della TNT  
Questo metodo cambia lo stato dell'oggetto corrente, accorciando il fuso  
I metodi possono chiamare altri metodi, per esempio se il fuso è 0, questo metodo chiama il metodo `explode()`  
Il metodo per far scoppiare la TNT stampa a schermo  

---

## V_enums

### 📄 `Direction.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture02/v_enums/Direction.java)

La Enum Direction e le sue varianti  

### 📄 `ToolTier.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture02/v_enums/ToolTier.java)

La definizione di ogni variante chiama il costruttore, che è privato alla classe  

---

# Lezione 03

**Argomenti Trattati**
- [Ackages](#ackages)
- [Final_mod](#final_mod)
- [Static_globals](#static_globals)

---

### 📄 File: `Lecture3.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/Lecture3.java)


#### Lezione 3

BT: Remember & Understand  

#### Packages

Un progetto piccolo potrebbe avere una decina di file di codice, Minecraft ne ha più di 5,000.  
Non si possono mettere in una sola cartella.  
E questo vale per ogni progetto, specialmente per quello che consegnate all'esame: non usare i packages vi costa punti  
Aggiungiamo tre classi: `Player`, `Witch` e `TNT` (senza guardarle)  
Per organizzarle, creiamo un package `entities`, con `Player` e `Witch`.  
Poi creiamo un package `blocks` e ci mettiamo la classe `TNT`  
Ci sono diverse organizzazioni per i packages, in questo progetto organizziamo i vari file in base alle loro features  
Concretamente, un package è tante cose.  
È un namespace, che previene conflitti di nome, come nel caso delle TNT  
È la struttura delle cartelle nel vostro hard disk, dentro alle quali sono organizzati i file di un progetto  
Per usare una classe definita dentro a un package `A` da un altro package `B`, bisogna importarla, come  
Le righe di `import` in cima al file rendono visibili le classi che sono in altri packages  
Questo metodo stampa le informazioni di package di due oggetti.  
Per capire bene i loro tipi, controllate gli `import`  
Tipicamente, se non state debuggando (o facendo override della `equals` --- cosa che capirete più avanti), non dovrete MAI usare il metodo `getClass()`  
Spiegherò perchè quando parliamo di polimorfismo, casting e instanceof  

#### Modificatori di visibilità/di accesso (e incapsulazione)

I modificatori di visibilità ci permettono di regolare l'accesso a campi e metodi, permettendoci di realizzare 'encapsulation'  
Ci sono i seguenti modificatori:  
- `public` : visibile a tutti (altri packages, altre classi)  
- `private ` : visibile solo al file / alla classe dichiarante  
- `protected` : visibile ai figli nella gerarchia di ereditarietà (ne parliamo in lezione 5)  
- 'nulla', cioè Package-Private: se non scrivete nulla, il modificatore è Package-Private, il che significa visibile a classi nello stesso package  
Consideriamo la classe `Player` dentro `ackages/entities`  
Tutti possono vedere il campo `username `, quindi è `public`  
--Attenzione, così però lo possono sia leggere che scrivere!  
Il campo `name ` evita questa cosa con `final`, che spieghiamo dopo  
La vita, invece, è privata, come il fatto che il personaggio sia avvelenato o meno.  
Quindi i campi `health` e `isPoisoned` sono `private `  
Questo ci impedisce di andare dentro un'altra classe, tipo `Witch` e modificare direttamente la vita, per esempio bypassando l'armatura  
Per modificare lo stato `private ` in maniera consona, si usano i metodi.  
I modificatori si applicano anche ai metodi.  
Questo ci permette di creare dei metodi `public`, che tutti possono invocare  
E dei metodi (`private ` o package-private) che invece servono solo localmente  
Alcuni metodi hanno un nome speciale: getters e setters sono metodi che ritornano il valore di un campo, o modificano il valore di un campo dato un certo input  
Per esempio dentro a `Player` ci sono un getter e un setter  
Nota: creare un campo `private ` e poi getters e setters per quel campo, è un errore grave  
Il metodo `visibilityExample()` crea un nuovo `Player` e cerca di accederne i campi  
> 📱 **Quiz:** posso decommentare questa riga?  
---  
> 📱 **Quiz:** posso decommentare questa riga?  
---  
Per capire il funzionamento di Package-Private, andiamo dentro a `Witch`  
Visto che il campo `fakeHealth` di `Player` è Package-private, possiamo accedervi  
Il campo `health` è `private ` e rimane accessibile solo dentro a `Player`  
> 📱 **Quiz:** ordinate i metodi dentro `attack` per uccidere `p`  

#### I modificatori in un linguaggio

I modificatori in Java sono rispettati a livello di linguaggio  
Vediamo un esempio di C++ dove i modificatori sono bypassabili (cosa non possibile in Java)  
File 'packages/Player.cpp'  

#### Final

La keyword `final` si può aggiungere a campi e a metodi, ha due significati diversi.  
Per ora vediamo solo l'applicazione ai campi.  
Un campo `final` diventa una costante, si può inizializzare, leggere, ma non scrivere  
Consideriamo la classe `FinalPlayer`, che modifica `Player` rendendone il nome `final` oltre che `private `  
Il campo `final` deve essere inizializzato.  
Si può aggiungere il valore quando dichiariamo il campo, oppure dentro ad un costruttore  
> 📱 **Quiz:** Cosa succede se commentiamo il corpo del default constructor di `FinalPlayer`?  
---  
Consideriamo la classe `ToolTier`, dove I campi `efficiency` e `maxUses` sono 'final'.  
Una volta settati dal costruttore, non possono cambiare  
Ogni istanza della classe ha questi valori.  
La velocità è una costante, non un valore che può variare.  
Rendere `efficiency` `final` garantisce che il Diamante sia più veloce del Legno, per come abbiamo impostato i valori  
E nessun altro pezzo di codice può (anche accidentalmente!) violare questa cosa  

#### Nota: Immutabilita

Un concetto di Ingegneria del Software è che la mutazione (cioè il permettere che i dati cambino) è una fonte di bug  
Se una variabile cambia valore inaspettatamente, il comportamento del programma diventa impredicibile  
L'Immutabilità ci permette di fidarci che lo stato di un oggetto non cambierà, sia per un attacco hacker, che per un problema  
Il metodo `finalExample()` alloca oggetti con campi `final`. Il codice commentato non può essere decommentato, o darà errore  

#### Static

La keyword `static` serve per identificare campi e metodi essenzialmente globali  
Intuitivamente, un campo o un metodo `static` appartiene alla classe, e non all'oggetto  
In entrambi i casi, li si accede così: `Classe.campo_statico ` oppure `Classe.metodo_statico()`.  
Dato un oggetto di una Classe, invocare `oggetto.campo_statico ` o `oggetto.metodo_statico()` è equivalente a scrivere `Classe.campo_statico ` e `Classe.metodo_statico()`.  
Un campo `public` e `static` si può considerare una variabile globale.  
Di questi campi, ne esiste una sola copia, non una per oggetto come per i campi non-`static`  
Un metodo `static` è propriamente una funzione (non un metodo) in quanto non necessita di un oggetto per essere eseguito  
Per esempio, `Math.sqrt( ... )` non ha bisogno di un oggetto su cui essere invocato, mentre `player.damage()` funziona su una precisa istanza di un giocatore  
Come gli altri metodi, anche dei metodi `static` ne esiste una sola copia  
I metodi `static` quindi non possono usare la keyword `this` al loro interno  
Inoltre, i metodi `static` possono fare riferimento solo a campi `static` e ad altri metodi `static`  
Questo perchè tali metodi possono essere invocati anche se non ci sono oggetti di quella classe, quindi non ha senso poter far riferimento a campi non-`static`  
Di seguito presentiamo i casi d'uso più frequente per gli `static`:  
- Costanti globali: Informazioni da condividere, tipo 'MAX_STACK_SIZE'.  
- Singleton: Serve per far in modo che ci sia un solo oggetto di una certa classe (es, Dragon Egg).  
- Factory Methods: Metodi statici per creare oggetti complessi (es, Trees).  
Gli ultimi due sono 'design patterns' cioè principi di Ingegneria del Software che sono nati per facilitare la scrittura del codice e racchiudere in una singola metodologia delle soluzioni frequenti a problemi comuni  
In OOP i dati appartengono a oggetti, tipicamente (es, la vita di un giocatore)  
Altri dati, invece, rappresentano dati generali, comuni a tutti  
Il valore di uno stack di blocchi è tipicamente 64  
Non vogliamo segnare questo valore in ogni oggetto, immaginate lo spreco di memoria!  
Invece lo segnamo una volta sola, nella classe `GameConstants`  
Vediamo la classe `GameConstants`  
La classe `System` contiene tante istanze di `static`  
> 📱 **Quiz:** Quali di queste righe si può decommentare?  
---  
Le variabili statiche possono mutare  
> 📱 **Quiz:** Come possiamo prevenire questa riga?  
---  
> 📱 **Quiz:** Cosa è `static` in `System.out.println()`?  
---  
System contiene altre cose utili:  
Fai il timing di certe funzionalità  
Chiama il garbage collector  
Vediamo ora due design pattern  
Tutto il software serio è sviluppato seguendo patterns.  
In questo corso non voglio farveli vedere tutti, ma parlare di OO senza parlare di pattern è strano  
Anche perchè molte delle scelte dei linguaggi OO influenzano e sono influenzate dai pattern.  
Nota: I design pattern sono elemento fondante di questo corso, e si trovano nei temi d'esame (non in quelli pre 2025/2026)  

#### Il Singleton Pattern

Alcune cose del gioco sono uniche: i settings, oppure l'uovo di drago  
Questo pattern usa la keyword `static` per fare in modo che ci sia una sola istanza di una certa classe: un solo oggetto  
Vediamo la classe `DragonEgg`  
Esiste una sola istanza di uovo di drago in tutto il gioco, e per farlo usiamo il pattern `Singleton`  
Per realizzare questo pattern seguiamo questi passi:  
- c'è una singola istanza del `DragonEgg`, creata a loading time, salvata in un campo `private ` e `static`  
- il costruttore è `private `: nessuno può chiamarlo se non all'interno della classe  
- c'è un getter `public`, ma è anche `static`, è l'unica funzionalità che ritorna un `DragonEgg`  
In questo modo, l'unico oggetto viene creato a loading time, tramite il costruttore privato, quando il gioco ne ha bisogno, accede a questo oggetto tramite il getter  
Una volta ottenuto, l'oggetto è normale, e si comporta come tutti gli altri oggetti  
Il metodo `singletonExample()` utilizza il singleton su `DragonEgg`  
Non possiamo fare 'new DragonEgg()', il costruttore è `private `!  
> 📱 **Quiz:** cosa stampa?  
---  

#### Link Utili

-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


---

## Ackages

### 📄 `Player.cpp`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/ackages/Player.cpp)

C++ ha i campi privati di default  

### 📂 `ackages/blocks`

#### 📄 `TNT.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/ackages/blocks/TNT.java)

> ❓ **Domanda:** *Q: Il campo `isIgnited` dovrebbe essere `static`?* 
---  
A: No, altrimenti innescare una `TNT` le innescherebbe tutte  
> ❓ **Domanda:** *Q: Il campo `fuseLength` dovrebbe essere `final`?* 
---  
A: No, perchè deve variare (decrementarsi) per il countdown  
> ❓ **Domanda:** *Q: Perchè rendere `explosionPower` `final`?* 
---  
A: Questo valore non cambia una volta che è creato un oggetto, e `final` ci rende sicuri che questo valore non cambi per errore  
> ❓ **Domanda:** *Q: Il campo `explosionPower` dovrebbe essere `static`?* 
---  
A: Si, perchè il potere dell'esplosione è sempre quello per tutte le `TNT`  
Invariante: il fuso è sempre un valore positivo  
Invariante: non si può innescare più volte  
Invariante: solo se è innescata, e se ha ancora del fuso, allora il metodo fa qualcosa  
Reset dell'invariante: dopo che è esplosa, si disinnesca  

### 📂 `ackages/entities`

#### 📄 `Player.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/ackages/entities/Player.java)

Tecnicamente, il nome `lecture03.packages.entities.Player` è il nome completo di questa classe  
Setter per `isPoisoned`  
Getter per `username `  
Metodo per applicare danno.  
Si può estendere con logica ulteriore, per esempio per ridurre il danno in caso di armatura  

#### 📄 `Witch.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/ackages/entities/Witch.java)

Da qui, possiamo accedere ai campi Package-Private di `Player`, ma non ai campi `private `  
La riga di sotto non compila  

---

## Final_mod

### 📄 `FinalPlayer.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/final_mod/FinalPlayer.java)

### 📄 `ToolTier.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/final_mod/ToolTier.java)

Campi `final`  

---

## Static_globals

### 📄 `DragonEgg.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/static_globals/DragonEgg.java)

Istanza del Singleton pattern  
Il metodo `teleport()` è un metodo da chiamare sul singolo oggetto  

### 📄 `GameConstants.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture03/static_globals/GameConstants.java)

Un valore condiviso da tutto il server, tutti lo possono leggere  
Questo è `static` perchè si applica al gioco, non ad un oggetto  
Un metodo `static` (Utility).  
Non ha bisogno di conoscere lo stato di alcun oggetto per svolgere il suo compito  
Elementi non-static per le domande  

---

# Lezione 04

### 📄 File: `Lecture4.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture04/Lecture4.java)


#### Lezione 4

BT: Understand, Analyse, Apply  
BT: Remember, Understand  
BT: Understand, Analyse, Apply  

#### Incapsulamento e Invarianti

Con i vari modificatori visti fin ora, il linguaggio ci da una proprietà fondamentale:  
Incapsulamento (o information hiding)  
Questo ci permette di nascondere dei dettagli implementativi all'interno di una classe, senza rivelarli agli utilizzatori della classe stessa  
Inoltre possiamo definire 'invarianti', cioè dei fatti che sono sempre veri per ogni classe e ogni oggetto che viene creato  
Tutto il codice è soggetto a Invarianti, le funzionalità viste fin ora ci danno un linguaggio che ci permette di definirli  
C non è un linguaggio che ci permette di avere Incapsulamento ed Invarianti (come abbiamo visto)  
Altri linguaggi ci permettono di definire invarianti ancora più potenti (es, Rust)  
Per esempio consideriamo `lecture03/packages/entities/Player`, ci sono diversi invarianti:  
Invariante: `poisonDamage ` non fa nulla se `this` non è avvelenato  
Invariante: `poisonDamage ` non fa danno se ho meno di 2 di vita, e sono avvelenato  
Esempi: Come fareste un effetto di rigenerazione? E una Golden Apple?  
Controllate di non farli in modo che qualcuno possa barare e ottenere più del dovuto  
Consideriamo la classe `lecture03/packages/blocks/TNT`  
Per capirne gli invarianti ci facciamo diverse domande:  
- c'è del comportamento che non dovremmo permettere?  
- ha senso poter far calare il fuso senza che sia innescata?  
- ha senso farla esplodere senza che sia innescata?  
- il fuso può essere un valore negativo?  
Per questo, iniziamo rendendo `fuseLength` un campo `private `  
Vediamo la classe per vedere  
- altre domande per ragionare sui modificatori  
- come si propagano gli invarianti nei vari metodi  
La `TNT` deve scoppiare solo quando il fuso arriva a 0  
Non dovremmo permettere di farla scoppiare prima  
Inoltre, il fuso si deve poter ridurre solo se la `TNT` è innescata  
Infine, il fuso si deve ridurre col passare del tempo, e non per valori arbitrari  
standardTNT.fuseLength = -100; // COMPILER ERROR!  
Utilizzo corretto  

#### Passaggio dei valori

Ci sono valori di tipo Primitivo, valori di tipo Classe, e valori di tipo Array  
> 📱 **Quiz:** Dove sono allocati?  
---  
I valori di tipo Primitivo, allocati sullo stack, tipicamente occupano uno (o pochi) registri, e vengono passati per 'Copia'  
I valori di tipo Array e Classe vengono allocati in memoria  
Pertanto, non vengono passati per copia, perchè potrebbero occupare molti registri  
Quindi, vengono passati per Riferimento, invece che un oggetto, viene passato un puntatore a tale oggetto  
Quando una variabile contiene un oggetto, in realtà contiene un puntatore a quell'oggetto.  
Un puntatore occupa un registro (tipicamente), ed è più facile sia da passare, che da allocare in uno stack frame  
Java per fortuna nasconde questa cosa, e non permette aritmetica dei puntatori, inserendo dei dereference automatici quando ha valori di tipo Classe e Array  
`x` è una variabile locale  
`x` viene copiata nello stack frame di `helper`, se `helper` modifica la sua copia, `x` non cambia  
`t` è una variabile locale che punta alla locazione di memoria dove è allocata un `TNT`  
il riferimento di `t` viene passato a `reference `, se quest'ultimo modifica `t`, il cambiamento lo vedremo anche qui  
`arrT` è una variabile locale che momento contiene `null`  
a questo punto la variabile punta alla locazione di memoria dove è allocato l'array di 5 `TNT`  
---  
questo ciclo inizializza ogni cella dell'array ad una `TNT`  

#### Layout di Classi e Oggetti in memoria

Consideriamo queste classi: `Witch`, `Player`, `TNT`  
Quando viene caricato il programma: dove sono i metodi di ogni classe? e i metodi `static`?  
Dove sono i campi `static`?  
Quando viene eseguito `layoutTest`, che oggetti vengono creati?  
Come viene creato un oggetto di tipo `Witch`? e uno di tipo `Player`? e uno di tipo `TNT`?  

#### Layout di `Witch`

La classe contiene solo 2 metodi, il cui codice viene messo nella 'code section' del programma  

#### Layout di `Player`

La classe contiene 4 campi e 6 metodi.  
Nulla è `static`, quindi il codice dei 6 metodi viene messo nella 'code section' del programma  

#### Layout di `TNT`

La classe contiene 2 campi `static` e 2 campi, 1 costruttore e 3 metodi  
I campi `static` vengono allocati nella parte di memoria 'read-only'  
I 3 metodi e il costruttore vengono messi nella 'code section' del programma  
Se ci fossero stati metodi `static` sarebbero andati nella 'code section' anche loro  

#### La v-table

Ogni classe contiene una v-table, cioè un elenco di puntatori alle implementazioni dei vari metodi  
L'ordinamento dei metodi non è quello definito dal programmatore, è una cosa più complicata che interagisce con l'ereditarietà  
Quindi per ora vi basti sapere che i metodi sono ordinati, ma non sapete come  
Supponendo che i due metodi di `Witch` (`fakeAttack` e `attack` siano rispettivamente agli indirizzi `0x000010` e `0x000040`, la v-table di `Witch` sarà fatta come segue:  
---  
| 0x000010 |  
| :---: |  
| 0x000040 |  
Il compilatore sa che `fakeAttack` quindi corrisponde all'offset `0` nella v-table, mentre `attack` ha offset `1`  
Supponendo che i sei metodi di `Player` siano agli indirizzi `0x0000A0`, `0x0000B0`, ... `0x0000F0`, la v-table di `Player` sarà fatta come segue:  
---  
| 0x0000A0 |  
| :---: |  
| 0x0000B0 |  
| 0x0000C0 |  
| 0x0000D0 |  
| 0x0000E0 |  
| 0x0000F0 |  
> ❓ **Domanda:** *Come potrebbe essere fatta la v-table di `TNT`? Contate che alcuni metodi sono `static`* 

#### Layout degli oggetti

Ogni oggetto segue un layout comune:  
- la prima parola è un link alla v-table della sua classe  
- seguita da una parola per ogni campo definito dalla sua classe  
Considerando un oggetto di tipo `Witch`, il compilatore converte una chiamata al metodo `fakeAttack` come segue:  
- considera l'indirizzo dell'oggetto  
- la prima parola a questo indirizzo è un puntatore alla sua v-table  
- segui questo puntatore, ora sei nella v-table  
- vai avanti di `0` parole (`0` è l'offset di `fakeAttack`): questo è la parola contenente il puntatore al codice che cerchi  
- segui questo puntatore: ora sei nel codice di `fakeAttack`  
> ❓ **Domanda:** *Esercizio: ragionate su come viene fatta l'invocazione dei metodi di `TNT` e di `Player`* 
Disegnare il layout attuale:  
- code section per Witch, Player, TNT  
- read-only section per Witch, Player, TNT  
- stack: `Lecture04.main()`::`Lecture04.layoutTest()` + local variables w1, w2  
- heap: oggetti per w1, w2  
Gli oggetti hanno solo la v-table  
update di campo diretto  
Aggiornare il layout durante la chiamata a `setPoisoned`  
Aggiornare il layout:  
- stack: local variables p1, p2  
- heap: oggetti per p1, p2  
Gli oggetti hanno la v-table e 4 parole  
Assumendo che la v-table di `Player` sia all'indirizzo `0x00A000`, il layout di `p1` è il seguente  
---  
| 0x00A000 |  
| :---: |  
| null |  
| 20 |  
| false |  
| 10 |  
---  
| 0x00A000 |  
| :---: |  
| null |  
| 20 |  
| true |  
| 10 |  
Quest'ultimo invece è il layout di `p1` dopo la chiamata a `setPoisoned()`.  
Aggiornare il layout:  
- heap: oggetto per p2  
Aggiornare il layout durante le chiamate a `ignitè e `tick`  
Aggiornare il layout:  
- stack: local variables t1, t2  
- heap: oggetti per t1, t2  
> ❓ **Domanda:** *Esercizio: pensate al layout di `t1` e `t2`* 

#### Link Utili

-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


---

# Lezione 05

**Argomenti Trattati**
- [Inheritance](#inheritance)

---

### 📄 File: `Lecture5.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture05/Lecture5.java)


#### Lezione 5

BT: Understand, Analyse, Apply  

#### Ereditarietà

L'ereditarietà è un concetto chiave dell'OOP, e ha come obiettivo principale il riuso di codice  
Con l'ereditarietà, andiamo a strutturare le nostre classe in un albero, con superclassi e sottoclassi  
Intuitivamente, le sottoclassi ereditano campi e metodi (`public` e `protected`, ma non `private `) delle superclassi  
Java permette ereditarietà singola: per ogni classe c'è al massimo una superclasse, mentre il numero di sottoclassi non è limitato  
Altri linguaggi permettono ereditarietà multipla, togliendo il limite ad una sola superclasse, ma vedremo che questo può causare problemi: il diamond problem  
La keyword per definire la gerarchia di ereditarietà è `extends`  
Consideriamo le classi dentro il package `inheritance `  
La superclasse `Entity` definisce due campi `protected` ed un metodo `public`  
Poi ci sono due sottoclassi, `Creeper` e `Zombie `  
Nella riga che definisce queste classi, la keyword `extends` dice che sono sottoclassi di `Entity`  
Questo fa si che sia `Creeper` che `Zombie ` abbiano:  
- effettivamente anch'essi una copia dei due campi (la cui definizione però non viene ripetuta nelle sottoclassi)  
- accesso al metodo `teleport()`, che può essere chiamato su oggetti di tipo `Creeper` e `Zombie `s  
Così facendo, il codice di `teleport()` viene scritto una volta sola, e se è da debuggare, c'è un solo luogo dove agire  
Le sottoclassi però, possono aggiungere:  
- campi (come `isHolding` dentro a `Zombie `)  
- metodi (come `hiss()` dentro a `Creeper`)  
Queste aggiunte sono invisibili alla superclasse `Entity`, ma potrebbero essere visibili ad eventuali sottoclassi  
> 📱 **Quiz:** Considerate `Drowned` come sottoclasse di `Zombie `. Ha accesso a `isHolding`?  
---  
Il metodo `inheritanceExample()` alloca uno `Zombie ` nella variabile `z`.  
Non possiamo fare `z.x` in quanto `x` è un campo `protected` di `Entity`, e per quanto `Zombie ` ce l'abbia, da questo file (`Lecture5`) non lo vediamo  
Però `Zombie ` può definire il metodo `getX()`, dove accede al campo `x` tramite `this`.  
Per quanto `x` non sia definito dentro `Zombie `, ci abbiamo accesso tramite l'ereditarietà  
Analogamente, possiamo creare un `Creeper` `c` e possiamo chiamare `teleport(...)`, che è definito in `Entity` sia su `c` che su `z`  
Però possiamo chiamare `hiss` solo su `c` (e non su `z`)  
> 📱 **Quiz:** Posso decommentare questa riga?  
---  
I costruttori non si ereditano.  
La classe entity, per esempio, definisce un costruttore `Entity(int x, int y)`  
Da questa classe non possiamo creare uno zombie facendo `Zombie(0,0)`, nè facendo `Entity(0,0)`  
Da una sottoclasse, però, possiamo richiamare i costruttori della superclasse dai costruttori della sottoclasse tramite la keyword `super()`  
Nota: questa keyword ha le parentesi (e gli eventuali argomenti) e non è da confondere con la keyword `super` senza parentesi, che vedremo più avanti  
> 📱 **Quiz:** Consideriamo il costruttore dentro a `Creeper`, quale riga possiamo decommentare?  
---  
Ci sono dei vincoli sull'uso del `super()`:  
- deve essere la prima riga di codice del costruttore di una sottoclasse  
- non può chiamare costruttori `private ` della superclasse  
Visto che la keyword `this()`, per richiamare altri costruttori della stessa classe deve anch'essa essere la prima riga di un costruttore, possiamo avere solo una delle due  
Se non è presente esplicitamente, il compilatore inserisce sempre una chiamata al costruttore di default della superclasse  
Quindi inserisce una chiamata a `super()`  
> ⚠️ **Nota Bene:** Analizzate le stampe dentro `inheritanceAndConstructorsExample()`  
---  
> 📱 **Quiz:** Cosa stampa se commentiamo la `super(x, y) dentro a `Creeper(x, y)?  
---  
> 📱 **Quiz:** Posso decommentare questa riga?  
---  
Questo è come 'funziona' l'ereditarietà, e quello che vi serve per metterla in atto.  
Adesso vediamo le proprietà che ci da e gli elementi di design di un linguaggio (e del paradigma OO) che vengono maggiormente influenzati dall'ereditarietà  

#### Polimorfismo di sottotipo

Esistono 3 tipi di polimorfismo:  
1. ad-hoc: o overloading.  
2. di sottotipo (che vediamo ora)  
3. parametrico (che vediamo coi Generics)  
L'idea del polimorfismo di sottotipo è il seguente:  
> una variabile di tipo `A` può contenere valori il cui tipo è sottotipo di `A`  
---  
Questo polimorfismo è indotto dalla relazione: 'is-a'  
Ogni oggetto è del suo tipo, ma è anche (is-a) di ogni suo supertipo  
Quindi un `Creeper` is-a `Creeper`, ma anche is-a `Entity` e is-a `Object`  
> 📱 **Quiz:** Posso decommentare questa riga?  
---  
> 📱 **Quiz:** Posso decommentare questa riga?  
---  
Il polimorfismo di sottotipo, e la relazione 'is-a' inducono l' 'upcasting': una variabile di un certo sottotipo viene 'upcast'ata, cioè messa in e considerata come di un suo supertipo  
Questo ci permette di definire una variabile il cui tipo è di superclasse, ma che viene istanziata con un oggetto di una sottoclasse  
Per esempio nel metodo `subtypingExample()`, la variabile `gr` ha tipo `Entity`, ma contiene un oggetto di tipo `Zombie `  
Sempre nello stesso metodo, creiamo un array `allMobs` di `Entity` e ci mettiamo dentro oggetti di tipo `Entity`, `Creeper` e `Zombie `  
Il compilatore tratta `gr`, ed il contenuto di `allMobs`, staticamente come oggetti di tipo `Entity`, perchè questo è il tipo con cui sono stati definiti: questo si chiama tipo 'statico'  
Quindi possiamo chiamare `teleport()` su tutti loro  
Dinamicamente però, gli oggetti sono del loro tipo di definizione, questo però lo vediamo quando parliamo di static e dynamic dispatch  

#### La classe Object

La classe Object è automaticamente superclasse di tutte le classi  
Se una classe non definisce `extends ...`, Java inserisce automaticamente un `extends Object` a quella classe  
Questo è utile perchè `Object` fornisce molti metodi utili a tutte le classi  
- `getClass()` dice la classe di un oggetto. Da usare per debuggare, non per funzionalità  
- `toString()` permette di stampare un oggetto  
- `equals()` dice se due oggetti sono allo stesso indirizzo di memoria  
- `hashCode()` fornisce un codice univoco per un oggetto  

#### Il diamond problem

Il diamond problem è un problema di ambiguità nella chiamata dei metodi nei linguaggi che permettono ad una classe di estendere più di una classe  
Consideriamo le classi `GameObject`, `Block` e `LightSource ` definite dentro la classe `DiamondProblem`  
Tutte definiscono un metodo `update()`  
Se potessimo creare la `RedstoneLamp`, chiamare `this.update()`, cosa chiama?  
`Block.update()`? oppure `LightSource.update()`?  
Oppure entrambi, ma in che ordine?  
In Java non possiamo, ma per esempio in C++ possiamo  

#### Link Utili

-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


---

### 📄 File: `DiamondProblem.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture05/DiamondProblem.java)

## Inheritance

### 📄 `Creeper.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture05/inheritance/Creeper.java)

Il metodo `hiss()` appartiene solo a `Creeper`, non a `Entity`  

### 📄 `Entity.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture05/inheritance/Entity.java)

Se i campi fossero `private `, le sottoclassi non li vedrebbero  
Se fossero `public`, li vedrebbero (in lettura e scrittura) tutti, violando l'incapsulamento  
Nota: `protected` li rende visibile anche alle classi nello stesso package  

### 📄 `Zombie.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture05/inheritance/Zombie.java)

Il metodo `groan()` usa 'this.x' e 'this.y' che eredita da `Entity`  
Il costruttore `Zombie(int x)` richiama il costruttore `Zombie `, non `Entity`  

---

# Lezione 06

**Argomenti Trattati**
- [Abstracts](#abstracts)
- [Overloading](#overloading)
- [Overriding](#overriding)

---

### 📄 File: `Lecture6.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/Lecture6.java)

BT: Understand, Apply  

#### Classi e metodi astratti

Quando definiamo una classe, possiamo metterci il modificatore `abstract`  
Per esempio, questo succede in `Entity`, dentro `abstracts`.  
Notate che l'ide vi segnala le classi `abstract` diversamente dalle altre  
Una classe astratta serve per raggruppare funzionalità e logica comune alle sue sottoclassi  
Le regole dell'ereditarietà si applicano normalmente alle classi astratte, quindi queste possono venire estese da altre classi, che ne ereditano campi e metodi (entrambi, non-`private `)  
Infatti, le sottoclassi di `Entity` hanno accesso ai suoi metodi  
Tipicamente, una classe è abstract perchè ha un metodo `abstract`, come nel caso di `Block`  
Questo non è necessario però: una classe può essere `abstract` pur non avendo metodi `abstract`.  
Le classi `abstract` non possono istanziarsi con la semplice chiamata a `new`  
Come vedremo più avanti nel corso, per istanziare una classe `abstract` bisogna creare una classe anonima  
Per ora quindi consideriamo le classi `abstract` come non instanziabili  
Per questo, spesso, il costruttore di una classe abstract è `protected`  
Questo rende la logica del costruttore riutilizzabile dalle sottoclassi.  
Guardiamo il costruttore di `Entity`, che è il responsabile di inizializzare i campi `x` e `y` che sono definiti dentro ad `Entity` stessa  
Ha senso permettere il riuso di queste funzionalità dai costruttori delle sottoclassi  
Per esempio il costruttore di `Chicken` in `abstracts/entities`, chiama `super()` proprio per inizializzare i campi ereditati  
Dopodichè, questo costruttore contiene la logica di inizializzazione dei campi propri di `Chicken`  
Il metodo `abstractExample ` istanzia le sottoclassi di `Entity` e vi chiama sopra dei metodi  
Su `c`, possiamo anche chiamare `makeSound()`, che è definito in `Chicken`, mentre sia su `c` che su `w` possiamo chiamare `teleport()` che è definito in `Entity`  
> 📱 **Quiz:** Posso decommentare questa riga?  
---  
Consideriamo la classe `Block`  
Questa classe deve essere `abstract` perchè contiene un metodo `abstract` (`getDrop()`)  
Un metodo abstract rappresenta un obbligo per le sottoclassi: se una classe (non-`abstract`) estende `Block`, dovrà implementare `getDrop()`  
Se una classe astratta invece estendesse `Block`, questo obbligo non sussiste  
Questo perchè le classi astratte non si possono istanziare.  
Se si potessero istanziare, avremmo un problema: che codice eseguiamo se chiamiamo `getDrop()` su un oggetto di tipo `Block`?  
Visto che tali oggetti non si possono creare, il problema non sussiste  
Il metodo `getDrop()` ci dice che ogni `Block` deve ritornare qualcosa  
Però, non c'è una implementazione di default, il programmatore che estende `Block` deve sapere che cosa ritornare come drop  
Se proviamo a commentare il metodo `getDrop()` dentro `Dirt` otteniamo un errore dal compilatore  
Questo ci garantisce che non possiamo creare un sottotipo di blocco e dimenticarci di definire cosa droppa  
> 📱 **Quiz:** Quale codice viene eseguito all'interno di `abstractMethodsExample()`, nella sua chiamata `d.mineWithDrop()`?  

#### Overriding

> 📱 **Quiz:** Cosa fa il metodo `mine()` di `GoldBlock`?  
---  
La keyword `super` (senza le parentesi) si usa per richiamare le funzionalità della superclasse  
Nota: non si possono concatenare i `super` per risalire la gerarchia di ereditarietà: non posso scrivere `super.super.super`, ma solo una volta `super`  
I metodi di questa sottoclasse sono decorati con `@Override `  
È una indicazione opzionale per il compilatore che ci dice che vogliamo sostituire l'implementazione di un metodo di una superclasse, con un'altra implementazione locale  
È buona pratica usare questa annotazione, così che in caso di typos, il compilatore ci avvisa  
In una sottoclasse, scrivere un metodo con lo stesso nome e firma di un metodo di una superclasse si chiama `overriding`, cioè, riscrittura.  
Con l'overriding possiamo andare a cambiare, estendere, incapsulare o sostituire il comportamento che ereditiamo dalle superclassi  
Per esempio, il `mine()` di `GoldBlock` si comporta come il `mine()` di `Block`, ma in più allerta anche i Piglin  
> 📱 **Quiz:** Se non facciamo overriding di `mine()` in `GoldBlock` cosa succede?  
---  
> 📱 **Quiz:** Posso cancellare il metodo `mine()` dentro `Andesitè?  
---  
A volte potremmo volere sostituire completamente il comportamento che ereditiamo  
Questo succede nel metodo `mine()` dentro a `Bedrock`  

#### Overloading

Da non confondere con overriding!  
Overloading significa scrivere metodi con nomi uguali e firme diverse  
Consideriamo la classe `Pick`, ha diversi metodi `usè, ognuno di firma diversa  
> 📱 **Quiz:** Possiamo aggiungere questo metodo a `Pick`?  
---  
Le firme non possono avere stesso input e output diversi, per variare l'output deve variare anche l'input  
Altrimenti non sapremmo cosa chiamare  

#### Link Utili

-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


---

## Abstracts

### 📄 `Block.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/abstracts/Block.java)

### 📄 `Entity.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/abstracts/Entity.java)

Tipicamente, il costruttore di una classe `abstract` è `protected`, perchè va richiamato dalle sottoclassi, ma non permette di istanziare questa classe  

### 📂 `abstracts/blocks`

#### 📄 `Dirt.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/abstracts/blocks/Dirt.java)

### 📂 `abstracts/entities`

#### 📄 `Chicken.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/abstracts/entities/Chicken.java)

#### 📄 `Wolf.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/abstracts/entities/Wolf.java)

---

## Overloading

### 📄 `Pick.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/overloading/Pick.java)

---

## Overriding

### 📄 `Andesite.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/overriding/Andesite.java)

### 📄 `Bedrock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/overriding/Bedrock.java)

Un metodo che fa `override ` non deve per forza richiamare il `super`, anzi  

### 📄 `GoldBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture06/overriding/GoldBlock.java)

Il metodo `getDrop()` mostra che il tag `@Override ` si usa anche per i metodi `abstract`  

---

# Lezione 07

**Argomenti Trattati**
- [Defaults](#defaults)
- [Interfaces](#interfaces)

---

### 📄 File: `Lecture7.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/Lecture7.java)

BT: Understand, Apply  
BT: Analyse  
BT: Understand, Apply  
BT: Analyse  

#### Interfacce

Le interfacce sono altri file di un progetto Java, ma si differenziano (molto) dalle classi nel modo in cui si definiscono  
Allo stesso tempo, le interfacce sono tipi, come le classi, quindi si comportano spesso in modo analogo  
Fisicamente, le interfacce sono collezioni di metodi astratti, senza implementazione  
Non possono avere nè campi, nè costruttori  
Le classi possono implementare interfacce, così come estendono altre classi, introducendo una gerarchia di erediarietà tra classi ed interfacce  
La relazione 'is-a' che si crea tra una sottoclasse ed una superclasse si crea anche tra una (sotto)classe ed una interfaccia implementata dalla (sotto)classe  
Intuitivamente, le interfacce forniscono degli obblighi, possiamo pensarle come dei contratti  
Definendo solo metodi astratti, senza implementazione, obbligano le loro sottoclassi a implementare tali metodi  
Per fare un esempio concreto, le prese della corrente danno un contratto (alle spine) di forma e voltaggio  
Un microonde può rispettare il contratto di una certa presa, e venirne alimentato  
Alla presa non interessa che sia attaccato un microonde, una TV, etc, ma solo che abbiano la spina giusta  
Nel caso di Minecraft, essere una `Entity` ci da informazioni sullo stato (le coordinate)  
Però, un mob potrebbe essere un `Enemy`, informazione che ci dice come si comporta quel mob (es, attacca)  
Un `Wolf` è si una `Entity`, ma potrebbe essere un `Enemy`  

#### L'interfaccia `Enemy`

Tutti i metodi di una interfaccia sono `public`, non hanno bisogno di questo modificatore  
L'interfaccia `Enemy` stipula un contratto: le sottoclassi di `Enemy`, cioè tutte le classi che 'is-a' `Enemy`, devono avere due comportamenti: `attack` e `playAggressiveSound`  

#### L'interfaccia `RangedAttackMob`

Questa interfaccia stipula un altro contratto: `attack` e `performRangedAttack`  
Le due interfacce sono scorrelate, infatti non tutti gli `Enemy` sono `RangedAttackMob` (es, gli zombie)  
Allo stesso modo, non tutti i `RangedAttackMob` sono `Enemy` (per es. pensate agli Snow Golem)  

#### La classe `Zombie `

La riga `import lecture06.abstracts.Entity;` ci dice a quale `Entity` fa riferimento la classe `Zombie `  
Dopo la keyword `extends` troviamo una nuova keyword: `implements`, seguita dal nome dell'interfaccia implementata da `Zombie `  
Il contratto che riceviamo implementando `Enemy` ci dice di fornire l'implementazione ai due metodi definiti nell'interfaccia  
> 📱 **Quiz:** Cosa succede se commento `attack` dentro a `Zombie `?  
---  
Il metodo `interfacesExample ` illustra che possiamo chiamare i metodi definiti nell'interfaccia `Entity` su un oggetto `Zombie `  

#### Interfacce e contratti multipli

Consideriamo la classe `Skeleton`  
Il vincolo di estendere una sola classe non si applica alle interfacce, infatti possiamo implementarne più di una  
Lo `Skeleton` è sì un `Enemy`, ma è anche un `RangedAttackMob`  
Pertanto, dentro `Skeleton` abbiamo gli obblighi derivanti dai contratti di entrambe le interfacce  
> 📱 **Quiz:** Cosa devo fare per `attack` in `Skeleton`?  
---  
Le interfacce `Entity` e `RangedAttackMob` hanno una signature identica: `attack() : Entity-> Void`  
In questo caso, non c'è un diamond problem, come nel caso di ereditarietà multipla, perchè non c'è una implementazione da scegliere  
Di nuovo, le interfacce forniscono contratti, o obblighi, e una singola implementazione di `attack` soddisferà entrambi gli obblighi  
Le interfacce permettono ereditarietà multipla di tipo, ma non permettono ereditarietà multipla di stato  
Non permettono ereditarietà multipla di comportamento, perchè le firme di metodi nelle interfacce non hanno implementazione  
> ⚠️ **Nota Bene:** Ci sono altri costrutti che permettono ereditarietà multipla di stato (Mixins) ed ereditarietà multipla di comportamento (Traits)  

#### Interfacce e polimorfismo

Le classi astratte ci danno una visione verticale della gerarchia di ereditarietà  
Risalendo l'albero delle classi, capiamo tutti i tipi che un oggetto è (is-a)  
Le interfacce, invece, definiscono una gerarchia orizzontale di abilità  
Ci dicono tutte le cose che un oggetto può fare (anche se il tipo di relazione è sempre la is-a)  
Implementando più interfacce, una classe può quindi decidere le sue abilità e quello che può fare a livello comportamentale  
Per fare un esempio concreto, gli oggetti del mondo reale sono complessi, e difficilmente si può definire una singola gerarchia di ereditarietà per caratterizzare tutte le loro dimensioni  
Per esempio uno Smartphone è un Telefono, una Telecamera, un Lettore di Musica e un Web Browser  
Se queste fossero classi, come dovremmo organizzarle in una gerarchia di ereditarietà?  
Ma queste non devono essere classi, possono essere interfacce che dicono cosa ci si aspetta da un oggetto che le implementa  
Il metodo `interfacesPolymorphismExample ` introduce un esempio di 'aliasing'  
L'aliasing è una caratteristica fondante dell'OO, è l'abilità di avere più riferimenti allo stesso oggetto  
Di seguito, la variabile `n` punta allo stesso oggetto della variabile `skelly`  
L'aliasing è utile, ma uccide le capacità di ragionare sul codice: metodi per controllare l'aliasing sono quelli che hanno portato all'ownership, e a Rust  
> 📱 **Quiz:** posso usare una classe astratta come tipo?  
---  
> 📱 **Quiz:** posso usare una intefaccia come tipo?  
---  
> 📱 **Quiz:** Posso chiamare teleport su badguy?  
---  

#### Default

Le interfacce possono essere organizzate in una gerarchia di ereditarietà a loro volta, tramite la keyword `extends`  
Possiamo avere sottointerfacce e soprainterfacce  
Per esempio l'interfaccia `Boss` nel package `defaults` è sottointerfaccia di `Enemy`  
Questo perchè tutti i `Boss` sono `Enemy`, quindi un `Boss` deve potersi comportare come un `Enemy`, e anche fare qualcosa in più  
L'interfaccia `Boss` introduce una keyword nuova: `default`  
Questa ci permette di dare un corpo alle interfacce, una implementazione di default  
Tecnicamente, questo rende le interfacce di Java molto più simili ai Traits, come concetto di Linguaggi di Programmazione  
L'implementazione di `announceArrival` è quindi disponibile per tutte le classi the implementano `Boss`  
Una classe però può fornire la sua implementazione, che avrà la precedenza sul `default`  
Questi metodi non sono accedibili tramite la keyword `super` dalle sottoclassi  
Infine, c'è un metodo `private `, che serve come helper per il metodo default  
Consideriamo la classe Wither  
Non abbiamo implementato `announceArrival()`, il `Wither` usa l'implementazione di default  
> 📱 **Quiz:** Da quale interfaccia arriva questo obbligo: `attack`?  
---  
> 📱 **Quiz:** Da quale interfaccia arriva questo obbligo: `playAggressiveSound`?  
---  
> 📱 **Quiz:** Da quale interfaccia arriva questo obbligo: `performSpecialAttack`?  
---  

#### Ragionare come chiamante e come chiamato

La gerarchia di ereditarietà che introduciamo estendendo classi, classi astratte, ed implementando interfacce, definisce i tipi che possiamo usare nel nostro programma  
Oltre a dare questi tipi alle variabili, questi vengono usati come parametri per chiamate di metodi  
Ragioniamo sul tipo da mettere ad un metodo da due punti di vista:  
- il punto di vista del chiamante: cioè, che oggetto passo ad un metodo che si aspetta un certo tipo?  
- il punto di vista del chiamato (o implementatore): cioè, quale è il tipo che mi serve per questo parametro?  
Consideriamo il metodo `takeSound`, che prende un oggetto sul quale abbiamo bisogno di chiamare solo il metodo `playAggressiveSound`: ha senso definire quell'oggetto di tipo `Enemy`  
Ha senso quindi definire il tipo più generale possibile, così che possiamo passarci sia uno `Zombie `, che un `Wither` che con uno `Skeleton`  
Se avessimo definito parametro di `takeSound` di tipo `Zombie `, l'implementazione del metodo non sarebbe cambiata, ma sarebbe cambiato il modo in cui il metodo viene usato: non avremmo potuto chiamarlo con un `Wither`  
Questo funziona in base all'assunzione iniziale: dentro al metodo `takeSound`, abbiamo bisogno solo di chiamare il metodo `playAggressiveSound`  

#### Recap e limitazioni delle interfacce


#### Contratti

Il game engine non si preoccupa se un oggetto è uno `Zombie `, uno `Skeleton` o un `Creeper`.  
Sapere se questo oggetto implementa `Enemy` ci garantisce che esiste un metodo `attack()`.  

#### Capacità

Con le interfacce possiamo comporre oggetti complessi aggiungendo più "tag" o capacità.  
Uno `Skeleton`:  
- Eredita lo stato (e alcuni comportamenti) da `Entity` (is-a `Entity`)  
- Adotta `playAggressiveSound` da `Enemy`  
- Adotta `performRangedAttack` da `RangedAttackMob`  

#### I Limiti delle Interfacce

Anche con le funzionalità moderne (Metodi Default), le interfacce hanno limiti rigidi.  

#### Limite 1: Nessuno Stato

Le interfacce non possono contenere variabili di istanza, quindi non puoi inserire `int health = 100;` dentro `Enemy`.  

#### Limite 2: Nessun Costruttore

Poiché le interfacce non hanno stato, non possono avere costruttori.  

#### Limite 3: API Fragili

Se crei l’interfaccia `Enemy` e 50 classi diverse la implementano, non puoi facilmente aggiungere un nuovo metodo in seguito.  
Aggiungere `void sleep();` a `Enemy` rompe immediatamente tutte e 50 le classi perché non implementano `sleep`.  
(Per questo Java 8 ha introdotto i metodi `default`).  

#### Link Utili

- [Oracle Docs: Interfaces and Inheritance](https://docs.oracle.com/javase/tutorial/java/IandI/createinterface.html) - Official Java documentation on defining interfaces.  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


#### Structural VS nominal subtyping


---

## Defaults

### 📄 `Boss.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/defaults/Boss.java)

### 📄 `Wither.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/defaults/Wither.java)

---

## Interfaces

### 📄 `Enemy.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/interfaces/Enemy.java)

### 📄 `RangedAttackMob.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/interfaces/RangedAttackMob.java)

### 📄 `Skeleton.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/interfaces/Skeleton.java)

### 📄 `Zombie.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture07/interfaces/Zombie.java)

---

# Lezione 08

**Argomenti Trattati**
- [Strategy](#strategy)

---

### 📄 File: `Lecture8.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture08/Lecture8.java)


#### Lezione 8

BT: Analyse  
BT: Understand, Apply, Evaluate  

#### Ereditarietà VS Composizione

L'ereditarietà è rigida, crea un albero statico con la relazione 'is-a'  
Supponiamo di voler creare uno Zombie Piglin, in Java non possiamo scrivere:  
`class ZombiePiglin extends Piglin, Zombie `  
> 📱 **Quiz:** Perchè?  
---  
`ZombiePiglin` dovrebbe ereditare da due classi, ha sostanzialmente due 'dimensioni' (ripensate all'esempio dello smartphone, che ha molte più dimensioni)  
Definire le dimensioni a livello di classi non è fattibile, porta a duplicazione del codice e una esplosione combinatoria delle possibilità di incrocio  
L'ereditarietà però è molto utile.  
A livello intuitivo, come vedremo nei Lab, dobbiamo chiederci l'identità di certi oggetti, e definire la gerarchia delle classi in base a quello  
Il tutto modularizzando identità (campi e costruttori in primis) tramite classi astratte  
Il comportamento, invece, lo definiamo (spesso) a livello di interfacce  
Minecraft usa `extends per `Block`, `Item` e `Entity`, perchè queste classi gestiscono logica del game engine  
Ma come si fa a risolvere il diamond problem, specializzando una classe lungo diverse dimensioni?  
Una soluzione è lo Strategy Pattern, che fa uso di Composizione invece che di ereditarietà  
La composizione è un principio secondo il quale un oggetto è composto da tanti sotto-oggetti di tipo diverso (salvati nei campi dell'oggetto originale)  
L'oggetto poi delega comportamento specifico ai vari sotto-oggetti  
La composizione introduce una relazione diversa rispetto all'ereditarietà, e si chiama 'has-a' (a differenza della 'is-a')  

#### Lo Strategy Pattern

Consideriamo le classe e le interfacce della Lezione 7:  
`Skeleton` e `Zombie ` estendono `Entity`, entrambe implementano `Enemy` e uno implementa `RangedAttackMob`  
Abbiamo usato l'ereditarità per definire cosa un mob è, e le interfacce per definire cosa faccia  
Il problema che si pone ora è quello della rigidità (proprio a runtime):  
- Se uno `Zombie ` prende un Arco, diventa uno `Skeleton`?  
- Se uno `Skeleton` finisce le frecce, diventa uno `Zombie `?  
Facciamo un esempiò più concreto da Minecraft  
Supponiamo di voler scrivere un `Piglin`:  
- che attacco fa di base? Se è la crossbow, diventa un `RangedPiglin`?  
- se gli si rompe la `Crossbow`, che attacco fa? Diventa un `PunchPiglin`?  
- se prende una spada da terra, che attacco fa? Diventa un `SwordPiglin`?  
Provando a risolvere questo problema con l'ereditarietà è complesso:  
> ⚠️ **Nota Bene:** Quale sarebbe la relazione tra le classi `Piglin`, `RangedPiglin`, `PunchPiglin` e `SwordPiglin`?  
---  
La soluzione è usare la composizione e la 'has-a' relation che introduce  
Invece che essere un `RangedPiglin`, definiamo solo `Piglin` come classe  
Però, il `Piglin` ha un metodo generico di attacco che delega la sua logica implementativa a un sott-oggetto  
Questo sotto-oggetto è responsabile di dire se usa la crossbow, se da un pugno o una spadata  
Il problema che affrontiamo ora è il seguente:  
La logica di usare la crossbow, di dare un pugno, e di dare una spadata risiederà realisticamente in tre classi diverse  
Questo perchè ci permette di estendere il codice modularmente: per esempio potremmo dover aggiungere un attacco da `Axè nel caso dei `PiglinBrutè  
Come facciamo a chiamare la logica di ogni attacco?  
In questo caso ci viene in soccorso il concetto di Interfacce  
Le interfacce permettono di definire una interfaccia comune , un insieme di comportamenti che ci si aspetta da tutti gli oggetti che sono suoi sottotipi --- che la implementano  
Il primo step è quello di definire questa interfaccia (che chiameremo `AttackStrategy`) e un metodo che applica l'attacco ( in questo caso `execute()`)  
Pertanto, tutte le classi che definiscono la logica di un attacco (`CrossbowAttack` e `PunchAttack`), devono implementare `AttackStrategy` e quindi dare una implementazione al metodo `execute ` che applica l'attacco  
Ogni classe specializzerà questo metodo con la propria logica (calcolo della distanza per la crossbow, etc)  
La classe `Piglin` poi, una volta che attaccherà, delegherà al sottooggetto dell'interfaccia `AttackStrategy`, la logica dell'attacco  
Questa è sostanzialmente l'idea dietro allo Strategy Pattern  
Un aspetto chiave del pattern è la sua capacità di far mutare il comportamento di un oggetto nel tempo  
Infatti, il sotto-oggetto responsabile della logica di attacco del `Piglin` può essere cambiato durante la vita di un oggetto `Piglin`  
Se ad un `Piglin` si rompe la `Crossbow`, basta sostituire il sottooggetto di tipo `CrossbowAttack` con uno di tipo `PunchAttack` ed il `Piglin` cambierà comportamento di attacco  
Notate che questo non richiede nessun cambiamento nella classe `Piglin`!  

#### Strategy Pattern in azione

Realizziamo lo strategy pattern appena visto per i `Piglin`  

#### 1. The Generic Context

We create a "Mob". It is not a Zombie or Skeleton class. It is just a container.  
We give it a "Melee" brain to start.  
The most important part is that we can change the behaviour not at runtime/dynamically  

#### La classe `Piglin`

Questa classe usa lo strategy pattern  
Il campo `currentStrategy` è l'oggetto con cui il `Piglin` ha la 'has-a' relation  
NON implementiamo i diversi `meleeAttack` o `crossbowAttack` come metodi quì dentro!  
Invece, delegheremo al contenuto di `currentStrategy`  
> ⚠️ **Nota Bene:** Il `Piglin` non sa come fare danno, delega questo comportamento al contenuto di `currentStrategy`  
---  
Il costruttore, tipicamente, sceglie la strategia di base  
Per poter far variare la strategia a runtime, creiamo anche un setter  

#### L'interfaccia `AttackStrategy`

Questa interfaccia rappresenta l'obbligo di saper realizzare un certo comportamento  
Definisce solo l'azione `execute `  
Qualsiasi variabile che ha questo tipo deve poter fare questo comportamento, nulla più  
Il contratto è: tutte le strategie di attacco possono essere `execute `d  

#### `PunchAttack` e `CrossbowAttack`

Queste classi semplicemente implementano la loro logica di attacco  
> 📱 **Quiz:** Come possiamo modellare la logica della crossbow che si rompe?  
---  
> 📱 **Quiz:** Come facciamo a fare la sword strategy?  
---  
> 📱 **Quiz:** Come possiamo modellare un Brute?  
---  

#### Link Utili

- [Wikipedia: Composition over inheritance](https://en.wikipedia.org/wiki/Composition_over_inheritance) - A great overview of the principle.  
- [StackOverflow: Why favor composition over inheritance?](https://stackoverflow.com/questions/49002/prefer-composition-over-inheritance) - A classic discussion with real-world examples of why inheritance fails. Very old but still relevant  
- [GameProgrammingPatterns: Component Pattern](https://gameprogrammingpatterns.com/component.html) - Guy writes very nice books. Has one on compilers in Java as well  
- [Wiki: The Fragile Base Class Problem](https://en.wikipedia.org/wiki/Fragile_base_class) - The specific architectural name for the "Rigidity" problem we discussed.  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up


---

## Strategy

### 📄 `Piglin.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture08/strategy/Piglin.java)

### 📂 `strategy/strategies`

#### 📄 `AttackStrategy.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture08/strategy/strategies/AttackStrategy.java)

#### 📄 `CrossbowAttack.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture08/strategy/strategies/CrossbowAttack.java)

#### 📄 `PunchAttack.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture08/strategy/strategies/PunchAttack.java)

---

# Lezione 09lab1

### 📄 File: `Lecture9.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture09lab1/Lecture9.java)


#### Lezione 9 -- Laboratorio 1


#### Struttura dei Laboratori

La metodologia di lavoro è la seguente:  
- per ogni laboratorio venite divisi in gruppi di 6/8 persone  
- ogni laboratorio ha un insieme di esami passati che vengono attribuiti ad ogni gruppo  
- ogni laboratorio ha una serie di fasi  
- durante ogni fase viene posta una domanda, che i gruppi risolvono. Tipicamente la domanda riguarda una parte del tema d'esame: come la risolvereste / come fareste il design  
- alla fine di ogni fase, si discutono alcune implementazioni / scelte  
- se volete, potete fare il push delle vostre soluzioni su github  
---  
Il corso prevede 5 laboratori + uno finale, di seguito elenchiamo cosa faremo in ognuno di essi.  
1. Focus: capire quali classi e quali classi astratte fare. Capire i campi delle classi e i loro modificatori di visibilità. Capire quali enums ci sono. Capire cosa rendere final e cosa static.  
2. Focus: torniamo sulle classi astratte e la gerarchia di ereditarietà. Capire i metodi delle classi, possibili override. Capire cosa fare come metodo di classe, e cosa fare come campo.  
3. Focus: capire quali eccezioni sono nel testo, dove vengono sollevate, dove vengono gestite. Capire dove usare i generics e che tipi usare. Capire quali patterns integrare.  
4. Focus: capire quali collections usare, come farne l'ordinamento. Capire quali patterns integrare.  
Secondo focus: proposta di temi di esami: ogni gruppo propone un micro argomento che vede in linea coi principi del corso  
5. Focus: capire il layout dei vari esami, strutturare l'MVC  
- Final lab: risoluzione delle proposte pervenute durante il lab 4  

#### Overview dei temi di esame

Di seguito si linkano i temi d'esame, e la loro rilevanza per i diversi labs  
- ✅ : ottimo da provare per gli aspetti del lab  
- ❌ : la soluzione ottimale richiede una comprensione avanzata degli aspetti del lab, esercitatevi prima su altri temi di esame  
- 😐 : non particolarmente interessante per gli aspetti del lab, focalizzatevi su altri temi d'esame per questo lab  
> ⚠️ **Nota Bene:** Nei temi d'esame fino a feb'26 non era richiesto di usare patterns, e non sono strutturati per avere patterns oltra a MVC  
---  
| Tema d'esame  | Lab 1 | Lab 2 | Lab 3 | Lab 4 | Lab 5 |  
| :-----------  | :---: | :---: | :---: | :---: | :---: |  
| armi (feb'26)         | ✅ | ✅ | ✅ | 😐 | ❌ |  
| ranked (set'25)       | ✅ | ✅ | ✅ | ✅ | ✅ |  
| blings (lug'25)       | ✅ | ✅ | ✅ | 😐 | ✅ |  
| bro-stelle (giu'25)   | ✅ | ✅ | ✅ | ✅ | ❌ |  
| ruzzol-are (gen'25)   | ✅ | ✅ | 😐 | 😐 | ✅ |  
| biblioteca (set'24)   | ✅ | ✅ | 😐 | ✅ | 😐 |  
| quests (lug'24)       | ✅ | ✅ | ✅ | ✅ | 😐 |  
| evocazioni (giu'24)   | ✅ | ✅ | ✅ | 😐 | ❌ |  
| farmacia (feb'24)     | ✅ | ✅ | ✅ | 😐 | 😐 |  
| streaming (set'23)    | ✅ | ✅ | ✅ | ✅ | ❌ |  
| ventilatori (lug'23)  | ✅ | ✅ | ✅ | ✅ | ❌ |  
| mutazioni (giu'23)    | ✅ | ✅ | ✅ | 😐 | ❌ |  
---  

#### Laboratorio 1


#### Fase 1: le classi e i loro campi

20 min lavoro di gruppo, 10 min presentazione  

#### Fase 2: modificatori dei campi

10 min lavoro di gruppo, 10 min presentazione  

#### Fase 3: definire i final e gli static

10 min lavoro di gruppo, 10 min presentazione  

#### Fase 4: enums

10 min lavoro di gruppo, 10 min presentazione  

---

# Lezione 10

**Argomenti Trattati**
- [Arguments](#arguments)
- [Bindings](#bindings)

---

### 📄 File: `Lecture10.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture10/Lecture10.java)


#### Lezione 10

> ⚠️ **Nota Bene:** Questa è una delle lezioni più importanti del corso  
---  
BT: Remember, Understand, Analyse  
BT: Understand, Analyse  

#### Static vs Dynamic Binding

Consideriamo (una parte) la classe `Block`, e il metodo `onBreak()`.  
La classe `Diamond` estende `Block` e fa overriding di quel metodo.  
Nel metodo `predictBindingExample `, la prima stampa è chiara: invoca il metodo `onBreak` di `Block`  
La seconda e la terza, invece, potrebbero essere meno chiare.  
> 📱 **Quiz:** Cosa viene stampato di sopra?  
---  
> 📱 **Quiz:** Cosa viene stampato di sopra?  
---  
Intuitivamente, `obj.method()` invoca il metodo `method` sull'oggetto `obj`  
Per capire quale codice viene eseguito a questa invocazione, Java ha due meccanismi  
1. 'dynamic binding` o `dynamic dispatch' o 'late binding'.  
In assenza di altre keyword, Java usa questo meccanismo.  
Sostanzialmente, per decidere quale metodo invocare, Java guarda il tipo effettivo (cioè a runtime) di un oggetto, e non il tipo indicato staticamente  
2. 'static binding' o 'static dispatch' o 'early binding'.  
Con le keyword `final`, `static` e `private `, Java non ha bisogno di guardare il tipo di un oggetto a runtime e sa già che metodo invocare  
Per capire questi meccanismi abbiamo bisogno di introdurre le nozioni di 'tipo statico' e 'tipo dinamico' di una variabile.  

#### Tipi statici e dinamici

Quando definiamo una variabile: `Block bd = new DiamondBlock();`, essa ha due tipi:  
`Block` è il tipo statico. È il tipo che il compilatore considera per `b`.  
`DiamondBlock` è il tipo dinamico. È il tipo che `b` ha in memoria.  
> ⚠️ **Nota Bene:** Se vogliamo capire che comportamento è possibile invocare su `b`, dobbiamo guardare il comportamento offerto dal suo tipo statico  
---  
> ⚠️ **Nota Bene:** Se vogliamo capire quale comportamento viene eseguito su `b`, dobbiamo guardare il comportamento offerto dal suo tipo dinamico  
---  
Notate la differenza tra 'è possibile invocare' e 'viene eseguito'.  
Nota: questa è una differenza fondamentale nel codice: c'è un aspetto statico e un aspetto dinamico.  
L'aspetto statico ha a che fare con quello che possiamo definire prima di eseguire, cioè a compile time. Tipicamente è il compilatore che fa queste analisi.  
L'aspetto dinamico invece modella quello che succede quando il programma viene eseguito.  
Consideriamo il codice di `predictStaticBindingExample `:  
> 📱 **Quiz:** Quale è il tipo statico di `bd`?  
---  
> 📱 **Quiz:** Quale è il tipo dinamico di `bd`?  
---  
> 📱 **Quiz:** Quale è il tipo statico di `dd`?  
---  
> 📱 **Quiz:** Quale è il tipo dinamico di `dd`?  
---  
> 📱 **Quiz:** Posso decommentare queste righe?  
---  
Guardiamo i suggerimenti dell'ide sulle variabili `bd` e `dd`.  
Per quanto `bd` sia di tipo `DiamondBlock`, non possiamo invocare il metodo `getDiamond` definito in `DiamondBlock`  
Questo perchè il compilatore ragiona solo in termine di tipo statico: `bd` è staticamente un `Block` e quindi offre i suoi comportamenti  
A runtime, però, quando invochiamo `okBreak()`, il runtime ragiona in base al tipo dinamico di `bd`, chè è un `DiamondBlock`.  
Pertanto, viene eseguito il metodo `onBreak()` dentro `DiamondBlock`  

#### La keyword `var`

In Java ora si può usare la keyword `var` per definire una variabile locale, come nel metodo `varExample()`  
> 📱 **Quiz:** Cosa stampano?  
---  
In questo caso il tipo statico viene inizializzato al tipo presente dopo l' `=`  

#### Dynamic dispatch

Il dynamic dispatch è il meccanismo standard con il quale vengono eseguiti i metodi in Java  
Il compilatore genera delle istruzioni per ricercare il metodo da eseguire in base al tipo dinamico di un oggetto: vedremo i dettagli nella lezione 11  
Il dynamic dispatch è fondamentale in OO: il tipo statico ci dice come comportarci, ma solo guardando il tipo dinamico possiamo sapere cosa succederà  
Guardare il tipo dinamico, però, non sempre è possibile.  
Considerate `dynamicTypeLookupExample()`, che invoca `breakBlock()` su un `Block` e su un `DiamondBlock`.  
Il metodo `breakBlock()` ha bisogno solo di un `Block` per funzionare, e questo definisce come tipo del suo parametro.  
Chi scrive `breakBlock()` potrebbe non conoscere tutti i tipi che possono essere passati al metodo, ma questo va bene: questo metodo sa che ha bisogno solo del fatto che l'oggetto 'is-a' `Block` per funzionare  
> ⚠️ **Nota Bene:** Questo è il principio di 'least privilege': viene richiesto il minimo delle funzionalità per svolgere il proprio compito  
---  
Questo è simile a quanto detto in `caller_calleeExample ` nella Lezione 7  

#### Static binding

Considerate il metodo `getRegistryName()` in `Block`  
Questo metodo viene chiamato dentro `staticTypeLookupExample()` su tre oggetti con tipo statico e dinamico diversi  
> 📱 **Quiz:** Cosa vi aspettate venga eseguito con `bd.getRegistryName()`?  
---  
Il metodo `getRegistryName()` ha una keyword che `onBreak()` non ha: `final`  
Questa keyword fa si che il metodo non sia overrid-abile nelle sottoclassi di `Block`.  
Pertanto, non dobbiamo chiederci quale sia il tipo dinamico di un oggetto per sapere quale `getRegistryName()` eseguire: è e sarà sempre quello dentro a `Block`s  
Notate, ci sono altre due keyword che forzano Java a fare static dispatch:  
- un metodo `static` viene eseguito con static dispatch per definizione: non appartiene a un oggetto, ma ad una classe, e una classe ha un solo tipo  
- un metodo `private ` non può venire overrid-ato da una sottoclasse perchè quest'ultima non lo vede, quindi il dispatch viene fatto staticamente  
> 📱 **Quiz:** Cosa è più efficiente?  
---  
> 📱 **Quiz:** Cosa viene chiamato?  
---  
> 📱 **Quiz:** Cosa viene chiamato?  
---  
> ⚠️ **Nota Bene:** Nota: lo strategy pattern si basa proprio su questi meccanismi, è un esempio dove NON vogliamo static binding.  
La decisione della strategia va lasciata a runtime, in base al tipo dinamico dell'oggetto  

#### Ulteriori esercizi sul binding

> ⚠️ **Nota Bene:** Ci sono tanti esercizi di dynamic dispatch nell'esame.  
---  
> 📱 **Quiz:** Questo è static o dynamic binding?  
---  
> 📱 **Quiz:** Questo è static o dynamic binding?  
---  
> 📱 **Quiz:** Questo è static o dynamic binding?  
---  
> 📱 **Quiz:** Questo è static o dynamic binding?  
---  

#### Binding e gli argomenti

Il tipo degli argomenti può confonderci quando cerchiamo di capire su quale metodo verrà fatto dynamic dispatch  
Consideriamo la classe `Miner`, che contiene due metodi in overloading:  
- `mine(Pickaxe p)`  
- `mine(DiamondPickaxe p)`  
Nel metodo `argBindingExample `, cosa viene chiamato?  
> 📱 **Quiz:** Cosa viene chiamato qui?  
---  
> 📱 **Quiz:** Cosa viene chiamato qui?  
---  
Il compilatore deve capire quale metodo va chiamato  
A runtime, poi, verrà chiamato il metodo scelto dal compilatore.  
Per fare questa scelta, il compilatore cerca (tra tutti i metodi offerti) il metodo con la firma più consona in base agli argomenti passati.  
Visto che la decisione è fatta dal compilatore, questa decisione è statica, quindi si considera solo il tipo statico.  
Per il compilatore, `hiddenDiamond` ha tipo statico `Pickaxè, quindi deciderà che va chiamato il metodo che vuole un `Pickaxè, anche se il tipo dinamico dell'oggetto è `DiamondPickaxè  
> 📱 **Quiz:** Quale feature del linguaggio genera questo problema?  
> ⚠️ **Nota Bene:** Attenzione: il tipo dinamico dell'oggetto è sempre `DiamondPickaxè  
---  
Se dentro `mine ` viene chiamato un metodo sull'argomento, di questo metodo verra fatto dispatch seguendo il tipo dinamico  
Vi invitiamo a ragionare su tipo statico e dinamico, e su oggetto e parametro  
> ⚠️ **Nota Bene:** Il tipo statico dell'oggetto su cui è chiamato il metodo determina quali metodi si possono chiamare  
> ⚠️ **Nota Bene:** Il tipo statico dei parametri attuali con cui è chiamato il metodo servono per determinare ulteriormente il metodo da chiamare in caso di overloading  
> ⚠️ **Nota Bene:** Il tipo dinamico dell'oggetto su cui è chiamato il metodo determina quale metodo viene eseguito a runtime  
---  
Consideriamo i metodi `mineWithSubcall` di `Miner` e i relativi metodi `pick` di `Pick` e `DiamondPick`  
> 📱 **Quiz:** Quale `mineWithSubcall` viene chiamato? Quale `pick`?  
---  
> 📱 **Quiz:** Come faccio a chiamare `mineWithSubcall` di `DiamondPick`?  
---  

#### Link Utili

-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up

- Come interagisce il tipo degli argomenti e lo static binding? Fatevi esempi.  
-  

---

## Arguments

### 📄 `DiamondPick.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture10/arguments/DiamondPick.java)

### 📄 `Miner.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture10/arguments/Miner.java)

### 📄 `Pick.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture10/arguments/Pick.java)

---

## Bindings

### 📄 `Block.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture10/bindings/Block.java)

I metodi `getRegistryName()`, `getStaticRegistry()` e `getRegistryCalculations()` sono tutti seguiti tramite static binding perchè definiti con le keyword dello static binding: `final`, `static` e `private `  

### 📄 `DiamondBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture10/bindings/DiamondBlock.java)

Non possiamo fare override di `getRegistryName `  
Se lo decommentate, il compilatore si arrabbia  

---

# Lezione 11

**Argomenti Trattati**
- [Bad](#bad)
- [Exercise](#exercise)
- [Templatemethod](#templatemethod)

---

### 📄 File: `Lecture11.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/Lecture11.java)


#### Lezione 11

BT: Analyse  
BT: Understand, Analyse  
BT: Understand, Evaluate  

#### The v-table

Dalla lezione 4 abbiamo lasciato indietro il concetto di v-table mentre disegnavamo il layout degli oggetti e delle classi in memoria  
Nel metodo `vtableTest` andiamo a riempire questo vuoto  
Disegnamo il layout delle classi `Miner`, `Pick` e `DiamondPick`  
---  
| 0x0000A0 | mine(Pick p) |  
| :---: | :--- |  
| 0x0000B0 | mine(DiamondPick p) |  
| 0x0000C0 | mineWithSubcall(Pick p) |  
| 0x0000D0 | mineWithSubcall(DiamondPick p) |  
---  
| 0x000100 | pick() |  
| :---: | :---: |  
---  
| 0x000A00 | pick() |  
| :---: | :---: |  
---  
Questi layout sono le v-table di ogni classe.  
Supponiamo che l'indirizzo a cui ogni tabella è, sia rispettivamente  
- `0x010000`  
- `0x0A0000`  
- `0x0B0000`  
Queste classi non hanno campi!  
Il layout degli oggetti `m`, `pp` e `pd`, quindi è il seguente:  
---  
| 0x010000 |  
| :---: |  
---  
| 0x0A0000 |  
| :---: |  
---  
| 0x0B0000 |  
| :---: |  
---  
Ora simuliamo l'esecuzione dei metodi di `Miner`  
Le domande che ci dobbiamo chiedere sono:  
- Quale è il tipo statico dell'oggetto su cui chiamiamo un metodo?  
Con questa capiamo che metodi possiamo considerare vengano eseguiti  
- Quale è il tipo statico degli argomenti del metodo?  
Con questa capiamo come disambiguare i casi di overloading  
- Quale è il tipo dinamico dell'oggetto su cui chiamiamo un metodo?  
Con questa capiamo quale metodo viene invocato (seguendo la v-table)  
> ❓ **Domanda:** *Disegnate il layout di `Block` e `DiamondBlock` dalla lezione 10, esercitatevi sul dispatch per oggetti di quelle classi come nel metodo `dynamicTypeLookupExample()`* 

#### Instanceof e casting

Ci sono casi in cui non sappiamo precisamente il tipo dell'oggetto che riceviamo, potremmo sapere che l'oggetto è un `Entity` o un `Object`, come tipo statico.  
Questa informazione però non basta per poter invocare i metodi corretti che ci aspettiamo su un tale oggetto, in base al suo tipo dinamico  
Per farlo, dovremmo usare un cast, cioè una coercizione statica di tipo, che convince il compilatore che il tipo (statico) di un oggetto è quello definito nel cast  
Il problema è che il cast è un costrutto fallibile: il compilatore si fida (e altro non può fare) che il cast sia corretto.  
Se il cast non è corretto, il programma scoppia a runtime.  
Per prevenire questo errore, il linguaggio ci fornisce una primitiva: `instanceof` che serve per controllare il tipo dinamico di un oggetto a runtime  
> ⚠️ **Nota Bene:** Spoiler: non vogliamo praticamente mai usare ne casting ne instanceof  
---  
Avere degli if-then-else annidati con `instanceof` e cast è una indicazione di pessima programmazione e di mancato utilizzo dei principi OO  
Se usate overriding e polimorfismo (tramite dynamic dispatch) non avete bisogno di `instanceof`  
Per capire il problema in atto, vediamo `castingAndInstanceof`.  
Qui, creiamo un `genericMob1` con tipo statico `Entity` ma tipo dinamico `Creeper`  
Questo è un esempio pedagogico, pensate se fosse un parametro preso in input, non avremmo controllo sui tipi qui!  
Il codice prima chiama `instanceof`, e solo in caso ritorni `true `, fa il cast, che a questo punto è sicuro di non fallire  
Inoltre il cast ci cambia il tipo statico, quini possiamo chiamare `hiss()`.  
Questo è da evitare.  
Questo e sue varianti, tipo usare il `getClass()`, oppure mettere un campo che contiene un encoding del tipo (es: un magic number o una enum)  
Vedremo che l'unico caso in cui possiamo e dovremmo usare modi per ottenere informazioni di tipo dinamicamente è dentro il metodo equals, ma ne parliamo con le collections  
Vediamo ora un esempio di come potreste voler usare `instanceof`, in maniera completamente errata, e successivamente vediamo come fixare questo esempio usando il Template Method design pattern  
Supponiamo di voler implementare la logica di distruzione di un blocco:  
1. animazione delle particelle (tutti i blocchi)  
2. suono (comune per molti blocchi)  
3. loot (specifico per ogni blocco)  
Vediamo il metodo `runBadInstanceExample `, che crea due `BadBlock` e vi chiama un metodo sopra.  
Il metodo `destroyBlock` dentro a `BadBlock` fa casting e instanceof, contiene tutta la logica, e per farlo deve conoscere tutte le sue sottoclassi  
La soluzione di `destroyBlock` è pessima e prevede la scrittura, all'interno del metodo chiamante, di un nested `instanceof` che controlla il tipo di blocco, e in base a cosa ritorna `true `, fa diverse cose  
> 📱 **Quiz:** Perchè non va bene?  
---  
Alcuni principi che vengono violati da questa soluzione:  
- open/closed: se aggiungiamo un blocco (es, `Wood`) dobbiamo modificare questo metodo. Ma le due cose sono scorrelate, logicamente.  
- fragile: se ci dimentichiamo un `else if`, non aggiungiamo il comportamento del nuovo blocco  
- lento: fare dynamic typecheck è più lento che fare dynamic dispatch  

#### Il pattern Template Method

Questo pattern si usa per risolvere il problema appena visto  
Più in generale, possiamo pensare al problema di avere molte classi che concettualmente fanno la stessa sequenza di passi, ma ognuna potrebbe fare questi passi in maniera diversa  
Una analogia che si usa spesso per il Template Method è quella della ricetta da cucina  
Lo scheletro dell'algoritmo viene scritto nella classe parent, e viene segnato come `final`  
> 📱 **Quiz:** Perchè viene segnato `final`?  
---  
Vengono poi creati metodi astratti per i passi dell'algoritmo  
Lo scheletro chiama i metodi astratti  
Le sottoclassi devono implementare i metodi astratti, ma non possono fare overriding dello scheletro final  
Quindi gli oggetti delle sottoclassi finiranno per eseguire i passi dello scheletro, ma contestualizzati con le loro implementazioni dei metodi abstract  
Nel metodo `runTemplateExample ` vediamo il problema del break+loot precedente risolto col template method  
Consideriamo la classe `AbstractBlock`, che è parent di `DiamondOrè e di `GlassBlock`  
Questa classe implementa il template method dentro a `destroyBlock()`  
Il metodo `spawnParticles()` rappresenta uno step comune a tutti i blocchi.  
Potremmo lasciarlo abstract, ma il modo in cui saltano via i pezzi è uguale per tutti i blocchi, quindi va bene qui  
> 📱 **Quiz:** Quali modificatori ha senso dare ad un tale metodo?  
---  
Il metodo `playBreakSound()` definisce una implementazione base, ma che può venire sovrascritta dalle sottoclassi  
Per esempio, la classe `GlassBlock` lo fa  
Il metodo `dropLoot` invece va lasciato abstract: ogni classe figlia deve istanziare questa logica  
Nelle classi `DiamondOrè e `GlassBlock`, dobbiamo solo implementare i metodi abstract  
Dal punto di vista dell'implementatore, sappiamo che non possono venire bypassati gli invarianti che noi settiamo  
Inoltre, noi che implementiamo il block sappiamo come si comporta, il nostro user (o caller) non lo sa  
Proviamo ad aggiungere blocchi e a variare il nostro Template Method  
Consideriamo il legno:  
- ha un suono diverso dai blocchi normali  
- ha un suono tutto uguale per tutti i legni  
- ha una loot specifica per ogni tipo di legno  
> ⚠️ **Nota Bene:** Esercizio: Create le classi per aggiungere `OakBlock`, in modo che sia estendibile all'aggiunta di `CherryBlock`.  
---  
> ❓ **Domanda:** *La classe `AbstractWoodBlock` può non essere `abstract`?* 
---  
> ⚠️ **Nota Bene:** Aggiungete la classe `CherryBlock`  

#### Link Utili

-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up

-  

---

## Bad

### 📄 `BadBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/bad/BadBlock.java)

### 📄 `BadDiamond.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/bad/BadDiamond.java)

### 📄 `BadGlass.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/bad/BadGlass.java)

---

## Exercise

### 📄 `AbstractWoodBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/exercise/AbstractWoodBlock.java)

### 📄 `OakBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/exercise/OakBlock.java)

---

## Templatemethod

### 📄 `AbstractBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/templateMethod/AbstractBlock.java)

### 📄 `DiamondOre.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/templateMethod/DiamondOre.java)

### 📄 `GlassBlock.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture11/templateMethod/GlassBlock.java)

---

# Lezione 12lab2

### 📄 File: `Lecture12.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture12lab2/Lecture12.java)


#### Lezione 12 -- Laboratorio 2


#### Laboratorio 2


#### Fase 1: le classi astratte

10 min lavoro di gruppo, 10 min presentazione  

#### Fase 2: i metodi, astratti e non

30 min lavoro di gruppo, 10 min presentazione  

#### Fase 3: i campi che dovrebbero essere metodi

20 min lavoro di gruppo, 10 min presentazione  

---

# Lezione 13

**Argomenti Trattati**
- [Exceptions](#exceptions)
- [Tables](#tables)

---

### 📄 File: `Lecture13.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/Lecture13.java)


#### Lezione 13

BT: Remember, Understand, Analyse  
BT: Understand, Analyse  
BT: Understand, Analyse  

#### Eccezioni

In linguaggi più vecchi, si utilizzavano codici di errore, per esempio una funzione in C può ritornare -1, e questo sappiamo essere un caso di errore.  
Questo approccio ha un sacco di problemi:  
1. Come possiamo differenziare errori diversi?  
2. E se -1 fosse un valore possibile della funzione? Come si mappano gli errori?  
3. Come facciamo a propagare l'errore tra le diverse chiamate?  
4. Come separiamo la logica di gestione degli errori dalla logica di business?  
---  
Le eccezioni sono una soluzione alla gestione degli errori che non prevede l'utilizzo di codici di errore.  
Invece, il fatto che un programma possa sollevare un errore viene portato ad un livello semantico.  
Non è più sintattico: -1 == errore, ma è semantico: il linguaggio ha le eccezioni, e quelle rappresentano gli errori.  
Altri linguaggi non usano eccezioni, ma lasciano la gestione degli errori a livello di tipo: questo è ancora buono perchè il livello è sempre semantico.  
Gestire le eccezioni a livello semantico permette di rispondere al punto 1: errori diversi sono eccezioni diverse  
Inoltre, permettono anche di rispondere al punto 2: le eccezioni non si mischiano coi valori di ritorno.  
Le eccezioni hanno un costrutto sintattico che differenzia la business logic dalla error logic, permettendoci di rispondere al punto 4.  
Infine, vedremo che le eccezioni hanno una semantica che attraversa tutto il call stack, permettendo di propagare le eccezioni tra diverse chiamate a funzione.  
Le eccezioni vengono definite come Classi, ma sono classi speciali, esse devono estendere `Exception`.  
Le firme dei metodi si ampliano: esse contemplano anche una lista di eccezioni.  
Quando invochiamo un metodo dobbiamo fornire input, ci aspettiamo un output, e dobbiamo poter gestire tutti i casi di errore che il metodo elenca come sue eccezioni.  
Nel codice che invoca un metodo che può sollevare eccezioni, abbiamo l'obbligo di gestirle.  
Questo obbligo si traduce in due modi:  
- nei nuovi costrutti sintattici del try-catch  
- nell'obbligo di propagare la possibilità di errore nella firma del metodo che contiene il codice invocante  

#### Definire le Eccezioni

Supponiamo di dover scrivere la classe `CraftingTable `, con i metodi per creare i blocchi.  
Oltre al metodo legacy, contiene anche un metodo `craftAdvanced` la cui signature definisce che può sollevare una eccezione di tipo `CraftingException`.  
Mentre definiamo la logica di business del metodo `craftAdvanced`, vediamo che questo può sollevare diversi errori.  
Per esempio, potremmo non avere la ricetta per creare un blocco, oppure potremmo crearlo, ma avere l'inventario pieno.  
Questi errori vengono codificati in eccezioni.  
Essendo le eccezioni delle classi, gli possiamo dare un parent.  
Inoltre, perchè siano eccezioni, devono ereditare ad `Exception`.  
In questo caso, generiamo prima una eccezione generale di tipo `CraftingException`, che estende `Exception`  
Poi creiamo le due specifiche eccezioni che solleva la crafting table.  
Il loro comportamento lo lasciamo vuoto, quello che conta è avere definito i tipi di errore, e aver definito che `craftAdvanced` può generare degli errori  
Non dovete per forza ricreare eccezioni per ogni errore, riutilizzate quelle di Java, come:  
1. IllegalArgumentException:  
2. IllegalStateException:  
3. UnsupportedOperationException:  
Il metodo `exceptionsExample ` mostra un primo esempio di gestione degli errori con error codes che è obsoleto e da evitare.  
Come i magic numbers, siamo noi a dover ricordare il significato semantico di ogni numero, con possibilità di errori e confusione.  

#### La keyword `throw` (senza la 's')

Il corpo del metodo `craftAdvanced` contiene la keyword `throw`.  
Essa solleva una eccezione: vuole un oggetto di un tipo che estende exception e la sua semantica è: ora c'è un errore, ecco l'oggetto che ne cattura i dettagli  

#### La keyword `throws` (con la 's' alla fine)

Il metodo `craftAdvanced` ha una firma arricchita, dopo la keyword `throws` dice quali tipi di errori può sollevare.  
> 📱 **Quiz:** Posso decommentare questa linea?  
---  
> 📱 **Quiz:** Posso decommentare questa linea?  
---  

#### Il blocco try-catch

Una volta che invochiamo il metodo `craftAdvanced`, otteniamo l'obbligo di gestire l'eccezione.  
Pertanto quell'invocazione va racchiusa in un blocco `try`, seguita da blocchi `catch` che definiscono cosa fare nei casi di errore  
Si possono avere più blocchi `catch`.  
Questi vanno dal più specifico al meno specifico, perchè vengono attraversati in ordine.  
Viene scelto uno solo, non vengono attraversati tutti.  
> 📱 **Quiz:** Posso lasciare solo questa linea?  
---  
> 📱 **Quiz:** Posso decommentare questa linea?  
---  
Consideriamo il metodo `craftGeneral` dentro `CraftingTable `  
Notate la gerarchia di ereditarietà: mettendo la classe parent, possiamo sollevare qualsiasi errore figlio di `CraftingException`  
Le eccezioni che vengono sollevate sono comunque figlie di `CraftingException`  
> 📱 **Quiz:** Posso aggiungere una di queste righe dentro al corpo di `craftGeneral()`?  'throw new Exception()' e 'throw new EnchantingException("");'  
---  
La gestione della seconda è forzata dall'indicazione attuale  
La gestione della prima, no, richiede un cambio nella firma.  
Il metodo `exceptionsAndConstructors` dimostra che le eccezioni sono particolarmente utili nei costruttori  
Come faremmo a modellare errori nei costruttori, che non ritornano un intero?  
Non tutte le eccezioni che ricevete vanno gestite, alcune vanno semplicemente propagate  
Come nel caso di `deepenStackExample `, l'eccezione viene tirata in `last`, ma `mid` non sa gestirla  
Allora deve aggiungere la `throws` clause nella sua firma  
E la gestione viene propagata a `deepenStackExample `  

#### Runtime Exceptions

Java fornisce già una gerarchia legata alle eccezioni  
Throwable  
├── Error  
└── Exception  
└── RuntimeException  
Gli `Error` sono errori problemi seri che non dovrebbero essere gestiti dall'applicazione (es. fine memoria, etc)  
Le `RuntimeException` sono casi di errore che non dovrebbero succedere se il codice fosse scritto correttamente.  
Queste includono `NullPointerException` e `IndexOutOfBoundsException`.  
Per queste, non vanno gestite coi try-catch, va corretta la logica che causa il problema  
Il codice di `runtimeExceptionsExample ` contiene dei try-catch con `RuntimeException` ma solo per fini didattici.  
Infatti, non dovremmo gestire la `IndexOutOfBoundsException` con un try-catch, ma con un semplice check che l'index sia in-bound  
Oppure non dovremmo gestire la `NullPointerException` di `riskyMethod()`, ma controllare che  
> 📱 **Quiz:** Posso mettere questa riga fuori dal try-catch?  
---  

#### Eccezioni e subtyping

Nella definizione delle eccezioni fatta in precedenza, potremmo aver voluto metterle tutte sotto `Exception`  
Questo design non è buono, eccezioni correlate andrebbero rese figlie di una classe comune, come nel caso di `CraftingException`  
La gerarchia (parziale) che abbiamo creato è questa:  
Exception  
└── CraftingException  
├── RecipeMissingException  
├── InventoryFullException  
└── EnchantingException  
└── LevelNotEnoughException  
Questo approccio ha diversi vantaggi sia dal punto di vista di chi la solleva, e di chi la deve gestire  
La relazione di subtyping tra eccezioni ha una interazione interessante con l'overriding di metodi.  
Consideriamo ora la classe `EnchantingTable ` che estende `CraftingTable `.  
Questa classe ha un metodo privato per fare enchantment che può sollevare una nuova eccezione: `LevelNotEnoughException`  
Questa classe fa overriding dei due metodi di `CraftingTable `.  
> 📱 **Quiz:** Possiamo aggiungere la chiamata a `enchant` nei metodi `craftAdvanced` e `craftGeneral`?  
---  
Nel caso di `craftGeneral`, visto che `LevelNotEnoughException` 'is-a' `CraftingException`, la firma del metodo cattura già gli errori che possono essere gnerati dalla chiamata a `enchant`  
Nel caso di `craftAdvanced`, non possiamo.  
E non possiamo neanche modificare la firma di `craftAdvanced` dentro a `EnchantingTable `.  
Questo perchè potremmo creare un `EnchantingTable ` ma legarlo a una variabile il cui tipo statico è un suo supertipo.  
A compile-time, `craftAdvanced` viene controllato sul tipo statico, quindi su `CraftingTable `  
Quindi se permettiamo tipi dinamici che sollevano più eccezioni, rischiamo di avere codice che solleva eccezioni che il compilatore non ha detto di gestire.  
Invece, nella sottoclasse possiamo dichiarare di sollevare meno eccezioni.  
Come nel caso di `craftAdvanced` dentro a `EnchantingTable `.  
I controlli statici saranno ok, perchè ci fanno catturare tutto, probabilmente generando codice morto  
Però a runtime, non ci saranno eccezioni che non sono gestite  

#### Try-with-resources

Per oggetti che 'is-a' `AutoCloseable `, possiamo usare il try-with-resources  
A livello di sintassi, notate il try con le () invece che con le {}.  
Semanticamente, questi sono oggetti su cui si può chiamare il metodo `closè  
Il compilatore inserisce una chiamata a `br.close()` in ogni caso.  
Perchè usare il try-with-resources?  
Se br.close tira una IOException (E può), `fr` non viene chiuso.  

#### Link Utili

-  https://docs.oracle.com/javase/tutorial/essential/exceptions/tryResourceClose.html  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up

- errori in altri linguaggi: rust e go // FIXME  

---

## Exceptions

### 📄 `CraftingException.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/exceptions/CraftingException.java)

Questa è la classe base per la nostra logica  

### 📄 `EnchantingException.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/exceptions/EnchantingException.java)

### 📄 `InventoryFullException.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/exceptions/InventoryFullException.java)

### 📄 `LevelNotEnoughException.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/exceptions/LevelNotEnoughException.java)

### 📄 `RecipeMissingException.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/exceptions/RecipeMissingException.java)

Qui estendiamo CraftingException, non Exception!  

---

## Tables

### 📄 `CraftingTable.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/tables/CraftingTable.java)

### 📄 `EnchantingTable.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture13/tables/EnchantingTable.java)

---

# Lezione 14

**Argomenti Trattati**
- [Examples](#examples)

---

### 📄 File: `Lecture14.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture14/Lecture14.java)


#### Lezione 14

BT: Understand, Analyse, Evaluate  
BT: Understand, Analyse, Evaluate  
BT: Understand, Analyse  

#### Senza Generics: Object

Vediamo la classe `RawSpawner`, dove settiamo una entità (di tipòObject`) e poi la possiamo spawnare  
Una volta che otteniamo l'entità, non sappiamo altro che non sia Object  
Quindi per usarla dobbiamo fare dei cast, che possono essere problematici  
> 📱 **Quiz:** Cosa succede quando invochiamo `c . h i s s ()` ?  
---  
Per esempio, in `rawTypeExample `, facciamo un cast convinti di aver messo un `Creeper` nello spawner, ed il codice scoppia  

#### Generics

Vediamo la classe `Spawner`.  
Questa classe usa una notazione nuova: introduce un parametro di Tipo tra parentesi angolari.  
Voi siete abituati a definire parametri formali nelle funzioni, e a passare valori come parametri attuali all'invocazione delle funzioni  
L'idea dei parametri di tipo è analoga  
Certe classi (o anche certi metodi) hanno dei parametri di tipo  
Quando vengono istanziate, questi parametri vanno istanziati a loro volta con dei tipi specifici  
La differenza coi parametri formali è che questi ultimi venivano istanziati con dei valori, mentre i parametri di tipo vengono istanziati coi dei tipi  
Proprio come i parametri formali, i parametri di tipo hanno uno scope  
Nel caso siano definiti a livello di classe, lo scope dei parametri di tipo è tutta la classe  
Nel caso siano definiti in un metodo, lo scope è il metodo stesso  
Quindi in `Spawner` noi possiamo usare il tipo `T` all'interno della classe  
Per esempio per un campo, come `entity`  
Oppure come parametro di un metodo, oppure come tipo di ritorno di un metodo  
I Generici forniscono al linguaggio la proprietà di Polimorfismo parametrico  
Purtroppo, Java implementa male i generici -- non è nato con questa feature  
Quindi non otteniamo tutti i benefici del polimorfismo parametrico: parametricity  
Però è una ottima feature, e in futuro parleremo anche di parametricity e di cosa significa per un linguaggio avere questa proprietà  

#### Come usiamo il parametro di tipo?

Non abbiamo informazioni su `T` all'interno di `Spawner`  
Non sappiamo come si possa comportare  
Quindi dobbiamo trattare `T` in modo 'opaco'  
Per non trattarlo in modo opaco, dobbiamo introdurre dei `bounds`, che vediamo più avanti  

#### Come usiamo una classe con un generico?

Dentro il metodo `genericsExample ` usiamo lo `Spawner`.  
Il tipo statico dello spawner deve necessariamente dichiarare il tipo con cui istanziare `T`  
Il costruttore può evitare di indicare il tipo: per una volta Java fa type inference  
> 📱 **Quiz:** Considerate `z o m b i e S p a w n e r` : `S p a w n e r < Z o m b i e >`.  
---  
> 📱 **Quiz:** Queste righe compilano?  
---  
I generici ci impediscono di fare errori di tipo: quello che c'è dentro un `Spawner<Zombie>` è staticamente conosciuto come qualcosa di tipo `Zombie `  

#### Generici e invarianza

I generici non sono una feature di Java di partenza, sono stati aggiunti  
Ora vediamo una cosa non particolarmente piacevole: i generici sono tipati secondo 'invarianza'  
Esistono diversi approcci per gestire il polimorfismo di sottotipo in un linguaggio che ha anche tipi composti (o polimorfismo parametrico)  
Questi approcci hanno il nome di varianza, ed includono: invarianza, covarianza e controvarianza  
Supponiamo che `Zombie ` is-a `Entity.  
> 📱 **Quiz:** Cosa possiamo dire?  
---  
Una cosa intuitiva sarebbe concludere che `Spawner<Zombie>` 'is-a' `Spawner<Entity>`  
Questa si chiama covarianza  
Il metodo `invarianceExample ` ci fa vedere che se avessimo covarianza, potremmo avere errori di tipo a runtime, senza che il compilatore se ne accorga  
Con covarianza, potremmo creare uno `Spawner<Zombie `, dargli tipo statico `Spawner<Entity>` e metterci dentro un `Creeper`  

#### Array e Covarianza

Gli array di Java so covarianti, e questo è un problema  
Infatti, `Zombie[]` è considerato un sottotipo di `Entity[]`  
Il metodo `covarianceExample ` genera un runtime crash  
Prima crea un array di `Zombie `, poi tramite covarianza lo assegna a un array di `Entity`, poi tramite subtyping mettee un `Creeper` in questo array: non si può!  

#### Controvarianza (come concetto)

Controvarianza è l'opposto della varianza: se `Zombie ` is-a `Entity` allora `Spawner<Entity>` is-a `Spawner<Zombie>`  
Questa cosa può sembrare controintutiva ma è utile per quando dobbiamo scrivere dati e creare cosiddetti consumers  

#### Dettagli di covarianza e controvarianza

Capiamo i dettagli di quando funzionano covarianza e controvarianza perchè Java li permette con le wildcards  
Il metodo `contravarianceExample ` ha diverse righe commentate perchè Java non ci permette di fare altrimenti (ancora)  
Se avessimo covarianza, potremmo mettere lo `zombieSpawner` di tipo `Spawner<Zombie>` dentro alla variabile di tipo `Spawner<Entity>`  
Questo perchè `Zombie ` is-a `Entity`  
Potremmo chiamare `spawn` e salvare il risultato dentro a un `Entity`, anche se il tipo dinamico di quello che viene ritornato è `Zombie `, va bene perchè il tipo statico della variabile è un super-tipo di `Zombie `  
Questo viene chiamato producer: il parametro di tipo è nel tipo di ritorno  
Per i producers, la covarianza va bene, non genera errori di tipo, infatti possiamo mettere il valore di ritorno dentro una variabile di tipo `Entity`, che è un supertipo, e viene trattato come tale, non possiamo fare errori  
Cosideriamo invece il caso duale:  
> 📱 **Quiz:** Potremmo fare `g e n e r i c S p a w n e r . s e t E n t i t y ( n e w  Z o m b i e ());` ?  
---  
Il metodo si aspetta una `Entity`, e passare `Zombie ` va bene, grazie al polimorfismo di sottotipo  
Però allo stesso modo possiamo anche passare un `Creeper`, che va sempre bene per il polimorfismo di sottotipo  
Questo però è errato, abbiamo messo un `Creeper` dove ci aspettiamo ci siano solo `Zombie `  
Il metodo `setEntity` è un consumer: consuma un valore di tipo `T` invece di produrlo  
Ora cambiamo supposizione: supponiamo di avere controvarianza  
Quindi `Spawner<Entity>` is-a `Spawner<Zombie>`  
In questo caso, potremmo assegnare il `genericSpawner` a una variabile di tipo `Spawner<Zombie>`  
Questo però permetterebbe di usare `getEntity` e ottenere uno `Zombie `, ma in realtà abbiamo un `Creeper` quindi abbiamo un errore a runtime  
Quindi, usare un consumer con controvarianza da errori  
D'altro canto, proviamo a usare un producer: potremmo usare il `setSpawner` tranquillamente, perchè possiamo mettere uno `Zombie ` dentro una variabile che si aspetta una `Entity`  
Formalmente, potremmo permettere covarianza se le variabli di tipo appaiono solo in posizioni 'positive', cioè un tipo di ritorno  
Invece, potremmo permettere controvarianza se sono in posizioni 'negative' cioè argomenti  
Scala permette di annotare i parametri di tipo così da permettere questa flessibilità  
In Java invece, possiamo usare le wildcards  
> 📱 **Quiz:** Cosa ha Java?  
---  

#### Wildcards

Per rendere `Spawner<Zombie>` compatibile con `Spawner<Entity>`, Java ha una notazione speciale: '?'  
Il '?' ci dice che non sappiamo il tipo specifico, ma possiamo dare delle regole per dire cosa possa andare bene al posto di '?'  
La wildcard '?' si usa in 2 modi:  
1. `? extends TYPÈ  
2. `? super TYPÈ  

#### Wildcards e covarianza

`? extends TYPÈ si legge: un tipo che sia almeno un `TYPÈ  
Consideriamo `Spawner<? extends TYPE>`  
Questo si legge: "uno Spawner che contenga qualcosa che sia almeno una Entity"  
Possiamo ottenerne il contenuto come un `Entity`, anche se c'è dentro un sottotipo  
Non possiamo settare il contenuto ad un sottotipo di `Entity`  
Infatti, come vediamo in `covarianceExtendsExample `, il contenuto potrebbe venir settato ad un `Creeper`, mentre lo spawner era di `Zombie `  
In questo caso, viene fatto enforcement di covarianza e viene impedito di creare un errore di tipo  

#### Wildcards e controvarianza

`? super TYPÈ si legge: un tipo che sia un parent di `TYPÈ  
Consideriamo `Spawner<? super Zombie>`  
Possiamo trattarlo come uno `Spawner` per metterci degli `Zombie `  
Infatti il metodo `contravarianceSuperExample ` mette uno `Zombie ` in questo spawner  
Però quando otteniamo il contenuto dello spawner, non sappiamo gran che, possiamo salvare questo contenuto solo in una variabile di tipo parent di `Zombie `  
Inoltre dobbiamo fare un cast.  
> 📱 **Quiz:** Possiamo decommentare queste righe?  
---  

#### Acronimo: PECS

* P-roducer E-xtends: se l'oggetto produce un valore si usa `? extends`  
* C-onsumer S-uper: se l'oggetto prende un valore si usa `? super`  
Nel metodo `pecsExample ` usiamo il metodo helper `transferMob` per spostare un mob da uno spawner di `Zombie ` a uno spawner di `Entity`  
Questo è ok perchè il producer estende `Entity`, in quanto `Spawner<Entity>` mentre il consumer è un super di `Entity`, in quanto è uno `Spawner<Entity>`  

#### Link Utili

- Slides con un buon recap e topics avanzati sulle Wildcards https://ethz.ch/content/dam/ethz/special-interest/infk/chair-program-method/pm/documents/Education/Courses/as2025/coop/lecture04-Types.pdf  
-  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up

-  

---

## Examples

### 📄 `RawSpawner.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture14/examples/RawSpawner.java)

### 📄 `Spawner.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture14/examples/Spawner.java)

---

# Lezione 15

**Argomenti Trattati**
- [Factory_method](#factory_method)
- [State](#state)

---

### 📄 File: `Lecture15.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/Lecture15.java)


#### Lezione 15

BT: Understand, Analyse  
BT: Understand, Evaluate  
BT: Understand, Evaluate  

#### Type erasure

Il compilatore di Java cancella le informazioni di tipo relative ai parametri di tipo  
'Spawner<Zombie>' diventa just 'Spawner', mentre un parametro 'T' diventa 'Object' (oppure il suo bound nel caso di ?).  
Per far funzionare questo, il compilatore aggiunge dei Cast, che non falliscono mai però  
Perchè?  
1. retrocompatibilità. I generici sono stati aggiunti in Java 5 e fare una cosa diversa avrebbe significato far rompere tantissimo codice  
2. condivisione. Non si generano istanze diverse di `Spawner`, ma solo una.  
> 📱 **Quiz:** Possiamo decommentare questa riga?  
---  
Per questo non possiamo scrivere `new T()`, a runtime è `Object`, non quello che vogliamo.  
Inoltre, nel caso di overloading, potremmo avere questi casi:  
`public void process(Spawner<Zombie> z) { ... }`  
`public void process(Spawner<Skeleton> s) { ... }`  
che diventano  
`public void process(Spawner z) { ... }`  
`public void process(Spawner s) { ... }`  
Quindi non è permesso.  

#### Parametricity e Representation independence

Il parametric polymorphism ci da questa proprietà  
Una classe parametrica tipo `Spawner` si comporta sempre in maniera uguale a se stessa, indipendentemente da quale tipo viene istanziato per `T`.  
Se non avessimo instance of, almeno, avremmo questo risultato  

#### Patterns


#### Factory method

Il factory method è un design pattern che serve per raggruppare la logica di costruzione di certi oggetti  
Pensate agli alberi di Minecraft: hanno un tronco di una certa lunghezza, e una chioma semi-sferica ... se sono Oak o Birch. Ma se sono Dark Oak o Spruce, sono alti e hanno il tronco spesso, se sono Mangrovie, sono molto ramificate, nella savana sono sbilenchi, nella giungla hanno i rampicanti  
Mettere tutta questa logica in un costruttore lo rende molto complesso  
Per semplificare il codice, si preferisce creare un Factory Method, cioè una classe che contiene i metodi per creare gli oggetti complessi -- in questo caso gli Alberi  
La classe il cui costruttore diverrebbe troppo complesso ottiene un costruttore PackagePrivate, ma il suo tipo rimane pubblico e conosciuto a tutti  
Nello stesso package della classe si crea la classe factory  
Nella classe factory si creano metodi `static` che contengono la logica complessa di costruzione degli oggetti  
In questo modo, solo la classe factory (assumendo non ce ne siano altre nel package, come qui) può chiamare il costruttore della classe complessa  
Vediamo la classe `Tree `, col costruttore package-private  
Vediamo la classe `TreeFactory`, che contiene i costruttori, gli unici metodi che ritornano un `Tree `  
> 📱 **Quiz:** Guardate la classe `Tree_Bad`. Perchè è 'bad'?  
---  

#### State pattern

Situazione: vogliamo modellare una state machine  
Cos'è una state machine ? stati e transizioni  
Prendiamo ad esempio: i comportamenti dei piglin, che possono essere disegnati come una state machine  
> ⚠️ **Nota Bene:** Disegnare alla lavagna  
---  
Di base uno userebbe una enum per gli stati, tipo `PiglinState_Sv1`  
La classe `Piglin_Sv1` salva lo stato del piglin in un campo  
I suoi metodi catturano le transizioni facendo uno switch sullo stato, e aggiornandolo  
Problemi: code duplication, logica scomposta  
E se vogliamo estendere la state machine?  
Nuova Enum, nuova classe `Piglin_Sv2`, potremmo estendere gli switch vecchi, ma è poco componibile, e abbiamo la stessa code duplication e logica scomposta  
La soluzione è lo state pattern  
> 📱 **Quiz:** Cosa possiamo usare per gli stati?  
---  
> 📱 **Quiz:** Cosa possiamo usare per le transizioni?  
---  
Per le transizioni creiamo una interfaccia: `PiglinStateInterface_v1` che contiene tutti i metodi che possono fare una transizione  
- player_not_visible, player_wears_gold, player_visible_no_gold,  
Per gli stati creiamo una classe apposita, visto che stiamo considerando 3 stati, creiamo solo quelli per la v1:  
- Passive, Friendly, Aggressive1,  
Queste classi devono implementare l'interfaccia `PiglinStateInterface_v1`, così da avere l'obbligo di dover gestire quelle transizioni.  
Non abbiamo più il problema del rischio di perderci dei casi: dobbiamo gestirli tutti  
Abbiamo il problema di codice duplicato, che possiamo fattorizzare  
Abbiamo il problema che dobbiamo inserire codice che gestisce tutti i casi, anche quelli che non hanno senso  
Inoltre devono aggiornare lo stato del piglin su cui hanno compiuto la transizione.  
Per questo, fattorizziamo alcuni comportamenti degli stati, visto che hanno bisogno del piglin, ne creiamo un campo, e lo inizializziamo nel costruttore  
Il tutto dentro alla classe astratta che tutti gli stati estendono: `AbstractPiglinState `  
Vediamo la classe `Piglin_v1`, che contiene come prima il campo dello stato, solo che ora ha il tipo dell'interfaccia degli stati  
In questo caso stiamo anche usando composition over inheritance, in quanto il piglin ha la stessa interfaccia `PiglinStateInterface_v1` degli stati, e delega le transizioni al suo campo che contiene lo stato (essendo di tipo `PiglinStateInterface_v1`  
Nella v2 vogliamo aggiungere comportamento  
Per prima cosa creiamo `PiglinStateInterface ` come estensione dell'interfaccia precedente  
Poi creiamo la `Piglin_v2`, e modifichiamo questa e tutte le classi precedenti in modo che lavorino con la nuova interfaccia  
Gli stati della v2 sono di più, quindi li aggiungiamo  
- Aggro2, Aggro3  
Le transizioni della v2 sono questi metodi dell'interfaccia:  
- player_open_chest, player_attack_piglin,  
Per fattorizzare il codice, lo mettiamo nella classe astratta, e lo chiamiamo con `super` dalle sottoclassi di stato  
In questo caso vediamo la comodità di usare dei pattern: estendere la v1 nella v2 con un pattern rende tutto più facile.  
Ricordate: stiamo facendo programming in the large  
> ⚠️ **Nota Bene:** Cosa dovremmo fare se volessimo aggiungere comportamento:  
" Distracted, Bartering, Trading "  
con le azioni:  
" player_mine_gold, player_gives_gold, pick_up_gold, wait, give_item(X) "  
---  
- Azioni: aggiungere Interfaccia coi metodi delle azioni  
- Stati: aggiungere gli stati nuovi (classi), aggiungere le azioni nuove agli stati vecchi  
- Ottimizzare: fattorizzare comportamento  

#### Link Utili

- Slides con un buon recap e topics avanzati sulle Wildcards https://ethz.ch/content/dam/ethz/special-interest/infk/chair-program-method/pm/documents/Education/Courses/as2025/coop/lecture04-Types.pdf  
- https://minecraft.fandom.com/wiki/Piglin  
FIXME: se avete suggerimenti, fateli via pull request  

#### Follow-up

-  

---

## Factory_method

### 📄 `Tree.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/factory_method/Tree.java)

Mettiamo la Enum dentro la classe perchè è rilevante solo per i Tree  
È accedibile dall'esterno con Tree_Good.Type.OAK perchè è `public`  
Una Enum qui ci assicura l'assenza di errori di spelling, di tipi non esistenti, etc.  
Usare una Enum fa si che si possano usare solo le varianti che decidiamo noi  

### 📄 `TreeFactory.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/factory_method/TreeFactory.java)

I metodi di questa classe contengono la logica, e la complessità legata a creare un certo tipo di albero  
Questa complessità è omessa per fini didattici  
inspessire il tronco  
aggiungere rampicanti  

### 📄 `Tree_Bad.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/factory_method/Tree_Bad.java)

Una classe fatta male  

---

## State

### 📂 `state/con/v1`

#### 📄 `Piglin_v1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v1/Piglin_v1.java)

### 📂 `state/con/v1/states`

#### 📄 `AbstractPiglinState_v1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v1/states/AbstractPiglinState_v1.java)

#### 📄 `PiglinAggressive1State_v1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v1/states/PiglinAggressive1State_v1.java)

#### 📄 `PiglinFriendlyState_v1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v1/states/PiglinFriendlyState_v1.java)

#### 📄 `PiglinPassiveState_v1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v1/states/PiglinPassiveState_v1.java)

#### 📄 `PiglinStateInterface_v1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v1/states/PiglinStateInterface_v1.java)

### 📂 `state/con/v2`

#### 📄 `Piglin_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/Piglin_v2.java)

Questa classe è da pensare come l'evoluzione temporale di `Piglin_v2`  

### 📂 `state/con/v2/states`

#### 📄 `PiglinAggressive2State_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/PiglinAggressive2State_v2.java)

#### 📄 `PiglinAggressive3State_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/PiglinAggressive3State_v2.java)

#### 📄 `PiglinStateInterface_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/PiglinStateInterface_v2.java)

### 📂 `state/con/v2/states/old`

#### 📄 `AbstractPiglinState_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/old/AbstractPiglinState_v2.java)

#### 📄 `PiglinAggressive1State_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/old/PiglinAggressive1State_v2.java)

Questa classe è la copia della versione v1, con i metodi extra richiesti da `PiglinStateInterface_v2`  

#### 📄 `PiglinFriendlyState_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/old/PiglinFriendlyState_v2.java)

Questa classe è la copia della versione v1, con i metodi extra richiesti da `PiglinStateInterface_v2`  

#### 📄 `PiglinPassiveState_v2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/con/v2/states/old/PiglinPassiveState_v2.java)

Questa classe è la copia della versione v1, con i metodi extra richiesti da `PiglinStateInterface_v2`  

### 📂 `state/senza/v1`

#### 📄 `PiglinState_Sv1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/senza/v1/PiglinState_Sv1.java)

#### 📄 `Piglin_Sv1.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/senza/v1/Piglin_Sv1.java)

### 📂 `state/senza/v2`

#### 📄 `PiglinState_Sv2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/senza/v2/PiglinState_Sv2.java)

#### 📄 `Piglin_Sv2.java`
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture15/state/senza/v2/Piglin_Sv2.java)

---

# Lezione 16lab3

### 📄 File: `Lecture16.java` (File Principale (Runner))
🔗 [Vedi codice su GitHub](https://github.com/squera/-unitn-Programmazione2/blob/main/src/lecture16lab3/Lecture16.java)


#### Lezione 16 -- Laboratorio 3


#### Laboratorio 3


#### Fase 1: che eccezioni definire, dove tirarle

20 min lavoro di gruppo, 10 min presentazione  

#### Fase 2: quali tipi usare come generici

20 min lavoro di gruppo, 10 min presentazione  

#### Fase 3: quali patterns esistono / quali possiamo introdurre

20 min lavoro di gruppo, 10 min presentazione  

---
