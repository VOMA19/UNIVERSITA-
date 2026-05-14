fun maxList (nil) = 0.0                      (* Caso base per lista vuota [cite: 784] *)
  | maxList (x::xs) =                        (* Pattern testa/coda [cite: 784] *)
    let
        val maxTail = maxList(xs)            (* STANZA LET: calcolo il massimo della coda  *)
    in
        if x < maxTail then maxTail else x   (* STANZA IN: confronto x con il risultato locale  *)
    end;