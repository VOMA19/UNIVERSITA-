#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <nome_file>" << endl;
        return 1;
    }
    
    ifstream file(argv[1]);
    if (!file) {
        cerr << "Errore: impossibile aprire il file " << argv[1] << endl;
        return 1;
    }
    
    int conteggio[26] = {0};
    char c;
    
    while (file.get(c)) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char letteraMinuscola = (c >= 'A' && c <= 'Z') ? c + 32 : c;
            conteggio[letteraMinuscola - 'a']++;
        }
    }
    
    file.close();
    
    for (int i = 0; i < 26; i++) {
        if (conteggio[i] > 0) {
            cout << (char)('a' + i) << ": " << conteggio[i] << endl;
        }
    }
    
    return 0;
}