#include <iostream>
#include <fstream>
#include <cstdlib> // Necessaria per atoi(), atof() e exit()

using namespace std; // VIETATO includere <string> [11]

// =================================================================
// PROTOTIPI DELLE FUNZIONI (Da personalizzare in base al testo)
// =================================================================
// void elaboraDati(double* array, int dim, ...);
// void scriviDati(char* nome_file, double* array, int dim);

// =================================================================
// MAIN UNIVERSALE
// =================================================================
int main(int argc, char *argv[]) {
    
    // --- 1. CONTROLLO ARGOMENTI DA LINEA DI COMANDO ---
    // Se il testo chiede di passare i nomi dei file o numeri da terminale [5]
    if (argc != 3) {
        cout << "Uso: ./a.out <file_input> <file_output>" << endl;
        return 1;
    }
    
    // (Opzionale) Convertire stringhe argv in numeri [2]:
    // int parametro_int = atoi(argv[12]); 
    // double parametro_double = atof(argv[13]);

    // --- 2. APERTURA FILE DI INPUT ---
    fstream input;
    input.open(argv[14], ios::in);
    
    // Protezione obbligatoria per evitare crash [5]
    if (input.fail()) {
        cout << "Errore: impossibile aprire il file di input." << endl;
        return 1;
    }

    // --- 3. INIZIALIZZAZIONE VARIABILI E ALLOCAZIONE DINAMICA ---
    int capacita = 2; // Dimensione di partenza dell'array
    int elementi_inseriti = 0; // Quanti dati ho effettivamente letto
    
    // Allocazione dinamica iniziale nello heap [6]
    double* array_dinamico = new double[capacita];

    // --- 4. CICLO DI LETTURA E RADDOPPIO DELL'ARRAY ---
    double valore_letto;
    
    // Leggo finché ci sono dati (o finché non incontro un valore sentinella, es. -1.0) [7]
    while (input >> valore_letto /* && valore_letto != -1.0 */) {
        
        // Se c'è una condizione per scartare dati errati, mettila qui:
        /* if (valore_letto < 0) {
               valore_letto = 1.0; // Correzione dato errato come da esame [7]
           }
        */

        // SE L'ARRAY E' PIENO, DEVO RADDOPPIARNE LA DIMENSIONE [8]
        if (elementi_inseriti == capacita) {
            // A. Alloco un nuovo array grande il doppio
            double* temp = new double[capacita * 2];
            
            // B. Copio i vecchi dati nel nuovo array
            for (int i = 0; i < capacita; i++) {
                temp[i] = array_dinamico[i];
            }
            
            // C. Dealloco il vecchio array per evitare memory leak
            delete[] array_dinamico;
            
            // D. Aggiorno puntatore e capacità
            array_dinamico = temp;
            capacita *= 2;
        }

        // Ora ho sicuramente spazio: salvo il valore e incremento il contatore [8]
        array_dinamico[elementi_inseriti] = valore_letto;
        elementi_inseriti++;
    }
    
    // Chiudo il file appena ho finito di leggerlo [5]
    input.close();

    // --- 5. LOGICA CENTRALE DEL PROGRAMMA ---
    // Qui chiami le funzioni che elaborano i dati, calcolano medie, straordinari, ecc.
    // elaboraDati(array_dinamico, elementi_inseriti, ...);

    // --- 6. SCRITTURA SU FILE DI OUTPUT ---
    fstream output;
    // ios::out sovrascrive, ios::app aggiunge in coda se il testo lo richiede [4, 15]
    output.open(argv[16], ios::out); 
    
    if (output.fail()) {
        cout << "Errore: impossibile aprire il file di output." << endl;
        delete[] array_dinamico; // FONDAMENTALE DEALLOCARE ANCHE IN CASO DI ERRORE!
        return 1;
    }

    for (int i = 0; i < elementi_inseriti; i++) {
        output << array_dinamico[i] << endl;
    }
    
    output.close();

    // --- 7. DEALLOCAZIONE FINALE (TEST VALGRIND) ---
    // Tutto ciò che è stato creato con 'new[]' deve essere distrutto con 'delete[]' [9, 10]
    delete[] array_dinamico;

    return 0;
}