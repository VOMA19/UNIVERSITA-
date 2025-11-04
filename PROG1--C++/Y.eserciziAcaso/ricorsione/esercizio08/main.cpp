#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int arraySum(int numeri[], int size);
void fillArray(int numeri[]);
#define DIM 10

int main(){

    srand(time(0));
    int numeri[DIM];
    fillArray(numeri);
    int somma = arraySum(numeri, DIM);
    cout << "la somma di tutti i numeri nell'array e':" << somma << endl;
    return 0;
}

int arraySum(int numeri[], int size) {
    
    if(size == 0)
        return 0;
    if(size == 1)
        return numeri[0];
    return numeri[size-1]+arraySum(numeri, size-1);

}

void fillArray(int numeri[]){
    for (int i = 0; i < DIM; i++){
        numeri[i] = rand() % 10;
    }
}