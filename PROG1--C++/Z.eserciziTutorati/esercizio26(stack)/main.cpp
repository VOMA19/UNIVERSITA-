#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int data[MAX_SIZE];
    int top_index;
};

void init(Stack* s);
void deinit(Stack* s);
bool push(Stack* s, int val);
bool pop(Stack* s);
bool top(Stack* s, int& val);

int main() {
    Stack s;
    init(&s);
    
    // Test the stack
    push(&s, 10);
    push(&s, 20);
    
    int val;
    if (top(&s, val)) {
        cout << "Top element: " << val << endl;
    }
    
    pop(&s);
    if (top(&s, val)) {
        cout << "Top element after pop: " << val << endl;
    }
    
    deinit(&s);
    return 0;
}

void init(Stack* s) {
    s->top_index = -1;
}

void deinit(Stack* s) {
    s->top_index = -1;
}

bool push(Stack* s, int val) {
    if (s->top_index >= MAX_SIZE - 1) {
        return false; // Stack overflow
    }
    s->top_index++;
    s->data[s->top_index] = val;
    return true;
}

bool pop(Stack* s) {
    if (s->top_index < 0) {
        return false; // Stack underflow
    }
    s->top_index--;
    return true;
}

bool top(Stack* s, int& val) {
    if (s->top_index < 0) {
        return false; // Stack is empty
    }
    val = s->data[s->top_index];
    return true;
}