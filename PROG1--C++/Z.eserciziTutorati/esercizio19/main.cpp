#include <iostream>

using namespace std;
/*
    Scrivere un programma che prende in input
    da riga di comando dei valori in formato:
    N v1 v2 v3 … vN
    Dove N e’ intero e gli altri sono decimali.
    Creare un array dinamico con quei valori,
    ordinarlo e poi stamparlo.
*/
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: program N v1 v2 ... vN" << endl;
        return 1;
    }
    
    int N = atoi(argv[1]);
    
    if (argc != N + 2) {
        cout << "Error: expected " << N << " values" << endl;
        return 1;
    }
    
    double* arr = new double[N];
    
    // Read values from command line
    for (int i = 0; i < N; i++) {
        arr[i] = atof(argv[i + 2]);
    }
    
    // Sort array (bubble sort)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) cout << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}