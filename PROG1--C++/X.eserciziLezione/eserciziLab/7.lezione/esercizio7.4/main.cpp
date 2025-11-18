#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int* arr, int n);
int* append(int* pa, int na, int* pb, int nb);

int main() {
    int nx, ny;
    
    // Seed the random number generator
    srand(time(NULL));
    
    cout << "Inserire la dimensione del primo array: ";
    cin >> nx;
    cout << "Inserire la dimensione del secondo array: ";
    cin >> ny;
    
    // Allocate arrays
    int* arrayX = new int[nx];
    int* arrayY = new int[ny];
    
    // Fill first array with random values
    cout << "Primo array con valori casuali: ";
    for (int i = 0; i < nx; i++) {
        arrayX[i] = rand() % 100 + 1;
        cout << arrayX[i] << " ";
    }
    cout << endl;
    
    // Fill second array with random values
    cout << "Secondo array con valori casuali: ";
    for (int i = 0; i < ny; i++) {
        arrayY[i] = rand() % 100 + 1;
        cout << arrayY[i] << " ";
    }
    cout << endl;
    
    // Sort arrays using bubble sort
    bubbleSort(arrayX, nx);
    bubbleSort(arrayY, ny);
    
    // Concatenate arrays
    int* result = append(arrayX, nx, arrayY, ny);
    
    // Print result
    cout << "Array concatenato ordinato: ";
    for (int i = 0; i < nx + ny; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    // Deallocate memory
    delete[] arrayX;
    delete[] arrayY;
    delete[] result;
    
    return 0;
}

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int* append(int* pa, int na, int* pb, int nb) {
    int* result = new int[na + nb];
    int i = 0, j = 0, k = 0;
    
    // Merge the two sorted arrays
    while (i < na && j < nb) {
        if (pa[i] <= pb[j]) {
            result[k++] = pa[i++];
        } else {
            result[k++] = pb[j++];
        }
    }
    // Copy remaining elements from pa
    while (i < na) {
        result[k++] = pa[i++];
    }
    // Copy remaining elements from pb
    while (j < nb) {
        result[k++] = pb[j++];
    }
    
    return result;
}