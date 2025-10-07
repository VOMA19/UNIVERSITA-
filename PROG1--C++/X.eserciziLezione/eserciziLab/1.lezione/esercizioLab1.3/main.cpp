#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Inserisci un carattere alfabetico: ";
    cin >> ch;

    // Converti il carattere in minuscolo per semplificare il controllo
    ch = tolower(ch);


    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        cout << "Il carattere è una vocale." << endl;
    } else {
        cout << "Il carattere è una consonante." << endl;
    }

    return 0;
}