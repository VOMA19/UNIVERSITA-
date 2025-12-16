#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* next;
};

// Funzione per inserire un nodo in testa alla lista
void inserisciInTesta(Nodo*& testa, int valore) {
    Nodo* nuovo = new Nodo;
    nuovo->dato = valore;
    nuovo->next = testa;
    testa = nuovo;
}

// Funzione per stampare la lista
void stampaLista(Nodo* testa) {
    Nodo* corrente = testa;
    while (corrente != nullptr) {
        cout << corrente->dato << " -> ";
        corrente = corrente->next;
    }
    cout << "NULL" << endl;
}

// Funzione per ottenere la lunghezza della lista
int lunghezzaLista(Nodo* testa) {
    int count = 0;
    Nodo* corrente = testa;
    while (corrente != nullptr) {
        count++;
        corrente = corrente->next;
    }
    return count;
}

// Funzione per invertire i nodi agli indici specificati
bool invertiNodi(Nodo*& testa, int indice1, int indice2) {
    int lunghezza = lunghezzaLista(testa);
    
    // Controllo validità indici
    if (indice1 >= lunghezza || indice2 >= lunghezza || indice1 < 0 || indice2 < 0) {
        return false;
    }
    
    if (indice1 == indice2) {
        return true; // Nessuno scambio necessario
    }
    
    // Trova i nodi agli indici specificati
    Nodo* corrente = testa;
    int temp;
    
    for (int i = 0; i < lunghezza; i++) {
        if (i == indice1) {
            temp = corrente->dato;
            break;
        }
        corrente = corrente->next;
    }
    
    Nodo* nodo2 = testa;
    for (int i = 0; i < lunghezza; i++) {
        if (i == indice2) {
            corrente->dato = nodo2->dato;
            nodo2->dato = temp;
            break;
        }
        nodo2 = nodo2->next;
    }
    
    return true;
}

// Funzione per deallocare la lista
void deallocaLista(Nodo*& testa) {
    while (testa != nullptr) {
        Nodo* temp = testa;
        testa = testa->next;
        delete temp;
    }
}

int main() {
    Nodo* lista = nullptr;
    int n, valore;
    
    cout << "Quanti elementi vuoi inserire nella lista? ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Inserisci elemento " << (i + 1) << ": ";
        cin >> valore;
        inserisciInTesta(lista, valore);
    }
    
    cout << "\nLista originale: ";
    stampaLista(lista);
    
    int indice1, indice2;
    cout << "\nInserisci il primo indice (0-" << (lunghezzaLista(lista) - 1) << "): ";
    cin >> indice1;
    cout << "Inserisci il secondo indice (0-" << (lunghezzaLista(lista) - 1) << "): ";
    cin >> indice2;
    
    if (invertiNodi(lista, indice1, indice2)) {
        cout << "\nLista dopo l'inversione: ";
        stampaLista(lista);
    } else {
        cout << "\nERRORE: Indici non validi!" << endl;
    }
    
    deallocaLista(lista);
    
    return 0;
}