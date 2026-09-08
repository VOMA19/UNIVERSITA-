// Stack.cpp
#include "Stack.h"
#include <iostream>

Stack::Stack() {
    topNode = nullptr;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int val) {
    StackNode* newNode = new (std::nothrow) StackNode;
    if (newNode) {
        newNode->val = val;
        newNode->next = topNode;
        topNode = newNode;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        return -1; // Ritorna valore sentinella se vuoto
    }
    StackNode* temp = topNode;
    int poppedVal = temp->val;
    topNode = topNode->next;
    delete temp;
    return poppedVal;
}

int Stack::top() const {
    if (isEmpty()) {
        return -1;
    }
    return topNode->val;
}

bool Stack::isEmpty() const {
    return topNode == nullptr;
}

bool Stack::empty() const {
    return topNode == nullptr;
}
