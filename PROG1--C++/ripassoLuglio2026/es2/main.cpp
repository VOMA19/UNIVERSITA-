#include <iostream>

// Definizione della struttura del nodo (standard, come fornita dal docente)
struct Node {
    int value;
    Node* next;
};

// Dichiarazione anticipata necessaria per la mutua ricorsione
Node* calcola(Node* head);

// Funzione ausiliaria puramente ricorsiva
Node* contaESalta(Node* current, int val_target, int contatore) {
    // Caso base: fine della lista o cambio di valore
    if (current == nullptr || current->value != val_target) {
        
        // 1. Creiamo dinamicamente il nuovo nodo in stile classico
        Node* nuovo_nodo = new Node;
        nuovo_nodo->value = contatore;
        
        // 2. Colleghiamo il nuovo nodo al risultato del calcolo sul resto della lista
        nuovo_nodo->next = calcola(current);
        
        return nuovo_nodo;
    }
    
    // Passo ricorsivo: proseguiamo incrementando il contatore
    return contaESalta(current->next, val_target, contatore + 1);
}

// Funzione principale
Node* calcola(Node* head) {
    // Caso base principale: lista vuota
    if (head == nullptr) {
        return nullptr;
    }
    
    // Avviamo il conteggio passando il nodo successivo, il valore da cercare e partenza da 1
    return contaESalta(head->next, head->value, 1);
}

// --- Funzioni di utilità esclusive per il test nel main ---

void stampaLista(Node* head) {
    while (head != nullptr) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

void liberaLista(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Funzione d'appoggio per popolare facilmente la lista nel main
void inserisciInCoda(Node*& head, int val) {
    Node* nuovo_nodo = new Node;
    nuovo_nodo->value = val;
    nuovo_nodo->next = nullptr;

    if (head == nullptr) {
        head = nuovo_nodo;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nuovo_nodo;
    }
}

int main() {
    // Creazione della lista di input: 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> nullptr
    Node* list = nullptr;
    inserisciInCoda(list, 1);
    inserisciInCoda(list, 2);
    inserisciInCoda(list, 2);
    inserisciInCoda(list, 3);
    inserisciInCoda(list, 3);
    inserisciInCoda(list, 3);

    std::cout << "Lista originale: ";
    stampaLista(list);

    // Esecuzione della funzione ricorsiva
    Node* count_list = calcola(list);

    std::cout << "Lista dei conteggi: ";
    stampaLista(count_list);

    // Pulizia della memoria
    liberaLista(list);
    liberaLista(count_list);

    return 0;
}
