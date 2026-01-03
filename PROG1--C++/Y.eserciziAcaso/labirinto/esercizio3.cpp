#include <iostream>
#include "pila.h"

using namespace std;

/**
 * struct cella {
 * int r;
 * int c;
 * };
 */
void risolviLabirinto(int labirinto[][5], int x, int y);

int main(int argc, char* argv[]) {
    // Matrice del labirinto: 1 = strada, 0 = muro
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    cout << "Percorso trovato: ";
    risolviLabirinto(labirinto, 4, 2);

    return 0;
}

void risolviLabirinto(int labirinto[][5], int x, int y) {
    init(); // Inizializza la pila
    
    // Controllo se la cella di partenza è valida
    if (labirinto[0][0] != 1) {
        cout << "Partenza non valida!" << endl;
        deinit();
        return;
    }

    // Aggiungi la cella di partenza [0,0]
    cella partenza = {0, 0};
    push(partenza);
    labirinto[0][0] = 2; // Marca come visitata (usiamo 2 per distinguerla dai muri 0)

    bool trovato = false;

    while (!vuota() && !trovato) {
        cella corrente;
        top(corrente); // Legge la cella in cima alla pila senza rimuoverla

        int riga = corrente.indiceRiga;
        int colonna = corrente.indiceColonna;

        // Caso base: abbiamo raggiunto la destinazione?
        if (riga == x && colonna == y) {
            trovato = true;
        } else {
            bool mossaEffettuata = false;
            // Direzioni: Su, Giù, Sinistra, Destra
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nr = riga + dr[i];
                int nc = colonna + dc[i];

                // Controllo confini e se la cella è libera (1)
                if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && labirinto[nr][nc] == 1) {
                    labirinto[nr][nc] = 2; // Segna come visitata
                    cella prossima = {nr, nc};
                    push(prossima);
                    mossaEffettuata = true;
                    break; // Approccio DFS: esplora la prima strada valida trovata
                }
            }

            // Se non ci sono mosse possibili da questa cella, fai backtracking
            if (!mossaEffettuata) {
                pop();
            }
        }
    }

    // Gestione della stampa del percorso
    if (trovato) {
        // Poiché la pila è LIFO, per stampare nell'ordine corretto 
        // usiamo un array d'appoggio o una seconda pila.
        int n = 0;
        cella percorso[25]; // Al massimo 25 celle in una 5x5
        
        while (!vuota()) {
            top(percorso[n]);
            pop();
            n++;
        }

        // Stampa al contrario (dall'inizio alla fine)
        for (int i = n - 1; i >= 0; i--) {
            cout << "[" << percorso[i].indiceRiga << "," << percorso[i].indiceColonna << "]";
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "Nessun percorso possibile per raggiungere [" << x << "," << y << "]" << endl;
    }

    deinit(); // Libera la memoria della pila
}