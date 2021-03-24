/*
    g++ ch15drills.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double slope(double x) { return x; }
int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_orig = 300;
    int y_orig = 300;

    int rmin = -10;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo {x_orig, y_orig};

	int xlength = 400;
	int ylength = 400;

	int xscale = 20, yscale = 20;


//	Function one_func ( [] (double x) { return 1.0; }, rmin, rmax, origo, n_points);
	Function sloping_cos_func ( [] (double x) { return cos(x)+slope(x); }, rmin, rmax, origo, n_points, xscale, yscale);
    Function one_func_scale ( [] (double x) { return 1.0; }, rmin, rmax, origo, n_points, xscale, yscale);
	Function slope ( [] (double x) { return x/2; }, rmin, rmax, origo, n_points, xscale, yscale);
	Function square ( [] (double x) { return x*x; }, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale);
	Axis x {Axis::x, Point{100, 300}, xlength, xscale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300, 500}, ylength, yscale, "1 == 20 pixels"};
    x.set_color(Color::red);
	y.set_color(Color::red);

	//win.attach(one_func);
	win.attach(one_func_scale);
	win.attach(slope);
	win.attach(square);
	win.attach(cos_func);
	win.attach(sloping_cos_func);
	win.attach(x);
	win.attach(y);
    win.wait_for_button();

}
