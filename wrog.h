#ifndef WROG_H
#define WROG_H

#include <QPixmap>
#include <QTimer>
#include <QtCore>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Wrog : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private slots:
    void onTimerTimeout();
public:
    Wrog();
    int id_w;
    int id_k;
    bool otwiera;
    QTimer *timer;
    int get_kier();
    bool czyOtwiera();
    void level2();
    void level3();

    ~Wrog();
};

#endif // WROG_H
