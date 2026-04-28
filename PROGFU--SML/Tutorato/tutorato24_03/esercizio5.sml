(*Scrivi una funzione che dato un numero A e una lista L, restituisca la sola degli elementi
della lista L senza considerare le ricorrenze del numero A.
esempi:
> somma_filtrata(2,[1,2,3,2]);
val it = 4: int
> somma_filtrata(5,[1,2,3,5]);
val it = 6: int*)

(* 1. La tua funzione perfetta *)
fun somma_filtrata (k, []) = 0
  | somma_filtrata (k, x::xs) =
        if x = k then  
            somma_filtrata (k, xs)
        else
            x + somma_filtrata (k, xs);

(* 2. Facciamo un paio di test *)
val risultato1 = somma_filtrata (2, [1, 2, 3, 2]);
val risultato2 = somma_filtrata (5, [1, 2, 3, 5]);
val risultato_vuoto = somma_filtrata (9, []); (* Test estremo con lista vuota *)

(* 3. Stampiamo a schermo *)
val _ = print("Risultato test 1 (escludo 2): " ^ Int.toString risultato1 ^ "\n");
val _ = print("Risultato test 2 (escludo 5): " ^ Int.toString risultato2 ^ "\n");
val _ = print("Risultato test lista vuota:  " ^ Int.toString risultato_vuoto ^ "\n");