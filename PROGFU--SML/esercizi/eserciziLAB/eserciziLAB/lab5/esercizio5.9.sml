fun printList (nil) = () (* Restituisce 'unit', il tipo vuoto per le azioni  *)
    | printList (x::xs) =
        (
            print(Int.toString(x)); (* Stampa il numero  *)
            print("\n");            (* Va a capo  *)
            printList(xs)           (* Continua con il resto della lista *)
        );