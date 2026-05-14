fun sumTree Empty = 0 
    | sumTree (Node((_, valore), sinistro, destro)) = 
        valore + sumTree sinistro + sumTree destro; 