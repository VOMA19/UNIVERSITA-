fun powerSet(nil) = [nil]                   (* Caso base [cite: 724, 727] *)
  | powerSet(x::xs) =                       (* Passo ricorsivo [cite: 725] *)
    let
        val L = powerSet(xs)                (* Calcoliamo il powerset della coda UNA sola volta [cite: 713, 729] *)
    in
        L @ insertAll(x, L)                 (* Usiamo la variabile L due volte nel risultato  *)
    end;