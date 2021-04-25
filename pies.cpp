#include "pies.h"

Pies::Pies()
{
    level=1;
    setPixmap(QPixmap(":/new/prefix1/Stuff/Pies1.png"));
    setPos(x()+740,y()+188);
}

void Pies::zmienKierunek(bool str)
{
    if(str && level==1)setPixmap(QPixmap(":/new/prefix1/Stuff/Pies2.png"));
    else if(!str && level==1)setPixmap(QPixmap(":/new/prefix1/Stuff/Pies1.png"));
    if(str && level==2)setPixmap(QPixmap(":/new/prefix1/Stuff/pies4.png"));
    else if(!str && level==2)setPixmap(QPixmap(":/new/prefix1/Stuff/pies3.png"));
    if(str && level==3)setPixmap(QPixmap(":/new/prefix1/Stuff/pies6.png"));
    else if(!str && level==3)setPixmap(QPixmap(":/new/prefix1/Stuff/pies5.png"));
    if(str && level==4)setPixmap(QPixmap(":/new/prefix1/Stuff/pies8.png"));
    else if(!str && level==4)setPixmap(QPixmap(":/new/prefix1/Stuff/pies7.png"));
    if(str && level==5)setPixmap(QPixmap(":/new/prefix1/Stuff/pies10.png"));
    else if(!str && level==5)setPixmap(QPixmap(":/new/prefix1/Stuff/pies9.png"));
    kierunek=str;
}

bool Pies::getKier()
{
    return kierunek;
}

void Pies::lvl2()
{
    level=2;
    setPixmap(QPixmap(":/new/prefix1/Stuff/pies3.png"));
    setPos(740,y()-32);
}

void Pies::lvl3()
{
    level=3;
    setPixmap(QPixmap(":/new/prefix1/Stuff/pies5.png"));
    setPos(740,y());
}

void Pies::lvl4()
{
    level=4;
    setPixmap(QPixmap(":/new/prefix1/Stuff/pies7.png"));
    setPos(740,y()-20);
}

void Pies::lvl5()
{
    level=5;
    setPixmap(QPixmap(":/new/prefix1/Stuff/pies9.png"));
    setPos(740,y()-18);
}
