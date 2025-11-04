#include <iostream>
using namespace std;

int somma_r(int a, int b);

int main(){

    int a, b; 
    cout << "inserisci il primo numero: ";
    cin >> a;
    cout << "inserisci il secondo numero: ";
    cin >> b;
    int somma = somma_r(a,b);
    cout << "la loro somma è: " << somma <<endl;
    return 0;
}

int somma_r(int a, int b){

    if (b == 0) return a;
    return somma_r(a + 1, b - 1);

}