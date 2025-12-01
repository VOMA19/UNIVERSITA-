#include <iostream>
#include <new>

struct Queue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
};

void init(Queue* q, int cap = 10) {
    q->data = new(std::nothrow) int[cap];
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = cap;
}

void deinit(Queue* q) {
    delete[] q->data;
    q->data = nullptr;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = 0;
}

bool enqueue(Queue* q, int val) {
    if (q->size == q->capacity || q->data == nullptr) {
        return false;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = val;
    q->size++;
    return true;
}

bool dequeue(Queue* q) {
    if (q->size == 0 || q->data == nullptr) {
        return false;
    }
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return true;
}

bool first(Queue* q, int& val) {
    if (q->size == 0 || q->data == nullptr) {
        return false;
    }
    val = q->data[q->front];
    return true;
}

int main() {
    Queue q;
    init(&q, 5);
    
    // Test enqueue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    // Test first
    int val;
    if (first(&q, val)) {
        std::cout << "First element: " << val << std::endl;
    }
    
    // Test dequeue
    dequeue(&q);
    if (first(&q, val)) {
        std::cout << "First element after dequeue: " << val << std::endl;
    }
    
    deinit(&q);
    return 0;
}