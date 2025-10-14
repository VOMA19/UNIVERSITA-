#include <iostream>
using namespace std;


/*
    Scrivere un programma che, prendendo in
    input un numero N intero, stampa la piramide
    di potenze di 2 alta N.
*/

void stampaTriangoloPot(int n);

int main() {

    int n = 0;
    cout << "Inserisci un numero intero positivo: ";
    cin >> n;

    cout << endl;

    stampaTriangoloPot(n);
    
    cout << endl;
    return 0;
}

void stampaTriangoloPot(int n) {
    for (int i = 0; i < n; i++) {
        // Stampa spazi per centrare la piramide
        for (int s = 0; s < n - i - 1; s++) {
            cout << "  ";
        }
        // Stampa la parte sinistra (decrescente)
        for (int j = i; j > 0; j--) {
            cout << (1 << j) << " ";
        }
        // Stampa il centro e la parte destra (crescente)
        for (int j = 0; j <= i; j++) {
            cout << (1 << j) << " ";
        }
        cout << endl;
    }
}