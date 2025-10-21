#include <iostream>
#include <chrono>
using namespace std;

bool isPrime(int num);

int main() {
    auto start_time = chrono::high_resolution_clock::now();
    
    int start, end;
    
    cout << "Inserisci l'inizio dell'intervallo: ";
    cin >> start;
    cout << "Inserisci la fine dell'intervallo: ";
    cin >> end;
    
    cout << "\nNumeri primi tra " << start << " e " << end << ":\n";
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "\nTempo di esecuzione: " << duration.count() << " ms" << endl;
    
    return 0;
}

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}