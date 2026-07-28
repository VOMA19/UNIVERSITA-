#include <iostream>
#include <fstream>

using namespace std;

// 1. DEFINIZIONE DELLA STRUCT
struct Rilevazione {
    int idSensore;
    double temperatura;
};

// --- PROTOTIPI ---
void elaboraSensori(istream& in, Rilevazione*& array, int& dim, double& media);
void leggiEAllocaStruct(istream& in, Rilevazione*& array, int& dim, int profondita, double& somma_temp);
void stampaRicorsiva(Rilevazione* array, int dim, int indice = 0);

// ==========================================
// FUNZIONE WRAPPER PRINCIPALE
// ==========================================
void elaboraSensori(istream& in, Rilevazione*& array, int& dim, double& media) {
    double somma_temp = 0.0;
    
    // Faccio partire la ricorsione passando i contatori a 0
    leggiEAllocaStruct(in, array, dim, 0, somma_temp);
    
    // Calcolo la media alla fine, se l'array non è vuoto
    if (dim > 0) {
        media = somma_temp / dim;
    } else {
        media = 0.0;
    }
}

// ==========================================
// FUNZIONE RICORSIVA AUSILIARIA (Il motore)
// ==========================================
void leggiEAllocaStruct(istream& in, Rilevazione*& array, int& dim, int profondita, double& somma_temp) {
    // Uso una struct temporanea per "catturare" i dati della riga corrente
    Rilevazione temp;
    
    // FASE 1: DISCESA (Lettura multipla dal file)
    // L'operatore >> legge entrambi i dati. Se la riga è incompleta o il file finisce, restituisce false.
    if (in >> temp.idSensore >> temp.temperatura) {
        
        // La lettura ha avuto successo: chiamo la ricorsione aumentando la profondità
        leggiEAllocaStruct(in, array, dim, profondita + 1, somma_temp);
        
        // FASE 3: RISALITA
        // L'array ora esiste (è stato creato nel caso base). 
        // L'assegnazione temp copia l'intera struct in un colpo solo!
        array[profondita] = temp;
        
        // Accumulo la temperatura per il calcolo della media
        somma_temp += temp.temperatura;
        
    } else {
        // FASE 2: CASO BASE (Fine del file)
        // La profondità indica esattamente quante struct complete abbiamo letto
        dim = profondita;
        
        if (dim > 0) {
            // ALLOCAZIONE DINAMICA CON DIMENSIONE ESATTA
            array = new Rilevazione[dim];
        } else {
            array = nullptr; // File vuoto
        }
        
        // Inizializzo la somma a 0 per far partire l'accumulo in risalita
        somma_temp = 0.0;
    }
}

// Funzione bonus per la stampa senza cicli
void stampaRicorsiva(Rilevazione* array, int dim, int indice) {
    if (indice == dim) {
        return;
    }
    cout << "Sensore ID: " << array[indice].idSensore 
         << " - Temp: " << array[indice].temperatura << endl;
    stampaRicorsiva(array, dim, indice + 1);
}

// ==========================================
// MAIN DI TEST
// ==========================================
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Uso: ./a.out <file_sensori.txt>" << endl;
        return 1;
    }

    fstream input;
    input.open(argv[3], ios::in); // Ricorda: argv[3] è il nome del file!
    
    if (input.fail()) {
        cout << "Errore apertura file!" << endl;
        return 1;
    }

    Rilevazione* database = nullptr;
    int dimensione = 0;
    double mediaTemperature = 0.0;

    // Chiamata alla funzione principale
    elaboraSensori(input, database, dimensione, mediaTemperature);
    
    input.close();

    // Stampa dei risultati
    if (dimensione > 0) {
        cout << "Trovate " << dimensione << " misurazioni." << endl;
        cout << "Temperatura Media: " << mediaTemperature << endl;
        cout << "--- Dettaglio Letture ---" << endl;
        stampaRicorsiva(database, dimensione);
    } else {
        cout << "Il file era vuoto o non conteneva dati validi." << endl;
    }

    // DEALLOCAZIONE FINALE (Previene il memory leak)
    if (database != nullptr) {
        delete[] database;
    }

    return 0;
}