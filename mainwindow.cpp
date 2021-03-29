#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    speed=30;
    this->time=0;
    level=1;
    inGame=false;
    blockUi=false;
    delay=false;

    tlo=new Tlo();
    menu=new Menu();
    brama=new Brama();

    fx=new QMediaPlayer();
    fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/Megadeth-DukeNukemThemeShort.wav"));
    fx->setVolume(20);
    fx->play();

    scene=new QGraphicsScene();
    scene->addItem(brama);
    scene->addItem(tlo);
    scene->addItem(menu);

    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawning())); //losowanie spawnu
    setFixedSize(size());

    //level=3;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::play()
{
    fx->stop();
    if(level==1)fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/Megadeth-DukeNukemThemeShort.wav")); //ost lvl1
    else if(level==2) fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level2theme.wav")); //ost lvl2
    else if(level==3) fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/God_Syria_and_Bashar.wav")); //ost lvl3
    fx->play();
    blockUi=true;
    inGame=true;
    lost=false;
    pies=new Pies();
    wrog=new Wrog();
    scene->removeItem(menu);
    brama->setPos(0,320);
    brama->clear();//usunięcie pozostałych przeciwników
    scene->addItem(pies); //piesek
    if(level==1){
        tlo->level1();
        pies->setPos(x()+740,y()+188);
    }
    else if(level==2){
        tlo->level2();
        brama->level2();
        pies->setPos(x()+740,y()+155);
        pies->lvl2();
    }
    else if(level==3){
        tlo->level3();
        brama->level3();
        pies->setPos(x()+740,y()+188);
        pies->lvl3();
    }

    timer->start(600);
}

void MainWindow::spawning()
{
    if(QRandomGenerator::global()->bounded(0,3)==2){
        wrog=new Wrog();
        if(level==2)wrog->level2();
        else if(level==3)wrog->level3();
        scene->addItem(wrog);
        if(wrog->get_kier()==0) wrog->setPos(x()-900,y()+600); //spawn z lewej
        else wrog->setPos(x()+1500,y()+600); //spawn z prawej
    }
    //wygrana
    if(fx->state()==QMediaPlayer::StoppedState){
        timer->stop();
        QTimer::singleShot(4000,this,SLOT(win()));
    }
    //przegrana
    if(brama->y()<=-80){
        timer->stop();
        QTimer::singleShot(1000,this,SLOT(lose()));
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A && inGame)
    {
        if(pies->x()<0) return; //pies->setPos(pies->x()+speed,pies->y());
        else pies->setPos(pies->x()-speed,pies->y());

        if(!event->isAutoRepeat())pies->zmienKierunek(0);
    }
    if(event->key()==Qt::Key_D && inGame)
    {
        if(pies->x()>1300) return;//pies->setPos(pies->x()-speed,pies->y());
        else pies->setPos(pies->x()+speed,pies->y());

        if(!event->isAutoRepeat())pies->zmienKierunek(1);
    }
    if(event->key()==Qt::Key_C && inGame)
    {
        if(!delay){
            pustak=new Pustak();
            scene->addItem(pustak);
            if(pies->getKier()) pustak->setPos(pies->x()+130,pies->y());
            else pustak->setPos(pies->x(),pies->y());
            delay=true; //antyspam do pustaków
            QTimer::singleShot(700,this,SLOT(unlock())); //delay między pustakami
        }
    }
    if(event->key()==Qt::Key_P && !event->isAutoRepeat() && !blockUi) play(); //zacznij grę
    if(event->key()==Qt::Key_S && !blockUi) tlo->control();  //pokaż/schowaj sterowanie
    if(event->key()==Qt::Key_Q && !blockUi) QApplication::quit(); //wyjdź
    if(event->key()==Qt::Key_N && !inGame && !lost) play(); //przejdź do następnego poziomu
    if(event->key()==Qt::Key_R && lost){
        lost=false;
        play(); //restart danego poziomu
    }
}

void MainWindow::win()
{
    fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/Team Fortress 2 Music Flourish.mp3"));
    fx->setVolume(100);
    fx->play();
    if(level!=3)menu->showWin();    //zakończenie gry
    else menu->congratulations(); //zakończenie poziomu
    scene->addItem(menu);
    delete pies;
    inGame=false;
    level++;
}

void MainWindow::lose()
{
    fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/lose.wav"));
    fx->setVolume(100);
    fx->play();
    menu->showLost();
    scene->addItem(menu);
    delete pies;
    inGame=false;
    lost=true;
}

void MainWindow::unlock()
{
    delay=false;
}

// ***---------------------------------------------------***
// |#######     Pierwsza kompilacja 26.01.2021      #######|
// |#####           Final build --.--.----            #####|
// |#######   Cinderblock Warrior by Wojtuś Pela    #######|
// **-----------------------------------------------------**

