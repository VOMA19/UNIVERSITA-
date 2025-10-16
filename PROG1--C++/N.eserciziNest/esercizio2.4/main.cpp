#include <iostream>
using namespace std;
const int N = 10;

int main(){
    int numeri[N];

    // Leggi i numeri
    for (int i = 0; i < N; i++) {
        cout << "Inserisci numero " << i + 1 << ": ";
        cin >> numeri[i];
    }

    // Reverse dell'array
    for (int i = 0; i < N / 2; i++) {
        int temp = numeri[i];
        numeri[i] = numeri[N - 1 - i];
        numeri[N - 1 - i] = temp;
    }

    // Stampa array invertito
    cout << "\nArray invertito: ";
    for (int i = 0; i < N; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;

    return 0;
}