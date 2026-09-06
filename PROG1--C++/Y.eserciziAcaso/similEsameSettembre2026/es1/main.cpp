#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double calcola_rms(double * numeri, int size );

int main(int argc, char *argv[]){

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);

    if (!input) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    int size;
    input >> size;

    if (input.fail() || input.eof() || size <= 0) {
        input.close();
        cerr << "Invalid size value in input file." << endl;
        return 1;
    }

    double * numeri = new double[size];

    if (!numeri) {
        input.close();
        delete [] numeri;
        cerr << "Error allocating memory for array." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++){
        input >> numeri[i];
        
        // input.fail() cattura sia l'EOF prematuro sia i dati non numerici
        if(input.fail()) {
            cerr << "Errore di lettura o numero di elementi insufficiente." << endl;
            input.close();
            delete [] numeri;
            return 1;
        }
    }
    

    input.close();

    double result = calcola_rms(numeri, size);

    ofstream output(argv[2]);

    if (!output) {
        delete[] numeri;
        cerr << "Error opening output file: " << argv[2] << endl;
        return 1;
    }

    output << "La varianza dei valori: ";
    for (int i = 0; i < size; ++i) {
        output << numeri[i];
        if (i < size - 1) {
            output << ", ";
        }
    }
    output << " è: " << result << std::endl;

    output.close();
    delete[] numeri;


    return 0;
}

double calcola_rms(double * numeri, int size ){
    double rms = 0;
    for (int i = 0; i < size; i++){
        rms += pow(numeri[i], 2); 
    }
    rms /= size;
    rms = sqrt(rms);
    return rms;
}