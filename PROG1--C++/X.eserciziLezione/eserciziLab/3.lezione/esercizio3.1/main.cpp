#include <iostream>
using namespace std;

bool isLowercaseLetter(char c);
void printUppercase(char c);

int main() {
    char ch;
    cout << "Inserisci un carattere: ";
    cin >> ch;

    if (isLowercaseLetter(ch)) {
        printUppercase(ch);
    } else {
        cout << "Il carattere non è una lettera minuscola." << endl;
    }

    return 0;
}

// Funzione che controlla se il carattere è una lettera minuscola
bool isLowercaseLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

// Funzione che converte e stampa il carattere maiuscolo
void printUppercase(char c) {
    char upper = c - ('a' - 'A');
    cout << "Il carattere maiuscolo è: " << upper << endl;
}
