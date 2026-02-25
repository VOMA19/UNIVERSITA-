#include <iostream>
#include <cstdlib>

using namespace std;

enum Colore { ROSSO, VERDE, BLU, GIALLO };

struct Lista {
    Colore tile;
    Lista* next;
};

struct Pavimento {
    double lunghezza;
    double larghezza;
    Lista ** area;
};


void PrintPavimento(const Pavimento & p, double tile_size) {
    int rows = int(p.lunghezza / tile_size);
    
    for (int i = 0; i < rows; ++i) {
        double v = p.larghezza;
        Lista* current = p.area[i];
        while (current != nullptr) {
            v = v - tile_size;
            switch (current->tile) {
                case ROSSO: cout << "R"; break;
                case VERDE: cout << "G"; break;
                case BLU: cout << "B"; break;
                case GIALLO: cout << "Y"; break;
            }
            current = current->next;
        }
        cout << " " << v << endl;
    }
    cout << (p.lunghezza - rows * tile_size) << endl;
}

// Inserire qui sotto la dichiarazione della funzione ricorsiva CalcolaPavimento
void FillRow(Lista* & head, double w, double ts, int r, int c);
void CalcolaPavimentoRecur(Pavimento & p, double ts, int r, int total_r);
void CalcolaPavimento(Pavimento & p, double ts);
// Inserire qui sopra la dichiarazione della funzione ricorsiva CalcolaPavimento

int main(int argc, char* argv[]) {
    Pavimento pavimento;
    pavimento.lunghezza = 15.0;
    pavimento.larghezza = 15.0;

    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <length> <width> <tile_size>" << endl;
        return 1;
    }

    double length = atof(argv[1]);
    double width = atof(argv[2]);
    double tile_size = atof(argv[3]);

    if (tile_size <= 0.0) {
        cerr << "Tile size must be a positive number." << endl;
        return 1;
    }

    if (length <= 0.0 || width <= 0.0) {
        cerr << "Length and width must be positive numbers." << endl;
        return 1;
    }

    pavimento.lunghezza = length;
    pavimento.larghezza = width;

    if (tile_size <= 0.0) {
        cerr << "Tile size must be a positive number." << endl;
        return 1;
    }

    CalcolaPavimento(pavimento, tile_size);

    PrintPavimento(pavimento, tile_size);

    // Clean up memory
    int rows = int(pavimento.lunghezza / tile_size);
    for (int i = 0; i < rows; ++i) {
        Lista* current = pavimento.area[i];
        while (current != nullptr){
            Lista* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }
    delete[] pavimento.area;
    return 0;
}

// Inserire qui sotto la definizione della funzione ricorsiva CalcolaPavimento
//RY
void FillRow(Lista* & head, double w, double ts, int r, int c) {
    if (w < ts) { head = nullptr; return; }
    Colore col = ((r + c) % 2 == 0) ? ROSSO : GIALLO;
    head = new Lista{col, nullptr};
    FillRow(head->next, w - ts, ts, r, c + 1);
}

void CalcolaPavimentoRecur(Pavimento & p, double ts, int r, int total_r) {
    if (r >= total_r) return;
    FillRow(p.area[r], p.larghezza, ts, r, 0);
    CalcolaPavimentoRecur(p, ts, r + 1, total_r);
}

void CalcolaPavimento(Pavimento & p, double ts) {
    int rows = int(p.lunghezza / ts);
    p.area = (rows > 0) ? new Lista*[rows] : nullptr;
    if (rows > 0) CalcolaPavimentoRecur(p, ts, 0, rows);
}
/*
//BGY
void FillRow(Lista* & head, double w, double ts, int r, int c) {
    if (w < ts) { head = nullptr; return; }
    int idx = (r + c) % 3;
    Colore col = (idx == 0) ? BLU : (idx == 1) ? VERDE : GIALLO;
    head = new Lista{col, nullptr};
    FillRow(head->next, w - ts, ts, r, c + 1);
}
// CalcolaPavimentoRecur e CalcolaPavimento seguono lo schema della V1

/*
//BR
void FillRow(Lista* & head, double w, double ts, int r, int c) {
    if (w < ts) { head = nullptr; return; }
    Colore col = ((r + c) % 2 == 0) ? BLU : ROSSO;
    head = new Lista{col, nullptr};
    FillRow(head->next, w - ts, ts, r, c + 1);
}
*/

/*RYG
void FillRow(Lista* & head, double w, double ts, int r, int c) {
    if (w < ts) { head = nullptr; return; }
    int idx = (r + c) % 3;
    Colore col = (idx == 0) ? ROSSO : (idx == 1) ? GIALLO : VERDE;
    head = new Lista{col, nullptr};
    FillRow(head->next, w - ts, ts, r, c + 1);
}
*/
// Inserire qui sopra la definizione della funzione ricorsiva CalcolaPavimento