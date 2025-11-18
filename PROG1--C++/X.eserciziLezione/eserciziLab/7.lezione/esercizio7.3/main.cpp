#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void ordinaDecrescente(double* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <file> <M> <N>" << endl;
        return 1;
    }
    
    char* filename = argv[1];
    int M = atoi(argv[2]);
    int N = atoi(argv[3]);
    
    if (M <= 0 || N <= 0) {
        cout << "M e N devono essere positivi" << endl;
        return 1;
    }
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    
    double* temperature = new double[M];
    int count = 0;
    
    while (count < M && file >> temperature[count]) {
        count++;
    }
    
    file.close();
    
    if (count == 0) {
        cout << "Nessuna temperatura letta dal file" << endl;
        delete[] temperature;
        return 1;
    }
    
    ordinaDecrescente(temperature, count);
    
    int numDaStampare = (N < count) ? N : count;
    cout << "Le " << numDaStampare << " temperature più alte:" << endl;
    
    for (int i = 0; i < numDaStampare; i++) {
        cout << temperature[i] << endl;
    }
    
    delete[] temperature;
    
    return 0;
}