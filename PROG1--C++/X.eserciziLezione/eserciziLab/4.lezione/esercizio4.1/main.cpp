#include <iostream>
using namespace std;

int divisione(int dividendo, int divisore);

int main(){
    int a, b;
    
    cout << "Inserisci il dividendo: ";
    cin >> a;
    cout << "Inserisci il divisore: ";
    cin >> b;
    
    if (b == 0) {
        cout << "Errore: divisione per zero!" << endl;
    } else {
        cout << "Risultato: " << divisione(a, b) << endl;
    }
    
    return 0;
}


int divisione(int dividendo, int divisore) {
    if (dividendo < divisore) {
        return 0;
    }
    return 1 + divisione(dividendo - divisore, divisore);
}