#include <iostream>
#include <fstream>
#include <cstring> // Utile se devi usare strcpy o strcmp con i char[]

using namespace std;

// 1. DEFINIZIONE DELLA STRUCT [3]
// Niente std::string! Usiamo array di char (stringhe C-style)
struct Studente {
    char nome[6];
    char cognome[6];
    int matricola;
    float media;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Uso: ./a.out <file_database>" << endl;
        return 1;
    }

    // 2. INIZIALIZZAZIONE ARRAY DINAMICO DI STRUCT
    int capacita = 2;
    int counter = 0;
    // Alloco dinamicamente un array in cui ogni elemento è uno 'Studente'
    Studente* database = new Studente[capacita]; 

    fstream input;
    input.open(argv[7], ios::in);
    
    if (input.fail()) {
        cout << "Errore apertura file." << endl;
        delete[] database;
        return 1;
    }

    // 3. LETTURA MULTIPLA DA FILE [8]
    // Creiamo una struct temporanea per "catturare" i dati della riga
    Studente temp;
    
    // Leggiamo i 4 campi tutti insieme. L'operatore >> si ferma in automatico 
    // ad ogni spazio o 'a capo', mettendo ogni dato nel posto giusto!
    input >> temp.nome >> temp.cognome >> temp.matricola >> temp.media;

    while (!input.eof() && !input.fail()) {
        
        // 4. RIDIMENSIONAMENTO (Stessa identica logica dei numeri interi!)
        if (counter == capacita) {
            int nuova_capacita = capacita * 2;
            Studente* nuovo_db = new Studente[nuova_capacita];
            
            // La copia di struct in C++ copia automaticamente anche tutti i 
            // dati degli array interni (nome e cognome) [9]
            for (int i = 0; i < counter; i++) {
                nuovo_db[i] = database[i]; 
            }
            
            delete[] database;
            database = nuovo_db;
            capacita = nuova_capacita;
        }

        // 5. SALVATAGGIO NEL DATABASE
        database[counter] = temp;
        counter++;

        // Leggo la riga successiva per il prossimo ciclo
        input >> temp.nome >> temp.cognome >> temp.matricola >> temp.media;
    }

    input.close();

    // --- ESEMPIO DI UTILIZZO: Stampa studenti con media > 25 ---
    for (int i = 0; i < counter; i++) {
        if (database[i].media > 25.0) {
            // Per accedere ai campi di un array di struct, si usa il '.' [10]
            cout << database[i].nome << " " 
                << database[i].cognome << " - Mat: " 
                << database[i].matricola << endl;
        }
    }

    // 6. PULIZIA DELLA MEMORIA
    delete[] database;

    return 0;
}
