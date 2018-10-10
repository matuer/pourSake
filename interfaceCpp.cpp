#include "interfaceCpp.h"

void displayMenu(std::vector<Sphere> systemeSolaire)
{
    size_t i = 0;
    printf("=======MENU=======");
    std::cout << "\n  - Ajouter un astre" << std::endl;
    for(i = 0 ; i < systemeSolaire.size() ; i++)
    {
        systemeSolaire[i].displaySphere();
    }
}

int menu(std::vector<Sphere> systemeSolaire)
{
    displayMenu(systemeSolaire);
    return navigationMenu(systemeSolaire);
}

void curseurParametres(int x, int y)
{
    gotoxy(x, y);
    printf(">");
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clsCurseurParametres(int x, int y)
{
    gotoxy(x, y);
    printf("-");
}

int navigationMenu(std::vector<Sphere> systemeSolaire)
{
    int event;
    size_t x = 2, y = 1, x0, y0;

    system("cls");
    gotoxy(0, 0);
    displayMenu(systemeSolaire);

    while(event != ' ' && event != 13) //Si l'utilisateur valide avec espace ou entrer
    {
        x0 = x;
        y0 = y;
        curseurParametres(x, y);
        event = getch();
        fflush(stdin);
        blindage(&event);
        switch(event)
        {
        case 'Z':
            if(y > 1)
                y--;
            break;
        case 'S':
            if(y < systemeSolaire.size()+1)
                y++;
            break;
        }
        clsCurseurParametres(x0, y0);
    }
    return y;
}

void blindage(int* event)
{
    switch(*event)
    {
    case '&':
        *event = '1';
        return;
    case 130:
        *event = '2';
        return;
    case '"':
        *event = '3';
        return;
    case '\'':
        *event = '4';
        return;
    case UP:
        *event = 'Z';
        return;
    case LEFT:
        *event = 'Q';
        return;
    case RIGHT:
        *event = 'D';
        return;
    case DOWN:
        *event = 'S';
        return;
    }
    if(*event >= 'a' && *event <= 'z')
    {
        *event -= 32;
        return;
    }
}
