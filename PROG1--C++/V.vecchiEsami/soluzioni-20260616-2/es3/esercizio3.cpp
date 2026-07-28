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


// Inserisci qui sopra la definizione della funzione calcola