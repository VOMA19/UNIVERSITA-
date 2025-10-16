#include <iostream>
using namespace std;

// Funzione per ottenere il valore di un singolo simbolo romano
int valoreRomano(char c);
int romanoToInt(const char numero[]) ;
bool controlloRomano(const char numero[]);


int main() {
    char numero[] = "MCMXCIV"; // esempio: 1994

    if (!controlloRomano(numero)) {
        cout << "Numero romano non valido (ripetizioni troppo lunghe)!" << endl;
        return 1;
    }

    int risultato = romanoToInt(numero);

    if (risultato == -1) {
        cout << "Numero romano non valido (simbolo sconosciuto)!" << endl;
    } else {
        cout << "Il numero romano " << numero << " vale: " << risultato << endl;
    }

    return 0;
}
int valoreRomano(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1; // simbolo non valido
    }
}

int romanoToInt(const char numero[]) {
    int risultato = 0;
    int i = 0;

    while (numero[i] != '\0') {
        int valoreCorrente = valoreRomano(numero[i]);
        if (valoreCorrente == -1) return -1; // simbolo non valido

        int valoreSuccessivo = valoreRomano(numero[i+1]);

        if (valoreSuccessivo > valoreCorrente) {
            // caso di sottrazione (IV=4, IX=9...)
            risultato += (valoreSuccessivo - valoreCorrente);
            i += 2; // salto il prossimo carattere
        } else {
            risultato += valoreCorrente;
            i++;
        }
    }

    return risultato;
}

// Funzione di controllo base: nessun simbolo ripetuto più di 3 volte consecutivamente
bool controlloRomano(const char numero[]) {
    int count = 1;
    for (int i = 1; numero[i] != '\0'; i++) {
        if (numero[i] == numero[i-1]) {
            count++;
            if (count > 3) return false;
        } else {
            count = 1;
        }
    }
    return true;
}