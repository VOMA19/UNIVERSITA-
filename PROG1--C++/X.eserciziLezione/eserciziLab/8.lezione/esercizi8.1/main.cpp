#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& head, int value){
    Node* newNode = createNode(value);
    if(!head){
        head = newNode;
    }else{
        Node* current = head;
        while (current->next){
            current = current->next;
        }
        current->next = newNode;
    }
}

void print(Node* head){
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    } 
    std::cout << std::endl;
}

void deleteList(Node*& head) {
    while(head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void invertiLista(Node*& head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void primizzaLista(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr) {
        if (!isPrime(current->data)) {
            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main(){
    std::string filename;
    std::cout << "Inserire il nome del file: ";
    std::cin >> filename;
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file!" << std::endl;
        return 1;
    }
    
    Node* head = nullptr;
    int number;
    
    while (file >> number) {
        append(head, number);
    }
    
    file.close();
    
    std::cout << "Lista creata:\t\t ";
    print(head);
    invertiLista(head);
    std::cout << "lista invertita:\t ";
    print(head);
    primizzaLista(head);
    std::cout << "lista primizzata\t ";
    print(head);
    deleteList(head);
    
    return 0;
}
struct Nodo {
    int valore;
    Nodo* sinistro;
    Nodo* destro;
};



