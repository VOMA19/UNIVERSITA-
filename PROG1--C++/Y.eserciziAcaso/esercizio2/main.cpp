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
void drawHeart(int size) {
    for (int y = size / 2; y <= size; y += 2) {
        for (int x = 1; x < size - y; x += 2)
            cout << " ";
        for (int x = 1; x <= y; x++)
            cout << "*";
        for (int x = 1; x <= size - y; x++)
            cout << " ";
        for (int x = 1; x <= y; x++)
            cout << "*";
        cout << endl;
    }
    for (int y = size; y >= 1; y--) {
        for (int x = 0; x < size - y; x++)
            cout << " ";
        for (int x = 1; x <= y * 2 - 1; x++)
            cout << "*";
        cout << endl;
    }
}
int main() {
    int r;
    int size;
    cout << "Inserisci il raggio del cerchio: ";
    cin >> r;
    cout << "inserisci grandezza cuore: ";
    cin >> size;
    drawCircle(r);
    cout << endl;
    drawHeart(size);
    return 0;
}