#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

// ============= FUNCTION DECLARATIONS =============

// ARRAY UTILITIES
void printArray(int arr[], int size);
void fillArray(int arr[], int size, int value);
void fillArrayRandom(int arr[], int size, int min, int max);
int sumArray(int arr[], int size);
double avgArray(int arr[], int size);
int maxArray(int arr[], int size);
int minArray(int arr[], int size);
void copyArray(int src[], int dest[], int size);
void reverseArray(int arr[], int size);
int searchArray(int arr[], int size, int value);
void sortArray(int arr[], int size);
int countOccurrences(int arr[], int size, int value);

// MATRIX UTILITIES
void printMatrix(int mat[][100], int rows, int cols);
void fillMatrix(int mat[][100], int rows, int cols, int value);
int sumMatrix(int mat[][100], int rows, int cols);
int sumDiagonal(int mat[][100], int size);
int sumAntiDiagonal(int mat[][100], int size);
void transposeMatrix(int mat[][100], int mat_t[][100], int rows, int cols);
int sumRow(int mat[][100], int cols, int row);
int sumColumn(int mat[][100], int rows, int col);
int maxMatrix(int mat[][100], int rows, int cols);
int minMatrix(int mat[][100], int rows, int cols);

// STRING UTILITIES (Char Arrays)
int stringLength(char str[]);
void copyString(char src[], char dest[]);
void concatenateStrings(char str1[], char str2[], char result[]);
void reverseString(char str[]);
int compareStrings(char str1[], char str2[]);
void toUpperCase(char str[]);
void toLowerCase(char str[]);
int countVowels(char str[]);
int countConsonants(char str[]);
bool isPalindrome(char str[]);

// NUMERIC UTILITIES
int factorial(int n);
int fibonacci(int n);
int power(int base, int exp);
int gcd(int a, int b);
bool isPrime(int n);
int countDigits(int n);
int sumDigits(int n);
int reverseNumber(int n, int rev = 0);
int numeroOcco(int arr[10], int n, int i, int numToCount);
int maxOfArray(int arr[], int n, int max);

// TREE UTILITIES
struct Nodo {
    int valore;
    Nodo* sinistro;
    Nodo* destro;
};
int altezzaAlberoRic(Nodo* radice);
int contaNodiRic(Nodo* radice);

// PERMUTATION UTILITIES
void swap(int *a, int *b);
void permutaRic(int a[], int n, int pos);
void permutaRicHelper(int a[], int n, int pos, int current);

// LINKED LIST UTILITIES
struct Node {
    int data;
    Node* next;
};
Node* createNode(int data);
void insertAtHead(Node*& head, int data);
void insertAtTail(Node*& head, int data);
void printList(Node* head);
int listLength(Node* head);
bool searchList(Node* head, int value);
int sumList(Node* head);
int sumListRecursive(Node* head);
void deleteNode(Node*& head, int value);
Node* reverseListRecursive(Node* head);
void deleteList(Node*& head);

// STRUCTURE UTILITIES
struct Persona {
    char name[50];
    int age;
    char email[50];
};
void printPersona(Persona p);
void printPersonas(Persona arr[], int size);
void sortPersonasByAge(Persona arr[], int size);
int searchPersona(Persona arr[], int size, char name[]);

// RECURSIVE UTILITIES
int sumArrayRecursive(int arr[], int size);
void printArrayRecursive(int arr[], int size, int index = 0);
int maxArrayRecursive(int arr[], int size, int index = 0, int max = -2147483648);
int minArrayRecursive(int arr[], int size, int index = 0, int min = 2147483647);
int searchArrayRecursive(int arr[], int size, int value, int index = 0);
int countOccurrencesRecursive(int arr[], int size, int value, int index = 0);
int prodottoArrayRic(int arr[], int n);

// FILE UTILITIES
void readFromFile(const char* filename, int arr[], int& size);
void writeToFile(const char* filename, int arr[], int size);
void readStringFromFile(const char* filename, char strings[][100], int& count);
void writeStringToFile(const char* filename, char strings[][100], int count);
int countLinesInFile(const char* filename);
void appendToFile(const char* filename, int arr[], int size);

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