struct List {
    int info;
    List* next;
};
#include <iostream>

using namespace std;

// --- PROTOTIPI ---
void filtraLista(List* sorgente, List*& destinazione);
void filtraAusiliaria(List* sorgente, List*& destinazione, int count);


// =================================================================
// 1. LA FUNZIONE WRAPPER (Richiesta dall'esame)
// =================================================================
void filtraLista(List* sorgente, List*& destinazione) {
    // Faccio partire la funzione ausiliaria con il contatore a 0
    filtraAusiliaria(sorgente, destinazione, 0);
}

// =================================================================
// 2. LA FUNZIONE AUSILIARIA (Il Motore Ricorsivo)
// =================================================================
void filtraAusiliaria(List* sorgente, List*& destinazione, int count) {
    
    // FASE 1: CASO BASE (Fine della lista sorgente)
    if (sorgente == nullptr) {
        
        // --- TRUCCO DA ESAME 2022 ---
        // L'esame del 2022 chiede di mettere in coda alla lista il numero 
        // totale di elementi inseriti. Lo facciamo esattamente qui!
        destinazione = new List;
        destinazione->info = count;  // Salvo il contatore
        destinazione->next = nullptr; // Chiudo definitivamente la lista
        
        return; // Inizia la risalita (che in questo caso non fa nulla)
    }
    
    // FASE 2: DISCESA E FILTRAGGIO
    // Applichiamo la condizione richiesta dal testo (Es: solo i numeri Pari)
    if (sorgente->info % 2 == 0) {
        
        // 1. IL DATO È VALIDO: Alloco un nuovo nodo per la destinazione
        destinazione = new List;
        destinazione->info = sorgente->info;
        
        // 2. CHIAMATA RICORSIVA (Avanzo ENTRAMBE le liste)
        // Passo sorgente->next per continuare a leggere.
        // Passo destinazione->next PER RIFERIMENTO, così il prossimo nodo 
        // si attaccherà automaticamente a questo! Aumento anche il count.
        filtraAusiliaria(sorgente->next, destinazione->next, count + 1);
        
    } else {
        // IL DATO È SCARTATO:
        // Avanzo SOLO nella lista sorgente. 
        // La destinazione e il count restano fermi ad aspettare il prossimo dato valido!
        filtraAusiliaria(sorgente->next, destinazione, count);
    }
}