#include <iostream>
#include <fstream>

using namespace std;

// --- PROTOTIPI DELLE FUNZIONI ---
void invertiArrayDaFile(istream& in, double*& array, int& dim);
void leggiEAllocaInvertiti(istream& in, double*& array, int& dim, int profondita);
void stampaRicorsiva(double* array, int dim, int indice = 0); 

// ==========================================
// FUNZIONE WRAPPER (Quella chiamata dal main)
// ==========================================
void invertiArrayDaFile(istream& in, double*& array, int& dim) {
    // Inizializza la profondità a 0
    leggiEAllocaInvertiti(in, array, dim, 0);
}

// ==========================================
// FUNZIONE RICORSIVA AUSILIARIA (Il motore)
// ==========================================
void leggiEAllocaInvertiti(istream& in, double*& array, int& dim, int profondita) {
    double valore;
    
    // FASE 1: DISCESA (Lettura dal file)
    if (in >> valore) {
        
        // Chiamo la ricorsione aumentando la profondità di 1
        leggiEAllocaInvertiti(in, array, dim, profondita + 1);
        
        // FASE 3: RISALITA (Salvataggio in ordine inverso)
        // ATTENZIONE QUI: 'dim' è stata impostata nel caso base ed è ora nota!
        // Se dim è 3, all'elemento a profondità 0 assegno l'indice 3-1-0 = 2 (ultimo posto)
        // All'elemento a profondità 2 assegno l'indice 3-1-2 = 0 (primo posto)
        array[dim - 1 - profondita] = valore;
        
    } else {
        // FASE 2: CASO BASE (Fine del file)
        // Ora 'profondita' contiene il numero totale esatto degli elementi
        dim = profondita; 
        
        if (dim > 0) {
            // ALLOCAZIONE DINAMICA DELLA MEMORIA CON LA DIMENSIONE ESATTA
            array = new double[dim];
        } else {
            // Se il file era vuoto
            array = nullptr; 
        }
    }
}

// Funzione per stampare l'array senza usare cicli
void stampaRicorsiva(double* array, int dim, int indice) {
    if (indice == dim) {
        cout << endl;
        return;
    }
    cout << array[indice] << " ";
    stampaRicorsiva(array, dim, indice + 1);
}

// ==========================================
// MAIN DI TEST
// ==========================================
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Uso: ./a.out <file_dati.txt>" << endl;
        return 1;
    }

    fstream input;
    
    if (input.fail()) {
        cout << "Errore apertura file!" << endl;
        return 1;
    }

    double* arrayDinamico = nullptr;
    int dimensione = 0;

    // Chiamata alla funzione principale
    invertiArrayDaFile(input, arrayDinamico, dimensione);
    
    input.close();

    // Stampa i risultati
    if (dimensione > 0) {
        cout << "L'array invertito contiene " << dimensione << " elementi." << endl;
        cout << "Contenuto: ";
        stampaRicorsiva(arrayDinamico, dimensione); 
    } else {
        cout << "Il file era vuoto." << endl;
    }

    // FONDAMENTALE: Prevenire il memory leak deallocando lo heap! [5]
    if (arrayDinamico != nullptr) {
        delete[] arrayDinamico;
    }

    return 0;
}