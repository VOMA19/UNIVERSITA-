#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Prototipi come da specifiche
int** CreaMappa(int m_lunghezza, int m_larghezza); 
int Muovi(int &x, int &y, int righe_matrice, int colonne_matrice, char comando);

int main(int argc, char* argv[]) {
    // a) Verifica numero argomenti
    if (argc < 4) {
        cerr << "Errore argomenti." << endl;
        return 1;
    }

    // b) Verifica dimensioni positive
    int m_lu = atoi(argv[1]);
    int m_la = atoi(argv[2]);
    if (m_lu <= 0 || m_la <= 0) return 1;

    // La funzione CreaMappa riceve i METRI e calcola internamente le celle (25x25cm)
    int** mappa = CreaMappa(m_lu, m_la);

    // Dimensioni effettive della matrice per la navigazione
    int righe = m_lu * 4;
    int colonne = m_la * 4;

    int curr_x = 0; // Ascissa (colonna)
    int curr_y = 0; // Ordinata (riga)

    // d) Segna la posizione iniziale
    mappa[curr_y][curr_x]++;

    // c) Analisi stringa comandi
    char* stringa_comandi = argv[3];
    for (int i = 0; i < strlen(stringa_comandi); ++i) {
        char c = stringa_comandi[i];
        
        // La traccia dice: se non è valido, si procede col comando successivo.
        // Se il robot non si muove, la posizione corrente viene COMUNQUE incrementata.
        int esito = Muovi(curr_x, curr_y, righe, colonne, c);
        
        // Sia che si muova (0), sia che resti fermo (-1 o 'x'), incremento la cella attuale
        mappa[curr_y][curr_x]++;
    }

    // e) Stampa su file e video
    fstream f("Mappa.txt", ios::out);
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            cout << mappa[i][j] << " ";
            if (f.is_open()) f << mappa[i][j] << " ";
        }
        cout << endl;
        if (f.is_open()) f << endl;
    }
    if (f.is_open()) f.close();

    // Deallocazione
    for (int i = 0; i < righe; ++i) delete[] mappa[i];
    delete[] mappa;

    return 0;
}

// Implementazione CreaMappa: riceve metri, alloca celle
int** CreaMappa(int m_lu, int m_la) {
    int r = m_lu * 4;
    int c = m_la * 4;
    int** m = new int*[r];
    for (int i = 0; i < r; ++i) {
        m[i] = new int[c];
        for (int j = 0; j < c; ++j) m[i][j] = 0;
    }
    return m;
}

// Implementazione Muovi: riceve DIMENSIONI MATRICE (righe/colonne)
int Muovi(int &x, int &y, int righe, int colonne, char comando) {
    int nx = x;
    int ny = y;

    // Verifica se il comando appartiene all'insieme definito
    if (comando == 'x') return 0; // Resta fermo, ma è valido

    switch (comando) {
        case 'n': ny--; break;
        case 's': ny++; break;
        case 'e': nx++; break;
        case 'o': nx--; break;
        default: return -2; // Comando non valido: non muovere, passa al succ.
    }

    // Verifica se il movimento è lecito (dentro i confini)
    if (nx >= 0 && nx < colonne && ny >= 0 && ny < righe) {
        x = nx;
        y = ny;
        return 0; // Movimento eseguito
    }

    return -1; // Movimento non lecito, coordinate invariate
}