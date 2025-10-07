#include <iostream>
using namespace std;

int main() {
    double miglia, chilometri;
    cout << "Inserisci la distanza in miglia: ";
    cin >> miglia;
    chilometri = miglia * 1.60934;
    cout << "La distanza in chilometri è: " << chilometri << endl;
    return 0;
}