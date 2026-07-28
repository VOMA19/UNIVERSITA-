datatype 'a T = Lf 
              | Br of 'a * 'a T * 'a T;

fun depth Lf = 0
    | depth (Br(valore, sx, dx)) = 
        if depth(sx) > depth(dx) 
        then 1 + depth(sx) 
        else 1 + depth(dx);

fun mirror Lf = Lf
    | mirror (Br(valore, sx, dx)) = Br(valore, mirror dx, mirror sx);
