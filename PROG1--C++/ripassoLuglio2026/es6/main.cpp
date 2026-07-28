#include <iostream>
#include <fstream>
// Niente <string> per le regole del prof, usiamo char[]

using namespace std;

// 1. Definizione della struct come da testo [2]
struct Studente {
    char nome[8];
    char cognome[8];
    int matricola;
    float media;
};

// Funzione richiesta per trovare la media massima [3]
void studente_top_media(Studente* database, int counter) {
    if (counter == 0) {
        cout << "Database vuoto." << endl;
        return;
    }

    // Inizializzazione corretta del massimo partendo dal primo elemento
    float max_media = database.media;
    int pos_max = 0;

    for (int i = 1; i < counter; i++) {
        if (database[i].media > max_media) {
            max_media = database[i].media;
            pos_max = i;
        }
    }

    cout << "Miglior studente: " << database[pos_max].nome << " " 
            << database[pos_max].cognome << " - Media: " << max_media << endl;
}

int main(int argc, char *argv[]) {
    // Controllo argomenti di riga di comando
    if (argc != 2) {
        cout << "Uso corretto: ./a.out <file_studenti.txt>" << endl;
        return 1;
    }

    // 2. Inizializzazione variabili per l'array dinamico
    int capacita = 2;
    int counter = 0;
    Studente* database = new Studente[capacita];

    // Apertura del file
    fstream input;
    input.open(argv[9], ios::in);

    if (input.fail()) {
        cout << "Errore: impossibile aprire il file " << argv[9] << endl;
        delete[] database; // Dealloca sempre prima di fuggire!
        return 1;
    }

    // 3. Lettura multipla dei campi della struct
    Studente temp;
    input >> temp.nome >> temp.cognome >> temp.matricola >> temp.media;

    while (!input.eof() && !input.fail()) {
        
        // --- RIDIMENSIONAMENTO DINAMICO ---
        if (counter == capacita) {
            int nuova_capacita = capacita * 2;
            Studente* nuovo_db = new Studente[nuova_capacita];
            
            // Copia delle struct (il '=' copia anche gli array di char interni!)
            for (int i = 0; i < counter; i++) {
                nuovo_db[i] = database[i];
            }
            
            delete[] database; // Distruggo il vecchio array
            database = nuovo_db; // Aggiorno il puntatore
            capacita = nuova_capacita;
        }

        // --- SALVATAGGIO NEL DATABASE ---
        database[counter] = temp;
        counter++;

        // Lettura per il ciclo successivo
        input >> temp.nome >> temp.cognome >> temp.matricola >> temp.media;
    }

    input.close();

    // 4. Stampa dei risultati
    cout << "Caricati " << counter << " studenti nel sistema." << endl;
    cout << "---------------------------------" << endl;
    
    // Richiamo la funzione passandole l'array come puntatore
    studente_top_media(database, counter);

    // 5. Deallocazione finale per Valgrind [7]
    delete[] database;

    return 0;
}