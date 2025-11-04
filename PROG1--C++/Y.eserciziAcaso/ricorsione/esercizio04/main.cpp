#include <iostream>
using namespace std;

int fibonacci(int a);

int main(){

    int a, b; 
    cout << "inserisci la base: ";
    cin >> a;
    int fib = fibonacci(a);
    cout << fib << endl;
    return 0;
}

// fibbonacci(6) --> 8 --> 0 1 1 2 3 5 8 13 

int fibonacci(int a){

    if(a == 0)
        return 0;
    if(a == 1)
        return 1;
    
    return fibonacci(a-1) + fibonacci(a-2);
}