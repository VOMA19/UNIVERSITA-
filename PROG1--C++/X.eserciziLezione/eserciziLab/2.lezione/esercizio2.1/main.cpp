#include <iostream>
using namespace std;

/*

    Scrivere un programma che, dato in input un valore intero n,
    stampi a video la successione di fibonacci fino all’n-esima cifra.

*/

void fibonacci(int n);

int main(){
    int n = 0;
    cout << "Inserisci un numero intero n: ";
    cin >> n;
    fibonacci(n);
}

void fibonacci(int n){
    int next = 0;
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        cout << next << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}