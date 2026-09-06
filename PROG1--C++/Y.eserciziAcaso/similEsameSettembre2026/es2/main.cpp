#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Definizione della struttura della lista concatenata
struct Lista {
    double data;
    Lista* next;
};

// Dichiarazione della procedura (non modificare questa firma)
void calcola(Lista* nodo, double& risultato, double& somma_reciproci, int& conteggio);

// ====================================================================
// FUNZIONI DI SUPPORTO FORNITE (NON MODIFICARE E NON USARE IN "calcola")
// ====================================================================
void inserisci_in_coda(Lista*& testa, double valore) {
    Lista* nuovo = new Lista;
    nuovo->data = valore;
    nuovo->next = nullptr;
    
    if (testa == nullptr) {
        testa = nuovo;
    } else {
        Lista* temp = testa;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nuovo;
    }
}

void dealloca_lista(Lista* testa) {
    while (testa != nullptr) {
        Lista* temp = testa;
        testa = testa->next;
        delete temp;
    }
}
// ====================================================================

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    Lista* testa = nullptr;
    double valore;

    // Costruzione della lista dal file
    while (input >> valore) {
        inserisci_in_coda(testa, valore);
    }
    input.close();

    // Inizializzazione variabili da passare per riferimento
    double risultato = 0.0;
    double somma_reciproci = 0.0; 
    int conteggio = 0;

    // Chiamata alla tua procedura
    calcola(testa, risultato, somma_reciproci, conteggio);

    // Stampa dei risultati (come richiesto dalle specifiche)
    if (risultato == -1) {
        cout << "Result: -1" << endl;
        cout << "No data to calculate harmonic mean." << endl;
    } else {
        cout << "Size: " << conteggio << endl;
        cout << "Result: " << risultato << endl;
        cout << "Harmonic Mean: " << risultato << endl;
    }

    // Deallocazione memoria
    dealloca_lista(testa);

    return 0;
}

// ====================================================================
// IMPLEMENTA QUI SOTTO LA PROCEDURA calcola
// (Ricorda: vietati for, while, do-while. Solo ricorsione!)
// ====================================================================

void calcola(Lista* nodo, double& risultato, double& somma_reciproci, int& conteggio) {
    if(nodo == nullptr && conteggio == 0){
        risultato = -1;
        return;
    }

    if(nodo == nullptr){
        risultato = conteggio/somma_reciproci;
        return;
    }

    somma_reciproci += 1.0/nodo->data;
    conteggio++;
    return calcola(nodo -> next, risultato, somma_reciproci, conteggio);
    

    
}