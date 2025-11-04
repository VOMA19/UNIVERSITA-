#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define DIM 10
void fillArray(int numeri[]);
int trovaMassimo(int arr[], int inizio, int fine);

int main(){
    srand(time(0)); 
    int numeri[DIM];
    int tar;

    fillArray(numeri);
    sort(numeri, numeri + DIM);  //all'esame usa bubble sort ecc... :(

    cout << "Array ordinato: "; // Stampiamo l'array ordinato
    for (int i = 0; i < DIM; i++){
        cout << numeri[i] << " ";
    }
    

    int max = trovaMassimo(numeri, 0, DIM);
    cout << "il massimo e': " << max << endl;

    return 0;
}

// trovaMassimo: Ricorsivamente trova il massimo nell'intervallo [inizio, fine) dell'array arr.
// L'intervallo è semi-aperto: inizio è incluso, fine è escluso.
// Divide l'intervallo in due metà e confronta i massimi trovati.
int trovaMassimo(int arr[], int inizio, int fine){
        
    if (inizio == fine - 1)
        return arr[inizio];
    
    int meta = (inizio + fine) / 2;
    int max1 = trovaMassimo(arr, inizio, meta);
    int max2 = trovaMassimo(arr, meta, fine);
    return (max1 > max2) ? max1 : max2;

}

void fillArray(int numeri[]){
    for (int i = 0; i < DIM; i++){
        numeri[i] = rand() % 100;
    }
}