#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    speed=6;
    this->time=0;
    inGame=false;
    blockUi=false;
    delay=false;

    tlo=new Tlo();
    menu=new Menu();
    brama=new Brama();

    fx=new QMediaPlayer();
    fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level1theme.wav"));
    fx->setVolume(20);
    fx->play();
    scene=new QGraphicsScene();
    scene->addItem(brama);
    scene->addItem(tlo);
    scene->addItem(menu);

    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawning())); //losowanie spawnu
    move = new QTimer(this);
    connect(move,SIGNAL(timeout()),this,SLOT(pressingKeys()));
    move->start(10);

    ui->graphicsView->horizontalScrollBar()->setValue(1);
    ui->graphicsView->verticalScrollBar()->setValue(1);
    ui->graphicsView->horizontalScrollBar()->blockSignals(true);
    ui->graphicsView->verticalScrollBar()->blockSignals(true);
    setFixedSize(size());

    level=1;
    maxLevels=5;
    select = new Selectlvl();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::play()
{
    pies=new Pies();
    wrog=new Wrog();
    level=select->getLvl();
    switch(level){
    case 1:
        tlo->level1();
        fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level1theme.wav"));
        break;
    case 2:
        tlo->level2();
        brama->level2();
        pies->lvl2();
        fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level2theme.wav"));
        break;
    case 3:
        tlo->level3();
        brama->level3();
        pies->lvl3();
        fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level3theme.wav"));
        break;
    case 4:
        tlo->level4();
        brama->level4();
        pies->lvl4();
        fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level4theme.wav"));
        break;
    case 5:
        tlo->level5();
        brama->level5();
        pies->lvl5();
        fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/level5theme.mp3"));
        break;
    }
    fx->stop();
    blockUi=true;
    inGame=true;
    lost=false;
    scene->removeItem(menu);
    brama->clear();//usunięcie pozostałych przeciwników
    scene->addItem(pies); //piesek
    fx->play();
    timer->start(600);
}

void MainWindow::spawning()
{
    if(QRandomGenerator::global()->bounded(0,3)==2){
        wrog=new Wrog();
        switch(level){
            case 2:
                wrog->level2();
                break;
            case 3:
                wrog->level3();
                break;
            case 4:
                wrog->level4();
                break;
            case 5:
                wrog->level5();
                break;
        }
        scene->addItem(wrog);
        if(wrog->get_kier()==0) wrog->setPos(x()-700,y()+600); //spawn z lewej
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
void MainWindow::pressingKeys()
{
    if(keys[Qt::Key_A] && inGame){
        if(pies->x()<0) return;
        else pies->setPos(pies->x()-speed,pies->y());
        pies->zmienKierunek(0);
    }
    if(keys[Qt::Key_D] && inGame){
        if(pies->x()>1280) return;
        else pies->setPos(pies->x()+speed,pies->y());
        pies->zmienKierunek(1);
    }
    if(keys[Qt::Key_C] && inGame)
    {
        if(!delay){
            pustak=new Pustak();
            scene->addItem(pustak);
            if(pies->getKier()) pustak->setPos(pies->x()+130,pies->y()+80);
            else pustak->setPos(pies->x(),pies->y()+80);
            delay=true; //antyspam do pustaków
            QTimer::singleShot(700,this,SLOT(unlock())); //delay między pustakami
        }
        return;
    }
    if(keys[Qt::Key_S] && !blockUi) tlo->control();  //pokaż/schowaj sterowanie
    if(keys[Qt::Key_Q] && !blockUi) QApplication::quit(); //wyjdź
    if((keys[Qt::Key_N] || keys[Qt::Key_P]) && !inGame && !lost && level!=maxLevels+1) play(); //przejdź do następnego poziomu
    if(keys[Qt::Key_R] && lost){
        lost=false;
        play(); //restart danego poziomu
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())return;
    keys[event->key()]=true;
    /*
    if(keys[Qt::Key_M] && !inGame){
        tlo->menu();
        brama->clear();
        blockUi=false;
        menu->showMenu();
    }
    */
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())return;
    if(keys[Qt::Key_X] && !blockUi && !delay){
        delay=true;
        QTimer::singleShot(5000,this,SLOT(unlock()));
        select->setModal(true);
        select->exec();
    }
    keys[event->key()]=false;
}

void MainWindow::win()
{
    fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/Team Fortress 2 Music Flourish.mp3"));
    fx->setVolume(50);
    fx->play();
    if(level!=maxLevels) menu->showWin();
    else menu->congratulations();
    scene->addItem(menu);
    delete pies;
    inGame=false;
    level++;
    select->increase();
}

void MainWindow::lose()
{
    fx->setMedia(QUrl("qrc:/new/prefix1/Stuff/lose.wav"));
    fx->setVolume(50);
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
