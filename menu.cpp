#include "menu.h"

Menu::Menu()
{
    showMenu();
}

void Menu::showMenu()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/ui.png"));
}

void Menu::showWin()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/win.png"));
}

void Menu::showLost()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/youlost.png"));
}

void Menu::congratulations()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/congrats.png"));
}
