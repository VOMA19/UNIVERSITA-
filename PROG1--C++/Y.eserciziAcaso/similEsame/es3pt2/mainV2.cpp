// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

using namespace std;

// Struttura del nodo per la lista concatenata dei risultati
struct Node {
    int val;
    Node* next;
};

// ============================================================================
// DICHIARAZIONE DELLA FUNZIONE VISITA (Richiesta dall'Esercizio 3)
// ============================================================================
int visita(bool** A, int N, int source);

// ============================================================================
// IMPLEMENTAZIONE DELLA FUNZIONE VISITA
// ============================================================================
int visita(bool** A, int N, int source) {
    // Creazione e inizializzazione array di supporto
    bool* visited = new (std::nothrow) bool[N];
    if (!visited) {
        std::cerr << "Errore: allocazione fallita per visited." << std::endl;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    int count_raggiungibili = 0;

    // Utilizzo dello Stack fornito
    Stack s;
    s.push(source);

    while (!s.isEmpty()) {
        int curr = s.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            count_raggiungibili++; // Contiamo il nodo visitato

            // Esploriamo i vicini
            for (int j = 0; j < N; ++j) {
                if (A[curr][j] && !visited[j]) {
                    s.push(j);
                }
            }
        }
    }

    // Pulizia obbligatoria delle risorse
    delete[] visited;

    return count_raggiungibili;
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


    // Stampa dei risultati della lista concatenata dei nodi raggiungibili
    // Deallocazione della matrice delle adiacenze
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
