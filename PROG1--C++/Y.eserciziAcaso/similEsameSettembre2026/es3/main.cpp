#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Definizione della struttura dell'albero binario
struct Tree {
    double data;
    Tree* left;
    Tree* right;
};

// Dichiarazione della funzione (non modificare la firma)
double calcola_escursione(Tree* root);

// ====================================================================
// FUNZIONI DI SUPPORTO FORNITE (NON MODIFICARE)
// ====================================================================
void inserisci_nodo(Tree*& root, double valore) {
    if (root == nullptr) {
        root = new Tree{valore, nullptr, nullptr};
    } else if (valore < root->data) {
        inserisci_nodo(root->left, valore);
    } else {
        inserisci_nodo(root->right, valore);
    }
}

void dealloca_albero(Tree* root) {
    if (root != nullptr) {
        dealloca_albero(root->left);
        dealloca_albero(root->right);
        delete root;
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

    Tree* radice = nullptr;
    double valore;

    // Costruzione dell'albero dal file
    while (input >> valore) {
        inserisci_nodo(radice, valore);
    }
    input.close();

    // Chiamata alla tua funzione
    double risultato = calcola_escursione(radice);

    // Stampa dei risultati
    if (risultato == -1) {
        cout << "Result: -1" << endl;
        cout << "No data to calculate range." << endl;
    } else {
        cout << "Result: " << risultato << endl;
        cout << "Range (Max - Min): " << risultato << endl;
    }

    // Deallocazione memoria
    dealloca_albero(radice);

    return 0;
}

// ====================================================================
// IMPLEMENTA QUI SOTTO LA FUNZIONE calcola_escursione
// Puoi definire liberamente funzioni ricorsive ausiliarie se necessario
// ====================================================================

// Funzione ausiliaria per esplorare l'albero e aggiornare gli estremi
void trova_min_max(Tree* nodo, double& min_val, double& max_val) {
    if (nodo == nullptr) {
        return; 
    }

    // Aggiorna il minimo o il massimo se il nodo corrente ha un valore fuori dal range parziale
    if (nodo->data < min_val) {
        min_val = nodo->data;
    }
    if (nodo->data > max_val) {
        max_val = nodo->data;
    }

    // Ricorsione sui rami sinistro e destro
    trova_min_max(nodo->left, min_val, max_val);
    trova_min_max(nodo->right, min_val, max_val);
}

double calcola_escursione(Tree* root) {
    // Controllo albero vuoto (specifica obbligatoria)
    if (root == nullptr) {
        return -1;
    }

    // Usiamo il valore della radice come innesco per i confronti
    double minimo = root->data;
    double massimo = root->data;

    // Chiamata alla funzione di attraversamento
    trova_min_max(root, minimo, massimo);

    // Restituisce l'escursione termica/chimica (Max - Min)
    return massimo - minimo;
}  


