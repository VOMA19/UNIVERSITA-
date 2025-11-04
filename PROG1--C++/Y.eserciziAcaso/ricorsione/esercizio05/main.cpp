#include <iostream>
using namespace std;

bool isPalindromo(string s);

int main(){

    string str; 
    cout << "inserisci la base: ";
    cin >> str;
    bool isP = isPalindromo(str);

    if(isP)cout << "è palindroma"<<endl;
    else cout << "non è palindroma" <<endl;
    return 0;
}


bool isPalindromo(string s){

    if(s.length() <= 1) return true;
    if(s[0] != s[s.length()-1]) return false;
    return isPalindromo(s.substr(1, s.length()-2));

}