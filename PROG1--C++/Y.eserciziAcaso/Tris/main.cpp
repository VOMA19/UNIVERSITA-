#include <iostream>
#include <vector>

using namespace std;

char tabella[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char turno = 'X';
bool pareggio = false;

void disegnaTabella() {
    /* 
       Pulisce lo schermo in modo portabile (o quasi)
       Su Windows 'cls' funziona, su Linux 'clear'. 
       Per semplicità qui stampiamo solo molte righe o semplicemente ridisegniamo.
    */
    // system("cls"); 
    cout << "\n\n\tTris Game\n\n";
    cout << "Giocatore 1 (X)  -  Giocatore 2 (O)\n\n";
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tabella[0][0] << "  |  " << tabella[0][1] << "  |  " << tabella[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tabella[1][0] << "  |  " << tabella[1][1] << "  |  " << tabella[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tabella[2][0] << "  |  " << tabella[2][1] << "  |  " << tabella[2][2] << endl;
    cout << "     |     |     " << endl << endl;
}

void turnoGiocatore() {
    int scelta;
    int riga = 0, colonna = 0;

    if(turno == 'X'){
        cout << "\tTocca al Giocatore 1 [X]: ";
    } else {
        cout << "\tTocca al Giocatore 2 [O]: ";
    }
    
    if (!(cin >> scelta)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input non valido! Inserisci un numero." << endl;
        turnoGiocatore();
        return;
    }

    switch(scelta){
        case 1: riga=0; colonna=0; break;
        case 2: riga=0; colonna=1; break;
        case 3: riga=0; colonna=2; break;
        case 4: riga=1; colonna=0; break;
        case 5: riga=1; colonna=1; break;
        case 6: riga=1; colonna=2; break;
        case 7: riga=2; colonna=0; break;
        case 8: riga=2; colonna=1; break;
        case 9: riga=2; colonna=2; break;
        default:
            cout << "Numero non valido! Scegli tra 1 e 9." << endl;
            turnoGiocatore();
            return;
    }

    if(turno == 'X' && tabella[riga][colonna] != 'X' && tabella[riga][colonna] != 'O'){
        tabella[riga][colonna] = 'X';
        turno = 'O';
    } else if(turno == 'O' && tabella[riga][colonna] != 'X' && tabella[riga][colonna] != 'O'){
        tabella[riga][colonna] = 'O';
        turno = 'X';
    } else {
        cout << "Casella gia' occupata! Riprova.\n";
        turnoGiocatore();
    }
}

bool controlloPartitaInCorso() {
    // Controllo righe e colonne per vittoria
    for(int i=0; i<3; i++) {
        if((tabella[i][0] == tabella[i][1] && tabella[i][0] == tabella[i][2]) || 
           (tabella[0][i] == tabella[1][i] && tabella[0][i] == tabella[2][i]))
            return false; // Qualcuno ha vinto
    }

    // Controllo diagonali per vittoria
    if((tabella[0][0] == tabella[1][1] && tabella[0][0] == tabella[2][2]) || 
       (tabella[0][2] == tabella[1][1] && tabella[0][2] == tabella[2][0]))
        return false; // Qualcuno ha vinto

    // Controllo se ci sono spazi vuoti (il gioco continua)
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(tabella[i][j] != 'X' && tabella[i][j] != 'O')
                return true; // Gioco continua

    // Se arriviamo qui e non ha vinto nessuno, è pareggio
    pareggio = true;
    return false;
}

int main() {
    while(controlloPartitaInCorso()){
        disegnaTabella();
        turnoGiocatore();
    }
    
    disegnaTabella();
    
    if(pareggio) {
        cout << "\tPARTITA PATTA!" << endl;
    } else {
        // Se non è patta e il turno è cambiato, allora ha vinto chi ha giocato PRIMA del cambio turno
        if(turno == 'O') {
            cout << "\tIL GIOCATORE 1 [X] VINCE!" << endl;
        } else {
            cout << "\tIL GIOCATORE 2 [O] VINCE!" << endl;
        }
    }
    
    cout << "\nPremi invio per uscire...";
    cin.ignore(); 
    cin.get();
    
    return 0;
}
