#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    
    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file " << argv[1] << endl;
        return 1;
    }
    
    ofstream outputFile(argv[2], ios::app);
    if (!outputFile.is_open()){
        cerr << "Error: Cannot open output file " << argv[2] << endl;
        inputFile.close();
        return 1;
    }
    
    char line[1024];
    while (inputFile.getline(line, 1024)){
        outputFile << line << endl;
    }
    
    inputFile.close();
    outputFile.close();
    
    cout << "File copied successfully in append mode." << endl;
    return 0;
}