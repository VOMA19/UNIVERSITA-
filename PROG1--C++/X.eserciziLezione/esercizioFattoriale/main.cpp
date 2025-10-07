#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main(){

    int numero = 0;
    cpp_int fattoriale = 1;

    cout << "inserisci il numero di cui vuoi calcolare il fattoriale: ";
    cin >> numero;

    while(numero != 0){
        fattoriale *= numero;
        numero --;
    }

    cout << fattoriale << endl;
    return 0;
}
