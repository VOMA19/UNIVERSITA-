#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int* generaArray(int n) {
    int* array = new int[n];
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100; // numeri da 0 a 99
    }
    
    return array;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <numero>" << endl;
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (n <= 0) {
        cout << "Inserire un numero positivo" << endl;
        return 1;
    }
    
    int* numeri = generaArray(n);
    
    cout << "Numeri generati: ";
    for (int i = 0; i < n; i++) {
        cout << numeri[i] << " ";
    }
    cout << endl;
    
    delete[] numeri;
    
    return 0;
}