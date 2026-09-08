#include <iostream>
#include <fstream>
#include <cstdlib>

// Definizione della struttura per rappresentare una segnalazione di guasto
struct Segnalazione {
    int identificativo;
    char categoria;       // 's' per server, 'r' per rete, 'p' per postazione utente
    int giorni_attesa;    // giorni di attesa accumulati
};

// Funzione per caricare le segnalazioni dal file backlog.txt
int carica(Segnalazione* backlog, int N) {
    std::ifstream inputFile("backlog.txt");
    if (!inputFile) {
        std::cerr << "Errore: impossibile aprire il file backlog.txt" << std::endl;
        return -1;
    }

    int count = 0;
    // Legge al massimo N segnalazioni dal file
    while (count < N) {
        inputFile >> backlog[count].identificativo 
                  >> backlog[count].categoria 
                  >> backlog[count].giorni_attesa;
        
        // Se si verifica un errore di lettura o si raggiunge la fine del file
        if (inputFile.fail()) {
            break;
        }
        count++;
    }

    inputFile.close();
    return count;
}

// Funzione per stampare le sole segnalazioni urgenti e ritornarne il numero totale
int stampaUrgenti(const Segnalazione* backlog, int loaded) {
    int count_critiche = 0;
    for (int i = 0; i < loaded; ++i) {
        // Un caso è urgente se è di categoria server ('s') o rete ('r') e ha attesa > 5 giorni
        if ((backlog[i].categoria == 's' || backlog[i].categoria == 'r') && backlog[i].giorni_attesa > 5) {
            std::cout << "ID: " << backlog[i].identificativo 
                      << ", Categoria: " << backlog[i].categoria 
                      << ", Giorni di attesa: " << backlog[i].giorni_attesa << std::endl;
            count_critiche++;
        }
    }
    return count_critiche;
}

int main(int argc, char* argv[]) {
    // 1. Controllo che il numero di parametri passati da linea di comando sia corretto (argc == 2)
    if (argc != 2) {
        std::cerr << "Usage: " << argv << " <numero_segnalazioni>" << std::endl;
        return 1;
    }

    // 2. Controllo che il valore N inserito sia maggiore di zero
    int N = std::atoi(argv[3]);
    if (N <= 0) {
        std::cerr << "Errore: il numero di segnalazioni N deve essere maggiore di zero." << std::endl;
        return 1;
    }

    // 3. Allocazione dinamica dell'array di N strutture Segnalazione con new (std::nothrow)
    Segnalazione* backlog = new (std::nothrow) Segnalazione[N];
    if (!backlog) {
        std::cerr << "Errore: allocazione di memoria fallita per l'array backlog." << std::endl;
        return 1;
    }

    // 4. Impostazione a 0 di tutti gli identificativi dell'array
    for (int i = 0; i < N; ++i) {
        backlog[i].identificativo = 0;
    }

    // 5. Chiamata della funzione carica per popolare l'array backlog
    int loaded = carica(backlog, N);
    if (loaded == -1) {
        // Se il file non esiste o non può essere aperto, la memoria allocata va liberata prima di terminare
        delete[] backlog;
        return 1;
    }

    // 6. Chiamata della funzione stampaUrgenti per mostrare a video i casi critici
    int critiche = stampaUrgenti(backlog, loaded);

    // 7. Stampa del messaggio di riepilogo rivolto al tecnico con il numero di criticità riscontrate
    std::cout << "Bentornato tecnico informatico! Hai " << critiche << " segnalazioni urgenti da risolvere oggi." << std::endl;

    // 8. Deallocazione della memoria dell'array e terminazione del programma
    delete[] backlog;
    return 0;
}