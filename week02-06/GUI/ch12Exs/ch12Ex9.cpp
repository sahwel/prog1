/*
    g++ ch12Ex9.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp .//Simple_window.cpp  -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"
#include "../std_lib_facilities.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    string label = "Image with a title and a caption";

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
    win.set_label(label); 
   
	Image ii {Point{100,100}, "badge.jpg"};

    
	Text title {Point{170,80}, label};    

	Text caption {Point{200,530}, "This is the caption"};   

    win.attach(caption);
    win.attach(title);
    win.attach(ii);

    win.wait_for_button();

}
