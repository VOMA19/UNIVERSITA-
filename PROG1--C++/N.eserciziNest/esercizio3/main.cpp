#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Inserisci un numero: ";
    cin >> n;

    if(n < 0 ){
        cout << "errore, il valore deve essere maggiore di 0"<<endl;
    }else if(n == 0){
        cout << "0" << endl;
    }else{

        int bits[32];
        int i = 0;

        while (n > 0) {
            bits[i++] = n % 2;
            n /= 2;
        }

        for (int j = i - 1; j >= 0; --j){
            cout << bits[j];
        }
        cout << endl;
    }

}