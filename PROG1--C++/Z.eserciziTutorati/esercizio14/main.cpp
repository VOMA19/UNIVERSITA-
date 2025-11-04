#include <iostream>
using namespace std;

/*
    Scrivere un programma che calcola il
    determinante di una matrice 3x3 usando
    il metodo che si preferisce (Strauss)
*/

void matrixFill(double matrix[][3]);
double calcolaDet(double matrix[][3]);

int main(){

    double matrix[3][3];
    matrixFill(matrix);
    double det = calcolaDet(matrix);

    cout << "\nDeterminante: " << det << endl;

    return 0;
}

// Input della matrice
void matrixFill(double matrix[][3]){
    cout << "Inserisci gli elementi della matrice 3x3:" << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
}

/*
    1 4 7 | 1 4
    2 5 8 | 2 5 
    3 6 9 | 3 6
*/

// Calcolo determinante con regola di Sarrus
double calcolaDet(double matrix[][3]){
    
    double det =    matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][0] +
                    matrix[0][2] * matrix[1][0] * matrix[2][1] -
                    matrix[0][2] * matrix[1][1] * matrix[2][0] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1] -
                    matrix[0][1] * matrix[1][0] * matrix[2][2];
    return det;
}