#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <righe> <colonne>" << endl;
        return 1;
    }

    int R = atoi(argv[1]);
    int C = atoi(argv[2]);

    if (R <= 0 || C <= 0) {
        cout << "Le dimensioni devono essere positive" << endl;
        return 1;
    }

    // Creazione dinamica della matrice
    int** matrice = new int*[R];
    for (int i = 0; i < R; i++) {
        matrice[i] = new int[C];
    }

    // Inizializzazione del generatore di numeri casuali
    srand(time(nullptr));

    // Popolamento della matrice con numeri random
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            matrice[i][j] = rand() % 100 + 1;
        }
    }

    // Stampa della matrice
    cout << "Matrice " << R << "x" << C << ":" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << matrice[i][j] << "\t";
        }
        cout << endl;
    }

    // Deallocazione memoria
    for (int i = 0; i < R; i++) {
        delete[] matrice[i];
    }
    delete[] matrice;

    return 0;
}
