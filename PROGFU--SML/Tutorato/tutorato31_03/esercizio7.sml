(*Scrivere una funzione extract ordered che prende in input una lista di coppie di interi e restituisce una
nuova lista contenente solo le coppie in cui il primo elemento `e strettamente minore del secondo. Se
nessuna coppia rispetta la condizione, restituire la lista vuota.
Ad esempio: extract ordered [(5,2), (1,3), (6,6), (2,8)] = [(1,3), (2,8)]*)

(* Funzione principale corretta *)
fun extract_ordered [] = [] 
  | extract_ordered ((x, y)::xs) = 
      if x < y then
          (x, y) :: extract_ordered xs  (* Tengo la coppia intera e vado avanti *)
      else
          extract_ordered xs;           (* Scarto la coppia e vado avanti *)

val nuovaLista = extract_ordered [(5,2), (1,3), (6,6), (2,8)];

(* Nuova funzione di stampa per gestire le coppie *)
fun stampaListaCoppie [] = print "\n"
  | stampaListaCoppie ((x, y)::xs) = 
      let
          (* Costruisco la stringa "(x,y) " concatenando i vari pezzi *)
          val _ = print("(" ^ Int.toString x ^ "," ^ Int.toString y ^ ") ")
      in 
          stampaListaCoppie xs
      end;

val _ = print "la nuova e': ";
val _ = stampaListaCoppie nuovaLista;