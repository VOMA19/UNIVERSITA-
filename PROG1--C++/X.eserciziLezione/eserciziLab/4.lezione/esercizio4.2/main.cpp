#include <iostream>
using namespace std;

void toBinary(int n);

int main() {
    int num;
    cout << "Inserisci un numero intero positivo: ";
    cin >> num;
    
    if (num == 0) {
        cout << "0" << endl;
    } else {
        cout << "Rappresentazione binaria: ";
        toBinary(num);
        cout << endl;
    }
    
    return 0;
}

void toBinary(int n) {
    if (n > 1) {
        toBinary(n / 2);
    }
    cout << (n % 2);
}