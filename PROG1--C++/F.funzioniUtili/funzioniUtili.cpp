#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

// ============= FUNCTION DECLARATIONS =============

// ARRAY UTILITIES
void printArray(int arr[], int size);                    // Stampa tutti gli elementi di un array su una riga
void fillArray(int arr[], int size, int value);           // Riempie un array con un valore specifico
void fillArrayRandom(int arr[], int size, int min, int max); // Riempie un array con valori casuali compresi tra min e max
int sumArray(int arr[], int size);                       // Calcola la somma di tutti gli elementi dell'array
double avgArray(int arr[], int size);                    // Calcola la media aritmetica degli elementi dell'array
int maxArray(int arr[], int size);                       // Trova l'elemento massimo nell'array
int minArray(int arr[], int size);                       // Trova l'elemento minimo nell'array
void copyArray(int src[], int dest[], int size);         // Copia tutti gli elementi da array sorgente a array destinazione
void reverseArray(int arr[], int size);                  // Inverte l'ordine degli elementi nell'array
int searchArray(int arr[], int size, int value);         // Cerca un valore nell'array e restituisce l'indice (-1 se non trovato)
void sortArray(int arr[], int size);                     // Ordina l'array in ordine crescente usando bubble sort
int countOccurrences(int arr[], int size, int value);    // Conta quante volte appare un valore nell'array

// MATRIX UTILITIES
void printMatrix(int mat[][100], int rows, int cols);    // Stampa una matrice formattata per righe e colonne
void fillMatrix(int mat[][100], int rows, int cols, int value); // Riempie una matrice con un valore specifico
int sumMatrix(int mat[][100], int rows, int cols);       // Calcola la somma di tutti gli elementi della matrice
int sumDiagonal(int mat[][100], int size);               // Calcola la somma della diagonale principale (matrice quadrata)
int sumAntiDiagonal(int mat[][100], int size);           // Calcola la somma della diagonale secondaria (matrice quadrata)
void transposeMatrix(int mat[][100], int mat_t[][100], int rows, int cols); // Crea la matrice trasposta
int sumRow(int mat[][100], int cols, int row);           // Calcola la somma di una riga specifica
int sumColumn(int mat[][100], int rows, int col);        // Calcola la somma di una colonna specifica
int maxMatrix(int mat[][100], int rows, int cols);       // Trova l'elemento massimo nella matrice
int minMatrix(int mat[][100], int rows, int cols);       // Trova l'elemento minimo nella matrice

// STRING UTILITIES (Char Arrays)
int stringLength(char str[]);                            // Calcola la lunghezza di una stringa (caratteri fino a '\0')
void copyString(char src[], char dest[]);                // Copia una stringa sorgente nella stringa destinazione
void concatenateStrings(char str1[], char str2[], char result[]); // Concatena due stringhe in una stringa risultato
void reverseString(char str[]);                          // Inverte l'ordine dei caratteri nella stringa
int compareStrings(char str1[], char str2[]);            // Confronta due stringhe (0=uguali, <0 se str1<str2, >0 se str1>str2)
void toUpperCase(char str[]);                            // Converte tutti i caratteri della stringa in maiuscolo
void toLowerCase(char str[]);                            // Converte tutti i caratteri della stringa in minuscolo
int countVowels(char str[]);                             // Conta il numero di vocali nella stringa
int countConsonants(char str[]);                         // Conta il numero di consonanti nella stringa
bool isPalindrome(char str[]);                           // Verifica se la stringa è un palindromo

// NUMERIC UTILITIES
int factorial(int n);                                    // Calcola il fattoriale di n ricorsivamente
int fibonacci(int n);                                    // Calcola l'n-esimo numero di Fibonacci ricorsivamente
int power(int base, int exp);                            // Calcola base^exp ricorsivamente
int gcd(int a, int b);                                   // Calcola il massimo comune divisore usando algoritmo di Euclide
bool isPrime(int n);                                     // Verifica se un numero è primo
int countDigits(int n);                                  // Conta il numero di cifre in un numero
int sumDigits(int n);                                    // Calcola la somma delle cifre di un numero ricorsivamente
int reverseNumber(int n, int rev = 0);                   // Inverte le cifre di un numero ricorsivamente
int numeroOcco(int arr[10], int n, int i, int numToCount); // Conta occorrenze di un numero in array ricorsivamente
int maxOfArray(int arr[], int n, int max);               // Trova massimo in array ricorsivamente

// TREE UTILITIES
struct Nodo {                                            // Struttura per nodo di albero binario
    int valore;                                          // Valore memorizzato nel nodo
    Nodo* sinistro;                                      // Puntatore al figlio sinistro
    Nodo* destro;                                        // Puntatore al figlio destro
};
int altezzaAlberoRic(Nodo* radice);                     // Calcola altezza dell'albero ricorsivamente
int contaNodiRic(Nodo* radice);                         // Conta numero totale di nodi nell'albero ricorsivamente

// PERMUTATION UTILITIES
void swap(int *a, int *b);                              // Scambia i valori di due variabili usando puntatori
void permutaRic(int a[], int n, int pos);               // Genera tutte le permutazioni di un array ricorsivamente
void permutaRicHelper(int a[], int n, int pos, int current); // Funzione helper per generare permutazioni

// LINKED LIST UTILITIES
struct Node {                                           // Struttura per nodo di lista collegata
    int data;                                           // Dato memorizzato nel nodo
    Node* next;                                         // Puntatore al nodo successivo
};
Node* createNode(int data);                             // Crea un nuovo nodo con il valore specificato
void insertAtHead(Node*& head, int data);              // Inserisce un nuovo nodo all'inizio della lista
void insertAtTail(Node*& head, int data);              // Inserisce un nuovo nodo alla fine della lista
void printList(Node* head);                            // Stampa tutti gli elementi della lista
int listLength(Node* head);                            // Calcola la lunghezza della lista
bool searchList(Node* head, int value);                // Cerca un valore nella lista
int sumList(Node* head);                               // Calcola la somma di tutti gli elementi (iterativo)
int sumListRecursive(Node* head);                      // Calcola la somma di tutti gli elementi (ricorsivo)
void deleteNode(Node*& head, int value);               // Elimina il primo nodo con il valore specificato
Node* reverseListRecursive(Node* head);                // Inverte la lista ricorsivamente
void deleteList(Node*& head);                          // Elimina tutti i nodi della lista
// ADDITIONAL LINKED LIST UTILITIES
Node* createListFromFile(const char* filename);               // Crea una lista concatenata leggendo interi da file
Node* createListFromArray(int arr[], int size);               // Converte un array in una lista concatenata
void arrayFromList(Node* head, int arr[], int& size);         // Converte una lista concatenata in un array
void removeDuplicates(Node*& head);                           // Rimuove i nodi duplicati dalla lista
void insertSorted(Node*& head, int value);                    // Inserisce un valore in modo ordinato in una lista crescente
void insertSortedRecursive(Node*& head, int value);           // Inserisce un valore ordinato ricorsivamente
Node* mergeSortedLists(Node* list1, Node* list2);             // Merge di due liste ordinate in una nuova lista ordinata
void reverseListIterative(Node*& head);                       // Inverte la lista iterativamente
Node* nextGreaterElements(Node* head);                        // Crea lista con elementi maggiori successivi più vicini
bool swapNodesByIndex(Node*& head, int index1, int index2);   // Scambia due nodi dati i loro indici

// DOUBLY LINKED LIST UTILITIES
struct DNode {                                                 // Struttura per nodo di lista doppiamente concatenata
    int data;                                                  // Dato memorizzato nel nodo
    DNode* next;                                               // Puntatore al nodo successivo
    DNode* prev;                                               // Puntatore al nodo precedente
};
DNode* createDNode(int data);                                 // Crea un nuovo nodo doppio
void insertAtHeadD(DNode*& head, int data);                   // Inserisce all'inizio della lista doppia
void insertAtTailD(DNode*& head, int data);                   // Inserisce alla fine della lista doppia
void printListD(DNode* head);                                 // Stampa la lista doppia
void printListDReverse(DNode* head);                          // Stampa la lista doppia al contrario
void deleteListD(DNode*& head);                               // Elimina tutti i nodi della lista doppia
DNode* createDListFromFile(const char* filename);             // Crea lista doppia da file

// STACK UTILITIES (PILE)
struct Stack {                                          // Struttura per rappresentare una pila
    int* data;                                          // Array dinamico per memorizzare gli elementi
    int top;                                            // Indice dell'elemento in cima alla pila
    int capacity;                                       // Capacità massima della pila
};
Stack* createStack(int capacity);                      // Crea una nuova pila con capacità specificata
void destroyStack(Stack* stack);                       // Distrugge una pila e dealloca la memoria
bool isEmpty(Stack* stack);                            // Verifica se la pila è vuota
bool isFull(Stack* stack);                            // Verifica se la pila è piena
bool push(Stack* stack, int value);                    // Inserisce un elemento in cima alla pila
bool pop(Stack* stack, int& value);                    // Rimuove e restituisce l'elemento in cima
bool peek(Stack* stack, int& value);                   // Legge l'elemento in cima senza rimuoverlo
int stackSize(Stack* stack);                          // Restituisce il numero di elementi nella pila
void printStack(Stack* stack);                        // Stampa tutti gli elementi della pila (dal basso verso l'alto)
void clearStack(Stack* stack);                        // Svuota completamente la pila
bool duplicateTop(Stack* stack);                      // Duplica l'elemento in cima alla pila
bool swapTop(Stack* stack);                           // Scambia i due elementi in cima alla pila
int sumStack(Stack* stack);                           // Calcola la somma di tutti gli elementi nella pila
int maxStack(Stack* stack);                           // Trova l'elemento massimo nella pila
int minStack(Stack* stack);                           // Trova l'elemento minimo nella pila
bool searchStack(Stack* stack, int value);            // Cerca un valore nella pila

// QUEUE UTILITIES (CODE)
struct Queue {                                          // Struttura per rappresentare una coda
    int* data;                                          // Array dinamico per memorizzare gli elementi
    int front;                                          // Indice del primo elemento
    int rear;                                           // Indice dell'ultimo elemento
    int size;                                           // Numero di elementi nella coda
    int capacity;                                       // Capacità massima della coda
};
Queue* createQueue(int capacity);                      // Crea una nuova coda con capacità specificata
void destroyQueue(Queue* queue);                       // Distrugge una coda e dealloca la memoria
bool isQueueEmpty(Queue* queue);                       // Verifica se la coda è vuota
bool isQueueFull(Queue* queue);                        // Verifica se la coda è piena
bool enqueue(Queue* queue, int value);                 // Inserisce un elemento in fondo alla coda
bool dequeue(Queue* queue, int& value);                // Rimuove e restituisce il primo elemento
bool queueFront(Queue* queue, int& value);             // Legge il primo elemento senza rimuoverlo
int queueSize(Queue* queue);                           // Restituisce il numero di elementi nella coda
void printQueue(Queue* queue);                         // Stampa tutti gli elementi della coda
void clearQueue(Queue* queue);                         // Svuota completamente la coda

