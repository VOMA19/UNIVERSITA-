(* 1. Funzione con i casi separati da | *)
fun cyclei (0, L) = L
  | cyclei (_, []) = []
  | cyclei (i, x::xs) = cyclei (i - 1, xs @ [x]);

val nuovaLista = cyclei (2, [1, 2, 3, 4]);

(* 2. Creiamo una piccola funzione per stampare le liste di numeri *)
fun stampaListaInt [] = print "\n"
  | stampaListaInt (x::xs) = 
      let 
          val _ = print (Int.toString x ^ " ")
      in 
          stampaListaInt xs 
      end;

(* 3. Stampiamo un messaggio e poi la lista *)
val _ = print "La nuova lista e': ";
val _ = stampaListaInt nuovaLista;