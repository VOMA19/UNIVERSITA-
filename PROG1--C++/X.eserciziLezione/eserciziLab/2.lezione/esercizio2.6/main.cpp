#include <iostream>
#include <cstdlib>
using namespace std;

int generaNumero();

int main(){
    srand(time(0)); // Inizializza il generatore di numeri casuali

    int numeroSegreto = generaNumero();
    int tentativo;

    cout << "Indovina il numero (tra 1 e 10): ";

    do {
        cin >> tentativo;
        if (tentativo != numeroSegreto) {
            cout << "Sbagliato! Riprova: ";
        }
    } while (tentativo != numeroSegreto);

    cout << "Bravo! Hai indovinato." << endl;
    return 0;
}

int generaNumero() {
    return rand() % 10 + 1;
}