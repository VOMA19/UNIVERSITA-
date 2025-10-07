#include <iostream>
using namespace std;
int main() {
    int a, n;

    cout << "Inserisci il valore di a: ";
    cin >> a;

    do {
        cout << "Inserisci il valore di n (n >= 1): ";
        cin >> n;
        if (n < 1) {
            cout << "n deve essere maggiore o uguale a 1. Riprova.\n";
        }
    } while (n < 1);

    int potenza = 1;
    for (int i = 1; i <= n; ++i) {
        potenza *= a;
        cout << potenza;
        if (i < n) cout << ", ";
    }
    cout << endl;

    return 0;
}