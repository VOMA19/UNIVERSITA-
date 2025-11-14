#include <iostream>
using namespace std;

#define N 10

void fillMatrixSpiral(int mat[N][N]);
int sumColumn(int mat[N][N], int col);
void printMatrix(int mat[N][N]);

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
    int top = 0, bottom = N-1, left = 0, right = N-1;
    int num = 1;
    
    while (top <= bottom && left <= right) {
        // Destra
        for (int i = left; i <= right; i++)
            mat[top][i] = num++;
        top++;
        
        // Basso
        for (int i = top; i <= bottom; i++)
            mat[i][right] = num++;
        right--;
        
        // Sinistra
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                mat[bottom][i] = num++;
            bottom--;
        }
        
        // Alto
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                mat[i][left] = num++;
            left++;
        }
    }
}

int sumColumn(int mat[N][N], int col) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += mat[i][col];
    return sum;
}
void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}