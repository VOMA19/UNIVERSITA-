#include <iostream>
using namespace std;

/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(const char* input_string);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
    char input_string[DIM+1];
    char * extracted;
    char answer;

    do {
        cout << "Inserire la stringa da controllare: ";
        cin >> input_string;

        extracted = extract(input_string);
        cout << "La stringa estratta e': " << extracted << endl;

        delete [] extracted;
        cout << "Si vuole inserire un'altra stringa? [*/n]";
        cin >> answer;
    } while (answer != '\0' && answer != 'N' && answer != 'n');
    return 0;
}

/* Inserire qui sotto la definizione della funzione estract */

// Funzione ausiliaria per contare il numero di '@'
int count_at(const char* str) {
    if (*str == '\0') {
        return 0;
    }
    return (*str == '@' ? 1 : 0) + count_at(str + 1);
}

// Funzione ausiliaria per estrarre i caratteri '@'
void fill_at(const char* src, char* dst, int& index) {
    if (*src == '\0') {
        dst[index] = '\0';
        return;
    }
    if (*src == '@') {
        dst[index] = '@';
        index++;
    }
    fill_at(src + 1, dst, index);
}

char* extract(const char* input_string) {
    int count = count_at(input_string);
    char* result = new char[count + 1];
    int index = 0;
    fill_at(input_string, result, index);
    return result;
}

/* Inserire qui sopra la definizione della funzione estract */
