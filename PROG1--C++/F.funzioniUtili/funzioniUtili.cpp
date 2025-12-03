#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

// ============= FUNCTION DECLARATIONS =============

// ARRAY UTILITIES
void printArray(int arr[], int size);                    // Stampa tutti gli elementi di un array su una riga
void fillArray(int arr[], int size, int value);          // Riempie un array con un valore specifico
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

// FILE UTILITIES
void readFromFile(const char* filename, int arr[], int& size); // Legge numeri interi da file e li memorizza in array
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

// ============= FILE UTILITIES =============

void readFromFile(const char* filename, int arr[], int& size) {
    ifstream file(filename);
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
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
        file << arr[i] << "\n";
    file.close();
}

void readStringFromFile(const char* filename, char strings[][100], int& count) {
    ifstream file(filename);
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
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < count; i++)
        file << strings[i] << "\n";
    file.close();
}

int countLinesInFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) return 0;
    int count = 0;
    char line[1000];
    while (file.getline(line, 1000))
        count++;
    file.close();
    return count;
}

void appendToFile(const char* filename, int arr[], int size) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
        file << arr[i] << "\n";
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


    