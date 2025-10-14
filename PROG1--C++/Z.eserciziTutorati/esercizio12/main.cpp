#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double jump();
int round(double a, double b, double c);
void podium(int a, int b, int c);

int main() {
    srand(time(0));
    int puntiA = 0, puntiB = 0, puntiC = 0;

    for (int i = 1; i <= 10; ++i) {
        double saltoA = jump();
        double saltoB = jump();
        double saltoC = jump();

        cout << "Round " << i << ": "
        << "A = " << saltoA << "m, "
        << "B = " << saltoB << "m, "
        << "C = " << saltoC << "m. ";

        int vincitore = round(saltoA, saltoB, saltoC);
        if (vincitore == 1) {
            cout << "Vince Atleta A\n";
            puntiA++;
        } else if (vincitore == 2) {
            cout << "Vince Atleta B\n";
            puntiB++;
        } else {
            cout << "Vince Atleta C\n";
            puntiC++;
        }
    }

    podium(puntiA, puntiB, puntiC);

    return 0;
}

// Ritorna un valore casuale tra 1.0 e 3.0 (inclusi)
double jump() {
    return 1.0 + (double)(rand()) / RAND_MAX * (3.0 - 1.0);
}

// Ritorna l'id dell'atleta vincitore (1: A, 2: B, 3: C)
int round(double a, double b, double c) {
    if (a > b && a > c) 
        return 1;
    if (b > a && b > c) 
        return 2;
    return 3;
}

// Stampa il podio
void podium(int a, int b, int c) {
    cout << "\n--- PODIO ---\n";
    int maxScore = max(a, max(b, c));
    if (a == maxScore) cout << "1° posto: Atleta A (" << a << " punti)\n";
    if (b == maxScore) cout << "1° posto: Atleta B (" << b << " punti)\n";
    if (c == maxScore) cout << "1° posto: Atleta C (" << c << " punti)\n";
    int secondScore = -1;
    if ((a != maxScore && (secondScore == -1 || a > secondScore))) secondScore = a;
    if ((b != maxScore && (secondScore == -1 || b > secondScore))) secondScore = b;
    if ((c != maxScore && (secondScore == -1 || c > secondScore))) secondScore = c;
    if (secondScore != -1) {
        if (a == secondScore) cout << "2° posto: Atleta A (" << a << " punti)\n";
        if (b == secondScore) cout << "2° posto: Atleta B (" << b << " punti)\n";
        if (c == secondScore) cout << "2° posto: Atleta C (" << c << " punti)\n";
    }
    int thirdScore = -1;
    if (a != maxScore && a != secondScore) thirdScore = a;
    if (b != maxScore && b != secondScore) thirdScore = b;
    if (c != maxScore && c != secondScore) thirdScore = c;
    if (thirdScore != -1) {
        if (a == thirdScore) cout << "3° posto: Atleta A (" << a << " punti)\n";
        if (b == thirdScore) cout << "3° posto: Atleta B (" << b << " punti)\n";
        if (c == thirdScore) cout << "3° posto: Atleta C (" << c << " punti)\n";
    }
}