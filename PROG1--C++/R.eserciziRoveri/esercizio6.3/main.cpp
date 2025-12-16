#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;  // Puntatore al nodo precedente
};

Node* readFromFile(const char* filename);
Node* createNode(int data);
void printList(Node* head);
void printListReverse(Node* tail);
void deleteList(Node*& head);
void deleteNode(Node*& head, int value);

int main(){
    char filename[50];
    cout << "inserisci il nome del file: ";
    cin >> filename;
    Node* head = readFromFile(filename);
    
    cout << "Lista in avanti: ";
    printList(head);
    
    // Trova la coda per stampare al contrario
    Node* tail = head;
    if (tail != nullptr) {
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }
    
    cout << "Lista al contrario: ";
    printListReverse(tail);

    int num;
    cout << "che numero vuoi eliminare? ";
    cin >> num;
    deleteNode(head, num);
    printList(head);
    
    // Trova la coda per stampare al contrario
    if (tail != nullptr) {
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }
    
    cout << "Lista al contrario: "<<endl;
    printListReverse(tail);

    deleteList(head);
    printList(head);

    return 0;
}

Node* readFromFile(const char* filename) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return nullptr;
    }
    
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;
    
    while (file >> value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;  // Collegamento verso il precedente
            tail = newNode;
        }
    }
    
    file.close();
    return head;
}

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;  // Inizializza anche prev
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printListReverse(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;
    
    Node* temp = head;
    
    // Cerca il nodo da eliminare
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }
    
    // Se il nodo non è stato trovato
    if (temp == nullptr) return;
    
    // Se è il primo nodo
    if (temp->prev == nullptr) {
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    }
    // Se è un nodo intermedio o finale
    else {
        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
    }
    
    delete temp;
}