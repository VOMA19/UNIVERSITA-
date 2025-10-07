#include <iostream>
using namespace std;

// Funzione per calcolare la radice quadrata (metodo di Newton-Raphson)
double mysqrt(double n);

int main() {
    double a, b, c;
    cout << "Inserisci i coefficienti a, b, c dell'equazione ax^2 + bx + c = 0:"<<endl;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "L'equazione e' indeterminata: infinite soluzioni."<<endl;
    }
    else if (a == 0 && b == 0) {
        cout << "L'equazione e' impossibile: nessuna soluzione."<<endl;
    }
    else if (a == 0) {
        double x = -c / b;
        cout << "Equazione di primo grado. Soluzione: x = " << x <<endl;
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "L'equazione non ha soluzioni reali.\n";
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "L'equazione ha una soluzione doppia: x = " << x <<endl;
        } else {
            double rad = mysqrt(delta);
            double x1 = (-b + rad) / (2 * a);
            double x2 = (-b - rad) / (2 * a);
            cout << "Le soluzioni sono:\n";
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2 << "\n";
        }
    }

    return 0;
}

double mysqrt(double n) {
    if (n < 0) return -1; // errore per numeri negativi
    if (n == 0) return 0;
    double x = n;
    double y = 0.0;
    while (abs(x - y) > 1e-9) {
        y = x;
        x = 0.5 * (x + n / x);
    }
    return x;
}