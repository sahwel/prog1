/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"
#include "../std_lib_facilities.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 2000;
    int ymax = 2000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
 // 6 feladat: Első kérdés: Minden össze megy
    Rectangle r {Point{2200,2200}, 100, 30};

    win.attach(r);
 // 2 kérdés: Lefut, ha nem lenne túl nagy a win, akkor a win nagyításával "megnézhető"
    win.wait_for_button();

}
