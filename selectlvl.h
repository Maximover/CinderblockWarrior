#ifndef SELECTLVL_H
#define SELECTLVL_H

#include <QDialog>

namespace Ui {
class Selectlvl;
}

class Selectlvl : public QDialog
{
    Q_OBJECT

public:
    explicit Selectlvl(QWidget *parent = nullptr);
    ~Selectlvl();

    int getLvl();
    void increase();

private slots:
    void on_ok_clicked();
private:
    Ui::Selectlvl *ui;
    int selected;
};

#endif // SELECTLVL_H