// DYNAMIC STACK UTILITIES (Pila con ridimensionamento automatico)
struct DynamicStack {                                   // Struttura per pila con array dinamico ridimensionabile
    int* data;                                          // Array dinamico per memorizzare gli elementi
    int top;                                            // Indice dell'elemento in cima
    int capacity;                                       // Capacità attuale
};
DynamicStack* createDynamicStack(int initialCapacity); // Crea pila dinamica con capacità iniziale
void destroyDynamicStack(DynamicStack* stack);         // Distrugge pila dinamica
bool pushDynamic(DynamicStack* stack, int value);      // Push con ridimensionamento automatico
bool popDynamic(DynamicStack* stack, int& value);      // Pop da pila dinamica
bool peekDynamic(DynamicStack* stack, int& value);     // Peek da pila dinamica
bool isDynamicStackEmpty(DynamicStack* stack);         // Verifica se pila dinamica è vuota
int dynamicStackSize(DynamicStack* stack);             // Dimensione pila dinamica
void printDynamicStack(DynamicStack* stack);           // Stampa pila dinamica

// DYNAMIC QUEUE UTILITIES (Coda con ridimensionamento automatico)
struct DynamicQueue {                                   // Struttura per coda con array dinamico ridimensionabile
    int* data;                                          // Array dinamico
    int front;                                          // Indice primo elemento
    int rear;                                           // Indice ultimo elemento
    int size;                                           // Numero elementi
    int capacity;                                       // Capacità attuale
};
DynamicQueue* createDynamicQueue(int initialCapacity); // Crea coda dinamica
void destroyDynamicQueue(DynamicQueue* queue);         // Distrugge coda dinamica
bool enqueueDynamic(DynamicQueue* queue, int value);   // Enqueue con ridimensionamento automatico
bool dequeueDynamic(DynamicQueue* queue, int& value);  // Dequeue da coda dinamica
bool isDynamicQueueEmpty(DynamicQueue* queue);         // Verifica se coda dinamica è vuota
int dynamicQueueSize(DynamicQueue* queue);             // Dimensione coda dinamica
void printDynamicQueue(DynamicQueue* queue);           // Stampa coda dinamica

// STACK LINKED LIST UTILITIES (Pila tramite lista concatenata)
struct StackNode {                                      // Nodo per pila basata su lista
    int data;                                           // Dato
    StackNode* next;                                    // Puntatore al nodo successivo
};
struct LinkedStack {                                    // Struttura per pila tramite lista
    StackNode* top;                                     // Puntatore alla cima della pila
    int size;                                           // Numero di elementi
};
LinkedStack* createLinkedStack();                       // Crea pila basata su lista
void destroyLinkedStack(LinkedStack* stack);           // Distrugge pila basata su lista
void pushLinked(LinkedStack* stack, int value);        // Push in pila basata su lista
bool popLinked(LinkedStack* stack, int& value);        // Pop da pila basata su lista
bool peekLinked(LinkedStack* stack, int& value);       // Peek da pila basata su lista
bool isLinkedStackEmpty(LinkedStack* stack);           // Verifica se pila lista è vuota
int linkedStackSize(LinkedStack* stack);               // Dimensione pila lista
void printLinkedStack(LinkedStack* stack);             // Stampa pila lista

// QUEUE LINKED LIST UTILITIES (Coda tramite lista concatenata)
struct QueueNode {                                      // Nodo per coda basata su lista
    int data;                                           // Dato
    QueueNode* next;                                    // Puntatore al nodo successivo
};
struct LinkedQueue {                                    // Struttura per coda tramite lista
    QueueNode* front;                                   // Puntatore al primo elemento
    QueueNode* rear;                                    // Puntatore all'ultimo elemento
    int size;                                           // Numero di elementi
};
LinkedQueue* createLinkedQueue();                       // Crea coda basata su lista
void destroyLinkedQueue(LinkedQueue* queue);           // Distrugge coda basata su lista
void enqueueLinked(LinkedQueue* queue, int value);     // Enqueue in coda basata su lista
bool dequeueLinked(LinkedQueue* queue, int& value);    // Dequeue da coda basata su lista
bool isLinkedQueueEmpty(LinkedQueue* queue);           // Verifica se coda lista è vuota
int linkedQueueSize(LinkedQueue* queue);               // Dimensione coda lista
void printLinkedQueue(LinkedQueue* queue);             // Stampa coda lista

// QUEUE WITH TWO STACKS (Coda implementata con due pile)
struct QueueWithStacks {                                // Coda implementata usando due pile
    Stack* stack1;                                      // Pila per enqueue
    Stack* stack2;                                      // Pila per dequeue
};
QueueWithStacks* createQueueWithStacks(int capacity);   // Crea coda con due pile
void destroyQueueWithStacks(QueueWithStacks* queue);   // Distrugge coda con due pile
bool enqueueWithStacks(QueueWithStacks* queue, int value); // Enqueue usando pile
bool dequeueWithStacks(QueueWithStacks* queue, int& value); // Dequeue usando pile
bool isQueueWithStacksEmpty(QueueWithStacks* queue);   // Verifica se coda con pile è vuota
void printQueueWithStacks(QueueWithStacks* queue);     // Stampa coda con pile

// EXPRESSION EVALUATION UTILITIES (Valutazione espressioni)
int evaluateSimpleExpression(const char* expr);         // Valuta espressione con solo addizioni
int evaluateExpression(const char* expr);               // Valuta espressione con + e * (gestisce precedenza)
bool isDigit(char c);                                   // Verifica se carattere è una cifra
bool isOperator(char c);                                // Verifica se carattere è un operatore
int precedence(char op);                                // Restituisce precedenza operatore
int applyOperator(int a, int b, char op);              // Applica operatore a due operandi

// STRUCTURE UTILITIES
struct Persona {                                        // Struttura per memorizzare dati di una persona
    char name[50];                                      // Nome della persona (max 49 caratteri)
    int age;                                            // Età della persona
    char email[50];                                     // Email della persona (max 49 caratteri)
};
void printPersona(Persona p);                          // Stampa i dati di una singola persona
void printPersonas(Persona arr[], int size);           // Stampa i dati di un array di persone
void sortPersonasByAge(Persona arr[], int size);       // Ordina array di persone per età crescente
int searchPersona(Persona arr[], int size, char name[]); // Cerca una persona per nome nell'array

// RECURSIVE UTILITIES
int sumArrayRecursive(int arr[], int size);             // Calcola somma array ricorsivamente
void printArrayRecursive(int arr[], int size, int index = 0); // Stampa array ricorsivamente
int maxArrayRecursive(int arr[], int size, int index = 0, int max = -2147483648); // Trova massimo ricorsivamente
int minArrayRecursive(int arr[], int size, int index = 0, int min = 2147483647);  // Trova minimo ricorsivamente
int searchArrayRecursive(int arr[], int size, int value, int index = 0); // Cerca valore ricorsivamente
int countOccurrencesRecursive(int arr[], int size, int value, int index = 0); // Conta occorrenze ricorsivamente
int prodottoArrayRic(int arr[], int n);                 // Calcola prodotto di tutti gli elementi ricorsivamente
int pascalTriangle(int row, int col);                  // Calcola elemento del Triangolo di Pascal (riga, colonna)
void printPascalRow(int row, int col);                 // Stampa ricorsivamente una riga del Triangolo di Pascal
void printPascalTriangle(int row, int currentRow);     // Stampa ricorsivamente il Triangolo di Pascal fino a row
int powerRecursive(int base, int exp);                 // Calcola potenza ricorsivamente (alternativa a power)
int sumDigitsRecursive(int n);                         // Calcola somma cifre ricorsivamente (alternativa a sumDigits)
bool isPalindromeRecursive(int n, int original, int reversed); // Verifica se numero è palindromo ricorsivamente
void hailstoneSequence(int n);                         // Stampa sequenza di Hailstone ricorsivamente
void stackOverflowTest(int depth);                     // Test ricorsivo per causare stack overflow

// FILE UTILITIES
void readFromFile(const char* filename, int arr[], int& size); // Legge numeri interi da file e li memorizza in array
void readFromFileWithCheck(const char* filename, int arr[], int& size, bool& success); // Legge da file con controllo di successo
void readFromFileSafe(const char* filename, int arr[], int maxSize, int& size); // Legge da file con limite di sicurezza
void readIntegersFromFile(const char* filename, int arr[], int& size); // Alias di readFromFile
void loadArrayFromFile(const char* filename, int arr[], int& size); // Legge array da file
void readFromBinaryFile(const char* filename, int arr[], int& size); // Legge numeri da file binario
void readFromFileUntilValue(const char* filename, int arr[], int& size, int stopValue); // Legge fino a trovare un valore specifico
void readFromFileSkipNegatives(const char* filename, int arr[], int& size); // Legge saltando valori negativi
void readFromFileInRange(const char* filename, int arr[], int& size, int min, int max); // Legge solo valori in un range
void writeToFileBinary(const char* filename, int arr[], int size); // Scrive array su file binario
void writeToFileFormatted(const char* filename, int arr[], int size); // Scrive con formattazione
void writeToFileWithHeader(const char* filename, int arr[], int size); // Scrive con intestazione
void writeToFileIndexed(const char* filename, int arr[], int size); // Scrive con indici
void overwriteFile(const char* filename, int arr[], int size); // Sovrascrive completamente un file
void writeArrayToFile(const char* filename, int arr[], int size); // Alias di writeToFile
void saveArrayToFile(const char* filename, int arr[], int size); // Scrive array su file
void writeToFileWithTimestamp(const char* filename, int arr[], int size); // Scrive con timestamp
void writeToFile(const char* filename, int arr[], int size);   // Scrive array di numeri interi su file
void readStringFromFile(const char* filename, char strings[][100], int& count); // Legge stringhe da file
void writeStringToFile(const char* filename, char strings[][100], int count);   // Scrive stringhe su file
int countLinesInFile(const char* filename);             // Conta il numero di righe in un file
void appendToFile(const char* filename, int arr[], int size); // Aggiunge numeri alla fine di un file esistente

// INPUT UTILITIES
bool readInt(int& n);                                    // Legge un intero con controllo di validità
int* maxArrayPtr(int arr[], int size);                   // Restituisce puntatore all'elemento massimo dell'array
int* allocArray(int size);                              // Alloca dinamicamente un array di interi
void deallocArray(int* arr);                            // Dealloca un array allocato dinamicamente
Persona* allocPersonas(int size);                       // Alloca dinamicamente un array di struct Persona
void freePersonas(Persona* arr, int size);              // Dealloca un array di struct Persona
bool isSorted(int arr[], int size);                     // Verifica se un array è ordinato in modo crescente
bool isSortedRecursive(int arr[], int size, int index = 0); // Verifica ordinamento ricorsivamente
int** allocMatrix(int rows, int cols);                  // Alloca dinamicamente una matrice di interi rows x cols
void deallocMatrix(int** mat, int rows);                // Dealloca una matrice allocata dinamicamente
void printDynamicMatrix(int** mat, int rows, int cols); // Stampa una matrice allocata dinamicamente
void fillDynamicMatrix(int** mat, int rows, int cols, int value); // Riempie una matrice dinamica con un valore
































// ============= MAIN FUNCTION =============

