#include <iostream>
using namespace std;
const int N = 10;

void fillArray(int numeri[]);
void reverseArray(int numeri[]);
void printRArray( int numeri[]);

int main(){
    int numeri[N];

    fillArray(numeri);
    reverseArray(numeri);
    printRArray(numeri);
    cout << endl;

    return 0;
}

// Leggi i numeri
void fillArray(int numeri[]){
    for (int i = 0; i < N; i++) {
        cout << "Inserisci numero " << i + 1 << ": ";
        cin >> numeri[i];
    }
}

// Reverse dell'array
void reverseArray(int numeri[]){
    for (int i = 0; i < N / 2; i++) {
        int temp = numeri[i];
        numeri[i] = numeri[N - 1 - i];
        numeri[N - 1 - i] = temp;
    }
}

// Stampa array invertito
void printRArray( int numeri[]){
    cout << "\nArray invertito: ";
    for (int i = 0; i < N; i++) {
        cout << numeri[i] << " ";
    }
}