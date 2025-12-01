#include "stack.h"

struct _Stack {
    struct _Node {
        char c;
        struct _Node * next;
    };
    struct _Node * top;
};

Stack init_stack() {
    Stack s = new _Stack;
    s->top = NULL;
    return s;
}

void push(Stack s, char c) {
    struct _Stack::_Node * n = new struct _Stack::_Node;
    n->c = c;
    n->next = s->top;
    s->top = n;
}

char pop(Stack s) {
    struct _Stack::_Node * n = s->top;
    char c = n->c;
    s->top = n->next;
    delete n;
    return c;
}

bool stack_is_empty(Stack s) {
    return s->top == NULL;
}

void delete_stack(Stack s) {
    while (!stack_is_empty(s)) {
        pop(s);
    }
    delete s;
}