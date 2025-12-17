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

// Funzione per deallocare la lista
void deallocaLista(Nodo*& testa) {
    while (testa != nullptr) {
        Nodo* temp = testa;
        testa = testa->next;
        delete temp;
    }
}

int* allocArray(int size) {
    if (size <= 0) return nullptr;
    return new int[size];
}

void createArrayFromList(Nodo* head, int numeri[]){
    Nodo* current = head;
    int i = 0;
    while(current != nullptr){
        numeri[i] = current->dato;
        current = current->next;
        i++;
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
    
    int* numeri = allocArray(lunghezzaLista(lista));
    createArrayFromList(lista, numeri);

    int lunghezza = lunghezzaLista(lista);
    for (int i = 0; i < lunghezza; i++){
        cout << numeri[i] << " ";
    }
    cout << endl;
    
    deallocaLista(lista);
    
    delete[] numeri;
    
    return 0;
}