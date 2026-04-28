(* 1. Rimettiamo la funzione di supporto per stampare (copiata da prima) *)
fun stampaListaInt [] = print "\n"
  | stampaListaInt (x::xs) = 
      let 
          val _ = print (Int.toString x ^ " ")
      in 
          stampaListaInt xs 
      end;

(* 2. La vera e propria funzione dell'esercizio 3.3 *)
fun duplicate [] = []
  | duplicate (x::xs) = x :: x :: duplicate xs;

(* 3. Eseguiamo il test *)
val listaDuplicata = duplicate [1, 2, 3, 4];

(* 4. Stampiamo il risultato *)
val _ = print "Risultato Esercizio 3.3: ";
val _ = stampaListaInt listaDuplicata;