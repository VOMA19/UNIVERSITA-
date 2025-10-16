#include <iostream>
using namespace std;

int main(){

    int m, n;
    cout << "Inserisci due numeri interi positivi (m e n)"<<endl;
    cout << "primo numero: ";
    cin >> m;
    cout << "secondo numero: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cout << m << " x " << i << " = " << m * i << endl;
    }

}