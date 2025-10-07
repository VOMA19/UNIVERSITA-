#include <iostream>
using namespace std;
/*

    Scrivere un programma che, dato in input il valore numerico di un mese, ritorni a video il corrispondente
    nome di quel mese (e.g., 1-Gennaio,..., 12-Dicembre);

 */
int main(){

    int numeroMese;

    cout<< "inserisci il numero di cui vuoi sapere il mese: ";
    cin >> numeroMese;

    switch(numeroMese){
        case 1:
            cout << "il mese numero " << numeroMese << " è: Gennaio" <<endl;
            break;
        case 2:
            cout << "il mese numero " << numeroMese << " è: Febbraio" <<endl;
            break;
        case 3:
            cout << "il mese numero " << numeroMese << " è: Marzo" <<endl;
            break;
        case 4:
            cout << "il mese numero " << numeroMese << " è: Aprile" <<endl;
            break;
        case 5:
            cout << "il mese numero " << numeroMese << " è: Maggio" <<endl;
            break;
        case 6:
            cout << "il mese numero " << numeroMese << " è: Giugno" <<endl;
            break;
        case 7:
            cout << "il mese numero " << numeroMese << " è: Luglio" <<endl;
            break;
        case 8:
            cout << "il mese numero " << numeroMese << " è: Agosto" <<endl;
            break;
        case 9:
            cout << "il mese numero " << numeroMese << " è: Settembre" <<endl;
            break;
        case 10:
            cout << "il mese numero " << numeroMese << " è: Ottobre" <<endl;
            break;
        case 11:
            cout << "il mese numero " << numeroMese << " è: Novembre" <<endl;
            break;
        case 12:
            cout << "il mese numero " << numeroMese << " è: Dicembre" <<endl;
            break;
        default:
            cout << "valore non valido" <<endl;
            break;
    }
    return 0;
}