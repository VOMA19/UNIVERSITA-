#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 3; // Numero di tabelle

void creaCartella(int cart[3][9]);
void stampaCartella(int cart[3][9]);
void ordinaColonna(int cart[3][9], int colonna);
void putZero(int cart[3][9]);
void segnaCella(int cart[3][9], bool marked[3][9], int numero);
void stampaCartellaConMarcature(int cart[3][9], bool marked[3][9]);
int check(bool marked[3][9]);
void stampaTutteCartelle(int carte[N][3][9], bool marcate[N][3][9]);

int main(int argc, char* argv[]) {
    
    int maxEstrazioni = 100; // valore di default
    if (argc > 1) {
        maxEstrazioni = atoi(argv[1]);
    }
    
    int carte[N][3][9];
    bool marcate[N][3][9] = {};
    bool estratti[90] = {}; // traccia numeri estratti
    int numero;
    bool tombola_trovata = false;
    int tabella_vincente = -1;
    int contEstrazioni = 0;

    srand(time(0));
    
    // Crea N tabelle
    for (int i = 0; i < N; i++) {
        creaCartella(carte[i]);
        putZero(carte[i]);
    }
    
    stampaTutteCartelle(carte, marcate);

    while (!tombola_trovata && contEstrazioni < maxEstrazioni) {
        cout << "\nPremere INVIO per estrarre un numero (estrazioni: " << contEstrazioni + 1 << "/" << maxEstrazioni << "): ";
        cin.ignore();
        
        // Estrai un numero non ripetuto
        int numero_temp;
        do {
            numero_temp = rand() % 90;
        } while (estratti[numero_temp]);
        
        numero = numero_temp;
        estratti[numero] = true;
        contEstrazioni++;
        
        cout << "Numero estratto: " << numero << endl << endl;
        
        // Segna il numero su tutte le tabelle
        for (int i = 0; i < N; i++) {
            segnaCella(carte[i], marcate[i], numero);
            int result = check(marcate[i]);
            if (result == 5) {
                tombola_trovata = true;
                tabella_vincente = i;
            }
        }
        
        stampaTutteCartelle(carte, marcate);
    }
    
    if (tombola_trovata) {
        cout << "\033[32m\n*** TOMBOLA! Tabella " << (tabella_vincente + 1) << " ha vinto! ***\033[0m" << endl;
    } else {
        cout << "\n*** GAME OVER! Limite di " << maxEstrazioni << " estrazioni raggiunto. ***" << endl;
    }
    
    return 0;
}

void stampaTutteCartelle(int carte[N][3][9], bool marcate[N][3][9]) {
    for (int i = 0; i < N; i++) {
        cout << "\n--- Tabella " << (i + 1) << " ---" << endl;
        stampaCartellaConMarcature(carte[i], marcate[i]);
    }
}

int check(bool marked[3][9]) {
    // Controlla tombola (tutte le caselle senza zero)
    int total_marked = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (marked[i][j]) total_marked++;
        }
    }
    if (total_marked == 15) {
        return 5;        // tombola
    }
    return 0;
}

void segnaCella(int cart[3][9], bool marked[3][9], int numero) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (cart[i][j] == numero) {
                marked[i][j] = true;
                return;
            }
        }
    }
}

void stampaCartellaConMarcature(int cart[3][9], bool marked[3][9]) {
    for (int j = 0; j < 9; j++) cout << "+----";
    cout << "+" << endl;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "| ";
            if (cart[i][j] == 0) {
                cout << "  ";
            } else {
                if (marked[i][j]){
                    cout << "\033[38;2;135;77;191m";
                }
                if (cart[i][j] - 9 <= 0) cout << 0;
                cout << cart[i][j];
                
                if (marked[i][j]) {
                    cout << "\033[0m";
                }
            }
            cout << " ";
        }
        cout << "|" << endl;
        for (int j = 0; j < 9; j++) cout << "+----";
        cout << "+" << endl;
    }
}

void stampaCartella(int cart[3][9]){
    for (int j = 0; j < 9; j++){
        cout << "+----";
    }
    cout << "+" << endl;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 9; j++){
            cout << "| ";
            if (cart[i][j] == 0){
                cout << "  ";
            } else {
                if(cart[i][j]-9 <= 0)
                    cout << 0;
                cout << cart[i][j];
            }
            cout << " ";
        }   
        cout << "|" << endl;
        
        for (int j = 0; j < 9; j++){
            cout << "+----";
        }
        cout << "+" << endl;
    }
}

void creaCartella(int cart[3][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 3; j++){
            int min = i * 10 + 1;
            int max = (i + 1) * 10;
            int num;
            bool duplicato;
            bool troppoVicino;
            do {
                duplicato = false;
                troppoVicino = false;
                num = min + rand() % (max - min + 1);
                
                for (int k = 0; k < j; k++){
                    if (cart[k][i] == num){
                        duplicato = true;
                        break;
                    }
                    if (abs(cart[k][i] - num) < 2){
                        troppoVicino = true;
                        break;
                    }
                }
            }while(duplicato || troppoVicino);
            cart[j][i] = num;
        }
        ordinaColonna(cart, i);
    }
}

void ordinaColonna(int cart[3][9], int colonna){
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            if (cart[i][colonna] > cart[j][colonna]){
                int temp = cart[i][colonna];
                cart[i][colonna] = cart[j][colonna];
                cart[j][colonna] = temp;
            }
        }
    }
}

void putZero(int cart[3][9]){
    for (int i = 0; i < 3; i++){
        int zeri = 0;
        while (zeri < 4){
            int col = rand() % 9;
            int zeriInColonna = 0;
            
            for (int k = 0; k < 3; k++){
                if (cart[k][col] == 0){
                    zeriInColonna++;
                }
            }
            
            if (cart[i][col] != 0 && zeriInColonna < 2){
                cart[i][col] = 0;
                zeri++;
            }
        }
    }
}
