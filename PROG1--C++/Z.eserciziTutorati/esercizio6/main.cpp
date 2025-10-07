#include <iostream>
using namespace std;

int calcolaRisultato(int num1, int num2, char op);

/*

    Scrivere un programma che implementi una
    calcolatrice per numeri interi, ossia che
    prenda in ingresso due numeri e un carattere
    ('+','-','*','/') e che calcoli poi il risultato
    dell'operazione

*/

int main() {
    int num1, num2;
    char op;
    cout << "Inserisci il primo numero: ";
    cin >> num1;
    cout << "Inserisci il secondo numero: ";
    cin >> num2;
    cout << "Inserisci l'operazione (+, -, *, /): ";
    cin >> op;

    int risultato = calcolaRisultato(num1, num2, op);

    if (risultato != 0) {
        cout << "Risultato: " << risultato << endl;
    }

    return 0;
}

int calcolaRisultato(int num1, int num2, char op){
    int risultato = 0;
    switch(op) {
        case '+':
            risultato = num1 + num2;
            break;
        case '-':
            risultato = num1 - num2;
            break;
        case '*':
            risultato = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Errore: divisione per zero!" << endl;
            } else {
                risultato = num1 / num2;
            }
            break;
        default:
            cout << "Operazione non valida!" << endl;
    }

    return risultato;
}