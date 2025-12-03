#include <iostream>
using namespace std;

struct Persona{
    char nome[50];
    int eta;
};

Persona* allocPersonas(int size);
void inputPersonas(Persona* arr, int n);
void printPersonas(Persona* arr, int n);
void menu();
Persona* findOldest(Persona* arr, int n);
int sumAgesRecursive(Persona* arr, int n);
void sortByAge(Persona* arr, int n);
void freePersonas(Persona* arr);

int main(){
    int sc, n = 1;
    do{
        if(n <= 0) cout << "valore non valido" << endl;
        cout << "inserisci il numero di persone: "; 
        cin >> n;
    }while(n <= 0);       
    
    Persona* persone = allocPersonas(n);
    if(!persone) return 1;

    do{
        menu();
        cout << "scegli: ";
        cin >> sc;
        switch(sc){
            case 1: 
                for(int i = 0; i < n; i++) inputPersonas(persone, i);
                break;
            case 2: printPersonas(persone, n); break;
            case 3:{
                Persona* pMax = findOldest(persone, n);
                if(pMax) cout << "Più vecchia: " << pMax->nome << " (" << pMax->eta << " anni)\n";
                break;
            }
            case 4:{
                int somma = sumAgesRecursive(persone, n);
                cout << "Somma età: " << somma << endl;
                break;
            }
            case 5: sortByAge(persone, n); break;
            case 0: freePersonas(persone); break;
            default: cout << "Opzione non valida\n";
        }
    }while(sc != 0);
    return 0;
}

Persona* allocPersonas(int size) {
    if(size <= 0) return nullptr;
    return new Persona[size];
}

void inputPersonas(Persona* arr, int n){
    cout << "Persona " << n+1 << " - Nome: ";
    cin >> arr[n].nome;
    int eta;
    do{
        cout << "Età: ";
        cin >> eta;
        if(eta < 0) cout << "Età non valida\n";
    }while(eta < 0);
    arr[n].eta = eta;
}

void printPersonas(Persona* arr, int n){
    for(int i = 0; i < n; i++){
        cout << i+1 << ". " << arr[i].nome << " (" << arr[i].eta << " anni)\n";
    }
}

void menu(){
    cout << "1-inserisci 2-visualizza 3-più vecchia 4-somma età 5-ordina 0-exit\n";
}

Persona* findOldest(Persona* arr, int n){
    if(n <= 0) return nullptr;
    Persona* pMax = &arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i].eta > pMax->eta) pMax = &arr[i];
    }
    return pMax;
}

int sumAgesRecursive(Persona* arr, int n){
    if(n <= 0) return 0;
    return arr[n-1].eta + sumAgesRecursive(arr, n-1);
}

void sortByAge(Persona* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j].eta > arr[j+1].eta){
                Persona temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "Ordinato per età:\n";
    printPersonas(arr, n);
}

void freePersonas(Persona* arr) {
    delete[] arr;
}
