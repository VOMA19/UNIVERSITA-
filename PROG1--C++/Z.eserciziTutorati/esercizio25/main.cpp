#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Cerchio {
    double x, y, r;
};

bool siIntersecano(const Cerchio& c1, const Cerchio& c2);

int main(){
    fstream file("cerchi.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }
    
    // Prima passata: conta i cerchi
    int numCerchi = 0;
    Cerchio temp;
    while (file >> temp.x >> temp.y >> temp.r) {
        numCerchi++;
    }
    
    file.close();
    file.open("cerchi.txt", ios::in);
    
    // Array dinamico per i cerchi
    Cerchio* cerchi = new Cerchio[numCerchi];
    bool* siInterseca = new bool[numCerchi];
    
    // Inizializza array
    for (int i = 0; i < numCerchi; i++) {
        siInterseca[i] = false;
    }
    
    // Seconda passata: leggi i cerchi
    for (int i = 0; i < numCerchi; i++) {
        file >> cerchi[i].x >> cerchi[i].y >> cerchi[i].r;
    }
    file.close();
    
    // Controlla le intersezioni
    for (int i = 0; i < numCerchi; i++) {
        for (int j = i + 1; j < numCerchi; j++) {
            if (siIntersecano(cerchi[i], cerchi[j])) {
                siInterseca[i] = true;
                siInterseca[j] = true;
            }
        }
    }
    
    // Conta i cerchi che si intersecano
    int count = 0;
    for (int i = 0; i < numCerchi; i++) {
        if (siInterseca[i]) count++;
    }
    
    cout << "Numero di cerchi che si intersecano: " << count << endl;
    
    delete[] cerchi;
    delete[] siInterseca;
    
    return 0;
}

bool siIntersecano(const Cerchio& c1, const Cerchio& c2) {
    double distanza = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
    return distanza <= (c1.r + c2.r) && distanza >= abs(c1.r - c2.r);
}