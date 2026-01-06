#include "stack.h"
#include <cstdlib>
#include <iostream>

using namespace std;

struct StackNode {
    double value;
    StackNode *next;
};

struct Stack {
    StackNode *top;
};

Stack * init() {
    Stack *s = new Stack;
    s->top = nullptr;
    return s;
}

void push(Stack *s, double value) {
    StackNode *newNode = new StackNode;
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
}

double pop(Stack *s) {
    if (s == nullptr || s->top == nullptr) {
        cerr << "ERROR: Stack vuoto" << endl;
        exit(EXIT_FAILURE);
    }
    StackNode *temp = s->top;
    double value = temp->value;
    s->top = s->top->next;
    delete temp;
    return value;
}

double top(Stack *s) {
    if (s == nullptr || s->top == nullptr) {
        cerr << "ERROR: Stack vuoto" << endl;
        exit(EXIT_FAILURE);
    }
    return s->top->value;
}

int isEmpty(Stack *s) {
    return s == nullptr || s->top == nullptr;
}

void freeStack(Stack *s) {
    if (s == nullptr) return;
    while (!isEmpty(s)) {
        pop(s);
    }
    delete s;
}

void printStack(Stack *s) {
    if (s == nullptr || isEmpty(s)) {
        cout << "Stack vuoto" << endl;
        return;
    }
    StackNode *current = s->top;
    cout << "Contenuto della pila: ";
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}