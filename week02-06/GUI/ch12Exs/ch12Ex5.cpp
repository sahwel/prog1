/*
    g++ ch12Ex8.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp .//Simple_window.cpp  -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"
#include "../std_lib_facilities.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1600;
    int ymax = 1100;

    string label = "Title";

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
    win.set_label(label); 
    
    int width = x_max()/2/3*2;// osztottam 2-vel mert 2 monitorom van mind a kettő 1920x1080
    int height = y_max()/4*3;


	Rectangle rec {Point{100, 100}, width, height};
	rec.set_style(Line_style(Line_style::solid,253/4));
    rec.set_color(Color::red);
    win.attach(rec);
    

    win.wait_for_button();

}
