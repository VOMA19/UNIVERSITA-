(*
Esercizio 2 (Argomento 2: Liste e Pattern Matching)
Scrivi una funzione conta_zeri che prende una lista di interi 
e restituisce un numero che indica quanti zeri ci sono al suo interno.
(Esempio: conta_zeri [1, 0, 3, 0, 0] deve restituire 3).

Indizi per il Pattern Matching (i casi da gestire):

Caso base: Quanti zeri ci sono in una lista vuota []?

Caso in cui la testa è uno zero: Se la lista è fatta come 0::xs, 
hai trovato uno zero! Quindi conterai 1 e poi chiamerai la funzione sul resto della lista (xs).

Caso in cui la testa è un altro numero: Se la lista è fatta da un numero qualsiasi 
(puoi usare la wildcard _::xs), non hai trovato zeri, quindi non aggiungi nulla e chiami semplicemente la funzione sul resto della lista.
*)

fun conta_zeri [] = 0
  | conta_zeri (x::xs) = (* Aggiunte le parentesi qui! *)
        if x = 0 
        then 1 + conta_zeri xs
        else conta_zeri xs;


(*oppure*)

fun conta_zeri [] = 0
  | conta_zeri (0::xs) = 1 + conta_zeri xs  (* Se la testa e' 0, aggiungi 1 *)
  | conta_zeri (_::xs) = conta_zeri xs;     (* Se la testa e' qualsiasi altra cosa (_), salta *)