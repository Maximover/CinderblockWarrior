#ifndef TLO_H
#define TLO_H

#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Tlo : public QObject, public QGraphicsPixmapItem
{
public:
    Tlo();
    void menu();
    void control();
    void level1();
    void level2();
    void level3();
    void level4();
    void level5();

    bool showControls;

};

#endif // TLO_H