int main() {
    cout << "=== DIMOSTRAZIONE FUNZIONI UTILI ===" << endl << endl;
    
    // ============= ARRAY UTILITIES =============
    cout << "--- ARRAY UTILITIES ---" << endl;
    
    int arr[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    cout << "Array originale: ";
    printArray(arr, 10);
    
    cout << "Somma degli elementi: " << sumArray(arr, 10) << endl;
    cout << "Media degli elementi: " << avgArray(arr, 10) << endl;
    cout << "Elemento massimo: " << maxArray(arr, 10) << endl;
    cout << "Elemento minimo: " << minArray(arr, 10) << endl;
    
    cout << "Indice dell'elemento 7: " << searchArray(arr, 10, 7) << endl;
    cout << "Occorrenze dell'elemento 5: " << countOccurrences(arr, 10, 5) << endl;
    
    int arrCopy[10];
    copyArray(arr, arrCopy, 10);
    cout << "Array copiato: ";
    printArray(arrCopy, 10);
    
    reverseArray(arrCopy, 10);
    cout << "Array invertito: ";
    printArray(arrCopy, 10);
    
    sortArray(arr, 10);
    cout << "Array ordinato: ";
    printArray(arr, 10);
    
    fillArray(arrCopy, 10, 42);
    cout << "Array riempito con 42: ";
    printArray(arrCopy, 10);
    
    fillArrayRandom(arrCopy, 10, 1, 20);
    cout << "Array con valori casuali (1-20): ";
    printArray(arrCopy, 10);
    
    cout << endl;
    
    // ============= MATRIX UTILITIES =============
    cout << "--- MATRIX UTILITIES ---" << endl;
    
    int matrix[100][100];
    int rows = 3, cols = 3;
    
    int value = 1;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            matrix[i][j] = value++;
    
    cout << "Matrice 3x3:" << endl;
    printMatrix(matrix, rows, cols);
    
    cout << "Somma di tutti gli elementi: " << sumMatrix(matrix, rows, cols) << endl;
    cout << "Somma diagonale principale: " << sumDiagonal(matrix, rows) << endl;
    cout << "Somma diagonale secondaria: " << sumAntiDiagonal(matrix, rows) << endl;
    cout << "Somma prima riga: " << sumRow(matrix, cols, 0) << endl;
    cout << "Somma prima colonna: " << sumColumn(matrix, rows, 0) << endl;
    cout << "Elemento massimo: " << maxMatrix(matrix, rows, cols) << endl;
    cout << "Elemento minimo: " << minMatrix(matrix, rows, cols) << endl;
    
    int matrixT[100][100];
    transposeMatrix(matrix, matrixT, rows, cols);
    cout << "Matrice trasposta:" << endl;
    printMatrix(matrixT, cols, rows);
    
    fillMatrix(matrix, rows, cols, 99);
    cout << "Matrice riempita con 99:" << endl;
    printMatrix(matrix, rows, cols);
    
    cout << endl;
    
    // ============= CHAR ARRAY UTILITIES =============
    cout << "--- CHAR ARRAY UTILITIES ---" << endl;
    
    char str1[100] = "Ciao";
    char str2[100] = "Mondo";
    char result[200];
    
    cout << "char array 1: '" << str1 << "'" << endl;
    cout << "Lunghezza char array 1: " << stringLength(str1) << endl;
    
    copyString(str1, result);
    cout << "char array copiato: '" << result << "'" << endl;
    
    concatenateStrings(str1, str2, result);
    cout << "char arrays concatenati: '" << result << "'" << endl;
    
    reverseString(result);
    cout << "char array invertito: '" << result << "'" << endl;
    
    cout << "Confronto 'Ciao' vs 'Mondo': " << compareStrings(str1, str2) << endl;
    
    char testCase[100] = "Programmazione";
    cout << "char array originale: '" << testCase << "'" << endl;
    
    toUpperCase(testCase);
    cout << "In maiuscolo: '" << testCase << "'" << endl;
    
    toLowerCase(testCase);
    cout << "In minuscolo: '" << testCase << "'" << endl;
    
    char vowelTest[100] = "Programmazione";
    cout << "Vocali in 'Programmazione': " << countVowels(vowelTest) << endl;
    cout << "Consonanti in 'Programmazione': " << countConsonants(vowelTest) << endl;
    
    char palindrome[100] = "radar";
    cout << "'" << palindrome << "' e' palindromo? " << (isPalindrome(palindrome) ? "Si" : "No") << endl;
    
    cout << endl;
    
    // ============= NUMERIC UTILITIES =============
    cout << "--- NUMERIC UTILITIES ---" << endl;
    
    cout << "Fattoriale di 5: " << factorial(5) << endl;
    cout << "7° numero di Fibonacci: " << fibonacci(7) << endl;
    cout << "2^8: " << power(2, 8) << endl;
    cout << "GCD(48, 18): " << gcd(48, 18) << endl;
    cout << "17 e' primo? " << (isPrime(17) ? "Si" : "No") << endl;
    cout << "Cifre in 12345: " << countDigits(12345) << endl;
    cout << "Somma cifre di 12345: " << sumDigits(12345) << endl;
    cout << "12345 invertito: " << reverseNumber(12345) << endl;
    
    cout << endl;
    
    // ============= LINKED LIST =============
    cout << "--- LINKED LIST ---" << endl;
    
    Node* head = nullptr;
    
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtTail(head, 5);
    insertAtTail(head, 15);
    
    cout << "Lista creata: ";
    printList(head);
    
    cout << "Lunghezza lista: " << listLength(head) << endl;
    cout << "Cerca 15: " << (searchList(head, 15) ? "Trovato" : "Non trovato") << endl;
    cout << "Somma elementi (iterativa): " << sumList(head) << endl;
    cout << "Somma elementi (ricorsiva): " << sumListRecursive(head) << endl;
    
    deleteNode(head, 20);
    cout << "Lista dopo eliminazione di 20: ";
    printList(head);
    
    head = reverseListRecursive(head);
    cout << "Lista invertita: ";
    printList(head);
    
    deleteList(head);
    cout << "Lista eliminata" << endl;
    // ============= ADDITIONAL LINKED LIST UTILITIES TEST =============
        cout << "--- ADDITIONAL LINKED LIST UTILITIES ---" << endl;
        
        // Test createListFromArray
        int testArr[5] = {10, 20, 30, 40, 50};
        Node* listFromArray = createListFromArray(testArr, 5);
        cout << "Lista creata da array: ";
        printList(listFromArray);
        
        // Test arrayFromList
        int arrFromList[10];
        int arrSize;
        arrayFromList(listFromArray, arrFromList, arrSize);
        cout << "Array ricreato da lista (" << arrSize << " elementi): ";
        printArray(arrFromList, arrSize);
        
        // Test removeDuplicates
        Node* listWithDuplicates = nullptr;
        insertAtTail(listWithDuplicates, 5);
        insertAtTail(listWithDuplicates, 10);
        insertAtTail(listWithDuplicates, 5);
        insertAtTail(listWithDuplicates, 20);
        insertAtTail(listWithDuplicates, 10);
        insertAtTail(listWithDuplicates, 30);
        cout << "Lista con duplicati: ";
        printList(listWithDuplicates);
        removeDuplicates(listWithDuplicates);
        cout << "Lista dopo rimozione duplicati: ";
        printList(listWithDuplicates);
        
        // Test insertSorted
        Node* sortedList = nullptr;
        insertSorted(sortedList, 30);
        insertSorted(sortedList, 10);
        insertSorted(sortedList, 50);
        insertSorted(sortedList, 20);
        insertSorted(sortedList, 40);
        cout << "Lista ordinata (inserimenti: 30,10,50,20,40): ";
        printList(sortedList);
        
        // Test insertSortedRecursive
        insertSortedRecursive(sortedList, 25);
        insertSortedRecursive(sortedList, 5);
        cout << "Lista dopo inserimenti ricorsivi (25, 5): ";
        printList(sortedList);
        
        // Test mergeSortedLists
        Node* list1 = nullptr;
        insertAtTail(list1, 1);
        insertAtTail(list1, 3);
        insertAtTail(list1, 5);
        Node* list2 = nullptr;
        insertAtTail(list2, 2);
        insertAtTail(list2, 4);
        insertAtTail(list2, 6);
        cout << "Lista 1: ";
        printList(list1);
        cout << "Lista 2: ";
        printList(list2);
        Node* mergedList = mergeSortedLists(list1, list2);
        cout << "Liste unite: ";
        printList(mergedList);
        
        // Test reverseListIterative
        Node* listToReverse = nullptr;
        insertAtTail(listToReverse, 1);
        insertAtTail(listToReverse, 2);
        insertAtTail(listToReverse, 3);
        insertAtTail(listToReverse, 4);
        cout << "Lista originale: ";
        printList(listToReverse);
        reverseListIterative(listToReverse);
        cout << "Lista invertita iterativamente: ";
        printList(listToReverse);
        
        // Test nextGreaterElements
        Node* ngeList = nullptr;
        insertAtTail(ngeList, 4);
        insertAtTail(ngeList, 5);
        insertAtTail(ngeList, 2);
        insertAtTail(ngeList, 25);
        insertAtTail(ngeList, 7);
        cout << "Lista per next greater elements: ";
        printList(ngeList);
        Node* ngeResult = nextGreaterElements(ngeList);
        cout << "Next greater elements: ";
        printList(ngeResult);
        
        // Test swapNodesByIndex
        Node* swapList = nullptr;
        insertAtTail(swapList, 100);
        insertAtTail(swapList, 200);
        insertAtTail(swapList, 300);
        insertAtTail(swapList, 400);
        insertAtTail(swapList, 500);
        cout << "Lista prima dello scambio: ";
        printList(swapList);
        swapNodesByIndex(swapList, 1, 3);
        cout << "Lista dopo scambio indici 1 e 3: ";
        printList(swapList);
        
        // Cleanup
        deleteList(listFromArray);
        deleteList(listWithDuplicates);
        deleteList(sortedList);
        deleteList(mergedList);
        deleteList(listToReverse);
        deleteList(ngeList);
        deleteList(ngeResult);
        deleteList(swapList);
        
        // ============= DOUBLY LINKED LIST TEST =============
        cout << "\n--- DOUBLY LINKED LIST UTILITIES ---" << endl;
        
        DNode* dList = nullptr;
        insertAtHeadD(dList, 30);
        insertAtHeadD(dList, 20);
        insertAtHeadD(dList, 10);
        insertAtTailD(dList, 40);
        insertAtTailD(dList, 50);
        
        cout << "Lista doppia (avanti): ";
        printListD(dList);
        cout << "Lista doppia (indietro): ";
        printListDReverse(dList);
        
        deleteListD(dList);
        cout << "Lista doppia eliminata" << endl;
    cout << endl;
    // ============= STACK UTILITIES =============
    cout << "--- STACK UTILITIES ---" << endl;
    
    // Crea una pila con capacità 10
    Stack* pila = createStack(10);
    if (pila != nullptr) {
        cout << "Pila creata con capacita' 10" << endl;
        
        // Verifica se la pila è vuota
        cout << "La pila e' vuota? " << (isEmpty(pila) ? "Si" : "No") << endl;
        
        // Push di alcuni elementi
        cout << "\nInserimento elementi: 5, 10, 15, 20, 25" << endl;
        push(pila, 5);
        push(pila, 10);
        push(pila, 15);
        push(pila, 20);
        push(pila, 25);
        
        cout << "Contenuto pila: ";
        printStack(pila);
        
        cout << "Dimensione pila: " << stackSize(pila) << endl;
        cout << "La pila e' vuota? " << (isEmpty(pila) ? "Si" : "No") << endl;
        cout << "La pila e' piena? " << (isFull(pila) ? "Si" : "No") << endl;
        
        // Peek dell'elemento in cima
        int topValue;
        if (peek(pila, topValue)) {
            cout << "Elemento in cima (peek): " << topValue << endl;
        }
        
        // Pop di un elemento
        int poppedValue;
        if (pop(pila, poppedValue)) {
            cout << "Elemento estratto (pop): " << poppedValue << endl;
        }
        
        cout << "Contenuto pila dopo pop: ";
        printStack(pila);
        
        // Duplica l'elemento in cima
        cout << "\nDuplica elemento in cima" << endl;
        duplicateTop(pila);
        cout << "Contenuto pila: ";
        printStack(pila);
        
        // Scambia i due elementi in cima
        cout << "\nScambia i due elementi in cima" << endl;
        swapTop(pila);
        cout << "Contenuto pila: ";
        printStack(pila);
        
        // Operazioni di calcolo
        cout << "\nSomma elementi nella pila: " << sumStack(pila) << endl;
        cout << "Elemento massimo: " << maxStack(pila) << endl;
        cout << "Elemento minimo: " << minStack(pila) << endl;
        
        // Ricerca elemento
        cout << "Cerca 10 nella pila: " << (searchStack(pila, 10) ? "Trovato" : "Non trovato") << endl;
        cout << "Cerca 99 nella pila: " << (searchStack(pila, 99) ? "Trovato" : "Non trovato") << endl;
        
        // Svuota la pila
        cout << "\nSvuota la pila" << endl;
        clearStack(pila);
        cout << "Contenuto pila dopo clear: ";
        printStack(pila);
        
        // Distrugge la pila
        destroyStack(pila);
        cout << "Pila distrutta" << endl;
    }
    
    cout << endl;

    // ============= QUEUE UTILITIES =============
    cout << "--- QUEUE UTILITIES ---" << endl;
    
    // Crea una coda con capacità 10
    Queue* coda = createQueue(10);
    if (coda != nullptr) {
        cout << "Coda creata con capacita' 10" << endl;
        
        // Verifica se la coda è vuota
        cout << "La coda e' vuota? " << (isQueueEmpty(coda) ? "Si" : "No") << endl;
        
        // Enqueue di alcuni elementi
        cout << "\nInserimento elementi: 10, 20, 30, 40, 50" << endl;
        enqueue(coda, 10);
        enqueue(coda, 20);
        enqueue(coda, 30);
        enqueue(coda, 40);
        enqueue(coda, 50);
        
        cout << "Contenuto coda: ";
        printQueue(coda);
        
        cout << "Dimensione coda: " << queueSize(coda) << endl;
        cout << "La coda e' vuota? " << (isQueueEmpty(coda) ? "Si" : "No") << endl;
        cout << "La coda e' piena? " << (isQueueFull(coda) ? "Si" : "No") << endl;
        
        // Front della coda
        int frontValue;
        if (queueFront(coda, frontValue)) {
            cout << "Primo elemento (front): " << frontValue << endl;
        }
        
        // Dequeue di un elemento
        int dequeuedValue;
        if (dequeue(coda, dequeuedValue)) {
            cout << "Elemento estratto (dequeue): " << dequeuedValue << endl;
        }
        
        cout << "Contenuto coda dopo dequeue: ";
        printQueue(coda);
        
        // Svuota la coda
        cout << "\nSvuota la coda" << endl;
        clearQueue(coda);
        cout << "Contenuto coda dopo clear: ";
        printQueue(coda);
        
        // Distrugge la coda
        destroyQueue(coda);
        cout << "Coda distrutta" << endl;
    }
    
    cout << endl;
    
    // ============= DYNAMIC STACK UTILITIES =============
    cout << "--- DYNAMIC STACK UTILITIES ---" << endl;
    
    DynamicStack* dynStack = createDynamicStack(5);
    if (dynStack != nullptr) {
        cout << "Pila dinamica creata con capacita' iniziale 5" << endl;
        
        cout << "\nInserimento 8 elementi (la pila si ridimensionera' automaticamente)" << endl;
        for (int i = 1; i <= 8; i++) {
            pushDynamic(dynStack, i * 10);
            cout << "Push " << (i * 10) << " - Capacita': " << dynStack->capacity << endl;
        }
        
        cout << "\nContenuto pila dinamica: ";
        printDynamicStack(dynStack);
        cout << "Dimensione: " << dynamicStackSize(dynStack) << endl;
        
        int val;
        popDynamic(dynStack, val);
        cout << "Pop: " << val << endl;
        cout << "Contenuto dopo pop: ";
        printDynamicStack(dynStack);
        
        destroyDynamicStack(dynStack);
        cout << "Pila dinamica distrutta" << endl;
    }
    
    cout << endl;
    
    // ============= DYNAMIC QUEUE UTILITIES =============
    cout << "--- DYNAMIC QUEUE UTILITIES ---" << endl;
    
    DynamicQueue* dynQueue = createDynamicQueue(5);
    if (dynQueue != nullptr) {
        cout << "Coda dinamica creata con capacita' iniziale 5" << endl;
        
        cout << "\nInserimento 8 elementi (la coda si ridimensionera' automaticamente)" << endl;
        for (int i = 1; i <= 8; i++) {
            enqueueDynamic(dynQueue, i * 5);
            cout << "Enqueue " << (i * 5) << " - Capacita': " << dynQueue->capacity << endl;
        }
        
        cout << "\nContenuto coda dinamica: ";
        printDynamicQueue(dynQueue);
        cout << "Dimensione: " << dynamicQueueSize(dynQueue) << endl;
        
        int val;
        dequeueDynamic(dynQueue, val);
        cout << "Dequeue: " << val << endl;
        cout << "Contenuto dopo dequeue: ";
        printDynamicQueue(dynQueue);
        
        destroyDynamicQueue(dynQueue);
        cout << "Coda dinamica distrutta" << endl;
    }
    
    cout << endl;
    
    // ============= LINKED STACK UTILITIES =============
    cout << "--- LINKED STACK UTILITIES ---" << endl;
    
    LinkedStack* linkedStack = createLinkedStack();
    if (linkedStack != nullptr) {
        cout << "Pila basata su lista creata" << endl;
        
        cout << "\nInserimento elementi: 100, 200, 300, 400" << endl;
        pushLinked(linkedStack, 100);
        pushLinked(linkedStack, 200);
        pushLinked(linkedStack, 300);
        pushLinked(linkedStack, 400);
        
        cout << "Contenuto pila lista: ";
        printLinkedStack(linkedStack);
        cout << "Dimensione: " << linkedStackSize(linkedStack) << endl;
        
        int val;
        peekLinked(linkedStack, val);
        cout << "Peek: " << val << endl;
        
        popLinked(linkedStack, val);
        cout << "Pop: " << val << endl;
        cout << "Contenuto dopo pop: ";
        printLinkedStack(linkedStack);
        
        destroyLinkedStack(linkedStack);
        cout << "Pila lista distrutta" << endl;
    }
    
    cout << endl;
    
    // ============= LINKED QUEUE UTILITIES =============
    cout << "--- LINKED QUEUE UTILITIES ---" << endl;
    
    LinkedQueue* linkedQueue = createLinkedQueue();
    if (linkedQueue != nullptr) {
        cout << "Coda basata su lista creata" << endl;
        
        cout << "\nInserimento elementi: 11, 22, 33, 44, 55" << endl;
        enqueueLinked(linkedQueue, 11);
        enqueueLinked(linkedQueue, 22);
        enqueueLinked(linkedQueue, 33);
        enqueueLinked(linkedQueue, 44);
        enqueueLinked(linkedQueue, 55);
        
        cout << "Contenuto coda lista: ";
        printLinkedQueue(linkedQueue);
        cout << "Dimensione: " << linkedQueueSize(linkedQueue) << endl;
        
        int val;
        dequeueLinked(linkedQueue, val);
        cout << "Dequeue: " << val << endl;
        cout << "Contenuto dopo dequeue: ";
        printLinkedQueue(linkedQueue);
        
        destroyLinkedQueue(linkedQueue);
        cout << "Coda lista distrutta" << endl;
    }
    
    cout << endl;
    
    // ============= QUEUE WITH TWO STACKS =============
    cout << "--- QUEUE WITH TWO STACKS ---" << endl;
    
    QueueWithStacks* queueStacks = createQueueWithStacks(10);
    if (queueStacks != nullptr) {
        cout << "Coda implementata con due pile creata" << endl;
        
        cout << "\nInserimento elementi: 1, 2, 3, 4, 5" << endl;
        enqueueWithStacks(queueStacks, 1);
        enqueueWithStacks(queueStacks, 2);
        enqueueWithStacks(queueStacks, 3);
        enqueueWithStacks(queueStacks, 4);
        enqueueWithStacks(queueStacks, 5);
        
        cout << "Contenuto coda con pile: ";
        printQueueWithStacks(queueStacks);
        
        int val;
        dequeueWithStacks(queueStacks, val);
        cout << "Dequeue: " << val << endl;
        dequeueWithStacks(queueStacks, val);
        cout << "Dequeue: " << val << endl;
        
        cout << "Contenuto dopo 2 dequeue: ";
        printQueueWithStacks(queueStacks);
        
        cout << "Inserimento nuovo elemento: 6" << endl;
        enqueueWithStacks(queueStacks, 6);
        cout << "Contenuto finale: ";
        printQueueWithStacks(queueStacks);
        
        destroyQueueWithStacks(queueStacks);
        cout << "Coda con pile distrutta" << endl;
    }
    
    cout << endl;
    
    // ============= EXPRESSION EVALUATION =============
    cout << "--- EXPRESSION EVALUATION ---" << endl;
    
    const char* expr1 = "2+3+5";
    cout << "Espressione semplice: " << expr1 << endl;
    cout << "Risultato: " << evaluateSimpleExpression(expr1) << endl;
    
    const char* expr2 = "2+3*4";
    cout << "\nEspressione con precedenza: " << expr2 << endl;
    cout << "Risultato: " << evaluateExpression(expr2) << endl;
    
    const char* expr3 = "10+5*2-3";
    cout << "\nEspressione complessa: " << expr3 << endl;
    cout << "Risultato: " << evaluateExpression(expr3) << endl;
    
    cout << endl;

    // ============= STRUCTURES =============
    cout << "--- STRUCTURES ---" << endl;
    
    Persona persone[3];
    
    copyString("Mario", persone[0].name);
    persone[0].age = 25;
    copyString("mario@email.com", persone[0].email);
    
    copyString("Anna", persone[1].name);
    persone[1].age = 30;
    copyString("anna@email.com", persone[1].email);
    
    copyString("Luigi", persone[2].name);
    persone[2].age = 20;
    copyString("luigi@email.com", persone[2].email);
    
    cout << "Persone inserite:" << endl;
    printPersonas(persone, 3);
    
    sortPersonasByAge(persone, 3);
    cout << "\nPersone ordinate per eta':" << endl;
    printPersonas(persone, 3);
    
    char nome[50] = "Anna";
    int indice = searchPersona(persone, 3, nome);
    cout << "\nIndice di Anna: " << indice << endl;
    
    cout << endl;
    
    // ============= RECURSIVE UTILITIES =============
    cout << "--- RECURSIVE UTILITIES ---" << endl;
    
    int testArr[5] = {1, 2, 3, 4, 5};
    
    cout << "Array per test ricorsivi: ";
    printArrayRecursive(testArr, 5);
    
    cout << "Somma ricorsiva: " << sumArrayRecursive(testArr, 5) << endl;
    cout << "Massimo ricorsivo: " << maxArrayRecursive(testArr, 5) << endl;
    cout << "Minimo ricorsivo: " << minArrayRecursive(testArr, 5) << endl;
    cout << "Cerca 3 ricorsivamente: " << searchArrayRecursive(testArr, 5, 3) << endl;
    cout << "Conta occorrenze di 3 ricorsivamente: " << countOccurrencesRecursive(testArr, 5, 3) << endl;
    cout << "Prodotto ricorsivo: " << prodottoArrayRic(testArr, 5) << endl;    
    cout << "\nTriangolo di Pascal (prime 5 righe):" << endl;
    printPascalTriangle(4, 0);
    cout << "\nPotenza ricorsiva 3^4: " << powerRecursive(3, 4) << endl;
    
    cout << "Somma cifre ricorsiva di 9876: " << sumDigitsRecursive(9876) << endl;
    
    cout << "12321 e' palindromo? " << (isPalindromeRecursive(12321, 12321, 0) ? "Si" : "No") << endl;
    cout << "12345 e' palindromo? " << (isPalindromeRecursive(12345, 12345, 0) ? "Si" : "No") << endl;
    
    cout << "\nSequenza di Hailstone per n=7:" << endl;
    hailstoneSequence(7);

    cout << endl;
    
    // ============= FILE UTILITIES =============
    cout << "--- FILE UTILITIES ---" << endl;
    
    int fileArray[5] = {10, 20, 30, 40, 50};
    writeToFile("test_numbers.txt", fileArray, 5);
    cout << "Scritti numeri su file 'test_numbers.txt'" << endl;
    
    cout << "Righe nel file: " << countLinesInFile("test_numbers.txt") << endl;
    
    int readArray[10];
    int readSize;
    readFromFile("test_numbers.txt", readArray, readSize);
    cout << "Letti " << readSize << " numeri dal file: ";
    printArray(readArray, readSize);
    
    int appendArray[2] = {60, 70};
    appendToFile("test_numbers.txt", appendArray, 2);
    cout << "Aggiunti numeri al file" << endl;
    
    char stringhe[3][100] = {"Prima riga", "Seconda riga", "Terza riga"};
    writeStringToFile("test_string.txt", stringhe, 3);
    cout << "Scritte stringhe su file 'test_string.txt'" << endl;
    
    char stringheLette[10][100];
    int stringCount;
    readStringFromFile("test_string.txt", stringheLette, stringCount);
    cout << "Lette " << stringCount << " stringhe dal file:" << endl;
    for(int i = 0; i < stringCount; i++)
        cout << "- " << stringheLette[i] << endl;

    // ============= ADDITIONAL FILE UTILITIES TEST =============
        cout << "\n--- ADDITIONAL FILE UTILITIES ---" << endl;
        
        // Test readFromFileWithCheck
        int checkArray[10];
        int checkSize;
        bool success;
        readFromFileWithCheck("test_numbers.txt", checkArray, checkSize, success);
        if (success) {
            cout << "readFromFileWithCheck - File letto con successo (" << checkSize << " elementi): ";
            printArray(checkArray, checkSize);
        } else {
            cout << "readFromFileWithCheck - Errore nella lettura del file" << endl;
        }
        
        // Test readFromFileSafe
        int safeArray[5];
        int safeSize;
        readFromFileSafe("test_numbers.txt", safeArray, 5, safeSize);
        cout << "readFromFileSafe - Letti " << safeSize << " elementi (max 5): ";
        printArray(safeArray, safeSize);
        
        // Test readIntegersFromFile
        int integersArray[10];
        int integersSize;
        readIntegersFromFile("test_numbers.txt", integersArray, integersSize);
        cout << "readIntegersFromFile - Letti " << integersSize << " elementi: ";
        printArray(integersArray, integersSize);
        
        // Test writeToFileBinary e readFromBinaryFile
        int binaryArray[5] = {100, 200, 300, 400, 500};
        writeToFileBinary("test_binary.bin", binaryArray, 5);
        cout << "writeToFileBinary - Scritti 5 numeri in formato binario" << endl;
        
        int readBinaryArray[10];
        int binarySize;
        readFromBinaryFile("test_binary.bin", readBinaryArray, binarySize);
        cout << "readFromBinaryFile - Letti " << binarySize << " numeri: ";
        printArray(readBinaryArray, binarySize);
        
        // Test writeToFileFormatted
        int formattedArray[4] = {11, 22, 33, 44};
        writeToFileFormatted("test_formatted.txt", formattedArray, 4);
        cout << "writeToFileFormatted - File formattato creato" << endl;
        
        // Test writeToFileWithHeader
        int headerArray[3] = {777, 888, 999};
        writeToFileWithHeader("test_header.txt", headerArray, 3);
        cout << "writeToFileWithHeader - File con intestazione creato" << endl;
        
        // Test writeToFileIndexed
        int indexedArray[4] = {5, 15, 25, 35};
        writeToFileIndexed("test_indexed.txt", indexedArray, 4);
        cout << "writeToFileIndexed - File con indici creato" << endl;
        
        // Test readFromFileUntilValue
        int untilArray[10];
        int untilSize;
        readFromFileUntilValue("test_numbers.txt", untilArray, untilSize, 40);
        cout << "readFromFileUntilValue - Letti elementi fino a 40 (" << untilSize << " elementi): ";
        printArray(untilArray, untilSize);
        
        // Test readFromFileSkipNegatives
        int mixedArray[6] = {10, -5, 20, -10, 30, 40};
        writeToFile("test_mixed.txt", mixedArray, 6);
        int positiveArray[10];
        int positiveSize;
        readFromFileSkipNegatives("test_mixed.txt", positiveArray, positiveSize);
        cout << "readFromFileSkipNegatives - Letti solo positivi (" << positiveSize << " elementi): ";
        printArray(positiveArray, positiveSize);
        
        // Test readFromFileInRange
        int rangeArray[10];
        int rangeSize;
        readFromFileInRange("test_numbers.txt", rangeArray, rangeSize, 20, 50);
        cout << "readFromFileInRange (20-50) - Letti " << rangeSize << " elementi: ";
        printArray(rangeArray, rangeSize);
        
        // Test overwriteFile
        int overwriteArray[3] = {1111, 2222, 3333};
        overwriteFile("test_overwrite.txt", overwriteArray, 3);
        cout << "overwriteFile - File sovrascritto con 3 elementi" << endl;
        
        // Test writeToFileWithTimestamp
        int timestampArray[3] = {99, 88, 77};
        writeToFileWithTimestamp("test_timestamp.txt", timestampArray, 3);
        cout << "writeToFileWithTimestamp - File con timestamp creato" << endl;
        
        cout << endl;
    
    // ============= INPUT UTILITIES =============
    cout << "--- INPUT UTILITIES ---" << endl;
    
    // Test readInt
    int numero;
    cout << "Test lettura numero con controllo:" << endl;
    if (readInt(numero)) {
        cout << "Numero letto correttamente: " << numero << endl;
    } else {
        cout << "Errore nella lettura del numero" << endl;
    }
    
    // Test maxArrayPtr
    int testPtrArr[5] = {10, 45, 20, 55, 30};
    cout << "\nArray per test puntatori: ";
    printArray(testPtrArr, 5);
    
    int* maxPtr = maxArrayPtr(testPtrArr, 5);
    if (maxPtr != nullptr) {
        cout << "Indirizzo elemento massimo: " << maxPtr << endl;
        cout << "Valore elemento massimo: " << *maxPtr << endl;
        *maxPtr = 100; // Modifica tramite puntatore
        cout << "Array dopo modifica tramite puntatore: ";
        printArray(testPtrArr, 5);
    }
    
    // Test allocazione dinamica array
    int dimensione = 5;
    int* dynArray = allocArray(dimensione);
    if (dynArray != nullptr) {
        cout << "\nArray dinamico allocato di dimensione " << dimensione << endl;
        
        // Riempimento array dinamico
        for (int i = 0; i < dimensione; i++)
            dynArray[i] = (i + 1) * 10;
        
        cout << "Array dinamico riempito: ";
        printArray(dynArray, dimensione);
        
        deallocArray(dynArray);
        cout << "Array dinamico deallocato" << endl;
    }
    
    // Test allocazione dinamica struct Persona
    int numPersone = 2;
    Persona* personePtr = allocPersonas(numPersone);
    if (personePtr != nullptr) {
        cout << "\nArray dinamico di " << numPersone << " persone allocato" << endl;
        
        // Riempimento dati persone
        copyString("Marco", personePtr[0].name);
        personePtr[0].age = 28;
        copyString("marco@test.com", personePtr[0].email);
        
        copyString("Sara", personePtr[1].name);
        personePtr[1].age = 24;
        copyString("sara@test.com", personePtr[1].email);
        
        cout << "Persone inserite dinamicamente:" << endl;
        printPersonas(personePtr, numPersone);
        
        freePersonas(personePtr, numPersone);
        cout << "Array dinamico persone deallocato" << endl;
    }
    
    // Test isSorted
    int sortedArr[5] = {1, 3, 5, 7, 9};
    int unsortedArr[5] = {5, 2, 8, 1, 4};
    
    cout << "\nTest ordinamento array:" << endl;
    cout << "Array ordinato: ";
    printArray(sortedArr, 5);
    cout << "E' ordinato? " << (isSorted(sortedArr, 5) ? "Si" : "No") << endl;
    
    cout << "Array non ordinato: ";
    printArray(unsortedArr, 5);
    cout << "E' ordinato? " << (isSorted(unsortedArr, 5) ? "Si" : "No") << endl;
    
    // Test isSortedRecursive
    cout << "\nTest ordinamento ricorsivo:" << endl;
    cout << "Array ordinato (ricorsivo): " << (isSortedRecursive(sortedArr, 5) ? "Si" : "No") << endl;
    cout << "Array non ordinato (ricorsivo): " << (isSortedRecursive(unsortedArr, 5) ? "Si" : "No") << endl;
    
    // ============= DYNAMIC MATRIX UTILITIES TEST =============
    cout << "\n--- DYNAMIC MATRIX UTILITIES ---" << endl;
    
    int righe = 3, colonne = 4;
    
    // Allocazione matrice dinamica
    int** matriceDinamica = allocMatrix(righe, colonne);
    if (matriceDinamica != nullptr) {
        cout << "Matrice dinamica " << righe << "x" << colonne << " allocata" << endl;
        
        // Riempimento con valore specifico
        fillDynamicMatrix(matriceDinamica, righe, colonne, 7);
        cout << "Matrice riempita con valore 7:" << endl;
        printDynamicMatrix(matriceDinamica, righe, colonne);
        
        // Riempimento con valori progressivi
        int valore = 1;
        for (int i = 0; i < righe; i++) {
            for (int j = 0; j < colonne; j++) {
                matriceDinamica[i][j] = valore++;
            }
        }
        
        cout << "\nMatrice con valori progressivi:" << endl;
        printDynamicMatrix(matriceDinamica, righe, colonne);
        
        // Modifica di elementi specifici
        matriceDinamica[1][2] = 99;
        cout << "\nMatrice dopo modifica elemento [1][2] = 99:" << endl;
        printDynamicMatrix(matriceDinamica, righe, colonne);
        
        // Deallocazione
        deallocMatrix(matriceDinamica, righe);
        cout << "Matrice dinamica deallocata" << endl;
    } else {
        cout << "Errore nell'allocazione della matrice dinamica" << endl;
    }
    
    cout << endl;
    cout << "\n=== FINE DIMOSTRAZIONE ===" << endl;
    
    return 0;
}
















































// ============= FUNCTION IMPLEMENTATIONS =============

// ============= ARRAY UTILITIES =============

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        arr[i] = value;
}

