#include <iostream>
#include "treequeue.h"

using namespace std;

// --- Implementazione della CODA ---

Queue createQueue(int capacity) {
    Queue q;
    q.capacity = capacity;
    q.array = new Node*[capacity]; // Array di puntatori a Node
    q.head = 0;
    q.tail = 0;
    q.current_size = 0;
    return q;
}

void enqueue(Queue& q, Node* n) {
    if (q.current_size < q.capacity) {
        q.array[q.tail] = n;
        q.tail = (q.tail + 1) % q.capacity; // Logica circolare
        q.current_size++;
    }
}

Node* dequeue(Queue& q) {
    if (q.current_size > 0) {
        Node* n = q.array[q.head];
        q.head = (q.head + 1) % q.capacity; // Logica circolare
        q.current_size--;
        return n;
    }
    return nullptr;
}

bool isEmpty(Queue q) {
    return q.current_size == 0;
}

int size(Queue q) {
    return q.current_size;
}

// --- Funzioni di utilità per l'ALBERO (richieste dal main) ---

Node* createNode(int val) {
    Node* n = new Node;
    n->data = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* createNodeV(int val, Node* l, Node* r) {
    Node* n = new Node;
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
}

void printTreeDepth(Node* root, int indent) {
    if (root == nullptr) return;
    
    if (root->right) printTreeDepth(root->right, indent + 4);
    
    for (int i = 0; i < indent; i++) cout << " ";
    cout << root->data << endl;
    
    if (root->left) printTreeDepth(root->left, indent + 4);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}