#include <iostream>
using namespace std;

double sconta_valore(double p, int s);
double sconta_riferimento(const double& p, const int& s);
double sconta_indirizzo(const double* p, const int* s);

int main() {
    double prezzo = 100.0;
    int sconto = 20;

    cout << "Passaggio per valore: " << sconta_valore(prezzo, sconto) << endl;
    cout << "Passaggio per riferimento: " << sconta_riferimento(prezzo, sconto) << endl;
    cout << "Passaggio per indirizzo: " << sconta_indirizzo(&prezzo, &sconto) << endl;

    return 0;
}

// Passaggio per valore
double sconta_valore(double p, int s){
    return p * (1.0 - s / 100.0);
}

// Passaggio per riferimento
double sconta_riferimento(const double& p, const int& s) {
    return p * (1.0 - s / 100.0);
}

// Passaggio per indirizzo
double sconta_indirizzo(const double* p, const int* s) {
    return (*p) * (1.0 - (*s) / 100.0);
}