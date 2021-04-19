#include "tlo.h"

Tlo::Tlo()  //menu główne
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/menu.png"));
    showControls=true;
}

void Tlo::control() //pokazanie sterowania
{
    if(showControls){
        setPixmap(QPixmap(":/new/prefix1/Stuff/ster.png"));
        showControls=false;
    }else{
        setPixmap(QPixmap(":/new/prefix1/Stuff/menu.png"));
        showControls=true;
    }
}

void Tlo::level1() //poziom 1
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo1.png"));
}

void Tlo::level2() //poziom 2
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo2.png"));
}

void Tlo::level3()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo3.png"));
}

void Tlo::level4()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo4.png"));
}
