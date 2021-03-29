#ifndef PUSTAK_H
#define PUSTAK_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QtCore>
#include "wrog.h"

class Pustak : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pustak();
    QTimer *timer;
    QMediaPlayer *player;
private slots:
    void onTimerTimeout();
};

#endif // PUSTAK_H
