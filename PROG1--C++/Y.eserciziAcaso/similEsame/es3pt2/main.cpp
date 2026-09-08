// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

using namespace std;

// Struttura del nodo per la lista concatenata dei risultati
struct Nodo {
    int val;
    Nodo* next;
};

// ============================================================================
// DICHIARAZIONE DELLA FUNZIONE VISITA (Richiesta dall'Esercizio 3)
// ============================================================================
Nodo* visita(bool** A, int N, int source);

// ============================================================================
// IMPLEMENTAZIONE DELLA FUNZIONE VISITA
// ============================================================================
Nodo* visita(bool** A, int N, int source) {
    // 1. Creo un array visited di boolean di dimensione N, inizializzato a False
    bool* visited = new (std::nothrow) bool[N];
    if (!visited) {
        std::cerr << "Errore: allocazione di memoria fallita per visited." << std::endl;
        return nullptr;
    }
    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    // 2. Creo una lista result inizialmente vuota
    Nodo* result = nullptr;

    // 3. Creo uno stack e vi inserisco il nodo sorgente ricevuto come argomento
    Stack s;
    s.push(source);

    // 4. Fintanto che lo stack non è vuoto
    while (!s.isEmpty()) {
        int curr = s.pop();

        // Se curr non è stato ancora visitato
        if (!visited[curr]) {
            // Modifico visited per tenere traccia che il nodo è stato visitato (True)
            visited[curr] = true;

            // Lo aggiungo in testa alla lista result (inserimento in testa)
            Nodo* newNodo = new (std::nothrow) Nodo;
            if (newNodo) {
                newNodo->val = curr;
                newNodo->next = result;
                result = newNodo;
            }

            // Considero tutti i nodi j adiacenti al nodo curr (A[curr][j] == True)
            // che non sono stati ancora visitati e li aggiungo allo stack.
            // Nota: scorriamo da 0 a N-1 per coerenza con l'ordine di adiacenza del grafo.
            for (int j = 0; j < N; ++j) {
                if (A[curr][j] && !visited[j]) {
                    s.push(j);
                }
            }
        }
    }

    // Liberiamo la memoria dinamica dell'array locale visited
    delete[] visited;

    // Ritorno la testa della lista concatenata ottenuta
    return result;
}

// ============================================================================
// SIMULAZIONE DEL MAIN DEL DOCENTE (Compila e genera un grafo casuale)
// ============================================================================
int main() {
    // Inizializzazione seed casuale
    std::srand(time(0));

    int N = 16; // Dimensione del grafo
    cout << "Grafo G[" << N << "][" << N << "]" << endl;

    // Allocazione dinamica della matrice delle adiacenze A
    bool** A = new bool*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new bool[N];
        for (int j = 0; j < N; ++j) {
            // Circa 20% di probabilità di avere un arco, nessun auto-anello
            if (i == j) {
                A[i][j] = false;
            } else {
                A[i][j] = (std::rand() % 100 < 20);
            }
        }
    }

    // Stampa della matrice delle adiacenze
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Scegliamo un nodo sorgente casuale minore di N
    int sorgente = std::rand() % N;
    cout << "\nAvvio visita dal nodo sorgente: " << sorgente << endl;

    // Chiamata della funzione visita
    Nodo* list = visita(A, N, sorgente);

    // Stampa dei risultati della lista concatenata dei nodi raggiungibili
    cout << "Lista: ";
    Nodo* temp = list;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deallocazione della lista dei risultati
    while (list != nullptr) {
        Nodo* toDelete = list;
        list = list->next;
        delete toDelete;
    }

    // Deallocazione della matrice delle adiacenze
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
