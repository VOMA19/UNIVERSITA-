#include <iostream>
#include <fstream>
using namespace std;

/*
    Scrivere un programma che, dato in input un file con un intero per riga, crei, stampi ed elimini una lista
    concatenata con i numeri contenuti nel file.
*/
struct Node {                                           // Struttura per nodo di lista collegata
    int data;                                           // Dato memorizzato nel nodo
    Node* next;                                         // Puntatore al nodo successivo
};
Node* readFromFile(const char* filename);
Node* createNode(int data);
void printList(Node* head);
void deleteList(Node*& head);
int main(){
    char filename[50];
    cout << "inserisci il nome del file: ";
    cin >> filename;
    Node*head =readFromFile(filename);
    printList(head);
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
        } else {
            tail->next = newNode;
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

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}