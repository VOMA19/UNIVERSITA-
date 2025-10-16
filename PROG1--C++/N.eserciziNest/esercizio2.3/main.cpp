#include <iostream>
using namespace std;

#define N 100

/*
    Scrivete un programma che simuli una banca dati nella quale sia possibile gestire numeri di
    identificazione. Il programma dovrà avere 4 funzioni che permetteranno di:
    • aggiungere un nuovo numero alla banca dati,
    • rimuovere un numero esistente,
    • cercare un numero per verificarne la presenza,
    • stampare tutti i numeri attualmente presenti nella banca dati.
*/

int banca_dati[N] = {'\0'};
void aggiungere(int* banca, int num);
void rimuovere(int* banca, int num);
int cercare(int* banca, int num);
void stampare(int* banca);
void menu();

int main(){
    int scelta;
    int numero;
    
    while(scelta != 5){
        menu();
        cin >> scelta; 
        int cerca;
        switch(scelta){
            case 1:
                cout << "Inserisci numero: ";
                cin >> numero;
                aggiungere(banca_dati, numero);
                break;
            case 2:
                cout << "Inserisci numero: ";
                cin >> numero;
                rimuovere(banca_dati, numero);
                break;
            case 3:
                cout << "Inserisci numero: ";
                cin >> numero;
                cerca = cercare(banca_dati, numero);
                if(cerca != -1){
                    cout << "Numero trovato! \nsi trova in questa posizione: "<< cerca+1 << endl;
                }else{
                    cout << "Numero non trovato!" << endl;
                }
                break;
            case 4:
                stampare(banca_dati);
                break;
            case 5:
                cout << "arrivederci!"<<endl;
                break;
            default:
                cout << "Scelta non valida!" << endl;
        }
    }
    return 0;
}

void menu(){
    cout << "\n--- BANCA DATI ---" << endl;
    cout << "1. Aggiungere numero" << endl;
    cout << "2. Rimuovere numero" << endl;
    cout << "3. Cercare numero" << endl;
    cout << "4. Stampare tutti" << endl;
    cout << "5. Esci" << endl;
    cout << "Scelta: ";
}

//stampare tutti i numeri attualmente presenti nella banca dati.
void stampare(int* banca){
    for(int i = 0; i < N; i++){
        if(banca[i] != '\0'){
            cout << banca[i] << endl;
        }else{
            cout << "banca vuota" <<endl;
        }
    }
}

//cercare un numero per verificarne la presenza
int cercare(int* banca, int num){

    for(int i = 0; i < N; i++){
        if(banca[i] == num){
            return i;
        }
    }
    return -1;
}

//rimuovere un numero esistente
void rimuovere(int* banca, int num){
    bool rimosso = false;
    for(int i = 0; i < N; i++){
        if(banca[i] == num){
            banca[i] = '\0';
            if(rimosso == false)cout << "Numero rimosso!" << endl;
            rimosso = true;
        }
    }

    if(rimosso == false) cout << "Numero non trovato!" << endl;
}

//aggiungere un nuovo numero alla banca dati
void aggiungere(int* banca, int num){
    for(int i = 0; i < N; i++){
        if(banca[i] == '\0'){
            banca[i] = num;
            cout << "Numero aggiunto!" << endl;
            return;
        }
    }
    cout << "Banca dati piena!" << endl;
}