#include "tlo.h"

Tlo::Tlo()  //menu główne
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/menu.png"));
    setScale(1);
    showControls=true;
}

void Tlo::control() //pokazanie sterowania
{
    if(showControls){
        setPixmap(QPixmap(":/new/prefix1/Stuff/ster.png"));
        setScale(1);
        showControls=false;
    }else{
        setPixmap(QPixmap(":/new/prefix1/Stuff/menu.png"));
        setScale(1);
        showControls=true;
    }
}

void Tlo::level1() //poziom 1
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo1.png"));
    setScale(1);
}

void Tlo::level2() //poziom 2
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo2.png"));
    setScale(1);
}

void Tlo::level3()
{
    setPixmap(QPixmap(":/new/prefix1/Stuff/Tlo3.png"));
    setScale(1);
}
