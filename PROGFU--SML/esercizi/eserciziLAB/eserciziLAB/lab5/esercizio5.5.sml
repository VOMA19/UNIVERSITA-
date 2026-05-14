fun sumPairs (nil) = (0,0)  (* Caso base *)
    | sumPairs ((x,y)::zs) = 
        let
            (* PREPARAZIONE: Chiediamo alla ricorsione di darci le somme del resto della lista *)
            val (s1, s2) = sumPairs(zs) 
        in
            (* AZIONE: Prendiamo x e y della coppia corrente e li aggiungiamo ai risultati precedenti *)
            (x + s1, y + s2)
        end;