void fillArrayRandom(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++)
        arr[i] = min + rand() % (max - min + 1);
}

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

double avgArray(int arr[], int size) {
    return size > 0 ? (double)sumArray(arr, size) / size : 0;
}

int maxArray(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

int minArray(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int searchArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value) return i;
    return -1;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int countOccurrences(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == value) count++;
    return count;
}

// ============= MATRIX UTILITIES =============

void printMatrix(int mat[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void fillMatrix(int mat[][100], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = value;
}

int sumMatrix(int mat[][100], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += mat[i][j];
    return sum;
}

int sumDiagonal(int mat[][100], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += mat[i][i];
    return sum;
}

int sumAntiDiagonal(int mat[][100], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += mat[i][size - 1 - i];
    return sum;
}

void transposeMatrix(int mat[][100], int mat_t[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat_t[j][i] = mat[i][j];
}

int sumRow(int mat[][100], int cols, int row) {
    int sum = 0;
    for (int j = 0; j < cols; j++)
        sum += mat[row][j];
    return sum;
}

int sumColumn(int mat[][100], int rows, int col) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
        sum += mat[i][col];
    return sum;
}

int maxMatrix(int mat[][100], int rows, int cols) {
    int max = mat[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] > max) max = mat[i][j];
    return max;
}

int minMatrix(int mat[][100], int rows, int cols) {
    int min = mat[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] < min) min = mat[i][j];
    return min;
}

