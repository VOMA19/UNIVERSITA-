#include <iostream>
using namespace std;

int main() {
    double x, y;
    double a, b, c, d;

    cout << "Inserisci le coordinate del punto (x y): ";
    cin >> x >> y;

    cout << "Inserisci le coordinate del vertice in alto a sinistra del rettangolo (a b): ";
    cin >> a >> b;

    cout << "Inserisci le coordinate del vertice in basso a destra del rettangolo (c d): ";
    cin >> c >> d;

    // Assumiamo che (a, b) sia in alto a sinistra e (c, d) in basso a destra
    if (x >= a && x <= c && y <= b && y >= d) {
        cout << "Il punto (" << x << ", " << y << ") si trova all'interno del rettangolo." << endl;
    } else {
        cout << "Il punto (" << x << ", " << y << ") NON si trova all'interno del rettangolo." << endl;
    }

    return 0;
}