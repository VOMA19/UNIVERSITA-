#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Lista {
    double data;
    struct Lista *next;
};

double varianza(double *data, int size) {
    double sumSQ = 0;
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sumSQ += (data[i] * data[i]);
        sum += data[i];
    }
    double mean = sum / size;
    return (sumSQ - size * (mean * mean)) / size;
}

double deviazioneStandard(double *data, int size) {
    return sqrt(varianza(data, size));
}

// Inserire qui sotto la dichiarazione della funzione calcola

void calcola(struct Lista *head, double &result, double *&data, int & size);

// Inserire qui sopra la dichiarazione della funzione calcola

int main (int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    struct Lista *head = nullptr;

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        return -1;
    }

    double result;
    double *data;
    int size = 0;
    
    {
        double value;
        while (inputFile >> value) {
            struct Lista *newNode = new struct Lista;
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
    }

    inputFile.close();

    calcola(head, result, data, size);

    cout << "Result: " << result << endl;
    if (size > 0) {
        cout << "Variance: " << varianza(data, size) << endl;
        delete[] data;
    } else {
        cout << "No data to calculate variance." << endl;
    }

    while (head) {
        struct Lista *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}

// Inserire qui sotto la definizione della funzione calcola


void calcola(struct Lista *head, double &result, 
             double *&data, int & size, double sum)
{
   if (nullptr == head) {
       if (size == 0)
       {
           result = -1;
           data = nullptr;
       }
       else
       {
           // cout << "Size: " << size << endl;
           data = new double[size];
           sum = sum / size; // media
           result = (result - size * sum * sum) / size; // varianza
       }
   } else {
     int oldSize = size;
     sum += head->data;
     result += head->data * head->data;
     size++;
     calcola(head->next, result, data, size, sum);
     data[oldSize] = head->data;
   }
}

void calcola(struct Lista *head, double &result, double *&data, int &size)
{
    result = 0.0;
    calcola(head, result, data, size, 0.0);
}

// Inserire qui sopra la definizione della funzione calcola