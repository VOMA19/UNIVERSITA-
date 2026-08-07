#include <iostream>
#include <fstream>
#include <cstdlib>

double calcola(double* array, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    double mean = sum / size;

    double varianceSum = 0.0;
    for (int i = 0; i < size; ++i) {
        varianceSum += (array[i] - mean) * (array[i] - mean);
    }
    return varianceSum / size;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening input file: " << argv[1] << std::endl;
        return 1;
    }

    int size;
    inputFile >> size;

    if (inputFile.fail() || inputFile.eof() || size <= 0) {
        inputFile.close();
        std::cerr << "Invalid size value in input file." << std::endl;
        return 1;
    }

    double* array = new (std::nothrow) double[size];
    if (!array) {
        inputFile.close();
        std::cerr << "Error allocating memory for array." << std::endl;
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        inputFile >> array[i];
        if (inputFile.fail() || inputFile.eof()) {
            delete[] array;
            inputFile.close();
            std::cerr << "Error reading array elements from input file." << std::endl;
            return 1;
        }
    }
    inputFile.close();

    double result = calcola(array, size);

    std::ofstream outputFile(argv[2]);
    if (!outputFile) {
        delete[] array;
        std::cerr << "Error opening output file: " << argv[2] << std::endl;
        return 1;
    }

    outputFile << "La varianza dei valori: ";
    for (int i = 0; i < size; ++i) {
        outputFile << array[i];
        if (i < size - 1) {
            outputFile << ", ";
        }
    }
    outputFile << " è: " << result << std::endl;

    outputFile.close();
    delete[] array;
    return 0;
}
