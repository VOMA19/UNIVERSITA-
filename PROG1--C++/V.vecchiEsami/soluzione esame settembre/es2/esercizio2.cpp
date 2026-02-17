#include <iostream>
#include "stack.h"

using namespace std;

// Dichiarazione della funzione calcola

// Dichiarazione della funzione calcola

int main() {
    Stack *s = init();
    double value = 0.0;
    
    // Esempio di utilizzo della pila
    push(s, 10.0);
    push(s, 15.0);
    push(s, 20.0);

    printStack(s); // Stampa la pila prima del calcolo
    value = calcola(s); // Calcola l'energia usando la pila
    printStack(s); // Stampa la pila dopo il calcolo
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);
    cout << "-------------------------" << endl;
    s = init();
    // Esempio di utilizzo della pila
    push(s, 10.0);
    printStack(s); // Stampa la pila prima del calcolo
    value = calcola(s); // Calcola l'energia usando la pila
    printStack(s); // Stampa la pila dopo il calcolo
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);
    cout << "-------------------------" << endl;
    s = init();
    // Esempio di utilizzo della pila
    printStack(s); // Stampa la pila prima del calcolo
    value = calcola(s); // Calcola l'energia usando la pila
    printStack(s); // Stampa la pila dopo il calcolo
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);

    return 0;
}

// Definizione della funzione calcola
