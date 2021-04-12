#include "brama.h"
Brama::Brama()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/brama.png"));
    setScale(1);

    speed = 300;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(podniesBrame()));
    timer->start(speed);
}

void Brama::level2()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/brama2.png"));
    setScale(1);
    timer->start(speed);
}
void Brama::level3()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/brama3.png"));
    setScale(1);
    timer->start(speed);
}

void Brama::level4()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/brama4.png"));
    setScale(1);
    timer->start(speed);
}

void Brama::clear()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Wrog)){
            delete colliding_items[i];
        }
    }
}

void Brama::podniesBrame()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Wrog)){
            setPos(this->x(),this->y()-5);
            if(this->y()<=-225) timer->stop();
            return;
        }
    }
}



