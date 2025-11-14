#include <iostream>
using namespace std;

void sommaRicorsivaBinaria(int bin1[], int bin2[], int bin3[], int i, int riporto);

int main(){
    int bin1[]= {0,1,1,1,0,1,0,1};
    int bin2[]= {1,1,1,0,0,1,1,1};
    int bin3[9] = {0};
    
    sommaRicorsivaBinaria(bin1, bin2, bin3, 0, 0);
    
    cout << "Somma binaria: ";
    for(int i = 8; i >= 0; i--){
        cout << bin3[i];
    }
    cout << endl;
    return 0;
}

void sommaRicorsivaBinaria(int bin1[], int bin2[], int bin3[], int i, int riporto){
    if(i == 8 && riporto == 0) 
        return;

    int somma = bin1[i] + bin2[i] + riporto;
    bin3[i] = somma % 2;
    int nuovoRiporto = somma / 2;

    if(i < 8){
        sommaRicorsivaBinaria(bin1, bin2, bin3, i + 1, nuovoRiporto);
    }
}