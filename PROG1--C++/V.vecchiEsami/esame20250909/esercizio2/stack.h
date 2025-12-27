struct Stack;

double pop(Stack *s);
Stack * init();
void push(Stack *s, double value);
void freeStack(Stack *s);
double top(Stack *s);
int isEmpty(Stack *s);
void printStack(Stack *s); // Funzione per stampare la pila (opzionale)