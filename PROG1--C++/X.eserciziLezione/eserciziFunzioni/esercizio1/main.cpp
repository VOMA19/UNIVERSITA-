#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void somma(int &a, int &b);
void saluta();
void stampa_circonferenza(double r);
void stampa_stella(int lunghezza);

int main() {
    int x, y;
    
    cout << "Inserisci due numeri interi: ";
    cin >> x >> y;
    somma(x, y);
    saluta();
    stampa_circonferenza(10.0);
    stampa_stella(11);
    cout << setw(10) << "Fine" << endl;
    return 0;
}

void somma( int &a, int &b) {
    cout << a + b <<endl;
}

void saluta() {
    cout << "Ciao!" << endl;
}


void stampa_circonferenza(double r) {
    const int diametro = static_cast<int>(r * 2);
    for (int y = 0; y <= diametro; ++y) {
        for (int x = 0; x <= diametro; ++x) {
            double dx = x - r;
            double dy = y - r;
            double distanza = sqrt(dx * dx + dy * dy);
            if (fabs(distanza - r) < 0.5)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void stampa_stella(int lunghezza) {
    int centro = lunghezza / 2;
    for (int y = 0; y < lunghezza; ++y) {
        for (int x = 0; x < lunghezza; ++x) {
            if (x == centro || y == centro || x == y || x == lunghezza - y - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}