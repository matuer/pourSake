#ifndef sphere
#define sphere
#include <math.h>
#include "svgfile.h"

class Coord
{
public:
    Coord(double _x = 100, double _y = 100);
    //~Coord();
    double get_x();
    double get_y();
    void set_xy(double _x,double _y);
private:
    double x,y;
};

class Sphere
{
public:
    void displaySphere();
    void dessiner(Svgfile &f);
    Sphere(std::string _nom = "terre", double _x = 200, double _y = 400, double _masse = 6, double _rayon = 63, std::string _couleur = "blueball");
    //~Sphere();
private:
    double masse,rayon;
    Coord coordSphere;
    std::string couleur, nom;
};

#endif // sphere
