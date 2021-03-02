/*
    g++ ch12Ex.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp .//Simple_window.cpp -o main `fltk-config --ldflags --use-images`
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


    // 1. exercise
    Polygon poly; 

	poly.add(Point{150,250});
	poly.add(Point{300,250});
	poly.add(Point{300,150});
	poly.add(Point{150,150});
	poly.set_color(Color::red);
	poly.set_fill_color(Color::green);

    win.attach(poly);

  

    // 2. exercise
	Rectangle r {Point{400,50}, 100, 30};
    Text t {Point{405,70}, "Howdy!"};

    win.attach(r);
    win.attach(t);


    
    
    // 3. exercise
    Text m {Point{300,300}, "M"};
	m.set_font(Font::times_bold);
	m.set_font_size(150);
    Text j {Point{500,300}, "J"};
	j.set_font(Font::times_bold);
	j.set_font_size(150);
    Text k {Point{600,300}, "K"};
	k.set_font(Font::times_bold);
	k.set_font_size(150);
    win.attach(m);
    win.attach(j);
    win.attach(k);

    //4. execrise
    int howM = 3;

    Vector_ref<Rectangle> rectangles;


    int girdSize = 50;
    int where = 0;
    for(int i = 0; i < howM; i++){
        for (int j = 0;  j < howM; j++)
        {
            rectangles.push_back(new Rectangle(Point{i*girdSize, j*girdSize}, girdSize, girdSize));
            if(where % 2 == 0){
                rectangles[where].set_fill_color(Color::red);
            }else{
                rectangles[where].set_fill_color(Color::white);
            }
       
            win.attach(rectangles[where]);
            where++;
        }
        
       
    }
   

    win.wait_for_button();

}
