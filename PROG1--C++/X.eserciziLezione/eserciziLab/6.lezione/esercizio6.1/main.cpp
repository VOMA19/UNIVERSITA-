#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    // Controllo dei parametri
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nomefile>" << endl;
        return 1;
    }

    // Apertura del file
    ifstream file(argv[1]);
    
    if (!file.is_open()) {
        cerr << "Errore: impossibile aprire il file." << endl;
        return 1;
    }

    // Lettura e visualizzazione del contenuto
    char linea[256];
    while (file.getline(linea, sizeof(linea))) {
        cout << linea << endl;
    }

    file.close();
    return 0;
}
