#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <string>
#include <climits>
using namespace std;


// ============= ARRAY UTILITIES =============

// Stampa tutti gli elementi di un array seguiti da uno spazio
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Riempie tutti gli elementi di un array con lo stesso valore specificato
void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        arr[i] = value;
}

// Riempie un array con valori casuali compresi tra min e max (inclusi)
void fillArrayRandom(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++)
        arr[i] = min + rand() % (max - min + 1);
}

// Calcola e restituisce la somma di tutti gli elementi dell'array
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// Calcola la media aritmetica degli elementi dell'array
double avgArray(int arr[], int size) {
    return size > 0 ? (double)sumArray(arr, size) / size : 0;
}

// Trova e restituisce l'elemento massimo dell'array
int maxArray(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Trova e restituisce l'elemento minimo dell'array
int minArray(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

// Copia tutti gli elementi dall'array sorgente a quello di destinazione
void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

// Inverte l'ordine degli elementi nell'array (il primo diventa l'ultimo, etc.)
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Cerca un valore nell'array e restituisce il suo indice, -1 se non trovato
int searchArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value) return i;
    return -1;
}

// Ordina l'array in ordine crescente usando l'algoritmo Bubble Sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Conta quante volte un valore specifico appare nell'array
int countOccurrences(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == value) count++;
    return count;
}

// ============= MATRIX UTILITIES =============

// Stampa una matrice con righe e colonne separate da spazi
void printMatrix(int mat[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

// Riempie tutti gli elementi della matrice con lo stesso valore
void fillMatrix(int mat[][100], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = value;
}

// Calcola la somma di tutti gli elementi della matrice
int sumMatrix(int mat[][100], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += mat[i][j];
    return sum;
}

// Calcola la somma degli elementi sulla diagonale principale (da alto-sinistra a basso-destra)
int sumDiagonal(int mat[][100], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += mat[i][i];
    return sum;
}

// Calcola la somma degli elementi sulla diagonale secondaria (da alto-destra a basso-sinistra)
int sumAntiDiagonal(int mat[][100], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += mat[i][size - 1 - i];
    return sum;
}

// Calcola la trasposta di una matrice (scambia righe e colonne)
void transposeMatrix(int mat[][100], int mat_t[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat_t[j][i] = mat[i][j];
}

// Calcola la somma degli elementi di una specifica riga
int sumRow(int mat[][100], int cols, int row) {
    int sum = 0;
    for (int j = 0; j < cols; j++)
        sum += mat[row][j];
    return sum;
}

// Calcola la somma degli elementi di una specifica colonna
int sumColumn(int mat[][100], int rows, int col) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
        sum += mat[i][col];
    return sum;
}

// Trova l'elemento massimo in tutta la matrice
int maxMatrix(int mat[][100], int rows, int cols) {
    int max = mat[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] > max) max = mat[i][j];
    return max;
}

// Trova l'elemento minimo in tutta la matrice
int minMatrix(int mat[][100], int rows, int cols) {
    int min = mat[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] < min) min = mat[i][j];
    return min;
}

// ============= STRING UTILITIES (Char Arrays) =============

// Calcola la lunghezza di una stringa contando i caratteri fino al terminatore '\0'
int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Copia una stringa sorgente in una stringa destinazione
void copyString(char src[], char dest[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Concatena due stringhe unendole in una stringa risultato
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

// Inverte l'ordine dei caratteri in una stringa
void reverseString(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Confronta due stringhe lessicograficamente, restituisce 0 se uguali, <0 se str1<str2, >0 se str1>str2
int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

// Converte tutti i caratteri minuscoli di una stringa in maiuscoli
void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
}

// Converte tutti i caratteri maiuscoli di una stringa in minuscoli
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
}

// Conta il numero di vocali (a,e,i,o,u maiuscole e minuscole) in una stringa
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

// Conta il numero di consonanti (lettere che non sono vocali) in una stringa
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

// Verifica se una stringa è un palindromo (uguale se letta al contrario)
bool isPalindrome(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i]) return false;
    return true;
}

// ============= NUMERIC UTILITIES =============

// Calcola il fattoriale di n usando la ricorsione (n! = n * (n-1)!)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Calcola l'n-esimo numero di Fibonacci usando la ricorsione
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Calcola base^exp usando la ricorsione (potenza)
int power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 0;
    return base * power(base, exp - 1);
}

