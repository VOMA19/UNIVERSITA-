#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

struct Nodo {
    int val;      
    Nodo* next;
};

// ============================================================================
// DICHIARAZIONE DELLA FUNZIONE CALCOLA
// ============================================================================
Nodo* calcola(int N);

// ============================================================================
// DEFINIZIONE DELLA FUNZIONE RICORSIVA CALCOLA (Senza cicli iterativi)
// ============================================================================
Nodo* calcola(int N) {
    // Caso base: se N è minore o uguale a zero, la lista è vuota (nullptr)
    if (N <= 0) {
        return nullptr;
    }
    
    // Allocazione dinamica del nodo corrente con std::nothrow (stile docente)
    Nodo* head = new (std::nothrow) Nodo;
    if (!head) {
        std::cerr << "Errore: allocazione di memoria fallita." << std::endl;
        return nullptr;
    }
    
    // Calcolo del valore dell'i-esimo termine per i = N - 1
    // Formula di Taylor / Numeri Triangolari data: T(i) = i * (i + 1) / 2
    int i = N - 1;
    head->val = i * (i + 1) / 2;
    
    // Chiamata ricorsiva: il puntatore 'next' punta al risultato di calcola(N - 1)
    head->next = calcola(N - 1);
    
    return head;
}

// ============================================================================
// STRUTTURA DEL MAIN (PREVISTO NELL'ESAME DI SETTEMBRE)
// ============================================================================
int main(int argc, char* argv[]) {
    // 1. Controllo formale del numero di argomenti da riga di comando
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <N>" << endl;
        return -1;
    }

    // 2. Lettura e validazione dell'intero N
    int N = atoi(argv[1]);
    if (N <= 0) {
        cerr << "Errore: N deve essere un intero positivo maggiore di zero." << endl;
        return -1;
    }

    // Stampa del valore di N come negli esempi del docente
    cout << "N = " << N << endl;

    // 3. Chiamata della funzione calcola per costruire la lista ricorsivamente
    Nodo* head = calcola(N);

    // 4. Stampa della lista di termini di Taylor costruita
    cout << "The list of taylor terms is: ";
    Nodo* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // 5. Deallocazione della memoria (pulizia finale)
    while (head != nullptr) {
        Nodo* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
