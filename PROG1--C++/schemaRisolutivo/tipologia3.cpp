// Struttura dell'Albero (Il singolo dipendente)
struct Impiegato {
    int id;
    double salario;
    double budget;
    ListaDipendenti* figli; // Puntatore alla lista dei suoi sottoposti
};

// Struttura della Lista Concatenata
struct ListaDipendenti {
    Impiegato* info;        // Puntatore al dipendente
    ListaDipendenti* next;  // Puntatore al prossimo fratello nella lista
};

#include <iostream>
// (I file .h del prof sono già inclusi dal testo di partenza)

using namespace std;

// --- PROTOTIPI DELLE FUNZIONI AUSILIARIE ---
// Dichiariamo i prototipi in alto, altrimenti il compilatore si lamenta 
// visto che le due funzioni si chiameranno a vicenda!
double calcolaSingolo(Impiegato* nodoAlbero);
double calcolaLista(ListaDipendenti* nodoLista);

// =================================================================
// 1. FUNZIONE AUSILIARIA PER LA LISTA (Muoversi in orizzontale)
// =================================================================
double calcolaLista(ListaDipendenti* nodoLista) {
    // CASO BASE LISTA: Se non ci sono più fratelli
    if (nodoLista == nullptr) {
        return 0.0;
    }
    
    // PASSO RICORSIVO: 
    // Costo di QUESTO impiegato (Funzione Albero) + Costo dei PROSSIMI fratelli (Funzione Lista)
    return calcolaSingolo(nodoLista->info) + calcolaLista(nodoLista->next);
}

// =================================================================
// 2. FUNZIONE AUSILIARIA PER L'ALBERO (Muoversi in verticale)
// =================================================================
double calcolaSingolo(Impiegato* nodoAlbero) {
    // CASO BASE ALBERO: Se il nodo è vuoto
    if (nodoAlbero == nullptr) {
        return 0.0;
    }
    
    // Calcolo il dato richiesto dal testo per questo specifico nodo
    // (Nel caso dell'esame di Settembre 2025: salario + budget)
    double costo_proprio = nodoAlbero->salario + nodoAlbero->budget;
    
    // Aggiungo il costo di tutti i suoi figli chiamando la funzione per la Lista!
    return costo_proprio + calcolaLista(nodoAlbero->figli);
}

// =================================================================
// 3. LA FUNZIONE WRAPPER (Quella richiesta dal testo d'esame)
// =================================================================
// Il testo dell'esame chiede tipicamente di far partire il tutto passandogli 
// la lista dei "capi" o il nodo Radice.
double calcola(ListaDipendenti* dipendenti_azienda) {
    
    // Basta far partire la pallina da ping-pong!
    return calcolaLista(dipendenti_azienda);
}