#include <iostream>
#include "stack.h"

using namespace std;

// Dichiarazione della funzione calcola
double calcola(Stack *s, double height=0.0); // Funzione ricorsiva per calcolare l'energia
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
double calcola(Stack *s, double height) {
    if (isEmpty(s))  return 0.0; // Caso base: pila vuota
    double topValue = top(s); // Ottieni il valore in cima alla pila
    pop(s); // Rimuovi il valore in cima alla pila
    double restValue = calcola(s, height + 1.5); // Chiamata ricorsiva per il resto
    push(s, topValue); // Ripristina il valore in cima alla pila
    return 9.81 * topValue * height + restValue; // Somma il valore in cima con il resto
}