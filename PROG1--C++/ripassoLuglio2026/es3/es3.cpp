#include <iostream>
using namespace std;

const double G = 9.81;

// Ricordati sempre di dichiarare i prototipi prima!
int contaPiatti(Stack& pila);
double calcola(Stack& pila);

int main(){
    // Qui andrebbe il codice di test
    return 0;
}

double calcola(Stack& pila){
    // CASO BASE
    if(vuota(pila))
        return 0.0;

    // 1. ESTRAZIONE CORRETTA
    int peso = top(pila);
    pop(pila);

    // 2. CALCOLO ALTEZZA (L'intuizione che hai avuto!)
    // Nota magica: se tolgo il piatto corrente, il numero di piatti 
    // RIMASTI nella pila è esattamente la sua posizione in altezza!
    int elementiSotto = contaPiatti(pila);
    double h = elementiSotto * 1.5;

    // 3. CALCOLO ENERGIA DEL DISCO CORRENTE
    double energia_disco = peso * G * h;

    // 4. PASSO RICORSIVO
    double energia_resto = calcola(pila);

    // 5. RIPRISTINO DELLO STACK (Rimetto il PESO, non l'energia!)
    push(pila, peso);

    // 6. RITORNO IL TOTALE
    return energia_disco + energia_resto;
} 

int contaPiatti(Stack& pila){
    // CASO BASE
    if(vuota(pila)){
        return 0;
    }

    // ESTRAZIONE CORRETTA
    int peso = top(pila);
    pop(pila);
    
    // PASSO RICORSIVO
    int restoPila = contaPiatti(pila);
    
    // RIPRISTINO
    push(pila, peso);

    // CONTO IL PIATTO (1) + GLI ALTRI, non sommo il peso!
    return 1 + restoPila;
}