#include <iostream>
#include "stack.h"

using namespace std;

// Dichiarazione della funzione calcola con parametro di default per il livello (altezza)
// level = 0 indica il disco in cima alla pila (altezza 0m)
double calcola(Stack *s, int level = 0);

int main() {
    Stack *s = init();
    double value = 0.0;
    
    // Esempio 1: pesi 10, 15, 20 kg
    push(s, 20.0);
    push(s, 15.0);
    push(s, 10.0);

    printStack(s); 
    value = calcola(s); 
    printStack(s); 
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);
    
    cout << "-------------------------" << endl;
    
    // Esempio 2: peso 10 kg
    s = init();
    push(s, 10.0);
    printStack(s); 
    value = calcola(s); 
    printStack(s); 
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);
    
    cout << "-------------------------" << endl;
    
    // Esempio 3: stack vuoto
    s = init();
    printStack(s); 
    value = calcola(s); 
    printStack(s); 
    cout << "Energia calcolata: " << value << endl;
    freeStack(s);

    return 0;
}

// Definizione della funzione calcola
double calcola(Stack *s, int level) {
    // Caso base: se lo stack è vuoto, l'energia è 0 [cite: 11]
    if (isEmpty(s)) {
        return 0.0;
    }

    // Estraiamo il peso corrente per processarlo 
    double m = pop(s);
    
    // Calcoliamo l'altezza h basandoci sulla posizione (level)
    // Ogni disco aggiunge 1.5m di altezza rispetto al precedente [cite: 7]
    // Il primo disco (in cima) è ad altezza 0 [cite: 11]
    double g = 9.81;
    double h = level * 1.5;
    double energia_corrente = m * g * h;

    // Chiamata ricorsiva per i dischi sottostanti incrementando il livello [cite: 14]
    double energia_totale_sottostante = calcola(s, level + 1);

    // Reinseriamo il peso per lasciare lo stack inalterato come richiesto 
    push(s, m);

    // Restituiamo la somma dell'energia del disco attuale e di quelli sotto [cite: 13]
    return energia_corrente + energia_totale_sottostante;
}