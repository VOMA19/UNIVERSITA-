#include <iostream>
using namespace std;

int sommaPari(int n);


int main() {
    int n;
    cout << "Inserisci un numero intero positivo: ";
    cin >> n;
    
    cout << "La somma di tutti i numeri pari fino a " << n << " è: " << sommaPari(n) << endl;
    
    return 0;
}


int sommaPari(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n % 2 == 0) {
        return n + sommaPari(n - 1);
    } else {
        return sommaPari(n - 1);
    }
}