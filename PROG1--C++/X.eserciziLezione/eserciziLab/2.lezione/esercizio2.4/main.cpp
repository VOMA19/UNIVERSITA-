#include <iostream>
using namespace std;


/*
    stampare una piramide di asterischi di altezza n inserita dall'utente
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
        // Stampa la parte sinistra della piramide di asterischi
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
