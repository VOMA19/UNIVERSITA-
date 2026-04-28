(*Scrivere una funzione sum pairs che prende in input una lista di coppie di interi e restituisce una lista
contenente la somma degli elementi di ciascuna coppia, utilizzando il pattern matching.
Ad esempio: sum pairs [(1,2),(4,3)] = [3,7]*)

fun sum_pairs [] = []
  | sum_pairs ((x, y) :: xs) = (x + y) :: sum_pairs xs;

val nuovaLista = sum_pairs([(0,1),(3,6),(8,1),(10,9)]);

fun stampaListaInt [] = print "\n"
    |stampaListaInt (x::xs) = 
        let
            val _ = print(Int.toString x ^ " ")
        in 
            stampaListaInt xs
        end;

val _ = print "la nuova e': ";
val _ = stampaListaInt nuovaLista;