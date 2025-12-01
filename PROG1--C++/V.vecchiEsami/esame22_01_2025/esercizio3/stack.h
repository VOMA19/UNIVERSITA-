#include <cstdlib>

using namespace std;

typedef struct _Stack * Stack;

Stack init_stack();
void push(Stack s, char c);
char pop(Stack s);
bool stack_is_empty(Stack s);
void delete_stack(Stack s);
