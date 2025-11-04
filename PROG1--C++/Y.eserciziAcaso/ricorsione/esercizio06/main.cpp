#include <iostream>
using namespace std;

int mcd(int a, int b);

int main(){

    int a, b; 
    cout << "inserisci la base: ";
    cin >> a;
    cout << "inserisci il secondo numero: ";
    cin >> b;
    int m = mcd(a, b);
    cout << m <<endl;
    return 0;
}


int mcd(int a, int b){

    if(b == 0)
        return a;

    return mcd(b , a%b);
    

}