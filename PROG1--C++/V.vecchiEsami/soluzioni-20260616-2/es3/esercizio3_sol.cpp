#include <iostream>
#include <cstdlib>


struct Node {
    int data;
    Node* next;
};

void print(const char * prefix, Node* head) {
    std::cout << prefix;
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(Node* & head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

// Inserisci qui sotto la dichiarazione della funzione calcola 

Node * calcola (Node * head);

// Inserisci qui sopra la dichiarazione della funzione calcola

int main() {
    Node* head = nullptr;
 
    head = new Node{0, nullptr}; 
    head = new Node{0, head};
    head = new Node{0, head};
    head = new Node{1, head};
    head = new Node{1, head};
    head = new Node{2, head};
    head = new Node{2, head};
    head = new Node{2, head};
    head = new Node{2, head};
    head = new Node{3, head};
    head = new Node{1, head};

    // Caso lista con più di un elemento
    print("Lista iniziale: ", head);
    Node * result = calcola(head);
    print("Lista risultante: ", result);
    deleteList(head);
    deleteList(result);

    // Caso lista con un solo elemento
    head = new Node{0, nullptr}; 
    print("Lista iniziale: ", head);
    result = calcola(head);
    print("Lista risultante: ", result);
    deleteList(head);
    deleteList(result);
    
    // Caso lista sia vuota
    print("Lista iniziale: ", head);
    result = calcola(head);
    print("Lista risultante: ", result);
    deleteList(head);
    deleteList(result);
    return 0;
}

// Inserisci qui sotto la definizione della funzione calcola

Node * calcola_aux(Node * current, int v, int count) {
    // Se current è nullptr, significa che abbiamo raggiunto la fine della lista, quindi restituiamo un nuovo nodo con il conteggio
    if (current == nullptr) {
        return new Node{count, nullptr};
    }
    // Se il valore del nodo corrente è uguale a v, incrementiamo il conteggio e continuiamo a scorrere la lista
    if (current->data == v) {
        return calcola_aux(current->next, v, count + 1);
    } else {
        // Se il valore del nodo corrente è diverso da v, significa che abbiamo finito di contare gli elementi uguali a v, quindi restituiamo un nuovo nodo con il conteggio e continuiamo a scorrere la lista con il nuovo valore
        return new Node{count, calcola_aux(current->next, current->data, 1)};
    }
}

Node * calcola (Node * head) {
    // Se la lista è vuota, restituisci nullptr
    if (head == nullptr) {
        return nullptr;
    }
    // Altrimenti, prendi il valore del primo nodo e chiama la funzione ausiliaria
    int v = head->data;
    return calcola_aux(head->next, v, 1);
}

// Inserisci qui sopra la definizione della funzione calcola