// ============= STRING UTILITIES (Char Arrays) =============

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void copyString(char src[], char dest[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void concatenateStrings(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[j++] = str1[i++];
    }
    i = 0;
    while (str2[i] != '\0') {
        result[j++] = str2[i++];
    }
    result[j] = '\0';
}

void reverseString(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
}

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
    }
    return count;
}

int countConsonants(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z' && str[i] != 'a' && str[i] != 'e' && 
            str[i] != 'i' && str[i] != 'o' && str[i] != 'u') ||
            (str[i] >= 'A' && str[i] <= 'Z' && str[i] != 'A' && str[i] != 'E' && 
            str[i] != 'I' && str[i] != 'O' && str[i] != 'U'))
            count++;
    }
    return count;
}

bool isPalindrome(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i]) return false;
    return true;
}

// ============= NUMERIC UTILITIES =============

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 0;
    return base * power(base, exp - 1);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    n = abs(n);
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int reverseNumber(int n, int rev) {
    if (n == 0) return rev;
    return reverseNumber(n / 10, rev * 10 + n % 10);
}

int numeroOcco(int arr[10], int n, int i, int numToCount){
    if(i == n) return 0;
    
    if(arr[i] == numToCount) return 1 + numeroOcco(arr, n, i+1, numToCount);
    
    return numeroOcco(arr, n, i+1, numToCount);
}

