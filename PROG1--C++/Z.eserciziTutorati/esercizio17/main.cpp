#include <iostream>
using namespace std;

void hit(char battleField[6][6]);
void printBattleField(char battleField[6][6]);
int main(){

    char battleField[6][6]{ {'1',' ',' ','2','2',' '},
                            {' ','2','2',' ',' ',' '},
                            {' ',' ',' ','3','3','3'},
                            {'1',' ','1',' ','2','2'},
                            {' ','1',' ',' ',' ',' '},
                            {'3','3','3',' ',' ',' '}};

    cout << "=== ⚓ Battaglia Navale - Modalità singolo giocatore ===\n";

    bool running = true;
    while (running) {
        printBattleField(battleField);
        hit(battleField);

        char risposta;
        cout << "\nVuoi continuare? (s/n): ";
        cin >> risposta;
        if (risposta == 'n' || risposta == 'N') {
            running = false;
        }
    }

    cout << "\n=== Fine partita ===\n";
    printBattleField(battleField);

    return 0;
}

void hit(char battleField[6][6]){
    char coordinata[3]; // es. "A3"

    // --- Input e validazione ---
    do {
        cout << "Inserisci una coordinata (es. A3): ";
        cin >> coordinata;

        if (coordinata[0] < 'A' || coordinata[0] > 'F' || coordinata[1] < '1' || coordinata[1] > '6') {
            cout << "Coordinata non valida!" << endl;
        } else {
            break;
        }
    } while (true);

    int r = coordinata[0] - 'A';  // Riga
    int c = coordinata[1] - '1';  // Colonna

    char &cell = battleField[r][c];

    // --- Controllo colpo ---
    if(cell == '1' || cell == '2' || cell == '3'){
        cout << "Colpito!" << endl;
        char nave = cell;  // tipo nave (1, 2 o 3)
        cell = 'X';        // segna colpito

        // --- Danno progressivo ---
        // Verifica le celle adiacenti (su, giù, sinistra, destra)
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < 6 && nc >= 0 && nc < 6) {
                if (battleField[nr][nc] == nave) {
                    battleField[nr][nc] = nave - 1; // esempio: '3' → '2'
                }
            }
        }

    }else{
        cout << "Mancato!" << endl;
        cell = 'O';
    }
}

void printBattleField(char battleField[6][6]) {
    cout << "\n    "; // spazio per intestazione
    for (int col = 0; col < 6; col++)
        cout << col + 1 << "   ";
    cout << endl;

    cout << "  +---+---+---+---+---+---+" << endl;

    for (int row = 0; row < 6; row++) {
        cout << (char)('A' + row) << " | ";
        for (int col = 0; col < 6; col++) {
            cout << battleField[row][col] << " | ";
        }
        cout << endl;
        cout << "  +---+---+---+---+---+---+" << endl;
    }

    cout << endl;
}