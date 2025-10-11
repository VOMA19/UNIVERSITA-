#include <iostream>
using namespace std;

bool controllo(const char parentesi[]) {
    char stack[100];
    int top = -1;

    for (int i = 0; parentesi[i] != '\0'; i++) {
        char c = parentesi[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top < 0)
                return false;
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
                return false;
        }
    }
    return top == -1;
}

int main() {
    char parentesi[] = {'[','(',']',')','\0'};
    bool corr = controllo(parentesi);

    if (corr)
        cout << "la parentesizzazione è perfetta" << endl;
    else
        cout << "la parentesizzazione non è perfetta" << endl;

    return 0;
}
