#include <iostream>
#include <fstream>
// Aggiungi <cmath> se il testo richiede potenze (pow) o radici (sqrt)

using namespace std;

// =================================================================
// 1. LA FUNZIONE AUSILIARIA (IL MOTORE RICORSIVO)
// =================================================================
void funzioneRicorsivaUniversale(istream& in, double*& array, int& dim, int profondita, double& accumulatore) {
    
    // [STEP 1] Dichiara la variabile (o la struct) per catturare i dati
    double dato_corrente; 
    
    // FASE 1: TENTATIVO DI DISCESA
    if (in >> dato_corrente) {
        
        // [STEP 2] IL FILTRO (C'è una condizione?)
        if (/* INSERISCI QUI L'EVENTUALE CONDIZIONE (es. dato_corrente > 0) */ true) {
            
            // Il dato è VALIDO: Scendo e AUMENTO la profondità
            funzioneRicorsivaUniversale(in, array, dim, profondita + 1, accumulatore);
            
            // FASE 3: RISALITA PER I DATI VALIDI
            // L'array ora esiste! (Allocato nel caso base)
            
            // [STEP 3] MAPPATURA INDICE
            // Se ordine normale: indice = profondita
            // Se ordine inverso: indice = dim - 1 - profondita
            int indice = profondita; 
            
            array[indice] = dato_corrente;
            
            // [STEP 4] AGGIORNAMENTO ACCUMULATORE
            accumulatore += dato_corrente; // Oppure *=, ecc.
            
        } else {
            // Il dato è SCARTATO: Scendo ma NON aumento la profondità
            funzioneRicorsivaUniversale(in, array, dim, profondita, accumulatore);
            // In risalita per i dati scartati non si fa nulla.
        }
        
    } else {
        // FASE 2: CASO BASE (Fine del file)
        // Ora so esattamente quanti elementi hanno passato il filtro!
        dim = profondita;
        
        if (dim > 0) {
            // ALLOCAZIONE DINAMICA PRECISA [6, 7]
            array = new double[dim];
        } else {
            array = nullptr; // Protezione se file vuoto
        }
        
        // INIZIALIZZAZIONE ACCUMULATORE
        // (0 per le somme, 1 se fosse un prodotto)
        accumulatore = 0.0; 
    }
}

// =================================================================
// 2. LA FUNZIONE WRAPPER (Quella richiesta dal testo d'esame)
// =================================================================
void calcola(istream& in, double& risultato_finale, double*& array, int& dim) {
    
    double accumulatore = 0.0;
    
    // Faccio partire il motore passando 0 come profondità di partenza
    funzioneRicorsivaUniversale(in, array, dim, 0, accumulatore);
    
    // ELABORAZIONE FINALE
    if (dim == 0) {
        risultato_finale = -1.0; // O qualsiasi codice d'errore richiesto
    } else {
        // Usa l'accumulatore calcolato in risalita per trovare la formula richiesta
        risultato_finale = accumulatore / dim; // Esempio: Media
    }
}