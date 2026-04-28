(* ===================================================================== *)
(* 1. FUNZIONE DI SUPPORTO: aggiungi_A_lista                             *)
(* Scopo: Prende un elemento 'x' e lo aggiunge in cima a ciascuna        *)
(* sottolista presente in una lista di liste.                            *)
(* ===================================================================== *)
fun aggiungi_A_lista (x, []) = [] 
  | aggiungi_A_lista (x, y::ys) = 
      (x :: y) :: aggiungi_A_lista (x, ys);


(* ===================================================================== *)
(* 2. FUNZIONE PRINCIPALE: powerSet                                      *)
(* Scopo: Calcola l'insieme delle parti (tutti i sottoinsiemi possibili) *)
(* ===================================================================== *)
fun powerSet [] = [[]]  (* L'insieme delle parti di un insieme vuoto e' [[]] *)
  | powerSet (x::xs) = 
      let
          (* Calcolo l'insieme delle parti per il resto della lista *)
          val ps_resto = powerSet xs 
          
          (* Uso l'aiutante per creare i nuovi sottoinsiemi che includono 'x' *)
          val ps_con_x = aggiungi_A_lista (x, ps_resto)
      in
          (* Incollo i due gruppi (quelli senza 'x' e quelli con 'x') *)
          ps_resto @ ps_con_x
      end;


(* ===================================================================== *)
(* 3. SEZIONE DI STAMPA (Per visualizzare int list list a schermo)       *)
(* ===================================================================== *)

(* 3.a Stampa una singola lista nel formato [1, 2] *)
fun stampaListaInt [] = print "[]"
  | stampaListaInt lista_singola =
      let
          (* Funzione interna per non stampare la virgola dopo l'ultimo elemento *)
          fun scorri [] = print "]"
            | scorri [ultimo] = print (Int.toString ultimo ^ "]")
            | scorri (corrente::resto) = (print (Int.toString corrente ^ ", "); scorri resto)
      in
          print "["; scorri lista_singola
      end;

(* 3.b Stampa l'intera lista di liste nel formato [[], [1], [2], [1, 2]] *)
fun stampaPowerSet [] = print "[]\n"
  | stampaPowerSet (tutte_le_liste) =
      let
          (* Uso stampaListaInt per ogni sottoinsieme *)
          fun scorri_esterne [] = print "]\n"
            | scorri_esterne [ultima_lista] = (stampaListaInt ultima_lista; print "]\n")
            | scorri_esterne (lista_corrente::resto) = 
                (stampaListaInt lista_corrente; print ", "; scorri_esterne resto)
      in
          print "["; scorri_esterne tutte_le_liste
      end;


(* ===================================================================== *)
(* 4. ESECUZIONE DEL TEST                                                *)
(* ===================================================================== *)

val risultato = powerSet [1, 2, 3];

val _ = print "L'insieme delle parti di [1, 2, 3] e':\n";
val _ = stampaPowerSet risultato;