// Calcola il Massimo Comune Divisore tra due numeri usando l'algoritmo di Euclide ricorsivo
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Verifica se un numero è primo (divisibile solo per 1 e se stesso)
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Conta il numero di cifre di un numero intero
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

// Calcola la somma delle cifre di un numero usando la ricorsione
int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

// Inverte le cifre di un numero usando la ricorsione (es: 123 -> 321)
int reverseNumber(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNumber(n / 10, rev * 10 + n % 10);
}

int numeroOcco(int arr[10], int n, int i, int numToCount){
    if(i == n) return 0;
    
    if(arr[i] == numToCount) return 1 + numeroOcco(arr, n, i+1, numToCount);
    
    return numeroOcco(arr, n, i+1, numToCount);
}

int maxOfArray(int arr[], int n, int max) {
    if (n == 0) return max;  // caso base: ho esaminato tutto

    if (arr[n-1] > max)
        return maxOfArray(arr, n-1, arr[n-1]);  // aggiorno massimo e continuo
    else
        return maxOfArray(arr, n-1, max);        // massimo invariato, continuo

}
struct Nodo {
    int valore;
    Nodo* sinistro;
    Nodo* destro;
};

int altezzaAlberoRic(Nodo* radice) {
    if (radice == nullptr) return 0;   // caso base corretto
    int hSx = altezzaAlberoRic(radice->sinistro);
    int hDx = altezzaAlberoRic(radice->destro);
    return 1 + (hSx > hDx ? hSx : hDx);
}

