#ifndef LOGO_H
#define LOGO_H

#include <QPixmap>
#include <QGraphicsPixmapItem>


class Menu : public QObject, public QGraphicsPixmapItem
{
public:
    Menu();
    void showMenu();
    void showWin();
    void showLost();
    void congratulations();
};

#endif // MENU_H
