#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCore>
#include <QString>
#include <QPixmap>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QPushButton>
#include <QVBoxLayout>
#include "pies.h"
#include "tlo.h"
#include "wrog.h"
#include "pustak.h"
#include "menu.h"
#include "brama.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void play();
    void spawning();
    void unlock();
    void win();
    void lose();
private:
    Ui::MainWindow *ui;
    qint64 time;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QMediaPlayer *fx;
    Pies *pies;
    Tlo *tlo;
    Wrog *wrog;
    Pustak *pustak;
    Menu *menu;
    Brama *brama;
    int speed;
    int level;
    bool delay;
    bool blockUi;
    bool lost;
    bool inGame;
};
#endif // MAINWINDOW_H
