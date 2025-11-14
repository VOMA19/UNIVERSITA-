#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

void reconstructSequence(char arr[], int index, int size);
char findSimilarLetter(char digit);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <sequenza>" << endl;
        return 1;
    }
    
    char* sequence = argv[1];
    int size = 0;
    while (sequence[size] != '\0') {
        size++;
    }
    
    cout << "Sequenza originale: " << sequence << endl;
    reconstructSequence(sequence, 0, size);
    cout << "Sequenza ricostruita: " << sequence << endl;
    
    return 0;
}

char findSimilarLetter(char digit) {
    switch(digit) {
        case '0': return 'O';
        case '1': return 'I';
        case '2': return 'Z';
        case '3': return 'E';
        case '4': return 'A';
        case '5': return 'S';
        case '6': return 'G';
        case '7': return 'T';
        case '8': return 'B';
        default: return digit;
    }
}

void reconstructSequence(char arr[], int index, int size) {
    if (index == size) {
        return;
    }
    if (isdigit(arr[index])) {
        arr[index] = findSimilarLetter(arr[index]);
    }
    reconstructSequence(arr, index + 1, size);
}