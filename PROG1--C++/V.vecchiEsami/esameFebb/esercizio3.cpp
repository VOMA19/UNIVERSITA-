#include <iostream>
#include "treequeue.h" 

using namespace std;

// Dichiarazione delle funzioni di utilità richieste dal main fornito
Node* createNode(int val);
Node* createNodeV(int val, Node* l, Node* r);
void printTreeDepth(Node* root, int indent = 0);
void deleteTree(Node* root);
void calcola(Node* root, int& sommarichiesta, int& livello);

int main() {
    // Creazione di un albero binario di esempio
    Node* root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(0));
    cout << "Stampa dell'albero:" << endl;
    int sommarichiesta, livello;
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = nullptr;
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(-6));
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    std::cout << "---------------------------------" << std::endl;
    root = createNodeV(1,
                        createNodeV(7,
                            createNode(7),
                            createNode(-8)),
                        createNode(-8));
    printTreeDepth(root);
    calcola(root, sommarichiesta, livello);
    if (livello != -1) {
        cout << "Somma richiesta: " << sommarichiesta << " al livello: " << livello << endl;
    } else {
        cout << "L'albero e' vuoto." << endl;
    }
    // Pulizia della memoria
    deleteTree(root);
    return 0;
}

// --- FUNZIONI DI SUPPORTO ---

void calcola(Node* root, int& sommarichiesta, int& livello) {
    // Caso albero vuoto: imposta livello a -1 come richiesto
    if (root == nullptr) {
        livello = -1;
        sommarichiesta = 0;
        return;
    }

    // Inizializzazione della coda (capacità stimata sulla dimensione dell'albero)
    // Nota: la funzione createQueue è parte della libreria treequeue citata
    Queue q = createQueue(100); 
    enqueue(q, root);

    int max_somma = 0;
    int max_livello = 0;
    int liv_corrente = 0;
    bool prima_somma = true;

    

    while (!isEmpty(q)) {
        // Il numero di elementi attualmente in coda rappresenta i nodi del livello corrente
        int nodi_al_livello = size(q); 
        int somma_attuale = 0;

        for (int i = 0; i < nodi_al_livello; i++) {
            Node* curr = dequeue(q);
            somma_attuale += curr->data;

            // Aggiunge i figli alla coda per il prossimo livello
            if (curr->left != nullptr) enqueue(q, curr->left);
            if (curr->right != nullptr) enqueue(q, curr->right);
        }

        if (prima_somma || somma_attuale > max_somma) {
            max_somma = somma_attuale;
            max_livello = liv_corrente;
            prima_somma = false;
        }

        liv_corrente++;
    }

    sommarichiesta = max_somma;
    livello = max_livello;
    
    // Pulizia della coda se la libreria lo richiede (es. deleteQueue(q))
}
