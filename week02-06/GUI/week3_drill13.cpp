/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1000;
    int ymax = 800;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    int xLong = 100;
    int yLong = 100;


    int xDist = 0;
    int yDist = 100;
    int howM = 8;

    Lines xlines ;

    for(int i = 0; i < howM; i++){
       xlines.add( Point{xDist, yDist}, Point{xLong*8, yLong});
       yDist += 100;
       yLong += 100;
    }

    win.attach(xlines);


    Lines ylines ;


    xLong = 100;
    yLong = 100;
    xDist = 100;
    yDist = 0;

    for(int i = 0; i < howM; i++){
       xlines.add( Point{xDist, yDist}, Point{xLong, yLong*8});
       xDist += 100;
       xLong += 100;
    }

    win.attach(ylines);

    Vector_ref<Rectangle> rectangles;

    int girdSize = 100;

    for(int i = 0; i < howM; i++){
       rectangles.push_back(new Rectangle(Point{i*girdSize, i*girdSize}, 100, 100));
       rectangles[i].set_fill_color(Color::red);
       win.attach(rectangles[i]);
    }

   Vector_ref<Image> images;



   images.push_back(new Image(Point{0, 200}, "badge.jpg"));
   images.push_back(new Image(Point{0, 400}, "badge.jpg"));
   images.push_back(new Image(Point{0, 600}, "badge.jpg"));

    constexpr int image_size = 200;

    for(int i = 0; i < images.size(); i++){
        images[i].set_mask(Point{100, 100}, image_size, image_size);
        win.attach(images[i]);
    }


    constexpr int logo_size = 100;

    Image logo(Point{0,0}, "badge.jpg");
    logo.set_mask(Point{150, 150}, logo_size, logo_size);

    win.attach(logo);

    for(int i = 0; i < howM; i++){
        for(int j = 0; j < howM; j++){
            win.wait_for_button();
            if(j < 7) logo.move(100, 0);
            else logo.move(-((howM-1)*100), 100);
        }
    }


}
