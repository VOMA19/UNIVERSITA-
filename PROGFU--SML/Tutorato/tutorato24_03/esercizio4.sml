(*Scrivi una funzione conta_occorrenze che, dato un elemento k e una lista L, calcoli
quante volte l'elemento k compare all'interno della lista L.
esempi:
> conta_occorenze(1, [2,1,3,1,2,2,1]);
val it = 3: int
> conta_occorenze("a", ["a","b","a","c"]);
val it = 2: int*)

fun conta_occorenze (k, []) = 0
  | conta_occorenze (k, x::xs) = 
        if x = k then
            1 + conta_occorenze (k, xs)  (* Trovato! Aggiungo 1 e vado avanti *)
        else   
            conta_occorenze (k, xs);     (* Non trovato, vado avanti senza aggiungere *)

(* Facciamo un test di prova *)
val test_conteggio = conta_occorenze (2, [1, 2, 3, 2, 2, 4]);
val _ = print ("Il numero 2 compare " ^ Int.toString test_conteggio ^ " volte\n");
    