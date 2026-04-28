(*Write a function printList that given as input a
list of integers, prints it.*)
fun stampaListaInt [] = print "nil"
  | stampaListaInt lista_singola =
      let
          (* Funzione interna per non stampare la virgola dopo l'ultimo elemento *)
          fun scorri [] = print ""
            | scorri [ultimo] = print (Int.toString ultimo)
            | scorri (corrente::resto) = (print (Int.toString corrente ^ "\n "); scorri resto)
      in
            scorri lista_singola
      end;

val _ = stampaListaInt [1,2,3,4,9];