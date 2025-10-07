#include <iostream>
using namespace std;
/*
    Scrivere un programma che prende in input
    un numero intero e stampa a video se e’ un numero primo.
*/

bool isPrimo(int n);

int main(){
    
    int n = 0;
    bool isP;
    cout << "inserisci un numero: ";
    cin >> n;

    isP = isPrimo(n);

    if(isP){
        cout << "il numero: " << n << " e' primo " << endl;
    }else{
        cout << "il numero: " << n << " non e' primo " << endl;
    }
    return 0;
}

bool isPrimo(int n){

    for(int i = 0; i < n/2; i++){
        if(n%2 == 0){
            return false;
        }else if(n%i == 0){
            return false;
        }else
            return true;
    }
    return false;
}