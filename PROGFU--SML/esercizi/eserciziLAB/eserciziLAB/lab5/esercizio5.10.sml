fun fact 0 = 1                                    (* Caso base corretto  *)
  | fact n = n * fact(n-1);

fun comb (n, m) =
    (
        print ("n is ");                          (* Stampa etichetta  *)
        print (Int.toString(n));                  (* Converte n in stringa  *)
        print ("\n");                             (* Va a capo  *)
        
        print ("m is ");                          (* Stampa etichetta  *)
        print (Int.toString(m));                  (* Converte m in stringa  *)
        print ("\n");

        print ("Result is ");                     (* Calcolo e stampa finale *)
        print (Int.toString (fact(n) div (fact(m) * fact(n-m)))); (*  *)
        print ("\n")
    );