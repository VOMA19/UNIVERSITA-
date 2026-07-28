#include <iostream>
#include <fstream>

using namespace std;

// 1. DEFINIZIONE DELLA STRUTTURA NODO
struct Node {
    double value;
    Node* next;
};

// --- PROTOTIPI DELLE FUNZIONI ---
void leggiECreaLista(istream& in, Node*& testa, int& dim, double& somma, double& somma_quadrati);
void calcola(istream& in, double& varianza, Node*& testa, int& dim);
void distruggiLista(Node* testa); // Sempre richiesta all'esame per le liste!

// =================================================================
// 2. FUNZIONE AUSILIARIA (Il Motore Ricorsivo)
// =================================================================
void leggiECreaLista(istream& in, Node*& testa, int& dim, double& somma, double& somma_quadrati) {
    double valore;
    
    // FASE 1: DISCESA (Tento di leggere dal file)
    if (in >> valore) {
        
        // 1. ALLOCAZIONE DEL NODO CORRENTE
        // A differenza degli array, alloco subito un singolo nodo!
        testa = new Node;
        testa->value = valore;
        
        // 2. AGGIORNAMENTO DEGLI ACCUMULATORI
        dim++;
        somma += valore;
        somma_quadrati += (valore * valore);
        
        // 3. CHIAMATA RICORSIVA AL PROSSIMO NODO
        // Passo testa->next PER RIFERIMENTO. 
        // La funzione successiva costruirà il resto della lista agganciandolo qui!
        leggiECreaLista(in, testa->next, dim, somma, somma_quadrati);
        
    } else {
        // FASE 2: CASO BASE (Fine del file)
        // Chiudo definitivamente la lista assegnando nullptr all'ultimo next
        testa = nullptr; 
    }
}

// =================================================================
// 3. LA FUNZIONE WRAPPER (Quella richiesta dal testo)
// =================================================================
void calcola(istream& in, double& varianza, Node*& testa, int& dim) {
    // Inizializzo gli accumulatori
    double somma = 0.0;
    double somma_quadrati = 0.0;
    dim = 0; 
    
    // Avvio la costruzione della lista
    leggiECreaLista(in, testa, dim, somma, somma_quadrati);
    
    // Elaborazione statistica finale
    if (dim == 0) {
        varianza = -1.0; // Codice di errore se il file era vuoto
    } else {
        // Formula della Varianza: Media dei quadrati - Quadrato della media
        double media = somma / dim;
        double media_dei_quadrati = somma_quadrati / dim;
        varianza = media_dei_quadrati - (media * media);
    }
}

// =================================================================
// 4. DEALLOCAZIONE RICORSIVA (Fondamentale per Valgrind)
// =================================================================
void distruggiLista(Node* testa) {
    if (testa == nullptr) {
        return; // Caso Base
    }
    distruggiLista(testa->next); // Prima scendo fino alla fine (Post-Order)
    delete testa;                // Poi distruggo risalendo
}