#include <iostream>
using namespace std;

/*
    Scrivere un programma che, dati in input tre valori dall’utente, riporti a video il maggiore di questi tre
    valori (interi, float, caratteri, etc,);
*/

int main(){
    int a, b, c;
    cout << "Inserisci tre numeri interi: ";
    cin >> a >> b >> c;

    if(a >= b && a >= c){
        cout << "Il maggiore e': " << a << endl;
    } else if(b >= a && b >= c){
        cout << "Il maggiore e': " << b << endl;
    } else {
        cout << "Il maggiore e': " << c << endl;
    }   

    return 0;
}