#ifndef TREEQUEUE_H
#define TREEQUEUE_H

// 1. Definizione della struttura del Nodo dell'albero
struct Node {
    int data;
    Node *left;
    Node *right;
};

// 2. Definizione della struttura Coda (Queue)
// Viene usata per la visita a livelli (BFS)
struct Queue {
    Node** array;    // Array di puntatori a Node
    int head;        // Indice dell'elemento in testa
    int tail;        // Indice dove inserire il prossimo elemento
    int current_size; // Numero di elementi attuali
    int capacity;    // Capacità massima
};

// --- Prototipi delle funzioni per la Coda ---

// Crea una coda con una capacità specifica
Queue createQueue(int capacity);

// Inserisce un nodo nella coda
void enqueue(Queue& q, Node* n);

// Estrae un nodo dalla coda
Node* dequeue(Queue& q);

// Restituisce true se la coda è vuota
bool isEmpty(Queue q);

// Restituisce il numero di elementi attualmente in coda
int size(Queue q);

#endif