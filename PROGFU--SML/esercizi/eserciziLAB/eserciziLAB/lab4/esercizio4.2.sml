fun remove ([], m) = []                    (* Caso 1: lista vuota, restituisci vuoto *) 
  | remove (x::xs, 1) = xs                 (* Caso 2: i=1, elimina la testa e restituisci la coda *) 
  | remove (x::ys, i) = x :: remove(ys, i-1); (* Caso 3: salva x e cerca l'elemento da eliminare in ys *) 