#include "wrog.h"

Wrog::Wrog()
{
    id_w=QRandomGenerator::global()->bounded(0,3);
    id_k=QRandomGenerator::global()->bounded(0,2);
    otwiera=false;
    if(id_w==0){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/robber_2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/robber.png"));
            setScale(0.4);
        }
    }
    else if(id_w==1){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/robber1.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/robber1_2.png"));
            setScale(0.4);
        }
    }
    else{
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/robber2_2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/robber2.png"));
            setScale(0.4);
        }
    }

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout()));
    timer->start(20);
}
Wrog::~Wrog()
{
    otwiera=false;
}

void Wrog::onTimerTimeout()
{
    if(id_k==0 && !otwiera)setPos(x()+7,y());
    else if(!otwiera) setPos(x()-7,y());
    if(this->x()>700 && this->x()<800){
        otwiera=true;
    }
}

int Wrog::get_kier()
{
    return id_k;
}

bool Wrog::czyOtwiera()
{
    return otwiera;
}

void Wrog::level2()
{
    if(id_w==0){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/swat.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/swat_2.png"));
            setScale(0.4);
        }
    }
    else if(id_w==1){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/swat1.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/swat1_2.png"));
            setScale(0.4);
        }
    }
    else{
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/swat2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/swat2_2.png"));
            setScale(0.4);
        }
    }
}

void Wrog::level3()
{
    if(id_w==0){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/saper_2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/saper.png"));
            setScale(0.4);
        }
    }
    else if(id_w==1){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/saper1.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/saper1_2.png"));
            setScale(0.4);
        }
    }
    else{
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/saper2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/saper2_2.png"));
            setScale(0.4);
        }
    }
}

void Wrog::level4()
{
    if(id_w==0){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/demon_2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/demon.png"));
            setScale(0.4);
        }
    }
    else if(id_w==1){
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/demon1_2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/demon1.png"));
            setScale(0.4);
        }
    }
    else{
        if(id_k==0){
            setPixmap(QPixmap(":/new/prefix1/Stuff/demon2_2.png"));
            setScale(0.4);
        }else{
            setPixmap(QPixmap(":/new/prefix1/Stuff/demon2.png"));
            setScale(0.4);
        }
    }
}
