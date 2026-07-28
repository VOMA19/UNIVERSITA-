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

void calcola(ifstream &inputFile, double &result, double *&data, int & size);

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

void calcola(ifstream &inputFile, double &result, 
             double *&data, int & size, double sum)
{
   double value;
   // First read the next value from the file if any
   inputFile >> value;
   if (inputFile.eof() || inputFile.fail()) {
       if (size == 0) {
           result = -1;
           data = nullptr;
       } else {
           cout << "Size: " << size << endl;
           data = new double[size];
           sum = sum / size; // media
           result = sqrt((result - size * sum * sum) / size); // deviazione standard
       } 
   } else {
     int oldSize = size;
     sum += value;
     result += value* value;
     size++;
     calcola(inputFile, result, data, size, sum);
     data[oldSize] = value;
   }
}

void calcola(ifstream &inputFile, double &result, double *&data, int &size)
{
    result = 0.0;
    calcola(inputFile, result, data, size, 0.0);
}

// Inserire qui sopra la definizione della funzione calcola