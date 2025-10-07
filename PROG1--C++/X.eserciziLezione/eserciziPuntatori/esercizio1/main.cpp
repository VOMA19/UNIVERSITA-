#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int x = 1;
    int &y = x;
    int *ptr = &x;

    cout << left << setw(40) << "Valore di x (x):" << setw(15) << x << endl;
    cout << left << setw(40) << "Valore di y (riferimento a x)(y):" << setw(15) << y << endl;
    cout << left << setw(40) << "Indirizzo di x(&x):" << setw(15) << &x << endl;
    cout << left << setw(40) << "Indirizzo di y (riferimento a x)(&y):" << setw(15) << &y << endl;
    cout << left << setw(40) << "Valore di ptr (indirizzo di x)(ptr):" << setw(15) << ptr << endl;
    cout << left << setw(40) << "Valore puntato da ptr (*ptr)(*ptr):" << setw(15) << *ptr << endl;
    cout << left << setw(40) << "Indirizzo di ptr(&ptr):" << setw(15) << &ptr << endl;
    cout << endl;

    y = 6;

    cout << "Dopo aver assegnato y = 6:" << endl;
    cout << left << setw(40) << "Valore di x (x):" << setw(15) << x << endl;
    cout << left << setw(40) << "Valore di y (riferimento a x)(y):" << setw(15) << y << endl;
    cout << left << setw(40) << "Indirizzo di x(&x):" << setw(15) << &x << endl;
    cout << left << setw(40) << "Indirizzo di y (riferimento a x)(&y):" << setw(15) << &y << endl;
    cout << left << setw(40) << "Valore di ptr (indirizzo di x)(ptr):" << setw(15) << ptr << endl;
    cout << left << setw(40) << "Valore puntato da ptr (*ptr)(*ptr):" << setw(15) << *ptr << endl;
    cout << left << setw(40) << "Indirizzo di ptr(&ptr):" << setw(15) << &ptr << endl;
    cout << endl;
    
    *ptr = 10;

    cout << "Dopo aver assegnato *ptr = 10:" << endl;
    cout << left << setw(40) << "Valore di x (x):" << setw(15) << x << endl;
    cout << left << setw(40) << "Valore di y (riferimento a x)(y):" << setw(15) << y << endl;
    cout << left << setw(40) << "Indirizzo di x(&x):" << setw(15) << &x << endl;
    cout << left << setw(40) << "Indirizzo di y (riferimento a x)(&y):" << setw(15) << &y << endl;
    cout << left << setw(40) << "Valore di ptr (indirizzo di x)(ptr):" << setw(15) << ptr << endl;
    cout << left << setw(40) << "Valore puntato da ptr (*ptr):" << setw(15) << *ptr << endl;
    cout << left << setw(40) << "Indirizzo di ptr(&ptr):" << setw(15) << &ptr << endl;
    cout << endl;

    return 0;
}