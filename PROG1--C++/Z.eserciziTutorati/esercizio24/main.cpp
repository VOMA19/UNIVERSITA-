#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/*
    Scrivere un programma che prende in input
    un file da riga di comando.
    Lo legge e stampa in standard output ogni
    parola invertita.
*/
int main(int argc, char* argv[]){
    
    if(argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if(!file.is_open()) {
        cout << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    char word[1000];
    while(file >> word) {
        // Reverse the word
        int len = strlen(word);
        for(int i = len - 1; i >= 0; i--) {
            cout << word[i];
        }
        cout << " ";
    }
    cout << endl;

    file.close();
    return 0;
}