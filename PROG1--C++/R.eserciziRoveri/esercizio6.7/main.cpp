#include <iostream>
using namespace std;
/*
    Scrivere un programma che, data una lista concatenata di interi, scorra la lista ed elimini i nodi duplicati
*/
struct Nodo {
    int dato;
    Nodo* next;
};
void inserisciInTesta(Nodo*& testa, int valore);
void stampaLista(Nodo* testa);
void deallocaLista(Nodo*& testa);
Nodo* eliminaDuplicati(Nodo* head);
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
    
    lista = eliminaDuplicati(lista);

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

Nodo* eliminaDuplicati(Nodo* head){
    Nodo* curr = head;
    while(curr != nullptr){
        Nodo* temp = curr;
        while(temp->next != nullptr){
            if(curr->dato == temp->next->dato){
                Nodo* duplicato = temp->next;
                temp->next = temp->next->next;
                delete duplicato;
                cout << "nodo eliminato" <<endl;
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}