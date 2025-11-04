#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> 

using namespace std;

#define DIM 10
void fillArray(int numeri[]);
bool ricercaBinaria(int arr[], int inizio, int fine, int target);

int main(){
    srand(time(0)); // Meglio metterlo in main
    int numeri[DIM];
    int tar;

    fillArray(numeri);
    
    // 2. ORDINA L'ARRAY
    sort(numeri, numeri + DIM);  //all'esame usa bubble sort ecc... :(

    cout << "Array ordinato: "; // Stampiamo l'array ordinato
    for (int i = 0; i < DIM; i++){
        cout << numeri[i] << " ";
    }
    cout << endl << "Inserisci valore da cercare: ";
    cin >> tar;

    // 3. La tua chiamata (è corretta per la tua implementazione)
    bool trov = ricercaBinaria(numeri, 0, DIM, tar); 
    
    if(trov) cout << "valore trovato" <<endl;
    else cout << "valore non trovato" <<endl;
    return 0;
}

bool ricercaBinaria(int arr[], int inizio, int fine, int target){
    if (inizio >= fine)
        return false;
    
    int mid = (inizio + fine) / 2;
    
    if (arr[mid] == target)
        return true;
    else if (arr[mid] < target)
        return ricercaBinaria(arr, mid + 1, fine, target);
    else
        return ricercaBinaria(arr, inizio, mid, target);
}

void fillArray(int numeri[]){
    for (int i = 0; i < DIM; i++){
        numeri[i] = rand() % 10;
    }
}