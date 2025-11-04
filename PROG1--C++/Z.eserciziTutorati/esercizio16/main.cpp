#include <iostream>
using namespace std;

/*
Scrivere un programma che prende una
stringa da riga di comando e la inverte,
ricorsivamente.
*/

void reverse(char* str, int i, int len);

int main(){

    char str[100];
    cout << "Inserisci una stringa: ";
    cin >> str;
    int len = 0;
    while (str[len] != '\0') len++;
    
    reverse(str, 0, len);
    cout << endl;

    return 0;
}

void reverse(char str[], int i, int len) {
    if (i < len) {
        reverse(str, i + 1, len);
        cout << str[i];
    }
}