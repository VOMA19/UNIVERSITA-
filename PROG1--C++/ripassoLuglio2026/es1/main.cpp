#include <iostream>
using namespace std;
int calcolaSomma(int n);
int compute_sum(int n);
int main(){

    int n = 99019;
    int somma = compute_sum(n);

    cout << "somma: " << somma << endl;


    return 0;
}

int compute_sum(int n){

    if(n == 0) return 0;
    
    int somma = calcolaSomma(n);

    if(somma < 10) return somma;
    else if (somma > 10 && somma % 2 == 0 ) return compute_sum(somma+10);
    else return compute_sum(somma+1);

}

int calcolaSomma(int n){
    
    if(n == 0) return 0;

    int somma = n%10 + calcolaSomma(n/10);

    return somma;
}