int maxOfArray(int arr[], int n, int max) {
    if (n == 0) return max;

    if (arr[n-1] > max)
        return maxOfArray(arr, n-1, arr[n-1]);
    else
        return maxOfArray(arr, n-1, max);
}

int altezzaAlberoRic(Nodo* radice) {
    if (radice == nullptr) return 0;
    int hSx = altezzaAlberoRic(radice->sinistro);
    int hDx = altezzaAlberoRic(radice->destro);
    return 1 + (hSx > hDx ? hSx : hDx);
}

int contaNodiRic(Nodo* radice) {
    if(radice == nullptr) return 0;

    int sinistri = contaNodiRic(radice->sinistro);
    int destri = contaNodiRic(radice->destro);

    return 1 + sinistri + destri;
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void permutaRic(int a[], int n, int pos) {
    if (pos == n) {
        printArrayRecursive(a, n);
        return;
    }
    permutaRicHelper(a, n, pos, pos);
}

void permutaRicHelper(int a[], int n, int pos, int current) {
    if (current == n) return;
    
    swap(&a[pos], &a[current]);
    permutaRic(a, n, pos + 1);
    swap(&a[pos], &a[current]);
    
    permutaRicHelper(a, n, pos, current + 1);
}

// ============= LINKED LIST =============

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertAtHead(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int listLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool searchList(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

int sumList(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int sumListRecursive(Node* head) {
    if (head == nullptr) return 0;
    return head->data + sumListRecursive(head->next);
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

Node* reverseListRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============= ADDITIONAL LINKED LIST UTILITIES =============

Node* copyList(Node* head) {
    if (head == nullptr) return nullptr;
    
    Node* newHead = nullptr;
    Node* temp = head;
    
    while (temp != nullptr) {
        if (newHead == nullptr) {
            newHead = createNode(temp->data);
        } else {
            Node* newNode = createNode(temp->data);
            Node* tail = newHead;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = newNode;
        }
        temp = temp->next;
    }
    
    return newHead;
}

Node* copyListRecursive(Node* head) {
    if (head == nullptr) return nullptr;
    
    Node* newNode = createNode(head->data);
    newNode->next = copyListRecursive(head->next);
    
    return newNode;
}

// ============= STRUCTURES =============

void printPersona(Persona p) {
    cout << "Nome: " << p.name << ", Eta: " << p.age << ", Email: " << p.email << endl;
}

void printPersonas(Persona arr[], int size) {
    for (int i = 0; i < size; i++)
        printPersona(arr[i]);
}

void sortPersonasByAge(Persona arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j].age > arr[j + 1].age) {
                Persona temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int searchPersona(Persona arr[], int size, char name[]) {
    for (int i = 0; i < size; i++)
        if (compareStrings(arr[i].name, name) == 0) return i;
    return -1;
}

// ============= RECURSIVE UTILITIES =============

int sumArrayRecursive(int arr[], int size) {
    if (size == 0) return 0;
    return arr[size - 1] + sumArrayRecursive(arr, size - 1);
}

void printArrayRecursive(int arr[], int size, int index) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << arr[index] << " ";
    printArrayRecursive(arr, size, index + 1);
}

int maxArrayRecursive(int arr[], int size, int index, int max) {
    if (index == size) return max;
    if (arr[index] > max) max = arr[index];
    return maxArrayRecursive(arr, size, index + 1, max);
}

int minArrayRecursive(int arr[], int size, int index, int min) {
    if (index == size) return min;
    if (arr[index] < min) min = arr[index];
    return minArrayRecursive(arr, size, index + 1, min);
}

int searchArrayRecursive(int arr[], int size, int value, int index) {
    if (index == size) return -1;
    if (arr[index] == value) return index;
    return searchArrayRecursive(arr, size, value, index + 1);
}

int countOccurrencesRecursive(int arr[], int size, int value, int index) {
    if (index == size) return 0;
    int count = (arr[index] == value) ? 1 : 0;
    return count + countOccurrencesRecursive(arr, size, value, index + 1);
}

int prodottoArrayRic(int arr[], int n){
    if(n == 0) return 1;
    return arr[n-1]*prodottoArrayRic(arr, n-1);
}


int pascalTriangle(int row, int col) {
    // Caso base: primo o ultimo elemento della riga è sempre 1
    if (col == 0 || col == row) return 1;
    
    // Caso ricorsivo: somma dei due elementi sopra
    return pascalTriangle(row - 1, col - 1) + pascalTriangle(row - 1, col);
}

void printPascalRow(int row, int col) {
    // Caso base: se abbiamo stampato tutti gli elementi della riga
    if (col > row) {
        cout << endl;
        return;
    }
    
    // Stampa l'elemento corrente
    cout << pascalTriangle(row, col) << " ";
    
    // Ricorsione per stampare il prossimo elemento
    printPascalRow(row, col + 1);
}

void printPascalTriangle(int row, int currentRow) {
    // Caso base: se abbiamo stampato tutte le righe
    if (currentRow > row) return;
    
    // Stampa la riga corrente
    printPascalRow(currentRow, 0);
    
    // Ricorsione per stampare la prossima riga
    printPascalTriangle(row, currentRow + 1);
}

int powerRecursive(int base, int exp) {
    // Caso base: qualsiasi numero elevato a 0 è 1
    if (exp == 0) return 1;
    
    // Caso negativo
    if (exp < 0) return 0;
    
    // Caso ricorsivo
    return base * powerRecursive(base, exp - 1);
}

int sumDigitsRecursive(int n) {
    // Caso base: se n è 0, la somma è 0
    if (n == 0) return 0;
    
    // Caso ricorsivo: ultima cifra + somma delle rimanenti
    return (n % 10) + sumDigitsRecursive(n / 10);
}

bool isPalindromeRecursive(int n, int original, int reversed) {
    // Caso base: quando n diventa 0, confronta original con reversed
    if (n == 0) {
        return original == reversed;
    }
    
    // Caso ricorsivo: costruisce il numero invertito
    return isPalindromeRecursive(n / 10, original, reversed * 10 + n % 10);
}

void hailstoneSequence(int n) {
    // Stampa il numero corrente
    cout << n << " ";
    
    // Caso base: sequenza termina quando raggiungiamo 1
    if (n == 1) {
        cout << endl;
        return;
    }
    
    // Caso ricorsivo: applica le regole della sequenza di Hailstone
    if (n % 2 == 0) {
        // Se pari, dividi per 2
        hailstoneSequence(n / 2);
    } else {
        // Se dispari, moltiplica per 3 e aggiungi 1
        hailstoneSequence(3 * n + 1);
    }
}

void stackOverflowTest(int depth) {
    // Stampa la profondità corrente
    cout << "Profondita' ricorsione: " << depth << endl;
    
    // Ricorsione infinita (ATTENZIONE: causerà stack overflow!)
    stackOverflowTest(depth + 1);
}

// ============= FILE UTILITIES =============

void readFromFile(const char* filename, int arr[], int& size) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    size = 0;
    while (file >> arr[size])
        size++;
    file.close();
}

void writeToFile(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
        file << arr[i] << "\n";
    file.close();
}

void readStringFromFile(const char* filename, char strings[][100], int& count) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    count = 0;
    while (file.getline(strings[count], 100))
        count++;
    file.close();
}

void writeStringToFile(const char* filename, char strings[][100], int count) {
    fstream file(filename, ios::out);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < count; i++)
        file << strings[i] << "\n";
    file.close();
}

int countLinesInFile(const char* filename) {
    fstream file(filename, ios::in);
    if (!file.is_open()) return 0;
    int count = 0;
    char line[1000];
    while (file.getline(line, 1000))
        count++;
    file.close();
    return count;
}

void appendToFile(const char* filename, int arr[], int size) {
    fstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
        file << arr[i] << "\n";
    file.close();
}

// ============= ADDITIONAL FILE UTILITIES IMPLEMENTATIONS =============

void readFromFileWithCheck(const char* filename, int arr[], int& size, bool& success) {
    fstream file(filename, ios::in);
    success = file.is_open();
    
    if (!success) {
        cout << "Errore: impossibile aprire il file" << endl;
        size = 0;
        return;
    }
    
    size = 0;
    while (file >> arr[size]) {
        size++;
    }
    file.close();
}

void readFromFileSafe(const char* filename, int arr[], int maxSize, int& size) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        size = 0;
        return;
    }
    
    size = 0;
    int value;
    while (file >> value && size < maxSize) {
        arr[size++] = value;
    }
    
    if (size >= maxSize) {
        cout << "Attenzione: raggiunto limite massimo di " << maxSize << " elementi" << endl;
    }
    
    file.close();
}

