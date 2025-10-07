#include <iostream>
using namespace std;

/*
    Scrivere un programma che, data una temperatura in input dall’utente, riporti a video un messaggio
    seguendo le regole sotto elencate:
    message(T) =
    T <−273.15 Temperatura impossibile!
    −273.15 ≥T ≥0.0 Fa freddo!
    0.0 >T ≥18.0 Temperatura cos`
    `
    ı cos
    ı
    18.0 >T ≥30.0 Temperatura accettabile
    T >30.0 Fa caldo!
*/

int main(){

    float T;
    cout << "Inserisci la temperatura in gradi Celsius: ";
    cin >> T;
    if(T < -273.15){
        cout << "Temperatura impossibile!" << endl;
    } else if(T >= -273.15 && T < 0.0){
        cout << "Fa freddo!" << endl;
    } else if(T >= 0.0 && T < 18.0){
        cout << "Temperatura cosi' cosi'" << endl;
    } else if(T >= 18.0 && T <= 30.0){
        cout << "Temperatura accettabile" << endl;
    } else {
        cout << "Fa caldo!" << endl;
    }


    return 0;
}