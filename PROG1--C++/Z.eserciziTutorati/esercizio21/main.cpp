#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/*
    Scrivere un programma che prende in input
    da riga di comando un file e due stringhe
    e sostituisce ogni occorrenza della prima con
    la seconda nel file.
*/

int main(int argc, char* argv[]){
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <filename> <search_string> <replace_string>" << endl;
        return 1;
    }
    
    char* filename = argv[1];
    char* searchStr = argv[2];
    char* replaceStr = argv[3];
    
    // Read file content
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return 1;
    }
    
    char content[10000] = "";
    char line[1000];
    while (file.getline(line, 1000)) {
        strcat(content, line);
        strcat(content, "\n");
    }
    file.close();
    
    // Replace occurrences
    char result[10000] = "";
    int contentLen = strlen(content);
    int searchLen = strlen(searchStr);
    int replaceLen = strlen(replaceStr);
    
    for (int i = 0; i < contentLen; ) {
        if (strncmp(&content[i], searchStr, searchLen) == 0) {
            strcat(result, replaceStr);
            i += searchLen;
        } else {
            strncat(result, &content[i], 1);
            i++;
        }
    }
    
    // Write back to file
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Error: Cannot write to file " << filename << endl;
        return 1;
    }
    
    outFile << result;
    outFile.close();
    
    cout << "Replacement completed successfully." << endl;
    return 0;
}