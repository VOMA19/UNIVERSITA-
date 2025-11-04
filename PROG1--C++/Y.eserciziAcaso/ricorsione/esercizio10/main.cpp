#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define DIM 10
void fillArray(int numeri[]);
int numOcc(int numeri[], int n, int target);

int main(){
    srand(time(0)); 
    int numeri[DIM];
    int tar;

    fillArray(numeri);
    for (int i = 0; i < DIM; i++){
        cout << numeri[i] << " ";
    }
    cout << "scegli il numero da cercare: ";
    cin >> tar;

    int nocc = numOcc(numeri, DIM, tar);
    cout << "numero occorrenze: " << nocc << endl;

    return 0;
}

int numOcc(int numeri[], int n, int target){

    if(n == 0)
        return 0;
        
    int occorrenzeNelResto = numOcc(numeri, n - 1, target);

    // Ora controlla l'ultimo elemento (quello che abbiamo "lasciato fuori")
    if (numeri[n - 1] == target) {
        // Se l'abbiamo trovato, restituiamo 1 + il resto
        return 1 + occorrenzeNelResto;
    } else {
        // Altrimenti, restituiamo 0 + il resto (cioè solo il resto)
        return occorrenzeNelResto;
    }
}

void fillArray(int numeri[]){
    for (int i = 0; i < DIM; i++){
        numeri[i] = rand() % 10;
    }
}