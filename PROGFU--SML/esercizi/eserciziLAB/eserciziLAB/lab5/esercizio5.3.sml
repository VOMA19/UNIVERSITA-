fun split(nil) = (nil, nil)               (* Caso base: lista vuota *) 
  | split([a]) = ([a], nil)               (* Caso base: un solo elemento *) 
  | split(a::b::cs) =                     (* Caso ricorsivo: almeno due elementi *) 
    let
        val x = split(cs)                 (* Salva il risultato della ricorsione in una singola variabile 'x' *) 
        val M = #1 x                      (* Usa il selettore #1 per estrarre la prima lista (posizioni pari) *) 
        val N = #2 x                      (* Usa il selettore #2 per estrarre la seconda lista (posizioni dispari) *) 
    in
        (a::M, b::N)                      (* Costruisce la nuova coppia aggiungendo 'a' e 'b' alle rispettive liste *) 
    end;