(* ==========================================================================
IL GRANDE BIGNAMI DI STANDARD ML (SML)
Tutto quello che abbiamo imparato finora, pronto all'uso!
========================================================================== *)

(* --------------------------------------------------------------------------
    1. VARIABILI, TIPI BASE E CONVERSIONI
-------------------------------------------------------------------------- *)

(* Dichiarazione di variabili fisse (immutabili) *)
val intero = 42;               (* Tipo: int *)
val reale = 3.14;              (* Tipo: real *)
val negativo = ~5;             (* ATTENZIONE: Il meno per i numeri è la tilde ~ *)
val carattere = #"A";          (* Tipo: char. Richiede l'hash # prima degli apici *)
val testo = "Ciao SML";        (* Tipo: string *)
val veroFalso = true;          (* Tipo: bool (true o false) *)

(* Conversioni tra tipi (Esercizi 1.1 e 1.2) *)
val realeDaIntero = Real.fromInt(intero);  (* Da int a real -> 42.0 *)
val stringaDaIntero = Int.toString(123);   (* Da int a string -> "123" *)

val giu = floor(3.9);          (* Arrotonda per difetto (pavimento) -> 3 *)
val su = ceil(3.1);            (* Arrotonda per eccesso (soffitto) -> 4 *)

val codiceAscii = ord(#"A");   (* Da carattere a intero ASCII -> 65 *)
val daAsciiAChar = chr(65);    (* Da intero ASCII a carattere -> #"A" *)
val stringaDaChar = str(#"A"); (* Da carattere a stringa -> "A" *)


(* --------------------------------------------------------------------------
    2. TIPI COMPOSTI: TUPLE E LISTE
-------------------------------------------------------------------------- *)

(* TUPLE: Insiemi di dimensione fissa, possono avere tipi misti. Usano ( e ) *)
val miaTupla = (1, "mela", true);           (* Tipo: int * string * bool *)
val primoElemento = #1 miaTupla;            (* Estrae il primo elemento -> 1 *)
val secondoElemento = #2 miaTupla;          (* Estrae il secondo -> "mela" *)

(* LISTE: Dimensione variabile, ma DEVONO avere tutti lo stesso tipo. Usano [ e ] *)
val miaLista = [1, 2, 3, 4];                (* Tipo: int list *)
val listaVuota = [];                        (* Tipo: 'a list (polimorfa/generica) *)

(* Operazioni sulle liste *)
val testa = hd miaLista;                    (* Prende il primo elemento -> 1 *)
val coda = tl miaLista;                     (* Prende tutto TRANNE il primo -> [2,3,4] *)
val incollaListe = [1, 2] @ [3, 4];         (* @ concatena DUE LISTE -> [1,2,3,4] *)
val aggiungiInTesta = 0 :: [1, 2];          (* :: (Cons) aggiunge UN ELEMENTO in cima -> [0,1,2] *)

(* Stringhe come liste di caratteri *)
val listaCaratteri = explode("Ciao");       (* Da string a char list -> [#"C",#"i",#"a",#"o"] *)
val stringaRicostruita = implode(listaCaratteri); (* Da char list a string -> "Ciao" *)


(* --------------------------------------------------------------------------
    3. FUNZIONI E PATTERN MATCHING (Il cuore di SML)
-------------------------------------------------------------------------- *)

(* Funzione base con pattern matching. 
   SML valuta le righe dall'alto verso il basso. Fermandosi alla prima che "combacia". *)
fun fattoriale 0 = 1                               (* Caso base *)
  | fattoriale n = n * fattoriale (n - 1);         (* Chiamata ricorsiva *)

(* Pattern Matching sulle liste. 
   Fondamentale per scorrere una lista elemento per elemento. *)
fun sommaLista [] = 0                              (* Se la lista è vuota *)
  | sommaLista (testa::coda) = testa + sommaLista coda; (* Separa il primo dal resto *)


(* --------------------------------------------------------------------------
    4. FOLD (Foldl e Foldr)
    Le funzioni che "schiacciano" una lista in un singolo valore accumulato.
    Sintassi: foldl/foldr (fn (elemento, accumulatore) => ...) valore_iniziale lista
-------------------------------------------------------------------------- *)

(* foldl (Fold Left): Parte da SINISTRA e va verso destra. *)
val stringaRovesciata = foldl (fn (x, acc) => str x ^ acc) "" (explode "abcd"); 
(* Risultato: "dcba" *)

(* foldr (Fold Right): Parte da DESTRA e torna indietro verso sinistra. *)
val stringaDritta = foldr (fn (x, acc) => str x ^ acc) "" (explode "abcd");
(* Risultato: "abcd" *)


(* --------------------------------------------------------------------------
    5. CREAZIONE DI TIPI PERSONALIZZATI (type e datatype)
-------------------------------------------------------------------------- *)

(* TYPE: Crea solo un "alias" (un sinonimo) per comodità di lettura *)
type coordinate = real * real;

(* DATATYPE: Crea un tipo di dato completamente nuovo con i suoi "Costruttori" (varianti).
   Regola d'oro: I costruttori si scrivono con l'Iniziale Maiuscola! *)
datatype veicolo = 
    Bicicletta                            (* Costruttore SENZA dati allegati *)
  | Automobile of string * int            (* Costruttore CON dati (tupla: targa, porte) *)
  | Treno of int;                         (* Costruttore CON dato (singolo: n° vagoni) *)

(* Datatype POLIMORFO E RICORSIVO (L'Albero Binario)
   'a significa che può contenere qualsiasi tipo. btree richiama sé stesso. *)
datatype 'a btree = 
    Empty 
  | Node of 'a * 'a btree * 'a btree;


(* --------------------------------------------------------------------------
    6. PATTERN MATCHING SUI DATATYPE (L'arte di estrarre i dati)
-------------------------------------------------------------------------- *)

(* Quando fai pattern matching su un costruttore che ha dei dati (of ...), 
   DEVI USARE LE PARENTESI per raggrupparlo! Usa variabili (es. 't' e 'p') per estrarli. *)
fun descriviVeicolo Bicicletta = "E' una bici ecologica!"
  | descriviVeicolo (Automobile (t, p)) = "Auto targata " ^ t ^ " con " ^ Int.toString(p) ^ " porte."
  | descriviVeicolo (Treno v) = "Treno lungo " ^ Int.toString(v) ^ " vagoni.";


(* --------------------------------------------------------------------------
   7. MODULI (Signature e Structure) - ANTEPRIMA
   Per nascondere il codice e creare Tipi di Dato Astratti (ADT).
   -------------------------------------------------------------------------- *)

(* 1. SIGNATURE (Il Menu / L'Interfaccia) - Tutto in MAIUSCOLO *)
signature BANCA = 
sig
    type conto                            (* Tipo nascosto (Abstract) *)
    val nuovoConto : conto                (* Valore disponibile *)
    val deposita : conto * int -> conto   (* Funzione esposta *)
end;

(* 2. STRUCTURE SIGILLATA (La Cucina / L'Implementazione)
   Il simbolo :> (Ascription Opaca) forza la Structure a rispettare la Signature 
   nascondendo tutto il resto al mondo esterno. *)
structure MiaBanca :> BANCA = 
struct
    type conto = int                      (* Sveliamo che in realtà è un intero *)
    val nuovoConto = 0                    (* Partiamo da 0 euro *)
    fun deposita (c, soldi) = c + soldi   (* Logica della funzione *)
    
    (* Se scrivessimo altre funzioni qui dentro, non elencate nella signature, 
       sarebbero invisibili e inutilizzabili dall'esterno (Information Hiding!) *)
end;

(* ==========================================================================
   FINE BIGNAMI
   ========================================================================== *)