#include <iostream>
using namespace std;

/*

    Scrivere un programma che prende prende in input un double.
    Poi lo raddoppia usando un puntatore a quella variabile (double*).
    E poi lo divide per 5 usando un puntatore alpuntatore (double**)
    E infine lo stampa.

*/

int main() {
    double x;
    cout << "Inserisci un numero double: ";
    cin >> x;

    double* px = &x;
    *px *= 2; // raddoppia x usando il puntatore

    double** ppx = &px;
    **ppx /= 5; // divide x per 5 usando il puntatore al puntatore

    cout << "Risultato finale: " << x << endl;

    return 0;
}
