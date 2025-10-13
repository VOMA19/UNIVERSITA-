#include <iostream>
using namespace std;
void mySwap(int* a, int* b);

int main() {
    int x = 5, y = 10;
    cout << "Prima dello swap: x = " << x << ", y = " << y << endl;
    mySwap(&x, &y);
    cout << "Dopo lo swap: x = " << x << ", y = " << y << endl;
    return 0;
}

void mySwap(int* a, int* b) {
    if (a == nullptr || b == nullptr) 
        return;
        
    int temp = *a;
    *a = *b;
    *b = temp;
}