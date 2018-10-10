#ifndef interfaceCpp
#define interfaceCpp

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sphere.h"

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

void displayMenu(std::vector<Sphere> systemeSolaire);
void gotoxy(int x, int y);
int navigationMenu(std::vector<Sphere> systemeSolaire);
void curseurParametres(int x, int y);
void clsCurseurParametres(int x, int y);
void blindage(int* event);
int menu(std::vector<Sphere> systemeSolaire);


#endif // interfaceCpp
