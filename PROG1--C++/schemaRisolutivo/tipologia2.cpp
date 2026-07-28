#include <iostream>
#include <cmath> // Necessario se ti capita la Versione 2 (Deviazione Standard)

using namespace std;

// --- 1. FUNZIONE AUSILIARIA RICORSIVA ---
// Passiamo le somme per riferimento in modo da accumularle durante la risalita
void leggiEAlloca(istream& in, double*& arr, int& dim, int profondita, double& somma, double& somma_quadrati) {
    double valore;
    
    // FASE DI DISCESA: cerco di leggere un numero dal file
    if (in >> valore) {
        // Se la lettura ha successo, vado più a fondo aumentando l'indice (profondita)
        leggiEAlloca(in, arr, dim, profondita + 1, somma, somma_quadrati);
        
        // FASE DI RISALITA: L'array ora esiste, lo popolo a ritroso
        arr[profondita] = valore;
        
        // Accumulo la somma e la somma dei quadrati per la formula statistica
        somma += valore;
        somma_quadrati += (valore * valore);
    } 
    else {
        // FASE 2: CASO BASE (Fine del file o stream vuoto)
        // La profondità raggiunta è esattamente la dimensione totale!
        dim = profondita;
        
        if (dim > 0) {
            // ALLOCAZIONE DINAMICA CON LA DIMENSIONE ESATTA [5]
            arr = new double[dim];
        } else {
            arr = nullptr; 
        }
        
        // Inizializzo le somme a zero per far partire i calcoli in risalita
        somma = 0.0;
        somma_quadrati = 0.0;
    }
}

// --- 2. FUNZIONE PRINCIPALE RICHIESTA DAL TESTO ---
void calcola(istream& in, double& varianza, double*& arr, int& dim) {
    // Variabili per i calcoli statistici intermedi
    double somma = 0.0;
    double somma_quadrati = 0.0;
    
    // Avvio la ricorsione a partire dalla profondità 0
    leggiEAlloca(in, arr, dim, 0, somma, somma_quadrati);
    
    // Controllo speciale richiesto dal testo: se il file è vuoto [5]
    if (dim == 0) {
        varianza = -1.0;
    } else {
        // Calcolo secondo la formula specificata nel testo d'esame: 
        // Varianza = (Somma dei quadrati / N) - (Media al quadrato) [6]
        double media = somma / dim;
        double media_dei_quadrati = somma_quadrati / dim;
        
        varianza = media_dei_quadrati - (media * media);
        
        // ATTENZIONE: Se ti capita la VERSIONE 2 (Deviazione Standard) [2], 
        // il calcolo finale sarà invece la radice quadrata della varianza:
        // varianza = sqrt(media_dei_quadrati - (media * media)); [7]
    }
}