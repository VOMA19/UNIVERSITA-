#include <iostream> 
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    // 1. CONTROLLO DEGLI ARGOMENTI (Previene crash se l'utente dimentica il file)
    if (argc != 2) {
        cout << "Uso corretto: ./a.out <file_input>" << endl;
        return 1;
    }

    int capIniziale = 2;
    int counter = 0;
    int totale = 0;
    
    // Allocazione dinamica iniziale
    int* arrayDinamico = new int[capIniziale]; 

    fstream input;
    // 2. APERTURA DEL FILE TRAMITE ARGV
    input.open(argv[1], ios::in);
    
    // Controllo fallimento apertura
    if (input.fail()) {
        cout << "Errore: Impossibile aprire il file " << argv[1] << endl;
        delete[] arrayDinamico; // Dealloca SEMPRE prima di fare return in caso di errore!
        return 1;
    }

    int valore;
    input >> valore;

    while (!input.eof() && !input.fail()) {
        
        // 3. RIDIMENSIONAMENTO DINAMICO (Logica perfetta che avevi già scritto)
        if (counter == capIniziale) {
            int nuova_capacita = capIniziale * 2; 
            int* nuovo_array = new int[nuova_capacita];
            
            for (int i = 0; i < counter; i++) {
                nuovo_array[i] = arrayDinamico[i];
            }
            
            delete[] arrayDinamico; 
            
            arrayDinamico = nuovo_array;
            capIniziale = nuova_capacita;
        }

        arrayDinamico[counter] = valore;
        counter++;
        totale += valore;
        
        input >> valore;
    }

    input.close();

    // 4. PROTEZIONE DA DIVISIONE PER ZERO (Nel caso il file sia vuoto)
    if (counter > 0) {
        double media = (double)totale / (double)counter;
        cout << media << endl;
        
        for (int i = 0; i < counter; i++) {
            if (arrayDinamico[i] > media) {
                cout << arrayDinamico[i] << endl;
            }
        }
    } else {
        cout << "Il file e' vuoto, impossibile calcolare la media." << endl;
    }

    // 5. DEALLOCAZIONE FINALE (Previene il memory leak)
    delete[] arrayDinamico;
    
    return 0;
}