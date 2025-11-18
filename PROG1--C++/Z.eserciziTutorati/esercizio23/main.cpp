#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 4) {
        cout << "Usage: " << argv[0] << " <input_file1> <input_file2> <output_file>" << endl;
        return 1;
    }
    
    ifstream file1(argv[1]);
    ifstream file2(argv[2]);
    ofstream output(argv[3]);
    
    if(!file1 || !file2 || !output) {
        cout << "Error opening files" << endl;
        return 1;
    }
    
    char c1, c2;
    while(file1.get(c1) && file2.get(c2)) {
        output << c1 << c2;
    }
    
    file1.close();
    file2.close();
    output.close();
    
    return 0;
}