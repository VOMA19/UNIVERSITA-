#include <iostream>
#include <fstream>
#include <cstdlib> // Necessaria per la funzione atoi() se leggi la dimensione da argv

using namespace std;

int main(int argc, char *argv[]) {
    
    // STEP 1: ALLOCAZIONE DINAMICA INIZIALE [4]
    int capacita = 2;  // Dimensione iniziale di partenza
    int contatore = 0; // Quanti elementi abbiamo effettivamente inserito
    
    // Creazione dell'array dinamico nello Heap usando 'new tipo[dimensione]' [5]
    int* arrayDinamico = new int[capacita]; 

    // Esempio: Apertura file (come nello schema precedente)
    fstream input;
    input.open("dati.txt", ios::in);
    if (input.fail()) {
        delete[] arrayDinamico; // ATTENZIONE: se esci per errore, dealloca sempre prima! [3, 6]
        return 1;
    }

    // STEP 2: LETTURA E UTILIZZO DELL'ARRAY
    int valore;
    input >> valore;

    while (!input.eof() && !input.fail()) {
        
        // STEP 3: IL RIDIMENSIONAMENTO (RESIZING) DINAMICO
        // Se l'array è pieno, dobbiamo "allargarlo" in corsa
        if (contatore == capacita) {
            int nuova_capacita = capacita * 2; // Raddoppio lo spazio
            
            // A. Alloco un nuovo array più grande [4]
            int* nuovo_array = new int[nuova_capacita];
            
            // B. Copio i vecchi dati nel nuovo array [7, 8]
            for (int i = 0; i < contatore; i++) {
                nuovo_array[i] = arrayDinamico[i];
            }
            
            // C. Libero la memoria del vecchio array per evitare Memory Leak! [6]
            delete[] arrayDinamico; 
            
            // D. Aggiorno il puntatore per farlo puntare alla nuova area di memoria
            arrayDinamico = nuovo_array;
            capacita = nuova_capacita;
        }

        // STEP 4: INSERIMENTO E UTILIZZO
        // Ora sono sicuro di avere spazio, uso l'array normalmente tramite indice [9]
        arrayDinamico[contatore] = valore;
        contatore++;

        input >> valore;
    }

    input.close();

    // --- Fai quello che ti chiede l'esercizio con arrayDinamico (es. stampe, somme) ---
    for(int i = 0; i < contatore; i++){
        cout << arrayDinamico[i] << " ";
    }
    cout << endl;

    // STEP 5: DEALLOCAZIONE FINALE (OBBLIGATORIA) [4]
    // Per deallocare gli array si deve OBBLIGATORIAMENTE usare delete[] con le parentesi quadre,
    // altrimenti si dealloca solo il primo elemento! [10]
    delete[] arrayDinamico;

    return 0;
}