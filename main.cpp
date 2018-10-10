#include "svgfile.h"
#include "sphere.h"
#include "interfaceCpp.h"
#include <iostream>
#include <windows.h>
#include <math.h>
/// VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
/// VVVV DEBUT DU CODE ETUDIANT VVVV
/// VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV

/// Voir implémentation après le main
void svgTest();

int main()
{
    int i = 0, event = 0;
    Sphere terre, lune("lune", 200+184*cos(i), 400+184*sin(i), 2.7, 27, "greyball");
    Svgfile svgout;
    std::vector<Sphere> systemeSolaire(1, terre);
    //systemeSolaire[0].push_back(lune);

    event = menu(systemeSolaire);

    while(i<9)
    {
    terre.displaySphere();
    terre.dessiner(svgout);
    lune.displaySphere();
    lune.dessiner(svgout);
    svgout.addGrid();
    svgout.~Svgfile();
    Sleep(1000);
    if(i == 0)
    {
        system("start output.svg");
    }
    i++;
    }
    return 0;
}

/// Code initial pour comprendre les ajouts de primitives
void svgTest()
{
    /// Sortie graphique dans le fichier output.svg
    /// ( options à voir svgfile.h ligne 23 )
    Svgfile svgout;

    /// Dessin du repère cartésien
    // svgout.addGrid();

    /// Dessins de sphères
    svgout.addDisk(100, 100, 90, "redball");
    svgout.addDisk(300, 100, 70, "greenball");
    svgout.addDisk(200, 300, 50, "blueball");
    //svgout.addDisk(700, 100, 30, "greyball");

    /// Dessins de disques
    //svgout.addDisk(100, 300, 30, "red");
    //svgout.addDisk(300, 300, 50, "green");
    //svgout.addDisk(500, 300, 70, "blue");
    //svgout.addDisk(700, 300, 90, "grey");

    /// Dessins de croix
    svgout.addCross(200, 200, 10);

    //for (int y=50; y<400; y+=50)
        //svgout.addCross(400, y, 15);

    /// L'objet svgout est automatiquement libéré à la sortie
    /// de ce sous-programme : le fichier output.svg est alors fermé
}
