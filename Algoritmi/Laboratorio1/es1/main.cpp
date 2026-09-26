#include <iostream>
#include <fstream>
using namespace std;
/*
    Dati due interi, sommateli.
    INPUT.TXT
        Due interi N, M separati da spazio
    OUTPUT.TXT
        Un intero, uguale alla somma di N e M.

*/
int main(){

    int a,b;

    ifstream in("input.txt");

    in >> a >> b;

    ofstream out("output.txt");

    out << a+b;
    return 0;
}