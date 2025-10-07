#include <iostream>
using namespace std;

/*
    Scrivere un programma che, dati in input i lati di un triangolo, ritorni a video se il triangolo ` e isoscele,
    equilatero o scaleno;
*/

int main(){

    float l1, l2, l3;
    cout << "inserisci i lato del traingolo: ";
    cin >> l1 >> l2 >> l3;

    if(l1 == l2 && l2 == l3){
        cout << "il triangolo è equilatero" <<endl;
    }else if(l1 != l2 && l1 != l3 && l2 != l3){
        cout << "il triangolo è scaleno" <<endl;
    }else{
        cout << "il triangolo è isoscele"<<endl;
    }

    return 0;
}