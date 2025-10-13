#include <iostream>
using namespace std;
void genericSwap(void* a, void* b, bool isInt);

int main() {
    int x = 10, y = 20;
    char c1 = 'A', c2 = 'B';

    genericSwap(&x, &y, true);
    cout << "x: " << x << ", y: " << y << endl;

    genericSwap(&c1, &c2, false);
    cout << "c1: " << c1 << ", c2: " << c2 << endl;

    return 0;
}

void genericSwap(void* a, void* b, bool isInt) {
    if (isInt) {
        int* pa = (int*)a;
        int* pb = (int*)b;
        int temp = *pa;
        *pa = *pb;
        *pb = temp;
    } else {
        char* pa = (char*)a;
        char* pb = (char*)b;
        char temp = *pa;
        *pa = *pb;
        *pb = temp;
    }
}