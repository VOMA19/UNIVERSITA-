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
    int value, soglia;
    int n = 100;
    cout << "inserisci il nome del file da cui leggere i voti: ";
    cin >> fileName;
    int* voti = allocArray(n);
    readFromFile(fileName, voti, n);
    printArray(voti, n);
    int max = maxArray(voti, n);
    int min = minArray(voti, n);
    double avg = avgArray(voti, n);
    cout << "il voto massimo e' stato: " << max <<endl;
    cout << "il voto minimo e' stato: " << min <<endl;
    cout << "il voto medio e' stato: " << avg <<endl;
    cout << "di quale voto vuoi sapere il numero di occorrenze? ";
    cin >> value;
    int occ = countOccurrences(voti, n, value);
    cout << "il numero di occorrenze del voto: " << value << " e': " << occ <<endl;
    cout << "sopra che voto vuoi sapere quanti hanno superato? ";
    cin >> soglia;
    int numOcc = countAboveThresholdRecursive(voti, n, soglia);
    cout << "il numero di persone che hanno superato il voto: " << soglia << " e': " << numOcc <<endl;
    sortArray(voti, n);
    delete[] voti;
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

int maxArray(int arr[], int n){
    int max = arr[0];

    for (int i = 0; i < n; i++)
        if(arr[i] > max) max = arr[i];

    return max;

}

int minArray(int arr[], int n){
    int min = arr[0];

    for (int i = 0; i < n; i++)
        if(arr[i] < min) min = arr[i];

    return min;
}

double avgArray(int arr[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}


int countOccurrences(int arr[], int n, int value){
    int occ = 0;
    for (int i = 0; i < n; i++)
        if(arr[i] == value) occ++;
    
    return occ;
}

int countAboveThresholdRecursive(int arr[], int n, int soglia){
    if (n == 0) return 0;
    int countHere = (arr[n-1] >= soglia) ? 1 : 0;
    return countHere + countAboveThresholdRecursive(arr, n-1, soglia);
}


void sortArray(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printArray(arr, n);
}
