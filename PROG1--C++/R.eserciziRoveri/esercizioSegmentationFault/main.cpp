#include <iostream>
using namespace std;

void recursiveFunction(int counter) {
    cout << "Depth: " << counter << endl;
    cout.flush();
    recursiveFunction(counter + 1);
}

int main() {
    cout << "Starting recursive function to cause stack overflow..." << endl;
    recursiveFunction(1);
    return 0;
}