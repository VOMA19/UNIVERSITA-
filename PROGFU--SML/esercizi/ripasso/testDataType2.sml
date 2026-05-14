(* ==========================================================================
    ESERCIZIO: Metodi di Pagamento
    
    Parte 1: Definire un datatype `pagamento` con 3 costruttori:
    - Contanti
    - Carta (tupla string * string per numero e titolare)
    - Assegno (int per il numero dell'assegno)
    
    Parte 2: Scrivere una funzione `descriviPagamento` che prenda un 
    pagamento e restituisca una stringa descrittiva.
   ========================================================================== *)

(* --- PARTE 1: Definizione del tipo di dato --- *)
datatype pagamento =
    Contanti 
  | Carta of string * string  (* Usiamo * per le tuple di tipi *)
  | Assegno of int;           (* Il tipo intero si chiama int *)


(* --- PARTE 2: La funzione con Pattern Matching --- *)
(* Invece di usare valori fissi, usiamo le variabili 'numeroCarta', 'titolare' e 'num' 
   per "catturare" i dati in ingresso e usarli nella concatenazione con ^ *)
fun descriviPagamento Contanti = "Pagamento effettuato in contanti."
    
    | descriviPagamento (Carta (numeroCarta, titolare)) = "Pagamento con carta " ^ numeroCarta ^ " intestata a " ^ titolare ^ "."
    
    | descriviPagamento (Assegno num) = "Pagamento tramite assegno numero " ^ Int.toString(num) ^ ".";


(* ==========================================================================
    TEST E STAMPE A SCHERMO
    Salviamo i risultati della funzione in delle variabili (val) e poi le stampiamo.
    Aggiungiamo "\n" alla fine per andare a capo nel terminale.
   ========================================================================== *)

val test1 = descriviPagamento Contanti;
val test2 = descriviPagamento (Carta ("1234-5678", "Mario Rossi"));
val test3 = descriviPagamento (Assegno 98765);

print ("\n--- RISULTATI TEST ---\n");
print (test1 ^ "\n");
print (test2 ^ "\n");
print (test3 ^ "\n");