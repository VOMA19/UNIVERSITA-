#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double calcolaSerie(int N) {
    double somma = 0.0;
    for (int n = 1; n <= N; ++n) {
        somma += 1.0 / (n * n);
    }
    return somma;
}

double approssimaPiGreco(double somma) {
    return sqrt(6 * somma);
}

int main(int argc, char* argv[]) {
    int N;
    cout << "Inserisci il valore di N: ";
    cin >> N;

    double somma = calcolaSerie(N);
    double pi_approssimato = approssimaPiGreco(somma);

    cout << "Somma della serie: " << somma << endl;
    cout << "Valore approssimato di pi greco: " << pi_approssimato << endl;

    return 0;
}