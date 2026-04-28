(*Supponendo che gli insiemi siano rappresentati come liste senza ripetizioni, scrivere una funzione intersection(S1,
S2) che calcola l’intersezione di due insiemi.
Nota: si pu`o utilizzare la funzione di supporto member(x, S) (Es 4.6 ML Lab 4) per verificare l’apparte-
nenza di un elemento a un insieme*)

fun member (x, []) = false
  | member (x, y::ys) = 
      if x = y then true 
      else member (x, ys);

fun intersection ([], S2) = []
  | intersection (x::xs, S2) = 
      if member (x, S2) then
          x :: intersection (xs, S2)
      else
          intersection (xs, S2);

(* Facciamo un test di prova *)
val nuovaLista = intersection ([1, 2, 3, 4], [3, 4, 5, 6]);

fun stampaListaInt [] = print "\n"
    |stampaListaInt (x::xs) = 
        let
            val _ = print(Int.toString x ^ " ")
        in 
            stampaListaInt xs
        end;

val _ = print "la nuova e': ";
val _ = stampaListaInt nuovaLista;