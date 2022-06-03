// measurements
jack_diameter = 8.42;
dist_outer = 23.45;
dist_inner = dist_outer - jack_diameter;

dist_edge_outer = 23.25 - 1.5;
dist_edge_inner = 13.29;
dist_edge = ((dist_edge_outer - jack_diameter / 2) + (dist_edge_inner + jack_diameter / 2)) / 2;

dist_edge_upper = 3.26;
dist_edge_lower = 11.93;
dist_edge_y = ((dist_edge_lower - jack_diameter / 2) + (dist_edge_upper + jack_diameter / 2)) / 2;

//          dist_edge
//  -------------
// |     x   x  | h
//  -------------
//

screw_dia = 2.4;
scew_dist_top = 13.35;
screw_dist_side = 4.8;

thickness = 5.5;
n_cols = 3;


base();


module base() { 
    h1 = dist_edge_y + jack_diameter/2 + dist_inner - jack_diameter + jack_diameter / 2 + dist_edge_y;
    w1 = dist_edge*2 + dist_inner * (n_cols - 1);
    echo(w1);
    echo(h1);
    echo(h1*2);
    cube([w1, h1, thickness]);
}