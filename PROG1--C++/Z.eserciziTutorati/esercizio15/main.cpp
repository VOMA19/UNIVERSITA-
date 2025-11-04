#include <iostream>
using namespace std;

int main() {
    const int n = 3; // Dimensione fissa

    double A[10][10], I[10][10];

    // Inizializza la matrice A (esempio)
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 0; A[1][1] = 1; A[1][2] = 4;
    A[2][0] = 5; A[2][1] = 6; A[2][2] = 0;

    // Inizializza la matrice identità
    /*
        1 0 0
        0 1 0
        0 0 1
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            I[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Metodo di Gauss-Jordan
    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];

        if (pivot == 0) {
            cout << "❌ La matrice non è invertibile (pivot nullo)." << endl;
            return 0;
        }

        for (int j = 0; j < n; j++) {
            A[i][j] = A[i][j] / pivot;
            I[i][j] = I[i][j] / pivot;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double fattore = A[k][i];
                for (int j = 0; j < n; j++) {
                    A[k][j] = A[k][j] - fattore * A[i][j];
                    I[k][j] = I[k][j] - fattore * I[i][j];
                }
            }
        }
    }

    cout << "\n✅ Matrice inversa:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << I[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
