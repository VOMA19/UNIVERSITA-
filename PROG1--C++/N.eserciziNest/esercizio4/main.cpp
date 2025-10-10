#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

int lancioDadi();

int main(){

    int numeroVolte;
    srand(time(0)); // Inizializza il generatore di numeri casuali

    cout << "quante volte vuoi lanciare i dadi? ";
    cin >> numeroVolte;
    for(int i = 0; i < numeroVolte; i++){
        int numeroSegreto = lancioDadi();
        cout << "numero: " << i+1 << ": " << numeroSegreto <<endl;
    }

    return 0;
}

int lancioDadi(){
    return rand() % 6 + 1;
}