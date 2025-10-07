#include <iostream>
#include <cmath>
#include <cstdlib>

double calcolaSerie(int N) {
    double somma = 0.0;
    for (int n = 1; n <= N; ++n) {
        somma += 1.0 / (n * n);
    }
    return somma;
}

double approssimaPiGreco(double somma) {
    return std::sqrt(6 * somma);
}

int main(int argc, char* argv[]) {
    int N;
    std::cout << "Inserisci il valore di N: ";
    std::cin >> N;

    double somma = calcolaSerie(N);
    double pi_approssimato = approssimaPiGreco(somma);

    std::cout << "Somma della serie: " << somma << std::endl;
    std::cout << "Valore approssimato di pi greco: " << pi_approssimato << std::endl;

    return 0;
}