int contaNodiRic(Nodo* radice) {
    if(radice == nullptr) return 0;           // caso base ✓

    int sinistri = contaNodiRic(radice->sinistro);  // sottoalbero sx ✓
    int destri = contaNodiRic(radice->destro);      // sottoalbero dx ✓

    return 1 + sinistri + destri;                   // totale ✓
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void permutaRic(int a[], int n, int pos) {
    if (pos == n) {          // caso base: permutacompleta
        printArrayRecursive(a, n);
        return;
    }
    // Funzione helper per generare permutazioni da posizione pos a n-1
    permutaRicHelper(a, n, pos, pos);
}

void permutaRicHelper(int a[], int n, int pos, int current) {
    if (current == n) return;  // ho provato tutti gli elementi per questa posizione
    
    swap(&a[pos], &a[current]);      // scelta
    permutaRic(a, n, pos + 1);       // ricorsione per posizione successiva
    swap(&a[pos], &a[current]);      // backtrack
    
    permutaRicHelper(a, n, pos, current + 1);  // prova elemento successivo
}
// ============= LINKED LIST =============

struct Node {
    int data;
    Node* next;
};

// Crea un nuovo nodo con il valore specificato e lo restituisce
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Inserisce un nuovo nodo all'inizio della lista collegata
void insertAtHead(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Inserisce un nuovo nodo alla fine della lista collegata
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

// Stampa tutti gli elementi della lista collegata
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Conta e restituisce il numero di nodi nella lista collegata
int listLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Cerca un valore nella lista collegata e restituisce true se trovato
bool searchList(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// Calcola la somma di tutti i valori nella lista collegata (versione iterativa)
int sumList(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// Calcola la somma di tutti i valori nella lista collegata (versione ricorsiva)
int sumListRecursive(Node* head) {
    if (head == nullptr) return 0;
    return head->data + sumListRecursive(head->next);
}

// Elimina il primo nodo con il valore specificato dalla lista
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

// Inverte l'ordine dei nodi nella lista collegata usando la ricorsione
Node* reverseListRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// Libera tutta la memoria occupata dalla lista collegata
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============= STRUCTURES =============

struct Persona {
    char name[50];
    int age;
    char email[50];
};

// Stampa le informazioni di una singola persona
void printPersona(Persona p) {
    cout << "Nome: " << p.name << ", Eta: " << p.age << ", Email: " << p.email << endl;
}

// Stampa le informazioni di un array di persone
void printPersonas(Persona arr[], int size) {
    for (int i = 0; i < size; i++)
        printPersona(arr[i]);
}

// Ordina un array di persone per età in ordine crescente usando Bubble Sort
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

// Cerca una persona per nome e restituisce il suo indice, -1 se non trovata
int searchPersona(Persona arr[], int size, char name[]) {
    for (int i = 0; i < size; i++)
        if (compareStrings(arr[i].name, name) == 0) return i;
    return -1;
}

// ============= RECURSIVE UTILITIES =============

// Calcola la somma degli elementi di un array usando la ricorsione
int sumArrayRecursive(int arr[], int size) {
    if (size == 0) return 0;
    return arr[size - 1] + sumArrayRecursive(arr, size - 1);
}

// Stampa gli elementi di un array usando la ricorsione
void printArrayRecursive(int arr[], int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << arr[index] << " ";
    printArrayRecursive(arr, size, index + 1);
}

// Trova l'elemento massimo di un array usando la ricorsione
int maxArrayRecursive(int arr[], int size, int index = 0, int max = INT_MIN) {
    if (index == size) return max;
    if (arr[index] > max) max = arr[index];
    return maxArrayRecursive(arr, size, index + 1, max);
}

// Trova l'elemento minimo di un array usando la ricorsione
int minArrayRecursive(int arr[], int size, int index = 0, int min = INT_MAX) {
    if (index == size) return min;
    if (arr[index] < min) min = arr[index];
    return minArrayRecursive(arr, size, index + 1, min);
}

// Cerca un elemento in un array usando la ricorsione
int searchArrayRecursive(int arr[], int size, int value, int index = 0) {
    if (index == size) return -1;
    if (arr[index] == value) return index;
    return searchArrayRecursive(arr, size, value, index + 1);
}

// Conta le occorrenze di un valore in un array usando la ricorsione
int countOccurrencesRecursive(int arr[], int size, int value, int index = 0) {
    if (index == size) return 0;
    int count = (arr[index] == value) ? 1 : 0;
    return count + countOccurrencesRecursive(arr, size, value, index + 1);
}

int prodottoArrayRic(int arr[], int n){
    if(n == 0) return 1;
    return arr[n-1]*prodottoArrayRic(arr, n-1);
}

// ============= FILE UTILITIES =============

// Legge numeri interi da un file di testo e li memorizza in un array
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

// Scrive gli elementi di un array in un file di testo (uno per riga)
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

// Legge stringhe da un file di testo (una per riga) e le memorizza in un array
void readStringsFromFile(const char* filename, char strings[][100], int& count) {
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

// Scrive un array di stringhe in un file di testo (una per riga)
void writeStringsToFile(const char* filename, char strings[][100], int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return;
    }
    for (int i = 0; i < count; i++)
        file << strings[i] << "\n";
    file.close();
}

// Conta il numero di righe presenti in un file di testo
int countLinesInFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) return 0;
    int count = 0;
    string line;
    while (getline(file, line))
        count++;
    file.close();
    return count;
}

// Aggiunge gli elementi di un array alla fine di un file esistente
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


// ============= MAIN FUNCTION - DEMONSTRAZIONE DI TUTTE LE FUNZIONI =============

int main() {
    cout << "=== DIMOSTRAZIONE FUNZIONI UTILI ===" << endl << endl;
    
    // ============= ARRAY UTILITIES =============
    cout << "--- ARRAY UTILITIES ---" << endl;
    
    int arr[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    cout << "Array originale: ";
    printArray(arr, 10); // Stampa l'array originale
    
    cout << "Somma degli elementi: " << sumArray(arr, 10) << endl; // Calcola la somma
    cout << "Media degli elementi: " << avgArray(arr, 10) << endl; // Calcola la media
    cout << "Elemento massimo: " << maxArray(arr, 10) << endl; // Trova il massimo
    cout << "Elemento minimo: " << minArray(arr, 10) << endl; // Trova il minimo
    
    cout << "Indice dell'elemento 7: " << searchArray(arr, 10, 7) << endl; // Cerca elemento
    cout << "Occorrenze dell'elemento 5: " << countOccurrences(arr, 10, 5) << endl; // Conta occorrenze
    
    int arrCopy[10];
    copyArray(arr, arrCopy, 10); // Copia l'array
    cout << "Array copiato: ";
    printArray(arrCopy, 10);
    
    reverseArray(arrCopy, 10); // Inverte l'array
    cout << "Array invertito: ";
    printArray(arrCopy, 10);
    
    sortArray(arr, 10); // Ordina l'array
    cout << "Array ordinato: ";
    printArray(arr, 10);
    
    fillArray(arrCopy, 10, 42); // Riempie con un valore specifico
    cout << "Array riempito con 42: ";
    printArray(arrCopy, 10);
    
    fillArrayRandom(arrCopy, 10, 1, 20); // Riempie con valori casuali
    cout << "Array con valori casuali (1-20): ";
    printArray(arrCopy, 10);
    
    cout << endl;
    
    // ============= MATRIX UTILITIES =============
    cout << "--- MATRIX UTILITIES ---" << endl;
    
    int matrix[100][100];
    int rows = 3, cols = 3;
    
    // Riempie la matrice con valori incrementali
    int value = 1;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            matrix[i][j] = value++;
    
    cout << "Matrice 3x3:" << endl;
    printMatrix(matrix, rows, cols); // Stampa la matrice
    
    cout << "Somma di tutti gli elementi: " << sumMatrix(matrix, rows, cols) << endl;
    cout << "Somma diagonale principale: " << sumDiagonal(matrix, rows) << endl;
    cout << "Somma diagonale secondaria: " << sumAntiDiagonal(matrix, rows) << endl;
    cout << "Somma prima riga: " << sumRow(matrix, cols, 0) << endl;
    cout << "Somma prima colonna: " << sumColumn(matrix, rows, 0) << endl;
    cout << "Elemento massimo: " << maxMatrix(matrix, rows, cols) << endl;
    cout << "Elemento minimo: " << minMatrix(matrix, rows, cols) << endl;
    
    int matrixT[100][100];
    transposeMatrix(matrix, matrixT, rows, cols); // Calcola la trasposta
    cout << "Matrice trasposta:" << endl;
    printMatrix(matrixT, cols, rows);
    
    fillMatrix(matrix, rows, cols, 99); // Riempie con un valore
    cout << "Matrice riempita con 99:" << endl;
    printMatrix(matrix, rows, cols);
    
    cout << endl;
    
    // ============= STRING UTILITIES =============
    cout << "--- STRING UTILITIES ---" << endl;
    
    char str1[100] = "Ciao";
    char str2[100] = "Mondo";
    char result[200];
    
    cout << "Stringa 1: '" << str1 << "'" << endl;
    cout << "Lunghezza stringa 1: " << stringLength(str1) << endl; // Calcola lunghezza
    
    copyString(str1, result); // Copia stringa
    cout << "Stringa copiata: '" << result << "'" << endl;
    
    concatenateStrings(str1, str2, result); // Concatena stringhe
    cout << "Stringhe concatenate: '" << result << "'" << endl;
    
    reverseString(result); // Inverte stringa
    cout << "Stringa invertita: '" << result << "'" << endl;
    
    cout << "Confronto 'Ciao' vs 'Mondo': " << compareStrings(str1, str2) << endl;
    
    char testCase[100] = "Programmazione";
    cout << "Stringa originale: '" << testCase << "'" << endl;
    
    toUpperCase(testCase); // Converte in maiuscolo
    cout << "In maiuscolo: '" << testCase << "'" << endl;
    
    toLowerCase(testCase); // Converte in minuscolo
    cout << "In minuscolo: '" << testCase << "'" << endl;
    
    char vowelTest[100] = "Programmazione";
    cout << "Vocali in 'Programmazione': " << countVowels(vowelTest) << endl;
    cout << "Consonanti in 'Programmazione': " << countConsonants(vowelTest) << endl;
    
    char palindrome[100] = "radar";
    cout << "'" << palindrome << "' è palindromo? " << (isPalindrome(palindrome) ? "Si" : "No") << endl;
    
    cout << endl;
    
    // ============= NUMERIC UTILITIES =============
    cout << "--- NUMERIC UTILITIES ---" << endl;
    
    cout << "Fattoriale di 5: " << factorial(5) << endl; // Calcola fattoriale
    cout << "7° numero di Fibonacci: " << fibonacci(7) << endl; // Calcola Fibonacci
    cout << "2^8: " << power(2, 8) << endl; // Calcola potenza
    cout << "GCD(48, 18): " << gcd(48, 18) << endl; // Calcola MCD
    cout << "17 è primo? " << (isPrime(17) ? "Si" : "No") << endl; // Verifica se primo
    cout << "Cifre in 12345: " << countDigits(12345) << endl; // Conta cifre
    cout << "Somma cifre di 12345: " << sumDigits(12345) << endl; // Somma cifre
    cout << "12345 invertito: " << reverseNumber(12345) << endl; // Inverte numero
    
    cout << endl;
    
    // ============= LINKED LIST =============
    cout << "--- LINKED LIST ---" << endl;
    
    Node* head = nullptr;
    
    insertAtHead(head, 10); // Inserisce in testa
    insertAtHead(head, 20);
    insertAtTail(head, 5); // Inserisce in coda
    insertAtTail(head, 15);
    
    cout << "Lista creata: ";
    printList(head); // Stampa la lista
    
    cout << "Lunghezza lista: " << listLength(head) << endl; // Calcola lunghezza
    cout << "Cerca 15: " << (searchList(head, 15) ? "Trovato" : "Non trovato") << endl;
    cout << "Somma elementi (iterativa): " << sumList(head) << endl;
    cout << "Somma elementi (ricorsiva): " << sumListRecursive(head) << endl;
    
    deleteNode(head, 20); // Elimina nodo
    cout << "Lista dopo eliminazione di 20: ";
    printList(head);
    
    head = reverseListRecursive(head); // Inverte lista ricorsivamente
    cout << "Lista invertita: ";
    printList(head);
    
    deleteList(head); // Libera memoria
    cout << "Lista eliminata" << endl;
    
    cout << endl;
    
    // ============= STRUCTURES =============
    cout << "--- STRUCTURES ---" << endl;
    
    Persona persone[3];
    
    // Inizializza array di persone
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
    printPersonas(persone, 3); // Stampa array di persone
    
    sortPersonasByAge(persone, 3); // Ordina per età
    cout << "\nPersone ordinate per età:" << endl;
    printPersonas(persone, 3);
    
    char nome[50] = "Anna";
    int indice = searchPersona(persone, 3, nome); // Cerca persona
    cout << "\nIndice di Anna: " << indice << endl;
    
    cout << endl;
    
    // ============= RECURSIVE UTILITIES =============
    cout << "--- RECURSIVE UTILITIES ---" << endl;
    
    int testArr[5] = {1, 2, 3, 4, 5};
    
    cout << "Array per test ricorsivi: ";
    printArrayRecursive(testArr, 5); // Stampa ricorsivamente
    
    cout << "Somma ricorsiva: " << sumArrayRecursive(testArr, 5) << endl;
    cout << "Massimo ricorsivo: " << maxArrayRecursive(testArr, 5) << endl;
    cout << "Minimo ricorsivo: " << minArrayRecursive(testArr, 5) << endl;
    cout << "Cerca 3 ricorsivamente: " << searchArrayRecursive(testArr, 5, 3) << endl;
    cout << "Conta occorrenze di 3 ricorsivamente: " << countOccurrencesRecursive(testArr, 5, 3) << endl;
    
    cout << endl;
    
    // ============= FILE UTILITIES =============
    cout << "--- FILE UTILITIES ---" << endl;
    
    // Scrive array su file
    int fileArray[5] = {10, 20, 30, 40, 50};
    writeToFile("test_numbers.txt", fileArray, 5);
    cout << "Scritti numeri su file 'test_numbers.txt'" << endl;
    
    // Conta righe nel file
    cout << "Righe nel file: " << countLinesInFile("test_numbers.txt") << endl;
    
    // Legge da file
    int readArray[10];
    int readSize;
    readFromFile("test_numbers.txt", readArray, readSize);
    cout << "Letti " << readSize << " numeri dal file: ";
    printArray(readArray, readSize);
    
    // Aggiunge al file
    int appendArray[2] = {60, 70};
    appendToFile("test_numbers.txt", appendArray, 2);
    cout << "Aggiunti numeri al file" << endl;
    
    // Test con stringhe
    char stringhe[3][100] = {"Prima riga", "Seconda riga", "Terza riga"};
    writeStringsToFile("test_strings.txt", stringhe, 3);
    cout << "Scritte stringhe su file 'test_strings.txt'" << endl;
    
    char stringheLette[10][100];
    int stringCount;
    readStringsFromFile("test_strings.txt", stringheLette, stringCount);
    cout << "Lette " << stringCount << " stringhe dal file:" << endl;
    for(int i = 0; i < stringCount; i++)
        cout << "- " << stringheLette[i] << endl;
    
    cout << "\n=== FINE DIMOSTRAZIONE ===" << endl;
    
    return 0;
}