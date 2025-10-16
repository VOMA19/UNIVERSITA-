#include <iostream>
using namespace std;

#define N 5

int Bancarella[N][N] = {{5,2,3,4,2},{5,6,7,8,0},{7,2,3,6,8},{8,2,5,4,2},{6,2,6,2,4}};
int Supporto[N][N] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

int main(){

    int minCosto;
    int minX = 0, minY = 0;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Supporto[i][j] = Bancarella[i][j] + Bancarella[j][i];
        }
    }

    minCosto = Supporto[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(Supporto[i][j] < minCosto){
                minCosto = Supporto[i][j];
                minX = i;
                minY = j;
            }

        }
    }

    for(int i = 0; i< N ; i++){
        for (int j = 0; j < N; j++){
            cout << Supporto[i][j] << endl;
        }
    }

    cout << "\nCosto minimo: " << minCosto << " in posizione (" << minX << ", " << minY << ")\n";
    return 0;
}