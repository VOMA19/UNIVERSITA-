#include <iostream>
#include <fstream>
#include <cstdlib>

#include "stack.h"
#include "queue.h"


using namespace std;

// Insert here after the declarations of the functions check
bool check(ifstream & in);
// Insert here above the declaration of the function check

int main(int argc, char ** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        exit(1);
    }

    ifstream in(argv[1]);
    if (in.fail()) {
        cerr << "Cannot open input file " << argv[1] << endl;
        exit(2);
    }

    bool balanced = check(in);

    if (balanced) {
        cout << "The function check returns true" << endl;
    } else {
        cout << "The function check returns false" << endl;
    }

    in.close();

    return 0;
}

// Insert here after the definition of the functions check
bool check(ifstream & in) {
    Stack s = init_stack();

    char c;
    while (in >> c) {
        switch(c) {
            case '(':
            case '[':
            case '{':
                push(s, c);
                break;
            case ')':
                if (stack_is_empty(s) || pop(s) != '(') {
                    delete_stack(s);
                    return false;
                }
                break;
            case ']':
                if (stack_is_empty(s) || pop(s) != '[') {
                    delete_stack(s);
                    return false;
                }
                break;
            case '}':
                if (stack_is_empty(s) || pop(s) != '{') {
                    delete_stack(s);
                    return false;
                }
                break;
            default:
                // We do not care about other characters
                break;
        }
    }

    // If the stack is empty, the parentheses are balanced
    bool result = stack_is_empty(s);

    // We need to delete the stack before returning
    delete_stack(s);

    return result;
}
// Insert here above the definition of the function check
