#include <iostream>
#include <cstring>
using namespace std;

struct Monaco{
    char nome[50];
    int eta;
    char mansione[50];
    int anniEsperienza;
};

int menu();
Monaco creaMonaco(Monaco monaci[], int &numeroMonaci);
void stampaMonaci(Monaco monaci[], int numeroMonaci);
void ordinaMonaci(Monaco monaci[], int numeroMonaci, bool ordineCrescente);
const int N = 100;

int main(){
    int numeroMonaci = 0;
    Monaco* monaci = new Monaco[N];
    bool ordineCrescente = true;
    int sc = 0;
    do{
        sc= menu();

        switch (sc){
        case 1:
            monaci[numeroMonaci-1] = creaMonaco(monaci, numeroMonaci);
            break;
        case 2:
            stampaMonaci(monaci, numeroMonaci);
            break;
        case 3:
            ordinaMonaci(monaci, numeroMonaci, ordineCrescente);
            break;
        default:
            cout << "valore non valido" << endl;
            break;
    }
    }while(sc != 0);
    
    return 0;
}

int menu(){
    int sc;

    cout << "1 -- inserisci un nuovo monaco" <<endl;
    cout << "2 -- stampa monaci " <<endl;
    cout << "3 -- ordina monaci " <<endl;
    cout << "scelta: ";
    cin >> sc;

    return sc;
}

Monaco creaMonaco(Monaco monaci[], int &numeroMonaci){
    Monaco m;
    cout << "Inserisci nome: ";
    cin >> m.nome;
    cout << "Inserisci eta: ";
    cin >> m.eta;
    cout << "Inserisci mansione: ";
    cin >> m.mansione;
    cout << "Inserisci anni di esperienza: ";
    cin >> m.anniEsperienza;

    numeroMonaci ++;
    return m;
}

void stampaMonaci(Monaco monaci[], int numeroMonaci) {
    if (numeroMonaci == 0) {
        cout << "Nessun monaco presente." << endl;
        return;
    }
    
    cout << "\n--- Lista Monaci ---" << endl;
    for (int i = 0; i < numeroMonaci; i++) {
        cout << "Monaco " << (i + 1) << ":" << endl;
        cout << "  Nome: " << monaci[i].nome << endl;
        cout << "  Eta: " << monaci[i].eta << endl;
        cout << "  Mansione: " << monaci[i].mansione << endl;
        cout << "  Anni di esperienza: " << monaci[i].anniEsperienza << endl;
        cout << endl;
    }
}

void ordinaMonaci(Monaco monaci[], int numeroMonaci, bool ordineCrescente) {
    if (numeroMonaci <= 1) {
        cout << "Non ci sono abbastanza monaci da ordinare." << endl;
        return;
    }
    
    // Bubble sort con toggle crescente/decrescente
    for (int i = 0; i < numeroMonaci - 1; i++) {
        for (int j = 0; j < numeroMonaci - i - 1; j++) {
            bool scambia = false;
            
            if (ordineCrescente) {
                // Ordine crescente
                if (monaci[j].anniEsperienza > monaci[j + 1].anniEsperienza) {
                    scambia = true;
                }
            } else {
                // Ordine decrescente
                if (monaci[j].anniEsperienza < monaci[j + 1].anniEsperienza) {
                    scambia = true;
                }
            }
            
            if (scambia) {
                Monaco temp = monaci[j];
                monaci[j] = monaci[j + 1];
                monaci[j + 1] = temp;
            }
        }
    }
    
    // Toggle dell'ordine per la prossima volta
    ordineCrescente = !ordineCrescente;
    
    if (!ordineCrescente) {
        cout << "Monaci ordinati in ordine crescente per anni di esperienza." << endl;
    } else {
        cout << "Monaci ordinati in ordine decrescente per anni di esperienza." << endl;
    }
}