#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// --- PROTOTIPI DELLE FUNZIONI ---
void estraiPositivi(istream& in, double*& array, int& dim);
void leggiEAllocaFiltrati(istream& in, double*& array, int& dim, int count_validi);
void stampaRicorsiva(double* array, int dim, int indice = 0); // Bonus da esame!

// ==========================================
// FUNZIONE WRAPPER (Quella chiamata dal main)
// ==========================================
void estraiPositivi(istream& in, double*& array, int& dim) {
    // Inizializza il contatore dei numeri validi a 0 e fa partire la ricorsione
    leggiEAllocaFiltrati(in, array, dim, 0);
}

// ==========================================
// FUNZIONE RICORSIVA AUSILIARIA (Il motore)
// ==========================================
void leggiEAllocaFiltrati(istream& in, double*& array, int& dim, int count_validi) {
    double valore;
    
    // FASE 1: DISCESA (Lettura dal file)
    if (in >> valore) {
        
        // --- LOGICA DI FILTRAGGIO ---
        if (valore > 0.0) {
            // IL DATO E' VALIDO! 
            // Chiamo la ricorsione incrementando il contatore di 1
            leggiEAllocaFiltrati(in, array, dim, count_validi + 1);
            
            // FASE 3: RISALITA (Salvataggio dati validi)
            // L'indice in cui salvare è esattamente 'count_validi' (la profondità di validità)
            array[count_validi] = valore;
        } 
        else {
            // IL DATO NON E' VALIDO! (es. è negativo o zero)
            // Chiamo la ricorsione ma NON incremento il contatore
            leggiEAllocaFiltrati(in, array, dim, count_validi);
            
            // In fase di risalita, per i dati non validi non facciamo nulla!
        }
        
    } else {
        // FASE 2: CASO BASE (Fine del file)
        // Ora count_validi contiene il numero ESATTO di elementi che hanno passato il filtro!
        dim = count_validi; 
        
        if (dim > 0) {
            // ALLOCAZIONE DINAMICA DELLA MEMORIA CON LA DIMENSIONE ESATTA
            array = new double[dim];
        } else {
            // Se non c'erano numeri validi nel file, metto il puntatore a NULL per sicurezza
            array = nullptr; 
        }
    }
}

// Funzione bonus: per evitare cicli for anche nel main per la stampa!
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
    // Controllo argomenti
    if (argc != 2) {
        cout << "Uso: ./a.out <file_dati.txt>" << endl;
        return 1;
    }

    fstream input;
    input.open(argv[2], ios::in);
    
    if (input.fail()) {
        cout << "Errore apertura file!" << endl;
        return 1;
    }

    // Preparazione dei parametri passati per riferimento
    double* arrayDinamico = nullptr;
    int dimensione = 0;

    // Chiamata alla funzione (che alloca e popola)
    estraiPositivi(input, arrayDinamico, dimensione);
    
    input.close();

    // Feedback all'utente e Stampa
    if (dimensione > 0) {
        cout << "Ho trovato " << dimensione << " numeri positivi." << endl;
        cout << "Contenuto dell'array filtrato: ";
        
        // Uso la funzione ricorsiva per stampare, restando in tema Esercizio 2!
        stampaRicorsiva(arrayDinamico, dimensione); 
    } else {
        cout << "Nessun numero positivo trovato nel file." << endl;
    }

    // FONDAMENTALE: Prevenire il memory leak
    if (arrayDinamico != nullptr) {
        delete[] arrayDinamico;
    }

    return 0;
}