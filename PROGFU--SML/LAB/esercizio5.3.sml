(* 1. La tua funzione split *)
fun split [] = ([], [])
  | split ((x, y)::xs) =
      let 
          val ris = split xs
      in  
          (x :: #1 ris, y :: #2 ris)
      end;

(* 2. Test della funzione *)
val test_lista = [(1, "A"), (2, "B"), (3, "C")];
val risultato = split test_lista;

val lista_numeri = #1 risultato;
val lista_lettere = #2 risultato;


(* 3. Funzioni di stampa (le classiche che hai gia' usato!) *)

(* Per la lista di interi *)
fun stampaListaNumeri [] = print "\n"
  | stampaListaNumeri (x::xs) = 
      (print (Int.toString x ^ " "); stampaListaNumeri xs);

(* Per la lista di stringhe (le stringhe si stampano direttamente) *)
fun stampaListaStringhe [] = print "\n"
  | stampaListaStringhe (x::xs) = 
      (print (x ^ " "); stampaListaStringhe xs);


(* 4. Esecuzione delle stampe *)
val _ = print "Lista dei numeri:  ";
val _ = stampaListaNumeri lista_numeri;

val _ = print "Lista delle lettere: ";
val _ = stampaListaStringhe lista_lettere;