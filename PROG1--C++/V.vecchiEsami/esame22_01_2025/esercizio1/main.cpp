#include <fstream>
#include <cstring>
#include <iostream>

// Do not modify the above lines
// Do not modify the above lines

using namespace std;
int leggi_file(const char* nome_file, int array[], int dimensione);
int check(int array[], int dimensione, int min_val, int max_val);
int voto(int sol[], int risp[], int dimensione);

int main(){
    int sol[10];
    
    // Leggi le soluzioni dal file
    if (leggi_file("Soluzioni.txt", sol, 10) == -1) {
        cout << "Errore nell'apertura del file Soluzioni.txt!" << endl;
        return 1;
    }
    
    // Verifica che le soluzioni siano valide
    if (check(sol, 10, 1, 4) == 0) {
        cout << "Errore: soluzioni non valide!" << endl;
        return 1;
    }
    
    int num_studenti;
    cout << "Inserisci il numero degli studenti partecipanti a questo appello: ";
    cin >> num_studenti;
    
    for (int i = 1; i <= num_studenti; i++) {
        char nome[32] = "Studente";
        strcat(nome, to_string(i).c_str());
        strcat(nome, ".txt");
        
        cout << "Sto elaborando il file: " << nome << endl;
        
        int risp[10];
        if (leggi_file(nome, risp, 10) == -1) {
            cout << "Errore nell'apertura del file!" << endl;
            continue;
        }
        
        int punteggio = voto(sol, risp, 10);
        
        // Scrivi il voto in fondo al file
        fstream file(nome, ios::out | ios::app);
        if (punteggio >= 18) {
            file << punteggio << endl;
        } else {
            file << "\nInsuff" << endl;
        }
        file.close();
    }

    return 0;
}

int leggi_file(const char* nome_file, int array[], int dimensione) {
    fstream file(nome_file, ios::in);
    if (!file.is_open()) {
        return -1;
    }
    
    // Riempi l'array di zeri
    for (int i = 0; i < dimensione; i++) {
        array[i] = 0;
    }
    
    int valore;
    int count = 0;
    while (file >> valore && count < dimensione) {
        array[count] = valore;
        count++;
    }
    
    file.close();
    return count;
}

int check(int array[], int dimensione, int min_val, int max_val) {
    for (int i = 0; i < dimensione; i++) {
        if (array[i] < min_val || array[i] > max_val) {
            return 0;
        }
    }
    return 1;
}

int voto(int sol[], int risp[], int dimensione) {
    int punteggio = 0;
    for (int i = 0; i < dimensione; i++) {
        if (sol[i] == risp[i]) {
            punteggio += 3;
        } else if (risp[i] != 0) {
            punteggio -= 1;
        }
    }
    return punteggio;
}
