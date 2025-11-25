#include <iostream>
#include <fstream>
using namespace std;

bool isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isAllUpperCase(const char* word, int length) {
    for (int i = 0; i < length; i++) {
        if (!isUpperCase(word[i])) {
            return false;
        }
    }
    return true;
}

void writeWord(ofstream& output, const char* word, int length, bool reverse) {
    if (reverse) {
        for (int i = length - 1; i >= 0; i--) {
            output << word[i];
        }
    } else {
        for (int i = 0; i < length; i++) {
            output << word[i];
        }
    }
}

void processWord(ofstream& output, const char* word, int length) {
    if (length > 0) {
        bool allUpper = isAllUpperCase(word, length);
        writeWord(output, word, length, allUpper);
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    
    if (!input || !output) {
        cout << "Errore nell'apertura dei file" << endl;
        return 1;
    }
    
    char c;
    char word[1000];
    int wordIndex = 0;
    
    while (input.get(c)) {
        if (isLetter(c)) {
            word[wordIndex++] = c;
        } else {
            processWord(output, word, wordIndex);
            wordIndex = 0;
            output << c;
        }
    }
    
    // Gestisci ultima parola
    processWord(output, word, wordIndex);
    
    input.close();
    output.close();
    
    return 0;
}
