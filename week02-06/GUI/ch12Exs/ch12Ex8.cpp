/*
    g++ ch12Ex8.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
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

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    int startX = xmax/3;
    int startY = ymax/3;

	Circle c1 {Point{startX,startY}, 100};
    c1.set_color(Color::blue);
	Circle c2 {Point{startX+200,startY}, 100};
    c2.set_color(Color::black);
	Circle c3 {Point{startX+400,startY}, 100};
    c3.set_color(Color::red);
	Circle c4 {Point{startX+100,startY+150}, 100};
    c4.set_color(Color::yellow);
	Circle c5 {Point{startX+300,startY+150}, 100};
    c5.set_color(Color::green);

	c1.set_style(Line_style(Line_style::solid, 6));
	c2.set_style(Line_style(Line_style::solid, 6));
	c3.set_style(Line_style(Line_style::solid, 6));
	c4.set_style(Line_style(Line_style::solid, 6));
	c5.set_style(Line_style(Line_style::solid, 6));

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    

    win.wait_for_button();

}
