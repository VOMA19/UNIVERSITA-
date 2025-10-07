#include <iostream>
using namespace std;

int main() {
    int a = 7;
    float b = 3.5f;
    double c = 2.25;

    // Somma
    cout << "a + b = " << a + b << endl;
    cout << "b + c = " << b + c << endl;
    cout << "a + c = " << a + c << endl;

    // Sottrazione
    cout << "a - b = " << a - b << endl;
    cout << "b - c = " << b - c << endl;
    cout << "a - c = " << a - c << endl;

    // Moltiplicazione
    cout << "a * b = " << a * b << endl;
    cout << "b * c = " << b * c << endl;
    cout << "a * c = " << a * c << endl;

    // Divisione
    cout << "a / b = " << a / b << endl;
    cout << "b / c = " << b / c << endl;
    cout << "a / c = " << a / c << endl;

    // Modulo (solo tra interi)
    cout << "a % 3 = " << a % 3 << endl;

    return 0;
}