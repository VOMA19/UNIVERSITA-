#include <iostream>
using namespace std;

#define N 7

void riempiMatriceSpiral(int mat[N][N]); 
void riempiMatriceSpiraleRic(int mat[N][N], int alto, int basso, int sinistra, int destra, int &num);  
void riempiDestraRic(int mat[N][N], int riga, int col, int destra, int &num);  
void riempiGiuRic(int mat[N][N], int riga, int basso, int col, int &num);  
void riempiSinistraRic(int mat[N][N], int riga, int sinistra, int col, int &num);   
void riempiSuRic(int mat[N][N], int riga, int alto, int col, int &num);      
int sommaColonna(int mat[N][N], int col); 
int sommaColonnaRic(int mat[N][N], int col, int riga);  
void stampaMatrice(int mat[N][N]);  
void stampaMatriceRic(int mat[N][N], int riga, int col);  

int main() {
    int mat[N][N];
    riempiMatriceSpiral(mat);  
    stampaMatrice(mat);       

    int column;
    cout << "Inserisci il numero della colonna (0-" << N-1 << "): ";
    cin >> column;
    
    if (column >= 0 && column < N) {
        cout << "Somma colonna " << column << ": " << sommaColonna(mat, column) << endl;
    }
    
    return 0;
}

// Funzione wrapper per iniziare il riempimento spirale
void riempiMatriceSpiral(int mat[N][N]) {
    int num = 1;  // Contatore che inizia da 1
    riempiMatriceSpiraleRic(mat, 0, N-1, 0, N-1, num);
}

// Riempie ricorsivamente da sinistra a destra
void riempiDestraRic(int mat[N][N], int riga, int col, int destra, int &num) {
    if (col > destra) 
        return;  // Caso base: superato il limite destro
    
    mat[riga][col] = num++;    // Assegna il numero corrente e incrementa
    riempiDestraRic(mat, riga, col + 1, destra, num);  // Ricorsione sulla colonna successiva
}

// Riempie ricorsivamente dall'alto in basso
void riempiGiuRic(int mat[N][N], int riga, int basso, int col, int &num) {
    if (riga > basso) 
        return;  // Caso base: superato il limite inferiore
    
    mat[riga][col] = num++;     // Assegna il numero corrente e incrementa
    riempiGiuRic(mat, riga + 1, basso, col, num);  // Ricorsione sulla riga successiva
}

// Riempie ricorsivamente da destra a sinistra
void riempiSinistraRic(int mat[N][N], int riga, int sinistra, int col, int &num) {
    if (col < sinistra) 
        return;   // Caso base: superato il limite sinistro
    
    mat[riga][col] = num++;    // Assegna il numero corrente e incrementa
    riempiSinistraRic(mat, riga, sinistra, col - 1, num);  // Ricorsione sulla colonna precedente
}

// Riempie ricorsivamente dal basso verso l'alto
void riempiSuRic(int mat[N][N], int riga, int alto, int col, int &num) {
    if (riga < alto) 
        return;    // Caso base: superato il limite superiore
    
    mat[riga][col] = num++;    // Assegna il numero corrente e incrementa
    riempiSuRic(mat, riga - 1, alto, col, num);  // Ricorsione sulla riga precedente
}

// Funzione ricorsiva principale per il riempimento a spirale
void riempiMatriceSpiraleRic(int mat[N][N], int alto, int basso, int sinistra, int destra, int &num) {
    if (alto > basso || sinistra > destra) 
        return;  // Caso base: limiti incrociati
    
    // Riempie il lato superiore (da sinistra a destra)
    riempiDestraRic(mat, alto, sinistra, destra, num);
    
    // Riempie il lato destro (dall'alto in basso, saltando l'angolo già riempito)
    riempiGiuRic(mat, alto + 1, basso, destra, num);
    
    // Riempie il lato inferiore (da destra a sinistra) solo se c'è più di una riga
    if (alto < basso) {
        riempiSinistraRic(mat, basso, sinistra, destra - 1, num);
    }
    
    // Riempie il lato sinistro (dal basso verso l'alto) solo se c'è più di una colonna
    if (sinistra < destra) {
        riempiSuRic(mat, basso - 1, alto + 1, sinistra, num);
    }
    
    // Ricorsione per lo strato interno della spirale
    riempiMatriceSpiraleRic(mat, alto+1, basso-1, sinistra+1, destra-1, num);
}

// Funzione wrapper per calcolare la somma di una colonna
int sommaColonna(int mat[N][N], int col) {
    return sommaColonnaRic(mat, col, 0);  // Inizia dalla riga 0
}

// Calcola ricorsivamente la somma degli elementi di una colonna
int sommaColonnaRic(int mat[N][N], int col, int riga) {
    if (riga >= N) 
        return 0;  // Caso base: fine della colonna
    
    return mat[riga][col] + sommaColonnaRic(mat, col, riga + 1);  // Somma elemento corrente + ricorsione
}

// Funzione wrapper per stampare la matrice
void stampaMatrice(int mat[N][N]) {
    stampaMatriceRic(mat, 0, 0);  // Inizia dalla posizione (0,0)
}

// Stampa ricorsivamente la matrice
void stampaMatriceRic(int mat[N][N], int riga, int col) {
    if (riga >= N) 
        return;  // Caso base: fine della matrice
    
    cout << mat[riga][col] << "\t";  // Stampa l'elemento corrente
    
    if (col == N-1) {  // Fine della riga
        cout << endl;
        stampaMatriceRic(mat, riga + 1, 0);  // Vai alla riga successiva
    } else {
        stampaMatriceRic(mat, riga, col + 1);  // Vai alla colonna successiva
    }
}