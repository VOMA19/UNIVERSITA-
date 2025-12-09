#include <iostream>
#include <fstream>
using namespace std;

struct Studente {
    int matricola;
    char nome[30];
    char cognome[30];
    int voto;      // 0–30
};

Studente* readStudentsFromFile(const char* filename, int& n);
void writeStudentsToFile(const char* filename, Studente* arr, int n);
void printStudents(Studente* arr, int n);
Studente* allocStudenti(int size);

double mediaVoti(Studente* arr, int n);
int votoMassimo(Studente* arr, int n);
int votoMinimo(Studente* arr, int n);
int countPromossiRecursive(Studente* arr, int n); // voto >= 18
bool cercaMatricolaRecursive(Studente* arr, int n, int matricola);

void sortByVoto(Studente* arr, int n);         // bubble sort crescente per voto
void sortByCognome(Studente* arr, int n);      // bubble sort lessicografico
bool aggiornaVoto(Studente* arr, int n, int matricola, int nuovoVoto);

int main(){

    int numStud = 0;
    cout << "quanti studenti vuoi allocare? ";
    cin >> numStud;
    Studente* personePtr = allocStudenti(numStud);
    personePtr = readStudentsFromFile("studenti.txt", numStud);
    writeStudentsToFile("output.txt", personePtr, numStud);
    printStudents(personePtr, numStud);
    double media = mediaVoti(personePtr, numStud);
    int votoMax = votoMassimo(personePtr, numStud);
    int votoMin = votoMinimo(personePtr, numStud);
    int numPromosso = countPromossiRecursive(personePtr, numStud);
    int matricola;
    cout << "inserisci la matricola da cercare: ";
    cin >> matricola;
    bool trovMat = cercaMatricolaRecursive(personePtr, numStud, matricola);

    cout << "Media voti: " << media << endl;
    cout << "Voto massimo: " << votoMax << endl;
    cout << "Voto minimo: " << votoMin << endl;
    cout << "Numero promossi: " << numPromosso << endl;
    if (trovMat) {
        cout << "Matricola " << matricola << " trovata" << endl;
    } else {
        cout << "Matricola " << matricola << " non trovata" << endl;
    }

    // Test sorting functions
    cout << "\n--- Ordinamento per voto (crescente) ---" << endl;
    sortByVoto(personePtr, numStud);
    printStudents(personePtr, numStud);

    cout << "\n--- Ordinamento per cognome (lessicografico) ---" << endl;
    sortByCognome(personePtr, numStud);
    printStudents(personePtr, numStud);

    // Test aggiorna voto function
    cout << "\n--- Test aggiornamento voto ---" << endl;
    int matricolaDaCambiare, nuovoVoto;
    cout << "Inserisci matricola per aggiornare il voto: ";
    cin >> matricolaDaCambiare;
    cout << "Inserisci nuovo voto: ";
    cin >> nuovoVoto;

    if (aggiornaVoto(personePtr, numStud, matricolaDaCambiare, nuovoVoto)) {
        cout << "Voto aggiornato con successo!" << endl;
        printStudents(personePtr, numStud);
    } else {
        cout << "Aggiornamento fallito!" << endl;
    }

    delete[] personePtr;
    return 0;
}


Studente* allocStudenti(int size) {
    if (size <= 0) return nullptr;
    return new Studente[size];
}

Studente* readStudentsFromFile(const char* filename, int& n) {
    ifstream file(filename);
    if (!file.is_open()) {
        n = 0;
        return nullptr;
    }

    n = 0;
    Studente temp;
    while (file >> temp.matricola >> temp.nome >> temp.cognome >> temp.voto)
        n++;

    if (n == 0) {
        file.close();
        return nullptr;
    }

    file.clear();
    file.seekg(0, ios::beg);

    Studente* studenti = new Studente[n];
    int i = 0;
    while (i < n && (file >> studenti[i].matricola >> studenti[i].nome >> studenti[i].cognome >> studenti[i].voto)) {
        i++;
    }

    file.close();
    return studenti;
}

void writeStudentsToFile(const char* filename, Studente* arr, int n){
    ofstream file(filename);
    if (!file.is_open()) return;

    for (int i = 0; i < n; i++){
        file << arr[i].matricola << " " 
            << arr[i].nome << " "
            << arr[i].cognome   << " "
            << arr[i].voto << "\n";
    }
    file.close();
}

void printStudents(Studente* arr, int n){
    for (int i = 0; i < n; i++){
        cout << "Matricola numero: " << i+1 <<endl;
        cout << "nome: " << arr[i].nome << endl;
        cout << "cognome: " << arr[i].cognome << endl;
        cout << "matricola: " << arr[i].matricola << endl;
        cout << "voto: " << arr[i].voto <<endl;
    }
}

double mediaVoti(Studente* arr, int n){
    double media = 0;
    for(int i = 0; i < n; i++){
        media += arr[i].voto;
    }
    
    return media /= (double)n;

}

int votoMassimo(Studente* arr, int n){
    int votoMassimo = arr[0].voto;
    for (int i = 1; i < n; i++)
        if(votoMassimo < arr[i].voto) votoMassimo = arr[i].voto;

    return votoMassimo;
}

int votoMinimo(Studente* arr, int n){
    int votoMinimo = arr[0].voto;
    for (int i = 1; i < n; i++)
        if(votoMinimo > arr[i].voto) votoMinimo = arr[i].voto;

    return votoMinimo;
}

int countPromossiRecursive(Studente* arr, int n){
    if(n == 0)return 0;
    if(arr[n].voto >= 18)
        return 1 + countPromossiRecursive(arr, n-1);
    else
        return countPromossiRecursive(arr, n-1);
}

bool cercaMatricolaRecursive(Studente* arr, int n, int matricola){
    if(n == 0) return false;
    if(arr[n-1].matricola == matricola) return true;
    return cercaMatricolaRecursive(arr, n-1, matricola);
}

void sortByVoto(Studente* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].voto > arr[j + 1].voto) {
                Studente temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortByCognome(Studente* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j].cognome, arr[j + 1].cognome) > 0) {
                Studente temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool aggiornaVoto(Studente* arr, int n, int matricola, int nuovoVoto){

    if(cercaMatricolaRecursive(arr,n,matricola)){
        arr[n].voto = nuovoVoto;
        return true;
    }else{
        cout <<"matricola non trovata!" <<endl;
        return false;
    }
}
