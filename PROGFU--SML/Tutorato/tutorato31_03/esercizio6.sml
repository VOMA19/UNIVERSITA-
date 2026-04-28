(*Rappresentando gli insiemi come liste senza ripetizioni, scrivere una funzione difference(S1, S2) che
calcola la differenza tra l’insieme S1 e l’insieme S2 (ovvero restituisce tutti gli elementi che appartengono
a S1 ma NON a S2).
Ad esempio: difference([1,2,3,4], [2,4,5]) = [1,3]*)

fun member (x, []) = false
  | member (x, y::ys) = 
      if x = y then true 
      else member (x, ys);


fun difference([],S2) = []
    |difference (x::xs, S2) = 
    if member(x,S2) then
        difference(xs, S2)
    else
        x :: difference (xs, S2);

    
val nuovaLista = difference ([1, 2, 3, 4], [3, 4, 5, 6]);

fun stampaListaInt [] = print "\n"
    |stampaListaInt (x::xs) = 
        let
            val _ = print(Int.toString x ^ " ")
        in 
            stampaListaInt xs
        end;

val _ = print "la nuova e': ";
val _ = stampaListaInt nuovaLista;