void readIntegersFromFile(const char* filename, int arr[], int& size) {
    readFromFile(filename, arr, size);
}

void loadArrayFromFile(const char* filename, int arr[], int& size) {
    readFromFile(filename, arr, size);
}

void readFromBinaryFile(const char* filename, int arr[], int& size) {
    fstream file(filename, ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file binario" << endl;
        size = 0;
        return;
    }
    
    size = 0;
    while (file.read((char*)&arr[size], sizeof(int))) {
        size++;
    }
    file.close();
}

void readFromFileUntilValue(const char* filename, int arr[], int& size, int stopValue) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        size = 0;
        return;
    }
    
    size = 0;
    int value;
    while (file >> value) {
        if (value == stopValue) {
            break;
        }
        arr[size++] = value;
    }
    file.close();
}

void readFromFileSkipNegatives(const char* filename, int arr[], int& size) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        size = 0;
        return;
    }
    
    size = 0;
    int value;
    while (file >> value) {
        if (value >= 0) {
            arr[size++] = value;
        }
    }
    file.close();
}

void readFromFileInRange(const char* filename, int arr[], int& size, int min, int max) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        size = 0;
        return;
    }
    
    size = 0;
    int value;
    while (file >> value) {
        if (value >= min && value <= max) {
            arr[size++] = value;
        }
    }
    file.close();
}

void writeToFileBinary(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out | ios::binary);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file binario" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        file.write((char*)&arr[i], sizeof(int));
    }
    file.close();
}

void writeToFileFormatted(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    
    file << "Array di " << size << " elementi:" << endl;
    file << "[ ";
    for (int i = 0; i < size; i++) {
        file << arr[i];
        if (i < size - 1) file << ", ";
    }
    file << " ]" << endl;
    file.close();
}

void writeToFileWithHeader(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    
    file << "=== ARRAY DATA ===" << endl;
    file << "Size: " << size << endl;
    file << "Elements:" << endl;
    for (int i = 0; i < size; i++) {
        file << arr[i] << endl;
    }
    file << "=== END ===" << endl;
    file.close();
}

void writeToFileIndexed(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        file << "[" << i << "] = " << arr[i] << endl;
    }
    file.close();
}

void overwriteFile(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) {
        file << arr[i] << endl;
    }
    file.close();
}

void writeArrayToFile(const char* filename, int arr[], int size) {
    writeToFile(filename, arr, size);
}

void saveArrayToFile(const char* filename, int arr[], int size) {
    writeToFile(filename, arr, size);
}

void writeToFileWithTimestamp(const char* filename, int arr[], int size) {
    fstream file(filename, ios::out);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    
    time_t now = time(0);
    char* dt = ctime(&now);
    
    file << "Timestamp: " << dt;
    file << "Number of elements: " << size << endl;
    file << "Data:" << endl;
    
    for (int i = 0; i < size; i++) {
        file << arr[i] << endl;
    }
    file.close();
}

// ============= INPUT UTILITIES =============

bool readInt(int& n) {
    cout << "Inserisci un numero intero: ";
    if (!(cin >> n)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

int* maxArrayPtr(int arr[], int size) {
    if (size <= 0) return nullptr;
    int* max = &arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > *max) max = &arr[i];
    return max;
}

int* allocArray(int size) {
    if (size <= 0) return nullptr;
    return new int[size];
}

void deallocArray(int* arr) {
    delete[] arr;
}

Persona* allocPersonas(int size) {
    if (size <= 0) return nullptr;
    return new Persona[size];
}

void freePersonas(Persona* arr, int size) {
    delete[] arr;
}

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

bool isSortedRecursive(int arr[], int size, int index) {
    if (index >= size - 1) return true;
    if (arr[index] > arr[index + 1]) return false;
    return isSortedRecursive(arr, size, index + 1);
}

// ============= DYNAMIC MATRIX UTILITIES =============

int** allocMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return nullptr;
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deallocMatrix(int** mat, int rows) {
    if (mat == nullptr) return;
    
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void printDynamicMatrix(int** mat, int rows, int cols) {
    if (mat == nullptr) return;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void fillDynamicMatrix(int** mat, int rows, int cols, int value) {
    if (mat == nullptr) return;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = value;
        }
    }
}

// ============= STACK UTILITIES IMPLEMENTATIONS =============

Stack* createStack(int capacity) {
    if (capacity <= 0) return nullptr;
    
    Stack* stack = new Stack();
    stack->data = new int[capacity];
    stack->top = -1;
    stack->capacity = capacity;
    
    return stack;
}

void destroyStack(Stack* stack) {
    if (stack == nullptr) return;
    
    delete[] stack->data;
    delete stack;
}

bool isEmpty(Stack* stack) {
    if (stack == nullptr) return true;
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    if (stack == nullptr) return false;
    return stack->top == stack->capacity - 1;
}

bool push(Stack* stack, int value) {
    if (stack == nullptr || isFull(stack)) return false;
    
    stack->data[++stack->top] = value;
    return true;
}

bool pop(Stack* stack, int& value) {
    if (stack == nullptr || isEmpty(stack)) return false;
    
    value = stack->data[stack->top--];
    return true;
}

bool peek(Stack* stack, int& value) {
    if (stack == nullptr || isEmpty(stack)) return false;
    
    value = stack->data[stack->top];
    return true;
}

int stackSize(Stack* stack) {
    if (stack == nullptr) return 0;
    return stack->top + 1;
}

void printStack(Stack* stack) {
    if (stack == nullptr || isEmpty(stack)) {
        cout << "Stack vuoto" << endl;
        return;
    }
    
    for (int i = 0; i <= stack->top; i++) {
        cout << stack->data[i] << " ";
    }
    cout << endl;
}

void clearStack(Stack* stack) {
    if (stack == nullptr) return;
    stack->top = -1;
}

bool duplicateTop(Stack* stack) {
    if (stack == nullptr || isEmpty(stack) || isFull(stack)) return false;
    
    int topValue = stack->data[stack->top];
    stack->data[++stack->top] = topValue;
    return true;
}

bool swapTop(Stack* stack) {
    if (stack == nullptr || stackSize(stack) < 2) return false;
    
    int temp = stack->data[stack->top];
    stack->data[stack->top] = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = temp;
    return true;
}

int sumStack(Stack* stack) {
    if (stack == nullptr || isEmpty(stack)) return 0;
    
    int sum = 0;
    for (int i = 0; i <= stack->top; i++) {
        sum += stack->data[i];
    }
    return sum;
}

int maxStack(Stack* stack) {
    if (stack == nullptr || isEmpty(stack)) return 0;
    
    int max = stack->data[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->data[i] > max) max = stack->data[i];
    }
    return max;
}

int minStack(Stack* stack) {
    if (stack == nullptr || isEmpty(stack)) return 0;
    
    int min = stack->data[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->data[i] < min) min = stack->data[i];
    }
    return min;
}

bool searchStack(Stack* stack, int value) {
    if (stack == nullptr || isEmpty(stack)) return false;
    
    for (int i = 0; i <= stack->top; i++) {
        if (stack->data[i] == value) return true;
    }
    return false;
}


// ============= ADDITIONAL LINKED LIST UTILITIES IMPLEMENTATIONS =============

Node* createListFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return nullptr;
    }
    
    Node* head = nullptr;
    int value;
    while (file >> value) {
        insertAtTail(head, value);
    }
    file.close();
    return head;
}

Node* createListFromArray(int arr[], int size) {
    if (size <= 0) return nullptr;
    
    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        insertAtTail(head, arr[i]);
    }
    return head;
}

void arrayFromList(Node* head, int arr[], int& size) {
    size = 0;
    Node* temp = head;
    while (temp != nullptr) {
        arr[size++] = temp->data;
        temp = temp->next;
    }
}

void removeDuplicates(Node*& head) {
    if (head == nullptr) return;
    
    Node* current = head;
    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void insertSorted(Node*& head, int value) {
    Node* newNode = createNode(value);
    
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < value) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSortedRecursive(Node*& head, int value) {
    if (head == nullptr || head->data >= value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        return;
    }
    insertSortedRecursive(head->next, value);
}

Node* mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    
    Node* result = nullptr;
    
    if (list1->data <= list2->data) {
        result = createNode(list1->data);
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = createNode(list2->data);
        result->next = mergeSortedLists(list1, list2->next);
    }
    
    return result;
}

