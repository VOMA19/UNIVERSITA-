#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <file_input> <file_output>" << endl;
        return 1;
    }

    fstream input(argv[1], ios::in);
    if (!input) {
        cerr << "Errore nell'apertura del file di input" << endl;
        return 1;
    }

    fstream output(argv[2], ios::out);
    if (!output) {
        cerr << "Errore nell'apertura del file di output" << endl;
        return 1;
    }

    bool capitalize_next = true;
    char c;

    while (input.get(c)) {
        if (capitalize_next && c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
            capitalize_next = false;
        } else if (capitalize_next && c >= 'A' && c <= 'Z') {
            capitalize_next = false;
        }

        output.put(c);

        if (c == '.' || c == '!' || c == '?') {
            capitalize_next = true;
        }
    }

    input.close();
    output.close();

    return 0;
}
