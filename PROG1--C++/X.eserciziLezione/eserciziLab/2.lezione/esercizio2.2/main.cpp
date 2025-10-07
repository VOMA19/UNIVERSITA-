#include <iostream>
using namespace std;

int main() {
    int numero;

    do {
        cout << "Inserisci un numero intero positivo: ";
        cin >> numero;
        if (numero <= 0) {
            cout << "Errore: il numero deve essere positivo." << endl;
        }
    } while (numero <= 0);

    int cifre = 0;
    int temp = numero;
    do {
        temp /= 10;
        cifre++;
    } while (temp != 0);

    cout << "Il numero " << numero << " è composto da " << cifre << " cifre." << endl;

    return 0;
}