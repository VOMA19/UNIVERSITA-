#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Scrivere un programma che dichiari e poi inizializzi (con valori random) una matrice di 10x10 interi
    con valore 0 oppure 1. Scrivere poi una funzione che torni il numero di “isole”, definite come elementi 
    della matrice con valore 1 circondati da soli zeri (nell’immagine proposta come esempio qui sotto questo    
    esercizio, ci sono 2 isole). Si pu` o utilizzare la funzione rand della libreria <cstdlib>.
*/
void printMatrix(int mat[10][10]);
void fillMatrixRandom(int mat[10][10]);
int findIsole(int mat[10][10]);
int main(){

    int mat[10][10];
    fillMatrixRandom(mat);
    // Create a specific matrix with 3 islands for testing
    int testMat[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    printMatrix(testMat);
    cout << "Number of islands: " << findIsole(testMat) << endl;

    return 0;
}

void printMatrix(int mat[10][10]){
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrixRandom(int mat[10][10]){
    for (int i = 0; i < 10; i++){
        for(int j = 0; j< 10; j++){
            mat[i][j] = rand() % 2;
        }
    }
}

int findIsole(int mat[10][10]){
    int num = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(mat[i][j] == 1){
                bool isIsland = true;
                // Check all 8 surrounding positions
                for(int di = -1; di <= 1; di++){
                    for(int dj = -1; dj <= 1; dj++){
                        if(di == 0 && dj == 0) continue; // Skip the center cell
                        int ni = i + di;
                        int nj = j + dj;
                        // Check if the neighbor is within bounds and is 1
                        if(ni >= 0 && ni < 10 && nj >= 0 && nj < 10){
                            if(mat[ni][nj] == 1){
                                isIsland = false;
                                break;
                            }
                        }
                    }
                    if(!isIsland) break;
                }
                if(isIsland) num++;
            }
        }
    }
    return num;
}