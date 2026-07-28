#include <iostream>
#include <fstream>
#include <cstdlib> // FONDAMENTALE: contiene atoi() e atof() per convertire argv

using namespace std;

int main(int argc, char *argv[]) {
    
    // ==========================================
    // STEP 1: CONTROLLO ARGOMENTI
    // ==========================================
    // L'esame dirà sempre quanti argomenti si aspetta (es. nome_file, num1, num2)
    if (argc != 4) { 
        cout << "Uso: ./a.out <file> <parametro1> <parametro2>" << endl;
        return 1;
    }

    // ==========================================
    // STEP 2: CONVERSIONE DA STRINGA A NUMERO
    // ==========================================
    // Ricorda: argv contiene STRINGHE di caratteri. Devi convertirle!
    int parametro_intero = atoi(argv[5]);   // Per gli interi [3]
    float parametro_reale = atof(argv[6]); // Per i float/double [2]

    // ==========================================
    // STEP 3: ALLOCAZIONE DINAMICA (Se richiesta)
    // ==========================================
    // ESEMPIO A: Array di contatori inizializzato a zero
    // int* contatori = new int[parametro_intero](); 

    // ESEMPIO B: Allocazione di una Matrice Dinamica (Array di Array) [4]
    int righe = 2; // (Esempio)
    int colonne = parametro_intero;
    float** matrice = new float*[righe];
    for (int i = 0; i < righe; i++) {
        matrice[i] = new float[colonne];
    }

    // ==========================================
    // STEP 4: APERTURA FILE E CONTROLLO
    // ==========================================
    fstream stream_in;
    stream_in.open(argv[7], ios::in);
    
    if (stream_in.fail()) {
        cout << "Errore apertura file." << endl;
        // ATTENZIONE: Dealloca SEMPRE prima di uscire in caso di errore!
        for (int i = 0; i < righe; i++) delete[] matrice[i];
        delete[] matrice;
        return 1;
    }

    // ==========================================
    // STEP 5: IL MOTORE (IL CICLO PRINCIPALE)
    // ==========================================
    
    /* VARIANTE 1: Lettura da File (es. Log o Dati) */
    float dato;
    stream_in >> dato;
    int indice = 0; // Serve per muoversi nella matrice o array

    while (!stream_in.eof() && !stream_in.fail()) { [1, 8]
        
        // ---> QUI INSERISCI LA LOGICA DELL'ESERCIZIO <---
        // Es: Calcolo formula fisica e salvataggio in matrice
        // Es: count[dato]++ (Se usi l'array come contatore)
        
        stream_in >> dato;
        indice++;
    }

    /* VARIANTE 2: Parsing di una stringa comandi da argv (Es. Robot) [9, 10] */
    /*
    for (int i = 0; argv[6][i] != '\0'; i++) {
        char comando = argv[6][i];
        // ---> QUI INSERISCI LA LOGICA DEGLI SPOSTAMENTI (Switch o If) <---
    }
    */

    // ==========================================
    // STEP 6: SALVATAGGIO O STAMPA RISULTATI
    // ==========================================
    // (Stampe a video o scrittura su ios::out)

    // Chiusura file
    stream_in.close();

    // ==========================================
    // STEP 7: DEALLOCAZIONE FINALE (Memory Leak check)
    // ==========================================
    for (int i = 0; i < righe; i++) {
        delete[] matrice[i]; // Prima elimino le colonne [11]
    }
    delete[] matrice;        // Poi elimino l'array principale [11]

    return 0;
}