#include <iostream>
using namespace std;

int main() {
    const double SQRT3 = 1.73205;
    double L;

    cout << "Inserisci la lunghezza del lato dell'esagono: ";
    cin >> L;

    double perimetro = 6 * L;
    double area = (3 * L * L * SQRT3) / 2;

    cout << "Perimetro: " << perimetro << endl;
    cout << "Area: " << area << endl;

    return 0;
}