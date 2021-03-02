/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;


    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	
    win.wait_for_button();

}
