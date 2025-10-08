#include <iostream>
#include <cmath>
using namespace std;

void drawCircle(int radius) {
    const double thickness = 0.4;
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            double distance = sqrt(x * x + y * y);
            if (distance > radius - thickness && distance < radius + thickness)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int r;
    cout << "Inserisci il raggio del cerchio: ";
    cin >> r;
    drawCircle(r);
    return 0;
}