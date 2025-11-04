#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//counting sort
#define DIM 10
void fillArray(int numeri[]);
void countingSort(int numeri[]);
void printArray(int out[]);
int findMax(int numeri[]);

int main(){

    srand(time(0));
    int numeri[DIM];
    fillArray(numeri);
    countingSort(numeri);
    return 0;
}

void fillArray(int numeri[]){
    for (int i = 0; i < DIM; i++){
        numeri[i] = rand() % 100;
    }
}

void countingSort(int numeri[]){

    //trovo il massimo numero
    int max = findMax(numeri);

    //creo l'array in cui inserire i contatori dei numeri presenti in numeri, e lo inizializzo a 0
    int count[max+1];
    for (int i = 0; i < max+1; i++){
        count[i] = 0;
    }

    //conto le occorrenze di ogni numero
    for (int i = 0; i < DIM; i++){
        count[numeri[i]]++;
    }

    //imposto la casella i-esima pari alla somma delle precedenti
    for (int i = 0; i < max+1; i++){
        if(i != 0)
            count[i] = count[i-1]+count[i];
    }

    /*
        creo l'array out e ordino gli elementi, per farllo scelgo la casella basandomi sul valore del numero in prima posizione,
        posizionadomi poi in count in posizione pari a quel valore, 
        ci sottraggo 1 e posiziono il valore di numeri in quella posizione
    */

    int out[DIM];
    for (int i = 0; i < DIM; i++){
        out[count[numeri[i]]-1] = numeri[i];
        count[numeri[i]]--;
    }

    printArray(out);
}

int findMax(int numeri[]){
    int max = numeri[0];
    for (int i = 0; i < DIM; i++){
        if(numeri[i] > max)
            max = numeri[i];
    }
    return max;
}
void printArray(int out[]){
    for (int i = 0; i < DIM; i++){
        cout << out[i] << " ";
    }
}