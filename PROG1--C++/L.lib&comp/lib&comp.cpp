/******************************************************************************
 * GUIDA ALLA COMPILAZIONE MULTI-FILE: IL MODELLO "OPACITY" (PROCEDURALE)
 ******************************************************************************
 *
 * Questo modello divide il codice in tre parti:
 * 1. L'Interfaccia (.h): Mostra le funzioni ma nasconde i dettagli dei dati.
 * 2. L'Implementazione (.cpp): Definisce i dati e la logica delle funzioni.
 * 3. Il Client (main.cpp): Utilizza la libreria senza conoscerne l'interno.
 *
 * ----------------------------------------------------------------------------
 * 1. IL FILE HEADER: "stack.h"
 * --------------------------------------------------------------------------*/

#ifndef STACK_H
#define STACK_H

// FORWARD DECLARATION: 
// Diciamo che esiste una struct Stack, ma non diciamo cosa c'è dentro.
// Questo impedisce all'utente di accedere direttamente a 's->top'.
struct Stack;

// PROTOTIPI DELLE FUNZIONI
Stack* init();
void push(Stack *s, double value);
double pop(Stack *s);
double top(Stack *s);
int isEmpty(Stack *s);
void freeStack(Stack *s);
void printStack(Stack *s);

#endif

/*-----------------------------------------------------------------------------
 * 2. IL FILE DI IMPLEMENTAZIONE: "stack.cpp"
 * --------------------------------------------------------------------------*/

#include "stack.h"  // Include la sua interfaccia
#include <cstdlib>
#include <iostream>

using namespace std;

// DEFINIZIONE PRIVATA DEI DATI
// Queste strutture sono visibili solo dentro questo file.
struct StackNode {
    double value;
    StackNode *next;
};

struct Stack {
    StackNode *top; // Il "vero" corpo della struttura dichiarata nell'header
};

// IMPLEMENTAZIONE DELLE FUNZIONI
Stack* init() {
    Stack *s = new Stack;
    s->top = nullptr;
    return s;
}

void push(Stack *s, double value) {
    StackNode *newNode = new StackNode;
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
}

// ... (seguono le altre funzioni: pop, top, isEmpty, freeStack, printStack)

/*-----------------------------------------------------------------------------
 * 3. IL FILE MAIN: "main.cpp"
 * --------------------------------------------------------------------------*/

#include <iostream>
#include "stack.h" // Importante: usiamo solo l'header

int main() {
    Stack *miaPila = init(); // Creazione tramite interfaccia
    
    push(miaPila, 10.5);
    push(miaPila, 20.3);
    
    printStack(miaPila);
    
    std::cout << "Elemento rimosso: " << pop(miaPila) << std::endl;
    
    freeStack(miaPila); // Pulizia della memoria
    return 0;
}

/*-----------------------------------------------------------------------------
 * 4. COME COMPILARE QUESTO PROGETTO
 * ----------------------------------------------------------------------------
 * Per unire correttamente stack.cpp e main.cpp, usa il compilatore così:
 *
 *  *
 * COMANDO G++:
 * $ g++ main.cpp stack.cpp -o programma_stack
 *
 * COSA ACCADE:
 * 1. Il compilatore legge main.cpp e "si fida" dell'header stack.h.
 * 2. Il compilatore legge stack.cpp e genera il codice binario per le funzioni.
 * 3. Il linker unisce i due file risolvendo gli indirizzi delle funzioni.
 *
 * VANTAGGI DI QUESTO FORMATO:
 * - Se cambi la struttura interna dello Stack (es. da lista a array), 
 * non devi cambiare una sola riga del main.cpp.
 * - Il main.cpp non può "rompere" lo stack accedendo a s->top direttamente.
 *****************************************************************************/