/******************************************************************************
 * GUIDA COMPLETA: GESTIONE argc/argv CON ARRAY DI CARATTERI (C-STYLE)
 ******************************************************************************
 *
 * In C++, 'argv' è un array di puntatori a char (char* []). 
 * Ogni elemento argv[i] è già, di fatto, un array di caratteri terminato dallo zero ('\0').
 *
 * 1. IL MAIN E I SUOI PARAMETRI
 * --------------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib> // Per atoi, atof
#include <cstring> // Per funzioni su array di char (strcmp, strcpy, strlen)

using namespace std;

/**
 * argc: Numero di argomenti (compreso il nome del programma).
 * argv: Array di stringhe C (char*).
 */
int main(int argc, char* argv[]) {

    /*-------------------------------------------------------------------------
     * 2. VERIFICA PRESENZA ARGOMENTI
     * ------------------------------------------------------------------------*/
    if (argc < 2) {
        cerr << "Utilizzo: " << argv[0] << " <operazione> <valore>" << endl;
        return 1;
    }

    /*-------------------------------------------------------------------------
     * 3. CONFRONTO DI ARRAY DI CARATTERI (strcmp)
     * ------------------------------------------------------------------------
     * NON puoi usare '==' per confrontare argv[i] con una stringa, perché
     * confronteresti gli indirizzi di memoria, non il contenuto.
     * Si usa strcmp(s1, s2): restituisce 0 se le stringhe sono identiche.
     */
    
    char* comando = argv[1]; // Puntatore al primo argomento

    if (strcmp(comando, "aggiungi") == 0) {
        cout << "Comando ricevuto: AGGIUNGI" << endl;
    } else if (strcmp(comando, "rimuovi") == 0) {
        cout << "Comando ricevuto: RIMUOVI" << endl;
    }

    /*-------------------------------------------------------------------------
     * 4. CONVERSIONE DA ARRAY DI CHAR A NUMERI
     * ------------------------------------------------------------------------*/
    if (argc > 2) {
        // argv[2] è un char*. Per sommarlo o usarlo come numero:
        int valoreIntero = atoi(argv[2]);    // Da array char a int
        double valoreDouble = atof(argv[2]); // Da array char a double
        
        cout << "Valore convertito: " << valoreIntero << endl;
    }

    /*-------------------------------------------------------------------------
     * 5. COPIARE UN ARGOMENTO (strcpy)
     * ------------------------------------------------------------------------
     * Se vuoi salvare un argomento in un tuo array locale:
     */
    char buffer[100]; 
    if (strlen(argv[1]) < 100) {
        strcpy(buffer, argv[1]); // Copia il contenuto di argv[1] in buffer
    }

    /*-------------------------------------------------------------------------
     * 6. ITERAZIONE COMPLETA
     * ------------------------------------------------------------------------*/
    cout << "\nElenco completo degli argomenti (char*):" << endl;
    for (int i = 0; i < argc; i++) {
        // Stampiamo la stringa C e la sua lunghezza
        cout << "Arg[" << i << "]: " << argv[i] << " (Lunghezza: " << strlen(argv[i]) << ")" << endl;
    }

    return 0;
}

/******************************************************************************
 * CASISTICHE ED ERRORI COMUNI CON ARRAY DI CHAR
 ******************************************************************************
 *
 * 1. ERRORE DI CONFRONTO:
 * if (argv[1] == "test") // SBAGLIATO! Confronta puntatori.
 * if (strcmp(argv[1], "test") == 0) // CORRETTO.
 *
 * 2. ACCESSO NON SICURO:
 * Accedere a argv[1] senza controllare se argc > 1 causa Segmentation Fault.
 *
 * 3. BUFFER OVERFLOW:
 * Quando usi strcpy per copiare un argomento in un array fisso (char buf[10]),
 * se l'utente inserisce una parola più lunga di 9 caratteri, il programma crasha
 * o diventa vulnerabile. Usa sempre controlli sulla lunghezza (strlen).
 *
 * 4. IL NOME DEL PROGRAMMA:
 * argv[0] contiene il percorso o il nome dell'eseguibile. Se lanci:
 * ./mia_stack 10
 * argc è 2.
 * argv[0] è "./mia_stack"
 * argv[1] è "10"
 *
 * 5. CONVERSIONE IN CICLO:
 * Se devi passare molti numeri (es: riempire lo stack), usa un for:
 * for(int i = 1; i < argc; i++) {
 * push(s, atof(argv[i]));
 * }
 *****************************************************************************/