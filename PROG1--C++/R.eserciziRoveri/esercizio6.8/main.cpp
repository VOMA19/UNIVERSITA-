#include <iostream>
using namespace std;
/*
    Scrivere un programma che, data una lista concatenata di interi in ordine crescente, chieda in input
    all’utente un nuovo intero e lo inserisca in modo ordinato nella lista
*/
struct Nodo {
    int dato;
    Nodo* next;
};
void inserisciInTesta(Nodo*& testa, int valore);
void stampaLista(Nodo* testa);
void deallocaLista(Nodo*& testa);
int main(){

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
    
    lista = sortList(lista);

    stampaLista(lista);
    
    deallocaLista(lista);
    return 0;
}

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
// Funzione per deallocare la lista
void deallocaLista(Nodo*& testa) {
    while (testa != nullptr) {
        Nodo* temp = testa;
        testa = testa->next;
        delete temp;
    }
}

Nodo* sortList(Nodo* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
        }
        
        // Bubble sort per lista concatenata
        bool scambiato;
        do {
        scambiato = false;
        Nodo* corrente = head;
        
        while (corrente != nullptr && corrente->next != nullptr) {
            if (corrente->dato > corrente->next->dato) {
            // Scambia i valori
            int temp = corrente->dato;
            corrente->dato = corrente->next->dato;
            corrente->next->dato = temp;
            scambiato = true;
            }
            corrente = corrente->next;
        }
        } while (scambiato);
        
        return head;
}

