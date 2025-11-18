#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Contatto {
    int id;
    string nome;
    string cognome;
    string telefono;
    string email;
};

class Rubrica {
private:
    vector<Contatto> contatti;
    int nextId;

public:
    Rubrica() {
        nextId = 1;
    }

    void inserisciContatto() {
        Contatto c;
        c.id = nextId++;

        cout << "Inserisci nome: ";
        getline(cin, c.nome);
        cout << "Inserisci cognome: ";
        getline(cin, c.cognome);
        cout << "Inserisci telefono: ";
        getline(cin, c.telefono);
        cout << "Inserisci email: ";
        getline(cin, c.email);

        contatti.push_back(c);
        cout << "Contatto inserito con ID " << c.id << endl;
    }

    void visualizzaTutti() {
        if (contatti.empty()) {
            cout << "Nessun contatto in rubrica." << endl;
            return;
        }
        for (const auto& c : contatti) {
            cout << "ID: " << c.id << endl;
            cout << "Nome: " << c.nome << endl;
            cout << "Cognome: " << c.cognome << endl;
            cout << "Telefono: " << c.telefono << endl;
            cout << "Email: " << c.email << endl;
            cout << "---------------------------" << endl;
        }
    }

    void cercaPerNome() {
        cout << "Inserisci nome da cercare: ";
        string nomeRicerca;
        getline(cin, nomeRicerca);

        bool trovato = false;
        for (const auto& c : contatti) {
            if (c.nome == nomeRicerca) {
                cout << "ID: " << c.id << " - " << c.nome << " " << c.cognome << " | Tel: " << c.telefono << " | Email: " << c.email << endl;
                trovato = true;
            }
        }
        if (!trovato)
            cout << "Nessun contatto trovato con il nome " << nomeRicerca << endl;
    }

    void cercaPerCognome() {
        cout << "Inserisci cognome da cercare: ";
        string cognomeRicerca;
        getline(cin, cognomeRicerca);

        bool trovato = false;
        for (const auto& c : contatti) {
            if (c.cognome == cognomeRicerca) {
                cout << "ID: " << c.id << " - " << c.nome << " " << c.cognome << " | Tel: " << c.telefono << " | Email: " << c.email << endl;
                trovato = true;
            }
        }
        if (!trovato)
            cout << "Nessun contatto trovato con il cognome " << cognomeRicerca << endl;
    }

    void modificaContatto() {
        cout << "Inserisci ID contatto da modificare: ";
        int id;
        cin >> id;
        cin.ignore();

        auto it = find_if(contatti.begin(), contatti.end(), [id](Contatto& c) { return c.id == id; });
        if (it == contatti.end()) {
            cout << "ID non trovato." << endl;
            return;
        }

        cout << "Modifica nome (vecchio: " << it->nome << "): ";
        string nuovoNome;
        getline(cin, nuovoNome);
        if (!nuovoNome.empty()) it->nome = nuovoNome;

        cout << "Modifica cognome (vecchio: " << it->cognome << "): ";
        string nuovoCognome;
        getline(cin, nuovoCognome);
        if (!nuovoCognome.empty()) it->cognome = nuovoCognome;

        cout << "Modifica telefono (vecchio: " << it->telefono << "): ";
        string nuovoTelefono;
        getline(cin, nuovoTelefono);
        if (!nuovoTelefono.empty()) it->telefono = nuovoTelefono;

        cout << "Modifica email (vecchia: " << it->email << "): ";
        string nuovaEmail;
        getline(cin, nuovaEmail);
        if (!nuovaEmail.empty()) it->email = nuovaEmail;

        cout << "Contatto modificato." << endl;
    }

    void eliminaContatto() {
        cout << "Inserisci ID contatto da eliminare: ";
        int id;
        cin >> id;
        cin.ignore();

        auto it = remove_if(contatti.begin(), contatti.end(), [id](Contatto& c){ return c.id == id; });
        if (it == contatti.end()) {
            cout << "ID non trovato." << endl;
            return;
        }
        contatti.erase(it, contatti.end());
        cout << "Contatto eliminato." << endl;
    }

    void ordinaPerNome() {
        sort(contatti.begin(), contatti.end(), [](const Contatto& a, const Contatto& b){
            return a.nome < b.nome;
        });
        cout << "Rubrica ordinata per nome." << endl;
    }

    void ordinaPerCognome() {
        sort(contatti.begin(), contatti.end(), [](const Contatto& a, const Contatto& b){
            return a.cognome < b.cognome;
        });
        cout << "Rubrica ordinata per cognome." << endl;
    }

    void menu() {
        cout << "Menu Rubrica:\n";
        cout << "1. Inserisci contatto\n";
        cout << "2. Visualizza tutti\n";
        cout << "3. Cerca per nome\n";
        cout << "4. Cerca per cognome\n";
        cout << "5. Modifica contatto\n";
        cout << "6. Elimina contatto\n";
        cout << "7. Ordina per nome\n";
        cout << "8. Ordina per cognome\n";
        cout << "9. Esci\n";
        cout << "Scegli opzione: ";
    }

    void run() {
        while (true) {
            menu();
            int scelta;
            cin >> scelta;
            cin.ignore();

            switch (scelta) {
                case 1: inserisciContatto(); break;
                case 2: visualizzaTutti(); break;
                case 3: cercaPerNome(); break;
                case 4: cercaPerCognome(); break;
                case 5: modificaContatto(); break;
                case 6: eliminaContatto(); break;
                case 7: ordinaPerNome(); break;
                case 8: ordinaPerCognome(); break;
                case 9: cout << "Uscita..." << endl; return;
                default: cout << "Opzione non valida." << endl; break;
            }

            cout << endl;
        }
    }
};

int main() {
    Rubrica rubrica;
    rubrica.run();
    return 0;
}
