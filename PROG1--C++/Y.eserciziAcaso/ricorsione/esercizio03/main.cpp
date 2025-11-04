#include <iostream>
using namespace std;

int potenza(int a, int b);

int main(){

    int a, b; 
    cout << "inserisci la base: ";
    cin >> a;
    cout << "inserisci l'esponente: ";
    cin >> b;
    int pot=potenza(a,b);
    cout << "il risultato e': " << pot <<endl;

    return 0;
}

//5^5 --> 5*5^4 --> 5*5*5^3 

int potenza(int a, int b){

    if(b == 0)
        return 1;

    return a*potenza(a, b-1);
}