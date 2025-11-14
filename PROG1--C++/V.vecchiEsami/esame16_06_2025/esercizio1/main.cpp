#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void calcola_modulo(double campioni[30][3], double modulo_acc[30]) {
    for (int i = 0; i < 30; i++) {
        double x = campioni[i][0];
        double y = campioni[i][1];
        double z = campioni[i][2];
        modulo_acc[i] = sqrt(x*x + y*y + z*z);
    }
}

void normalizza(double modulo_acc[30], double modulo_acc_norm[30]) {
    double val_max = modulo_acc[0];
    for (int i = 1; i < 30; i++) {
        if (modulo_acc[i] > val_max) {
            val_max = modulo_acc[i];
        }
    }
    
    for (int i = 0; i < 30; i++) {
        modulo_acc_norm[i] = modulo_acc[i] / val_max;
    }
}

void quantizza(double modulo_acc_norm[30], int q[30], int n) {
    for (int i = 0; i < 30; i++) {
        q[i] = round(modulo_acc_norm[i] * (pow(2, n) - 1));
    }
}

int main() {
    ifstream finput("Test.txt");
    
    if (!finput) {
        cout << "File non esiste!" << endl;
        return 1;
    }
    
    double campioni[30][3];
    double primo_valore;
    
    finput >> primo_valore;
    if (finput.eof()) {
        cout << "Errore: file vuoto" << endl;
        finput.close();
        return 1;
    }
    
    campioni[0][0] = primo_valore;
    finput >> campioni[0][1] >> campioni[0][2];
    
    for (int i = 1; i < 30; i++) {
        finput >> campioni[i][0] >> campioni[i][1] >> campioni[i][2];
    }
    
    finput.close();
    
    double modulo_acc[30];
    calcola_modulo(campioni, modulo_acc);
    
    double modulo_acc_norm[30];
    normalizza(modulo_acc, modulo_acc_norm);
    
    int q[30];
    quantizza(modulo_acc_norm, q, 8);
    
    for (int i = 0; i < 30; i++) {
        cout << q[i];
        if (i < 29) cout << " ";
    }
    cout << endl;
    
    return 0;
}