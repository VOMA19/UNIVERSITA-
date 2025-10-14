#include <iostream>
using namespace std;

/*
    Scrivere un programma che prende in input
    un numero intero e stampa a video se e’ un numero perfetto
    Un numero si dice ‘perfetto’ quando la
    somma di tutti i suoi divisori propri (tutti tranne se stesso), e’ uguale al numero stesso.
*/

bool isPerfetto(int n);

int main(){

    int n = 0;
    bool isP;

    cout << "insersci un numero: ";
    cin >> n;

    isP = isPerfetto(n);

    if(isP)
        cout << "il numero " << n << " è perfetto " << endl;
    else
        cout << "il numero " << n << " non è perfetto " << endl;

    return 0;
}

bool isPerfetto(int n){
    int somma = 0;
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            somma += i;
        }
    }
    return somma == n;

}