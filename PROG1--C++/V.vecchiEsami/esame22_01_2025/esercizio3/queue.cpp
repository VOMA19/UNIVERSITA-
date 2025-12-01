#include "queue.h"

struct _Queue {
    struct _Node {
        char c;
        struct _Node * next;
    };
    struct _Node * head;
    struct _Node * tail;
};

Queue init_queue() {
    Queue q = new _Queue;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue q, char c) {
    struct _Queue::_Node * n = new struct _Queue::_Node;
    n->c = c;
    n->next = NULL;
    if (q->head == NULL) {
        q->head = n;
    } else {
        q->tail->next = n;
    }
    q->tail = n;
}

char dequeue(Queue q) {
    struct _Queue::_Node * n = q->head;
    char c = n->c;
    q->head = n->next;
    delete n;
    return c;
}

bool queue_is_empty(Queue q) {
    return q->head == NULL;
}

void delete_queue(Queue q) {
    while (!queue_is_empty(q)) {
        dequeue(q);
    }
    delete q;
}