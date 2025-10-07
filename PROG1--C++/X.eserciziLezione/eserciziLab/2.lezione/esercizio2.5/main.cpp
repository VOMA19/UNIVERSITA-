#include <iostream>
using namespace std;
/*

    Scrivere un programma C++ che dato in input un numero binario,
    stampi a video il suo corrispondente valore decimale.

*/

int toDecimal(int n);

int main() {

    int num, decimal;
    bool err;

    cout << "inserisci un numero binario di cui sapere il decimale: ";
    cin >> num;

    decimal = toDecimal(num);

    cout << "il numero: " << num << " in decimale e': " << decimal <<endl;

    return 0;
}

int toDecimal(int n){
    int decimal;

    decimal = 0;
    int base = 1;
    while (n > 0) {
        int last_digit = n % 10;
        decimal += last_digit * base;
        base *= 2;
        n /= 10;
    }
    

    return decimal;
}