#include <iostream>
using namespace std;

bool isAbbondante(int num);

int main() {
    int a,b;

    do{
        cout << "inserisci i valori dell'intervallo"<<endl;
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;

        if(a>b)cout << "errore, A deve essere più piccola di B" <<endl;

    }while(a>b);

    for (int i = a; i < b; i++)
    {
        bool isA = isAbbondante(i);
        if(isA) 
            cout << "numero abbondante: " << i <<endl;            
        else 
            cout << "numero: " << i << " non è abbondante" <<endl;
    }
    return 0;
}

bool isAbbondante(int num){

    bool isA = false;
    
    int somma = 0;
    for(int i = 1; i < num; i++){
        if(num % i == 0)
            somma += i;
        if(somma > num)
            isA = true;
    }
    return isA;
}
