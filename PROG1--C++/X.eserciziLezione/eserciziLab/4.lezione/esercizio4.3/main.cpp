#include <iostream>
using namespace std;

int sumOfDigits(int n);

int main() {
    int num;
    cout << "Inserisci un numero intero: ";
    cin >> num;
    
    cout << "La somma delle cifre è: " << sumOfDigits(abs(num)) << endl;
    
    return 0;
}

int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + sumOfDigits(n / 10);
}