(*
Hai una lista di parole ["gatto", "cane", "elefante", "topo"]. Scrivi una dichiarazione 
val usando List.filter per tenere solo le parole che hanno una lunghezza strettamente maggiore di 4 caratteri.
(Ricorda: la lunghezza di una stringa si calcola con la funzione String.size tua_stringa).
*)

val max4 = List.filter (fn x => String.size(x)>4) ["gatto", "cane", "elefante", "topo"];