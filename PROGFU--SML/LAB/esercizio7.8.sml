fun sumTree Empty = 0
    | sumTree (Node ((chiave, valore), sinistro, destro)) = 
        valore + sumTree sinistro + sumTree destro;