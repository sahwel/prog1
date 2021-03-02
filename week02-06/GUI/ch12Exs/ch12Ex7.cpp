/*
    g++ ch12Ex7.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
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

	Rectangle house {Point{100, 300}, 1000, 400};
	Rectangle door {Point{550, 500}, 100, 200};

	Rectangle window1 {Point{200, 375}, 100, 100};
	Rectangle window2 {Point{900, 375}, 100, 100};

    Polygon roof; 
	roof.add(Point{100,300});
	roof.add(Point{600,100});
	roof.add(Point{1100,300});

    Lines cihmney;
    cihmney.add( Point{400, 100}, Point{400, 180});//jobb hoszzú oldal
    cihmney.add( Point{350, 100}, Point{350, 200});//bal hosszú oldal

    cihmney.add( Point{400, 100}, Point{425, 100});//jobb alsó kis vonal
    cihmney.add( Point{325, 100}, Point{350, 100});//bal alsó kis vonal

    cihmney.add( Point{425, 75}, Point{425, 100});//jobb oldali kis vonal
    cihmney.add( Point{325, 75}, Point{325, 100});//bal alsó kis vonal

    cihmney.add( Point{325, 75}, Point{425, 75});//felső hosszú vonal

    Text smoke {Point{350,50}, "Smoke (lol)"};

    win.attach(smoke);
    win.attach(cihmney);
    win.attach(roof);
    win.attach(house);
    win.attach(door);
    win.attach(window1);
    win.attach(window2);
    

    win.wait_for_button();

}
