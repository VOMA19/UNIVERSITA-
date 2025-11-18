#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

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
    
    double numbers[100];
    int count = 0;
    char line[1000];
    
    if(file.getline(line, 1000)) {
        char* token = strtok(line, ",");
        
        while(token != nullptr) {
            numbers[count++] = atof(token);
            token = strtok(nullptr, ",");
        }
    }
    
    file.close();
    
    double sum = 0;
    for(int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    
    double average = sum / count;
    
    cout << "Somma: " << sum << endl;
    cout << "Media: " << average << endl;
    
    return 0;
}
