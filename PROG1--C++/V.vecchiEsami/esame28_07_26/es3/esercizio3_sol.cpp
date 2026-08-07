#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

struct Tree
{
    double data;
    struct Tree *left;
    struct Tree *right;
};

void insert(struct Tree *&root, double value)
{
    if (root == nullptr)
    {
        root = new struct Tree;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (value < root->data)
    {
        insert(root->left, value);
    }
    else
    {
        insert(root->right, value);
    }
}

void deleteTree(struct Tree *&root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

void populateData(struct Tree *root, double *data, int size, int &index)
{
    if (root != nullptr)
    {
        populateData(root->left, data, size, index);
        if (index < size)
        {
            data[index++] = root->data;
        }
        else
        {
            cerr << "Error: Index out of bounds while populating data." << endl;
            exit(EXIT_FAILURE);
        }
        populateData(root->right, data, size, index);
    }
}
double varianza(double *data, int size)
{
    double sumSQ = 0;
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sumSQ += (data[i] * data[i]);
        sum += data[i];
    }
    double mean = sum / size;
    return (sumSQ - size * (mean * mean)) / size;
}

double deviazioneStandard(double *data, int size)
{
    return sqrt(varianza(data, size));
}

// Inserire qui sotto la dichiarazione della funzione calcola

double calcola(struct Tree *root);

// Inserire qui sopra la dichiarazione della funzione calcola

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    struct Tree *root = nullptr;

    ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        cerr << "Error opening file: " << argv[1] << endl;
        return -1;
    }

    double *data;
    int size = 0;

    {
        double value;
        while (inputFile >> value)
        {
            insert(root, value);
            size++;
        }
        if (size != 0)
        {
            data = new double[size];
            int index = 0;
            populateData(root, data, size, index);
            assert(index == size); // Ensure we filled the array correctly
        }
        else
        {
            data = nullptr;
        }
    }

    inputFile.close();

    double result = calcola(root);

    cout << "Result: " << result << endl;
    if (size > 0)
    {
        cout << "Standard Deviation: " << deviazioneStandard(data, size) << endl;
        delete[] data;
    }
    else
    {
        cout << "No data to calculate standard deviation." << endl;
    }

    deleteTree(root);

    return 0;
}

// Inserire qui sotto la definizione della funzione calcola

void calcola(struct Tree *root, double &result,
             int &size, double &sum)
{
    if (nullptr == root)
    {
        return;
    }
    else
    {
        sum += root->data;
        result += root->data * root->data;
        size++;
        calcola(root->left, result, size, sum);
        calcola(root->right, result, size, sum);
    }
}

double calcola(struct Tree *root)
{
    double result = 0.0;
    int size = 0;
    double sum = 0.0;
    calcola(root, result, size, sum);
    if (size > 0)
    {
        double mean = sum / size;
        result = sqrt((result - size * mean * mean) / size);
    }
    else
    {
        result = -1.0; // Handle case with no elements
    }
    return result;
}

// Inserire qui sopra la definizione della funzione calcola