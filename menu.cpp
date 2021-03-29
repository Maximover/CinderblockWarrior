#include "menu.h"

Menu::Menu()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/ui.png"));
    //setRotation(350);
    setScale(1);
}

void Menu::showWin()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/win.png"));
    setScale(1);
}

void Menu::showLost()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/youlost.png"));
    setScale(1);
}

void Menu::congratulations()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/congrats.png"));
    setScale(1);
}
