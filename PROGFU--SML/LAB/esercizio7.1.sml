fun curry F x y z = F (x, y, z);

curry (fn(x,y,z)=>x*y*z) 1 2 3