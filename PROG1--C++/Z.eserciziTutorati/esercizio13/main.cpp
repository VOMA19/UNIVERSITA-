#include <iostream>
#include <ctime>
using namespace std;

enum Scelta { SASSO = 1, CARTA, FORBICE };
int computer();
int round(int A, int B);
void menu();
int scegli_giocatore(int num);
string scelta_to_string(int scelta);
int scegli_modalita();

int main(){
    srand(time(0));
    int vittoriaG1 = 0, vittoriaG2 = 0;

    int modalita = scegli_modalita();

    while (vittoriaG1 < 3 && vittoriaG2 < 3) {
        int scelta1, scelta2;

        if (modalita == 1) {
            scelta1 = scegli_giocatore(1);
            scelta2 = computer();
            cout << "Il computer ha scelto: " << scelta_to_string(scelta2) << endl;
        } else if (modalita == 2) {
            scelta1 = scegli_giocatore(1);
            scelta2 = scegli_giocatore(2);
        } else if (modalita == 3) {
            scelta1 = computer();
            scelta2 = computer();
            cout << "Computer A ha scelto: " << scelta_to_string(scelta1) << endl;
            cout << "Computer B ha scelto: " << scelta_to_string(scelta2) << endl;
        } else {
            cout << "Modalità non valida.\n";
            return 1;
        }

        int risultato = round(scelta1, scelta2);

        if (risultato == -1) {
            cout << "Pareggio, si ripete il round.\n";
            
        } else if (risultato) {
            cout << "Vittoria Giocatore A!\n";
            vittoriaG1++;
        } else {
            cout << "Vittoria Giocatore B!\n";
            vittoriaG2++;
        }
        cout << "Punteggio: Giocatore A " << vittoriaG1 << " - Giocatore B " << vittoriaG2 << "\n\n";

    }

    if(modalita == 1){

        if (vittoriaG1 == 3)
            cout << "Giocatore A ha vinto la partita!\n";
        else
            cout << "il Computer ha vinto la partita!\n";

    }else if(modalita == 2){

        if (vittoriaG1 == 3)
            cout << "Giocatore A ha vinto la partita!\n";
        else
            cout << "Giocatore B ha vinto la partita!\n";
    }else{
        if (vittoriaG1 == 3)
            cout << "Computer A ha vinto la partita!\n";
        else
            cout << "Computer B ha vinto la partita!\n";
    }

    return 0;
}

int scegli_modalita() {
    cout << "Scegli modalità di gioco:\n";
    cout << "1 --> Giocatore vs Computer\n";
    cout << "2 --> Giocatore vs Giocatore\n";
    cout << "3 --> Computer vs Computer\n";
    cout << "Scelta: ";
    int modalita;
    cin >> modalita;
    return modalita;
}

int computer() {
    return 1 + rand() % 3;
}

// Ritorna true se vince A, false se vince B, e -1 se pareggio
int round(int A, int B) {
    if (A == B) return -1; // pareggio
    if ((A == SASSO && B == FORBICE) ||
        (A == CARTA && B == SASSO) ||
        (A == FORBICE && B == CARTA))
        return true; // vince A
    return false; // vince B
}

void menu() {
    cout << "Scegli tra:\n";
    cout << "1 --> Sasso\n";
    cout << "2 --> Carta\n";
    cout << "3 --> Forbice\n";
    cout << "Scegli: ";
}

int scegli_giocatore(int num) {
    cout << "Giocatore " << num << ", ";
    menu();
    int scelta;
    cin >> scelta;
    return scelta;
}

string scelta_to_string(int scelta) {
    switch (scelta) {
        case SASSO: return "sasso";
        case CARTA: return "carta";
        case FORBICE: return "forbice";
        default: return "scelta non valida";
    }
}