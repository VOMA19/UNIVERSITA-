(*Scrivi una funzione minList che restituisca l'elemento più piccolo di una lista di interi.
Assumi che la lista non sia vuota e usa i pattern matching.
esempi:
> minList([3,4,2,6]);
val it = 2: int
> minList([3,1]);
val it = 1: int*)

(* 1. Dichiaro una nuova eccezione personalizzata *)
exception ListaVuota;

(* 2. Aggiungo il caso della lista vuota alla mia funzione *)
fun minList [] = raise ListaVuota              (* Caso anomalo coperto! *)
  | minList [x] = x                            (* Caso base: un elemento *)
  | minList (x::y::xs) =                       (* Caso ricorsivo: due o più *)
        if x < y then 
            minList (x::xs)
        else
            minList (y::xs);

val valore = minList [3,4,2,5,6]; 

val _ = print("Il minore della lista e': " ^ Int.toString valore ^ "\n");