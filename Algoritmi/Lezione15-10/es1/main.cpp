/*
Scrivere un algoritmo che preso in input un albero binario T i cui nodi
sono associati ad un valore intero T.value, restituisca il numero di nodi
dell’albero il cui valore è uguale al livello del nodo.
Vi ricordo che il livello del nodo è pari al numero di archi che devono
essere attraversati per raggiungere la radice dal nodo. Per cui la
radice ha livello 0, i suoi figli hanno livello 1, etc.
*/
#include <iostream>
using namespace std;
struct Nodo {
    int value;
    Nodo* left = nullptr;
    Nodo* right = nullptr;
};

int contaNodi(Nodo* T, int livello = 0);

int main(){

    Nodo * T = new Nodo();
    T->value = 0;                   // Livello 0: viene contato

    T->left = new Nodo{1};          // Livello 1: viene contato
    T->right = new Nodo{7};         // Livello 1: non viene contato

    T->left->left = new Nodo{2};    // Livello 2: viene contato
    T->left->right = new Nodo{4};   // Livello 2: non viene contato
    int risultato = contaNodi(T, 0);
    cout << risultato << endl;
    return 0;
}

int contaNodi(Nodo* T, int livello) {
    if (T == nullptr) {
        return 0;
    }

    int conta = 0;

    if (T->value == livello) {
        conta = 1;
    }

    return conta
         + contaNodi(T->left, livello + 1)
         + contaNodi(T->right, livello + 1);
}