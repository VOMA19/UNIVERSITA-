(*
Esercizio 1 (Argomento 1: Pattern Matching e Condizioni)

Scrivi una funzione ordina_coppia che prende in input una tupla di due interi (a, b).

Se a è strettamente maggiore di b, la funzione deve restituire la tupla invertita (b, a).

Altrimenti, restituisce la tupla originale (a, b).
(Esempio: ordina_coppia (5, 2) deve restituire (2, 5)).
*)

fun ordina_coppia (a, b) = 
    if a > b 
    then (b, a)   (* Restituisco semplicemente la tupla invertita *)
    else (a, b);  (* Restituisco semplicemente la tupla originale *)

(* --- TEST --- *)
val test1 = ordina_coppia (5, 2); (* Risultato: (2, 5) *)
val test2 = ordina_coppia (1, 8); (* Risultato: (1, 8) *)
