#include "sphere.h"

void Sphere::displaySphere()
{
    std::cout << "  - "
        << nom
        << " : {"
        << coordSphere.get_x() << ","
        << coordSphere.get_y() << ","
        << masse << ","
        << rayon << ","
        << couleur
        << "}"
        <<std::endl;
}

Sphere::Sphere(std::string _nom, double _x, double _y, double _masse, double _rayon, std::string _couleur)
{
    nom = _nom;
    coordSphere.set_xy(_x, _y);
    masse = _masse;
    rayon = _rayon;
    couleur = _couleur;
}

Coord::Coord(double _x, double _y)
{
    x = _x;
    y = _y;
}

void Sphere::dessiner(Svgfile &f)
{
    f.addDisk(coordSphere.get_x(), coordSphere.get_y(), rayon, couleur);
}

double Coord::get_x()
{
    return x;
}

double Coord::get_y()
{
    return y;
}
void Coord::set_xy(double _x,double _y)
{
    x =_x;
    y =_y;
}

/*Coord sommer(Sphere s1, Sphere s1)
{

}
*/
