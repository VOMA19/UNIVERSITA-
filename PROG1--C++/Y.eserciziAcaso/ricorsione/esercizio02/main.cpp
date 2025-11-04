#include <iostream>
using namespace std;

int sommaN_r(int a);

int main(){

    int a, b; 
    cout << "inserisci il primo numero: ";
    cin >> a;
    int somma = sommaN_r(a);
    cout << "la somma dei precedenti e': " << somma <<endl;
    return 0;
}

int sommaN_r(int a){
    if(a == 0)
        return 0;

    return a + sommaN_r(a - 1);
}