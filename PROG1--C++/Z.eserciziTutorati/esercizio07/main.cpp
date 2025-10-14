#include <iostream>
using namespace std;

/*

    Riprendere la calcolatrice di prima, ma ora una volta fatta la prima operazione, il programma continua a richiedere un nuovo 
    operatore e un nuovo numero fintanto che non viene inserito il simbolo $.
    Ogni volta il programma esegue l'operazione usando come primo operando il risultato ottenuto precedentemente e come secondo il
    nuovo numero.

*/

char leggiOperatore();
int leggiNumero();
void mostraRisultato(int risultato);
int calcolaRisultato(int num1, int num2, char op);

int main() {
    int num1, num2;
    char op;
    cout << "Inserisci il primo numero: ";
    cin >> num1;
    int risultato = num1;

    do {
        op = leggiOperatore();
        if (op == '$') {
            break;
        }
        num2 = leggiNumero();
        risultato = calcolaRisultato(risultato, num2, op);
        mostraRisultato(risultato);
    } while (true);

    cout << "Calcolatrice terminata. Risultato finale: " << risultato << endl;
    return 0;
}

// Funzione per leggere l'operatore
char leggiOperatore() {
    char op;
    cout << "Inserisci l'operazione (+, -, *, /) oppure $ per terminare: ";
    cin >> op;
    return op;
}

// Funzione per leggere un numero
int leggiNumero() {
    int num;
    cout << "Inserisci il prossimo numero: ";
    cin >> num;
    return num;
}

// Funzione per mostrare il risultato
void mostraRisultato(int risultato) {
    cout << "Risultato: " << risultato << endl;
}

// Funzione per calcolare il risultato
int calcolaRisultato(int num1, int num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num2 != 0 ? num1 / num2 : 0;
        default: return num1;
    }
}
