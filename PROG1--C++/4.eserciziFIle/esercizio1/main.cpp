#include <iostream>
using namespace std;

#define DIM 500

int main() {
    char word[DIM];
    int i = 0;
    do{
        
        if(cin >> word[i]){
            cout << word[i];
        }
        i++;
    }while(word[i] != '.');

    return 0;
}