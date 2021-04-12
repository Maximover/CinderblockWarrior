#ifndef BRAMA_H
#define BRAMA_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QtCore>
#include "wrog.h"

class Brama : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void podniesBrame();
public:
    Brama();
    int speed;
    QTimer *timer;
    void level2();
    void level3();
    void level4();

    void clear();
};

#endif // BRAMA_H
