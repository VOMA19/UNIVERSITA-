datatype cell = alive | dead;
type grid = cell list list;
type grid_cols = cell list;

val row = 5;
val col = 4;
type grid g = [[alive,dead]
                [alive,dead]];


fun n_rows(nil) = 0
    | n_rows(t::tab) = 1 + n_rows(tab);

fun r_col(nil) = nil
    |r_col(t::tab) = 
        let
            val numcolI = n_rows(t)
        in
            [numcolI]@r_col(tab)
        end;

fun cell_at_x_y(x, y, grid) =
    if x < 0 orelse y < 0 orelse x >= n_rows(grid) orelse y >= n_rows(List.nth(grid, 0)) 
        then dead
    else
        cell_at_x_y(x, y, grid);

fun convert(cel:cell)= if(cel = alive) then 1 else 0;

fun count_live_neghbours(tab, x, y)=
    let
        val a = cell_at_x_y(x-1, y-1, tab);
        val b = cell_at_x_y(x-1, y, tab);
        val c = cell_at_x_y(x-1, y+1, tab);
        val d = cell_at_x_y(x, y-1, tab);
        val e = cell_at_x_y(x+1, y-1, tab);
        val f = cell_at_x_y(x+1, y, tab);
        val g = cell_at_x_y(x+1, y+1, tab);
        val h = cell_at_x_y(x, y+1, tab);
    in
        convert(a)+
        convert(b)+
        convert(c)+
        convert(d)+convert(e)+convert(f)+convert(g)+convert(h)
    end;

fun cell_next_state(tab, x, y)= 
    if(cell_at_x_y(x,y,tab) = alive andalso count_live_neghbours(tab, x,y)>1 andalso count_live_neghbours(tab, x,y) <4) 
        then alive  
    else 
        if(cell_at_x_y(x,y,tab) = dead andalso  count_live_neghbours(tab, x,y) =3) 
            then alive
    else dead;