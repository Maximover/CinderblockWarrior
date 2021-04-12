#ifndef PIES_H
#define PIES_H

#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Pies : public QObject, public QGraphicsPixmapItem
{
public:
    Pies();
    bool kierunek;
    void zmienKierunek(bool);
    bool getKier();
    int level;
    void lvl2();
    void lvl3();
    void lvl4();

};

#endif // PIES_H
