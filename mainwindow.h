#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QTimer>
#include <QtCore>
#include <QString>
#include <QPixmap>
#include <QPointF>
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
#include "selectlvl.h"

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
    void keyReleaseEvent(QKeyEvent *event);
private slots:
    void play();
    void spawning();
    void unlock();
    void win();
    void lose();
    void pressingKeys();
private:
    Ui::MainWindow *ui;
    qint64 time;
    QTimer *timer;
    QTimer *move;
    QMap<int, bool>keys;
    QGraphicsScene *scene;
    QMediaPlayer *fx;
    Pies *pies;
    Tlo *tlo;
    Wrog *wrog;
    Pustak *pustak;
    Menu *menu;
    Brama *brama;
    Selectlvl *select;
    int speed;
    int level;
    int maxLevels;
    bool delay;
    bool blockUi;
    bool lost;
    bool inGame;
};
#endif // MAINWINDOW_H