void reverseListIterative(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

Node* nextGreaterElements(Node* head) {
    if (head == nullptr) return nullptr;
    
    Node* result = nullptr;
    Node* temp = head;
    
    while (temp != nullptr) {
        int nextGreater = -1;
        Node* search = temp->next;
        
        while (search != nullptr) {
            if (search->data > temp->data) {
                nextGreater = search->data;
                break;
            }
            search = search->next;
        }
        
        insertAtTail(result, nextGreater);
        temp = temp->next;
    }
    
    return result;
}

bool swapNodesByIndex(Node*& head, int index1, int index2) {
    if (head == nullptr || index1 == index2) return false;
    if (index1 < 0 || index2 < 0) return false;
    
    if (index1 > index2) {
        int temp = index1;
        index1 = index2;
        index2 = temp;
    }
    
    Node* node1 = head;
    Node* node2 = head;
    
    for (int i = 0; i < index1 && node1 != nullptr; i++)
        node1 = node1->next;
    
    for (int i = 0; i < index2 && node2 != nullptr; i++)
        node2 = node2->next;
    
    if (node1 == nullptr || node2 == nullptr) return false;
    
    int tempData = node1->data;
    node1->data = node2->data;
    node2->data = tempData;
    
    return true;
}

// ============= DOUBLY LINKED LIST UTILITIES IMPLEMENTATIONS =============

DNode* createDNode(int data) {
    DNode* newNode = new DNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertAtHeadD(DNode*& head, int data) {
    DNode* newNode = createDNode(data);
    
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtTailD(DNode*& head, int data) {
    DNode* newNode = createDNode(data);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    DNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void printListD(DNode* head) {
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printListDReverse(DNode* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    
    DNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void deleteListD(DNode*& head) {
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
}

DNode* createDListFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return nullptr;
    }
    
    DNode* head = nullptr;
    int value;
    while (file >> value) {
        insertAtTailD(head, value);
    }
    file.close();
    return head;
}

// ============= QUEUE UTILITIES IMPLEMENTATIONS =============

Queue* createQueue(int capacity) {
    if (capacity <= 0) return nullptr;
    
    Queue* queue = new Queue();
    queue->data = new int[capacity];
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    
    return queue;
}

void destroyQueue(Queue* queue) {
    if (queue == nullptr) return;
    
    delete[] queue->data;
    delete queue;
}

bool isQueueEmpty(Queue* queue) {
    if (queue == nullptr) return true;
    return queue->size == 0;
}

bool isQueueFull(Queue* queue) {
    if (queue == nullptr) return false;
    return queue->size == queue->capacity;
}

bool enqueue(Queue* queue, int value) {
    if (queue == nullptr || isQueueFull(queue)) return false;
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
    return true;
}

bool dequeue(Queue* queue, int& value) {
    if (queue == nullptr || isQueueEmpty(queue)) return false;
    
    value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return true;
}

bool queueFront(Queue* queue, int& value) {
    if (queue == nullptr || isQueueEmpty(queue)) return false;
    
    value = queue->data[queue->front];
    return true;
}

int queueSize(Queue* queue) {
    if (queue == nullptr) return 0;
    return queue->size;
}

void printQueue(Queue* queue) {
    if (queue == nullptr || isQueueEmpty(queue)) {
        cout << "Queue vuota" << endl;
        return;
    }
    
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        cout << queue->data[index] << " ";
    }
    cout << endl;
}

void clearQueue(Queue* queue) {
    if (queue == nullptr) return;
    
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// ============= DYNAMIC STACK UTILITIES IMPLEMENTATIONS =============

DynamicStack* createDynamicStack(int initialCapacity) {
    if (initialCapacity <= 0) initialCapacity = 10;
    
    DynamicStack* stack = new DynamicStack();
    stack->data = new int[initialCapacity];
    stack->top = -1;
    stack->capacity = initialCapacity;
    
    return stack;
}

void destroyDynamicStack(DynamicStack* stack) {
    if (stack == nullptr) return;
    
    delete[] stack->data;
    delete stack;
}

bool pushDynamic(DynamicStack* stack, int value) {
    if (stack == nullptr) return false;
    
    if (stack->top == stack->capacity - 1) {
        int newCapacity = stack->capacity * 2;
        int* newData = new int[newCapacity];
        
        for (int i = 0; i <= stack->top; i++) {
            newData[i] = stack->data[i];
        }
        
        delete[] stack->data;
        stack->data = newData;
        stack->capacity = newCapacity;
    }
    
    stack->data[++stack->top] = value;
    return true;
}

bool popDynamic(DynamicStack* stack, int& value) {
    if (stack == nullptr || stack->top == -1) return false;
    
    value = stack->data[stack->top--];
    return true;
}

bool peekDynamic(DynamicStack* stack, int& value) {
    if (stack == nullptr || stack->top == -1) return false;
    
    value = stack->data[stack->top];
    return true;
}

bool isDynamicStackEmpty(DynamicStack* stack) {
    if (stack == nullptr) return true;
    return stack->top == -1;
}

int dynamicStackSize(DynamicStack* stack) {
    if (stack == nullptr) return 0;
    return stack->top + 1;
}

void printDynamicStack(DynamicStack* stack) {
    if (stack == nullptr || isDynamicStackEmpty(stack)) {
        cout << "Dynamic Stack vuoto" << endl;
        return;
    }
    
    for (int i = 0; i <= stack->top; i++) {
        cout << stack->data[i] << " ";
    }
    cout << endl;
}

// ============= DYNAMIC QUEUE UTILITIES IMPLEMENTATIONS =============

DynamicQueue* createDynamicQueue(int initialCapacity) {
    if (initialCapacity <= 0) initialCapacity = 10;
    
    DynamicQueue* queue = new DynamicQueue();
    queue->data = new int[initialCapacity];
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = initialCapacity;
    
    return queue;
}

void destroyDynamicQueue(DynamicQueue* queue) {
    if (queue == nullptr) return;
    
    delete[] queue->data;
    delete queue;
}

bool enqueueDynamic(DynamicQueue* queue, int value) {
    if (queue == nullptr) return false;
    
    if (queue->size == queue->capacity) {
        int newCapacity = queue->capacity * 2;
        int* newData = new int[newCapacity];
        
        for (int i = 0; i < queue->size; i++) {
            int index = (queue->front + i) % queue->capacity;
            newData[i] = queue->data[index];
        }
        
        delete[] queue->data;
        queue->data = newData;
        queue->front = 0;
        queue->rear = queue->size - 1;
        queue->capacity = newCapacity;
    }
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
    return true;
}

bool dequeueDynamic(DynamicQueue* queue, int& value) {
    if (queue == nullptr || queue->size == 0) return false;
    
    value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return true;
}

bool isDynamicQueueEmpty(DynamicQueue* queue) {
    if (queue == nullptr) return true;
    return queue->size == 0;
}

int dynamicQueueSize(DynamicQueue* queue) {
    if (queue == nullptr) return 0;
    return queue->size;
}

void printDynamicQueue(DynamicQueue* queue) {
    if (queue == nullptr || isDynamicQueueEmpty(queue)) {
        cout << "Dynamic Queue vuota" << endl;
        return;
    }
    
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        cout << queue->data[index] << " ";
    }
    cout << endl;
}

// ============= STACK LINKED LIST UTILITIES IMPLEMENTATIONS =============

LinkedStack* createLinkedStack() {
    LinkedStack* stack = new LinkedStack();
    stack->top = nullptr;
    stack->size = 0;
    return stack;
}

void destroyLinkedStack(LinkedStack* stack) {
    if (stack == nullptr) return;
    
    while (stack->top != nullptr) {
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        delete temp;
    }
    delete stack;
}

void pushLinked(LinkedStack* stack, int value) {
    if (stack == nullptr) return;
    
    StackNode* newNode = new StackNode();
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

bool popLinked(LinkedStack* stack, int& value) {
    if (stack == nullptr || stack->top == nullptr) return false;
    
    value = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    delete temp;
    stack->size--;
    return true;
}

bool peekLinked(LinkedStack* stack, int& value) {
    if (stack == nullptr || stack->top == nullptr) return false;
    
    value = stack->top->data;
    return true;
}

bool isLinkedStackEmpty(LinkedStack* stack) {
    if (stack == nullptr) return true;
    return stack->top == nullptr;
}

int linkedStackSize(LinkedStack* stack) {
    if (stack == nullptr) return 0;
    return stack->size;
}

void printLinkedStack(LinkedStack* stack) {
    if (stack == nullptr || isLinkedStackEmpty(stack)) {
        cout << "Linked Stack vuoto" << endl;
        return;
    }
    
    StackNode* temp = stack->top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ============= QUEUE LINKED LIST UTILITIES IMPLEMENTATIONS =============

LinkedQueue* createLinkedQueue() {
    LinkedQueue* queue = new LinkedQueue();
    queue->front = nullptr;
    queue->rear = nullptr;
    queue->size = 0;
    return queue;
}

void destroyLinkedQueue(LinkedQueue* queue) {
    if (queue == nullptr) return;
    
    while (queue->front != nullptr) {
        QueueNode* temp = queue->front;
        queue->front = queue->front->next;
        delete temp;
    }
    delete queue;
}

void enqueueLinked(LinkedQueue* queue, int value) {
    if (queue == nullptr) return;
    
    QueueNode* newNode = new QueueNode();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (queue->rear == nullptr) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

bool dequeueLinked(LinkedQueue* queue, int& value) {
    if (queue == nullptr || queue->front == nullptr) return false;
    
    value = queue->front->data;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    
    if (queue->front == nullptr) {
        queue->rear = nullptr;
    }
    
    delete temp;
    queue->size--;
    return true;
}

bool isLinkedQueueEmpty(LinkedQueue* queue) {
    if (queue == nullptr) return true;
    return queue->front == nullptr;
}

int linkedQueueSize(LinkedQueue* queue) {
    if (queue == nullptr) return 0;
    return queue->size;
}

void printLinkedQueue(LinkedQueue* queue) {
    if (queue == nullptr || isLinkedQueueEmpty(queue)) {
        cout << "Linked Queue vuota" << endl;
        return;
    }
    
    QueueNode* temp = queue->front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ============= QUEUE WITH TWO STACKS IMPLEMENTATIONS =============

QueueWithStacks* createQueueWithStacks(int capacity) {
    if (capacity <= 0) return nullptr;
    
    QueueWithStacks* queue = new QueueWithStacks();
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    
    if (queue->stack1 == nullptr || queue->stack2 == nullptr) {
        destroyStack(queue->stack1);
        destroyStack(queue->stack2);
        delete queue;
        return nullptr;
    }
    
    return queue;
}

void destroyQueueWithStacks(QueueWithStacks* queue) {
    if (queue == nullptr) return;
    
    destroyStack(queue->stack1);
    destroyStack(queue->stack2);
    delete queue;
}

bool enqueueWithStacks(QueueWithStacks* queue, int value) {
    if (queue == nullptr) return false;
    
    return push(queue->stack1, value);
}

bool dequeueWithStacks(QueueWithStacks* queue, int& value) {
    if (queue == nullptr) return false;
    
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int temp;
            pop(queue->stack1, temp);
            push(queue->stack2, temp);
        }
    }
    
    return pop(queue->stack2, value);
}

bool isQueueWithStacksEmpty(QueueWithStacks* queue) {
    if (queue == nullptr) return true;
    return isEmpty(queue->stack1) && isEmpty(queue->stack2);
}

void printQueueWithStacks(QueueWithStacks* queue) {
    if (queue == nullptr || isQueueWithStacksEmpty(queue)) {
        cout << "Queue with Stacks vuota" << endl;
        return;
    }
    
    Stack* tempStack = createStack(queue->stack1->capacity + queue->stack2->capacity);
    
    for (int i = 0; i <= queue->stack2->top; i++) {
        cout << queue->stack2->data[i] << " ";
        push(tempStack, queue->stack2->data[i]);
    }
    
    for (int i = queue->stack1->top; i >= 0; i--) {
        cout << queue->stack1->data[i] << " ";
    }
    
    cout << endl;
    destroyStack(tempStack);
}

// ============= EXPRESSION EVALUATION UTILITIES IMPLEMENTATIONS =============

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluateSimpleExpression(const char* expr) {
    int result = 0;
    int currentNumber = 0;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isDigit(expr[i])) {
            currentNumber = currentNumber * 10 + (expr[i] - '0');
        } else if (expr[i] == '+') {
            result += currentNumber;
            currentNumber = 0;
        }
    }
    result += currentNumber;
    
    return result;
}

int evaluateExpression(const char* expr) {
    DynamicStack* values = createDynamicStack(100);
    DynamicStack* operators = createDynamicStack(100);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ' ') continue;
        
        if (isDigit(expr[i])) {
            int num = 0;
            while (i < stringLength((char*)expr) && isDigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            pushDynamic(values, num);
        } else if (isOperator(expr[i])) {
            while (!isDynamicStackEmpty(operators)) {
                int topOp;
                peekDynamic(operators, topOp);
                
                if (precedence((char)topOp) >= precedence(expr[i])) {
                    popDynamic(operators, topOp);
                    int val2, val1;
                    popDynamic(values, val2);
                    popDynamic(values, val1);
                    pushDynamic(values, applyOperator(val1, val2, (char)topOp));
                } else {
                    break;
                }
            }
            pushDynamic(operators, expr[i]);
        }
    }
    
    while (!isDynamicStackEmpty(operators)) {
        int op;
        popDynamic(operators, op);
        int val2, val1;
        popDynamic(values, val2);
        popDynamic(values, val1);
        pushDynamic(values, applyOperator(val1, val2, (char)op));
    }
    
    int result;
    popDynamic(values, result);
    
    destroyDynamicStack(values);
    destroyDynamicStack(operators);
    
    return result;
}