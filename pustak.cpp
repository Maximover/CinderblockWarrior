#include "pustak.h"

Pustak::Pustak()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/pustak.png"));
    setScale(0.18);

    player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/new/prefix1/Stuff/boonk.wav"));
    player->setVolume(80);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout()));
    timer->start(20);
}

void Pustak::onTimerTimeout()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Wrog)){
            player->play();
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()+40);
    if(pos().y()>880){
        scene()->removeItem(this);
        delete this;
    }
}
