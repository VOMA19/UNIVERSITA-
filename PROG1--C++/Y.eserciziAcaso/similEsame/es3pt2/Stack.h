// Stack.h
#ifndef STACK_H
#define STACK_H

struct StackNode {
    int val;
    StackNode* next;
};

class Stack {
private:
    StackNode* topNode;

public:
    Stack();
    ~Stack();
    
    void push(int val);
    int pop();
    int top() const;
    
    // Supporto per entrambi i metodi di verifica pila vuota
    bool isEmpty() const;
    bool empty() const;
};

#endif // STACK_H
