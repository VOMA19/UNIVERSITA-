#include <iostream>
using namespace std;

#define N 10

void fillMatrixSpiral(int mat[N][N]);
void fillMatrixSpiralRec(int mat[N][N], int top, int bottom, int left, int right, int &num);
int sumColumn(int mat[N][N], int col);
int sumColumnRec(int mat[N][N], int col, int row);
void printMatrix(int mat[N][N]);
void printMatrixRec(int mat[N][N], int row, int col);

int main(){
    int mat[N][N];
    fillMatrixSpiral(mat);
    printMatrix(mat);

    int column;
    cout << "Inserisci il numero della colonna (0-" << N-1 << "): ";
    cin >> column;
    
    if (column >= 0 && column < N) {
        cout << "Somma colonna " << column << ": " << sumColumn(mat, column) << endl;
    }
    
    return 0;
}

void fillMatrixSpiral(int mat[N][N]) {
    int num = 1;
    fillMatrixSpiralRec(mat, 0, N-1, 0, N-1, num);
}

void fillMatrixSpiralRec(int mat[N][N], int top, int bottom, int left, int right, int &num) {
    if (top > bottom || left > right) return;
    
    // Destra
    for (int i = left; i <= right; i++)
        mat[top][i] = num++;
    
    // Basso
    for (int i = top+1; i <= bottom; i++)
        mat[i][right] = num++;
    
    // Sinistra
    if (top < bottom) {
        for (int i = right-1; i >= left; i--)
            mat[bottom][i] = num++;
    }
    
    // Alto
    if (left < right) {
        for (int i = bottom-1; i >= top+1; i--)
            mat[i][left] = num++;
    }
    
    fillMatrixSpiralRec(mat, top+1, bottom-1, left+1, right-1, num);
}

int sumColumn(int mat[N][N], int col) {
    return sumColumnRec(mat, col, 0);
}

int sumColumnRec(int mat[N][N], int col, int row) {
    if (row >= N) return 0;
    return mat[row][col] + sumColumnRec(mat, col, row + 1);
}

void printMatrix(int mat[N][N]) {
    printMatrixRec(mat, 0, 0);
}

void printMatrixRec(int mat[N][N], int row, int col) {
    if (row >= N) return;
    
    cout << mat[row][col] << "\t";
    
    if (col == N-1) {
        cout << endl;
        printMatrixRec(mat, row + 1, 0);
    } else {
        printMatrixRec(mat, row, col + 1);
    }
}