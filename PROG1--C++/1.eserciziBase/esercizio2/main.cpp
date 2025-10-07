#include <iostream>
using namespace std;

int main() {
    cout << "Dimensione dei tipi base in byte:\n";
    cout << "char: " << sizeof(char) << " byte\n";
    cout << "short: " << sizeof(short) << " byte\n";
    cout << "int: " << sizeof(int) << " byte\n";
    cout << "long: " << sizeof(long) << " byte\n";
    cout << "long long: " << sizeof(long long) << " byte\n";
    cout << "float: " << sizeof(float) << " byte\n";
    cout << "double: " << sizeof(double) << " byte\n";
    cout << "long double: " << sizeof(long double) << " byte\n";
    cout << "bool: " << sizeof(bool) << " byte\n";
    return 0;
}