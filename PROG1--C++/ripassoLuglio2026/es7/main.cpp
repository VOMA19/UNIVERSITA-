#include <iostream>

using namespace std;

// --- PROTOTIPI DELLE FUNZIONI ---
// La funzione principale richiesta dall'esame
void conta(char A[], int D, int i, int j, int*& res);

// (Dichiara qui le tue eventuali funzioni ricorsive ausiliarie)
// void contaAusiliaria(...);


// =========================================================
// MAIN PREIMPOSTATO DAL DOCENTE (NON MODIFICARE)
// =========================================================
int main() {
    // Array di test: le azioni del robottino
    // Indici:   0    1    2    3    4    5    6    7
    char A[] = {'n', 's', 'e', 'n', 'o', 'n', 'x', 's'};
    int D = 8;  // Dimensione dell'array
    int i = 0;  // Indice di partenza
    int j = 5;  // Indice target (in A[4] c'è l'azione 'n')
    
    // In questo test, vogliamo contare quante volte 'n' (che è in A[4])
    // compare tra l'indice i=0 e k<5.
    // Dovrebbe comparire 2 volte (in A e A[5]).

    int* res = nullptr;

    // Chiamata alla tua funzione
    conta(A, D, i, j, res);

    // Stampa dei risultati per verificare la tua implementazione
    if (res != nullptr) {
        cout << "Azione cercata: '" << A[j] << "'" << endl;
        cout << "Numero di occorrenze trovate (res): " << res << endl;
        
        if (res > 0) {
            cout << "Indici in cui compare (res[1...]): ";
            for (int k = 1; k <= res; k++) {
                cout << res[k] << " ";
            }
            cout << endl;
        }

        // Il main del prof dealloca la memoria che TU devi aver allocato in conta()
        delete[] res;
    } else {
        cout << "Errore: l'array res non e' stato allocato!" << endl;
    }

    return 0;
}

// =========================================================
// INSERISCI QUI SOTTO LA TUA IMPLEMENTAZIONE DI conta()
// E DELLE EVENTUALI FUNZIONI AUSILIARIE (TUTTE RICORSIVE)
// =========================================================
// Prototipo della funzione ausiliaria
void contaAusiliaria(char A[], int curr_i, int j, int count, int*& res);

void conta(char A[], int D, int i, int j, int*& res) {
    // Il wrapper si occupa solo di far partire la funzione ausiliaria 
    // passando 'i' come indice di partenza e inizializzando il contatore a 0.
    contaAusiliaria(A, i, j, 0, res);
}

void contaAusiliaria(char A[], int curr_i, int j, int count, int*& res) {
    // 1. CASO BASE: Abbiamo scorso l'array fino all'indice limite 'j'
    if (curr_i == j) {
        // Ormai sappiamo con esattezza quante volte è comparso il carattere (count).
        // Possiamo allocare l'array della dimensione PERFETTA.
        res = new int[count + 1]; 
        
        // Salviamo il totale in prima posizione come richiesto dall'esercizio
        res[0] = count; 
        
        // Terminiamo la discesa e iniziamo la risalita!
        return; 
    }

    // 2. FASE DI DISCESA
    // Controlliamo se l'elemento attuale è uguale all'elemento target (A[j])
    if (A[curr_i] == A[j]) {
        // Se è uguale, andiamo avanti incrementando il contatore 'count'
        contaAusiliaria(A, curr_i + 1, j, count + 1, res);
        
        // 3. FASE DI RISALITA (Backtracking)
        // Se siamo qui, significa che avevamo trovato un'occorrenza.
        // L'array 'res' è già stato allocato dal Caso Base.
        // In che posizione di 'res' dobbiamo salvare questo indice? 
        // Il trucco è che 'count' in QUESTO frame della ricorsione rappresenta 
        // il numero di match trovati PRIMA di questo indice. Quindi il nostro indice 
        // andrà proprio nella cella [count + 1]!
        res[count + 1] = curr_i;
        
    } else {
        // Se non è uguale, andiamo avanti nella discesa senza incrementare il contatore
        contaAusiliaria(A, curr_i + 1, j, count, res);
    }
}