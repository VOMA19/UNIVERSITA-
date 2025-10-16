#include <iostream>
using namespace std;

int main(){

    char tasca1, tasca2;
    cout << "input 1: ";
    cin >> tasca1;

    cout << "input 2: ";
    cin >> tasca2;

    
    tasca1 = tasca1 + tasca2;
    tasca2 = tasca1 - tasca2;
    tasca1 = tasca1 - tasca2;

    cout << tasca1 << " " << tasca2 << endl;

}