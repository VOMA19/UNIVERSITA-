#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    if (!(in >> N) || N < 0) return 1;

    int corrente = 0;
    int massimo = 0;  

    for (int i = 0; i < N; i++) {
        int valore;
        if (!(in >> valore)) return 1;

        corrente = max(0, corrente + valore);
        cout<< "corrente: " << corrente <<endl;
        massimo = max(massimo, corrente);
        cout <<"massimo: "<< massimo <<endl;
    }

    out << massimo << endl;
}