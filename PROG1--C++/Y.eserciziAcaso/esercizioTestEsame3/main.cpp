#include <iostream>
#include <fstream>
using namespace std;

struct Prodotto {
    int codice;
    char nome[30];
    double prezzo;
    int quantita;
};

Prodotto* readProductsFromFile(const char* filename, int& count);
void writeProductsToFile(const char* filename, Prodotto* arr, int count);
void printProducts(Prodotto* arr, int n);
double totalValue(Prodotto* arr, int n);
void sortByPrice(Prodotto* arr, int n);
bool updateQuantity(Prodotto* arr, int n, int codice, int nuovaQta);
Prodotto* addProductDynamic(Prodotto* arr, int& count, int newSize);
void freeProducts(Prodotto* arr);

int main() {
    int n = 0;
    Prodotto* prodotti = readProductsFromFile("magazzino.txt", n);
    if (!prodotti || n == 0) {
        cout << "Errore: nessun prodotto letto." << endl;
        return 1;
    }

    cout << "=== PRODOTTI LETTI DAL FILE ===" << endl;
    printProducts(prodotti, n);

    cout << "\n=== VALORE TOTALE MAGAZZINO ===" << endl;
    cout << "Valore totale: " << totalValue(prodotti, n) << " euro" << endl;

    cout << "\n=== AGGIORNAMENTO QUANTITA' (codice 123 -> 50) ===" << endl;
    if (updateQuantity(prodotti, n, 123, 50))
        cout << "Quantita' aggiornata con successo!" << endl;
    else
        cout << "Prodotto con codice 123 non trovato!" << endl;

    cout << "\n=== AGGIUNTA NUOVO PRODOTTO ===" << endl;
    int oldCount = n;
    prodotti = addProductDynamic(prodotti, n, n + 1); // +1 prodotto
    // inizializzo l’ultimo elemento (indice n-1)
    prodotti[n-1].codice   = 999;
    // ATTENZIONE: nome senza spazi
    // in un esame spesso basta così
    // se vuoi leggere da input user, usa cin >>
    // qui lo metto fisso
    // (se il compilatore si lamenta, togli il const)
    char nomeNuovo[] = "NuovoProd";
    for (int i = 0; i < 30; ++i) prodotti[n-1].nome[i] = '\0';
    for (int i = 0; nomeNuovo[i] != '\0' && i < 29; ++i)
        prodotti[n-1].nome[i] = nomeNuovo[i];
    prodotti[n-1].prezzo   = 25.99;
    prodotti[n-1].quantita = 10;

    cout << "Prodotti prima di ordinare:" << endl;
    printProducts(prodotti, n);

    cout << "\n=== ORDINAMENTO PER PREZZO ===" << endl;
    sortByPrice(prodotti, n);
    printProducts(prodotti, n);

    cout << "\n=== SCRITTURA SU FILE magazzino_aggiornato.txt ===" << endl;
    writeProductsToFile("magazzino_aggiornato.txt", prodotti, n);

    freeProducts(prodotti);
    return 0;
}

// Conta quanti prodotti ci sono, poi li legge in un array dinamico
Prodotto* readProductsFromFile(const char* filename, int& count){
    ifstream file(filename);
    if (!file.is_open()) {
        count = 0;
        return nullptr;
    }

    count = 0;
    Prodotto temp;
    while (file >> temp.codice >> temp.nome >> temp.prezzo >> temp.quantita)
        count++;

    if (count == 0) {
        file.close();
        return nullptr;
    }

    file.clear();
    file.seekg(0, ios::beg);

    Prodotto* prodotti = new Prodotto[count];
    int i = 0;
    while (i < count &&
           (file >> prodotti[i].codice >> prodotti[i].nome
                 >> prodotti[i].prezzo >> prodotti[i].quantita)) {
        i++;
    }

    file.close();
    return prodotti;
}

void writeProductsToFile(const char* filename, Prodotto* arr, int count){
    ofstream file(filename);
    if (!file.is_open()) return;

    for (int i = 0; i < count; i++) {
        file << arr[i].codice << " "
            << arr[i].nome   << " "
            << arr[i].prezzo << " "
            << arr[i].quantita << "\n";
    }
    file.close();
}

void printProducts(Prodotto* arr, int n) {
    if (!arr) return;
    for (int i = 0; i < n; i++) {
        cout << "Codice: " << arr[i].codice
            << ", Nome: " << arr[i].nome
            << ", Prezzo: " << arr[i].prezzo
            << ", Quantita: " << arr[i].quantita << endl;
    }
}

double totalValue(Prodotto* arr, int n) {
    if (!arr) return 0.0;
    double total = 0.0;
    for (int i = 0; i < n; i++)
        total += arr[i].prezzo * arr[i].quantita;
    return total;
}

void sortByPrice(Prodotto* arr, int n) {
    if (!arr || n <= 1) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].prezzo > arr[j + 1].prezzo) {
                Prodotto temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool updateQuantity(Prodotto* arr, int n, int codice, int nuovaQta) {
    if (!arr) return false;
    for (int i = 0; i < n; i++) {
        if (arr[i].codice == codice) {
            arr[i].quantita = nuovaQta;
            return true;
        }
    }
    return false;
}

// rialloca l’array con dimensione newSize, copia i primi count elementi,
// aggiorna count
Prodotto* addProductDynamic(Prodotto* arr, int& count, int newSize) {
    if (newSize <= count) return arr;
    Prodotto* newArr = new Prodotto[newSize];
    for (int i = 0; i < count; i++)
        newArr[i] = arr[i];
    delete[] arr;
    count = newSize;
    return newArr;
}

void freeProducts(Prodotto* arr) {
    delete[] arr;
}
