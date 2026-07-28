#include <iostream>


// Inserire qui la dichiarazione della funzione calcola

int calcola(const int v[], int n, int * & ris);

// Inserire qui sopra la dichiarazione della funzione calcola


int main() {
    const int n = 10;
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // array di input
    
    int * ris; // array per memorizzare le lunghezze dei segmenti crescenti
    int val = calcola(v, n, ris);

    std::cout << "Lunghezze: ";
    for (int i = 0; i < val; ++i) {
        std::cout << ris[i] << " ";
    }
    std::cout << std::endl;

    if (val > 0) {
        delete[] ris; // deallocazione dell'array dinamico
    }

    v[3] = 0;
    v[7] = 0;
    v[9] = 0;
    val = calcola(v, n, ris);
    std::cout << "Lunghezze: ";
    for (int i = 0; i < val; ++i) {
        std::cout << ris[i] << " ";
    }
    std::cout << std::endl;
    if (val > 0) {
        delete[] ris; // deallocazione dell'array dinamico
    }

    return 0;
}


// Inserire qui sotto la definizione della funzione calcola

// Inserire qui sopra la definizione della funzione calcola
