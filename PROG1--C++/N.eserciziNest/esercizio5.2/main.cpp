#include <iostream>
using namespace std;

int eliminaRicorsivo(int arr[], int i);

int main() {
    int arr[] = {10, 93, 3, 73, 22, 14, 22, 5, 10, -1};

    eliminaRicorsivo(arr, 0);

    cout << "Risultato: ";
    for (int i = 0; arr[i] != -1; i++) {
        cout << arr[i];
        if(arr[i+1] != -1) cout << ",";
    }
    cout << endl;

    return 0;
}

int eliminaRicorsivo(int arr[], int i) {
    if (arr[i] == -1) 
        return 0;
    
    if (arr[i+1] == -1) {
        return arr[i]; 
    }

    int sommaValidiSuccessivi = eliminaRicorsivo(arr, i + 1);

    if (arr[i] >= sommaValidiSuccessivi) {
        arr[i] = 0; 
        return sommaValidiSuccessivi; 
    }else{
        return sommaValidiSuccessivi + arr[i];
    }
}