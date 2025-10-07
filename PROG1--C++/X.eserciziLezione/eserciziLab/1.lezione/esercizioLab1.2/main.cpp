#include <iostream>
using namespace std;

int f(int a, int b, int c);

int main() {
    int a, b, c;

    cout << "Inserisci il primo numero (a): ";
    cin >> a;

    // Richiedi b e c finché b > c
    do {
        cout << "Inserisci il secondo numero (b): ";
        cin >> b;
        cout << "Inserisci il terzo numero (c): ";
        cin >> c;
        if (b >= c) {
            cout << "Errore: b deve essere minore o uguale a c. Riprova."<< endl;
        }
    }while (b > c);

    int risultato = f(a, b, c);
    cout << "Risultato: " << risultato << endl;

    return 0;
}

int f(int a, int b, int c) {
    if (b <= a && a <= c)
        return -1;
    else if (a < b)
        return 1;
    else // a > c
        return 0;
}