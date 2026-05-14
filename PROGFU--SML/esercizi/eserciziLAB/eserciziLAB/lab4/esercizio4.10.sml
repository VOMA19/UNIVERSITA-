fun insertAll(a, nil) = nil
    | insertAll(a, L::Ls) = (a::L) :: insertAll(a, Ls);

fun powerSet(nil) = [nil] (* Caso base: l'unica parte del vuoto è il vuoto stesso [cite: 744] *)
    |powerSet(x::xs) = 
        let 
            val ps_rest = powerSet(xs) (* Calcoliamo i sottoinsiemi del resto  *)
        in 
            ps_rest @ insertAll(x, ps_rest) (* Li uniamo a quelli con 'x' aggiunto  *)
        end;