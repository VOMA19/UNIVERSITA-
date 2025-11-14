#include <iostream>
using namespace std;

void sommaRicorsivaBinaria(int bin1[], int bin2[], int bin3[], int index1, int index2, int index3, int riporto);
int getLength(int bin[]);

int main(){
    
    int bin_1[] = {1,1,-1};
    int bin_2[] = {1,0,1,-1};
    int bin_3[100] = {0};
    
    sommaRicorsivaBinaria(bin_1, bin_2, bin_3, getLength(bin_1)-1, getLength(bin_2)-1, 0, 0);
    
    cout << "Somma binaria: ";
    int len = getLength(bin_3);
    for(int i = len - 1; i >= 0; i--){
        cout << bin_3[i];
    }
    cout << endl;
    return 0;
}

void sommaRicorsivaBinaria(int bin1[], int bin2[], int bin3[], int index1, int index2, int index3, int riporto){
    if(index1 < 0 && index2 < 0 && riporto == 0){
        bin3[index3] = -1;
        return;
    }
    
    int b1 = (index1 >= 0) ? bin1[index1] : 0;
    int b2 = (index2 >= 0) ? bin2[index2] : 0;

    int somma = b1 + b2 + riporto;
    bin3[index3] = somma % 2;
    int nuovoRiporto = somma / 2;
    
    sommaRicorsivaBinaria(bin1, bin2, bin3, index1 - 1, index2 - 1, index3 + 1, nuovoRiporto);
}

int getLength(int bin[]){
    int i = 0;
    while(bin[i] != -1) 
        i++;
    return i;
}