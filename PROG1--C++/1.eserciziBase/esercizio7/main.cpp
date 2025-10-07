#include <iostream>
using namespace std;

int main() {
    unsigned int x = 1;
    char *c = (char*)&x;
    if (*c) {
        cout << "Little Endian\n";
    } else {
        cout << "Big Endian\n";
    }
    return 0;
}