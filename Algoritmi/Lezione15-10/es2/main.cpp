#include <iostream>
#include <queue>
using namespace std;
struct Nodo {
    int value;
    Nodo* left = nullptr;
    Nodo* right = nullptr;
};

int livelloPiuLargo(Nodo* T);

int main(){

    Nodo * T = new Nodo();
    T->value = 0;                   // Livello 0: viene contato

    T->left = new Nodo{1};          // Livello 1: viene contato
    T->right = new Nodo{7};         // Livello 1: non viene contato

    T->left->left = new Nodo{2};    // Livello 2: viene contato
    T->left->right = new Nodo{4};   // Livello 2: non viene contato
    cout << "Livello più largo: " << livelloPiuLargo(T) << endl;    
    return 0;
}


int livelloPiuLargo(Nodo* T) {
    if (T == nullptr) {
        return -1;  // L'albero vuoto non ha livelli
    }

    queue<Nodo*> coda;
    coda.push(T);

    int livello = 0;
    int livelloMax = 0;
    int larghezzaMax = 0;

    while (!coda.empty()) {
        // All'inizio di ogni giro, la coda contiene
        // tutti e soli i nodi del livello corrente.
        int larghezza = coda.size();

        if (larghezza > larghezzaMax) {
            larghezzaMax = larghezza;
            livelloMax = livello;
        }

        // Estraggo i nodi del livello corrente
        // e inserisco i loro figli nella coda.
        for (int i = 0; i < larghezza; i++) {
            Nodo* corrente = coda.front();
            coda.pop();

            if (corrente->left != nullptr) {
                coda.push(corrente->left);
            }

            if (corrente->right != nullptr) {
                coda.push(corrente->right);
            }
        }

        livello++;
    }

    return livelloMax;
}