#include <iostream>
using namespace std;

//Scrivere un programma che, tramite dei cicli for, disegni le seguenti figure:
//quadrato vuoto
//triangolo rettangolo isoscele vuoto
//quadrato con diagonali
//rombo usando ‘^’ ‘v’ ‘/’ ‘\’ ‘+’ ‘-’ ‘|’ con diagolali 

void stampaQuadrato(int lato);
void stampaTriangolo(int lato);
void stampaQuadratoConDiagonali(int lato);
void stampaRombo(int lato);

int main() {

    int lato;
    cout << "Inserisci il lato delle figure: ";
    cin >> lato;
    cout << endl << "Quadrato:" << endl;
    stampaQuadrato(lato);
    cout << endl << "Triangolo rettangolo isoscele:" << endl;
    stampaTriangolo(lato);
    cout << endl << "Quadrato con diagonali:" << endl;
    stampaQuadratoConDiagonali(lato);
    cout << endl << "Rombo:" << endl;
    stampaRombo(lato);


    return 0;
}

void stampaQuadrato(int lato) {
    for (int i = 0; i < lato; i++) {
        for (int j = 0; j < lato; j++) {
            if (i == 0 || i == lato - 1 || j == 0 || j == lato - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void stampaTriangolo(int lato) {
    for (int i = 1; i <= lato; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == lato || j == 1 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void stampaQuadratoConDiagonali(int lato) {
    for (int i = 0; i < lato; i++) {
        for (int j = 0; j < lato; j++) {
            if (i == 0 || i == lato - 1 || j == 0 || j == lato - 1 || i == j || j == lato - i - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void stampaRombo(int lato) {
    if (lato % 2 == 0) 
        lato++; // Assicura lato dispari per simmetria
    int n = lato / 2;
    for (int i = 0; i < lato; i++) {
        for (int j = 0; j < lato; j++) {
            // Vertici
            if (i == 0 && j == n)
                cout << "^";
            else if (i == lato - 1 && j == n)
                cout << "v";
            else if ((i == n && j == 0) || (i == n && j == lato - 1))
                cout << "|";
            // Diagonali
            else if (i + j == n || i + j == lato + n - 1)
                cout << "/";
            else if (j - i == n || i - j == n)
                cout << "\\";
            // Centro
            else if (i == n && j == n)
                cout << "+";
            // Bordo orizzontale
            else if (i == n)
                cout << "-";
            // Bordo verticale
            else if (j == n)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }
}