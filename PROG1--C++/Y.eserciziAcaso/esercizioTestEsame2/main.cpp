#include <iostream>
#include <fstream>
using namespace std;

void printArray(int arr[], int n);
int maxArray(int arr[], int n);
int minArray(int arr[], int n);
double avgArray(int arr[], int n);
int countOccurrences(int arr[], int n, int value);
int countAboveThresholdRecursive(int arr[], int n, int soglia);
void sortArray(int arr[], int n); // bubble sort
void readFromFile(const char* filename, int arr[], int& size);
int* allocArray(int size);

int main(){
    char fileName[50];
    int n = 100;
    cout << "inserisci il nome del file da cui leggere i voti: ";
    cin >> fileName;
    int* voti = allocArray(n);
    readFromFile(fileName, voti, n);
    printArray(voti, n);
    return 0;
}

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

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* allocArray(int size) {
    if (size <= 0) return nullptr;
    return new int[size];
}