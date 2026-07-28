#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

double varianza(double *data, int size) {
    double sumSQ = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sumSQ += (data[i] * data[i]);
        sum += data[i];
    }
    double mean = sum / size;
    return (sumSQ - size * (mean * mean)) / size;
}

double deviazioneStandard(double *data, int size) {
    return sqrt(varianza(data, size));
}

// Inserire qui sotto la dichiarazione della funzione calcola


// Inserire qui sopra la dichiarazione della funzione calcola

int main (int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        return -1;
    }

    double result;
    double *data;
    int size = 0;
    
    calcola(inputFile, result, data, size);

    cout << "Result: " << result << endl;
    if (size > 0) {
        cout << "Standard Deviation: " << deviazioneStandard(data, size) << endl;
        delete[] data;
    } else {
        cout << "No data to calculate standard deviation." << endl;
    }
    
    inputFile.close();
    return 0;
}

// Inserire qui sotto la definizione della funzione calcola


// Inserire qui sopra la definizione della funzione calcola