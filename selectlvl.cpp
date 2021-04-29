#include "selectlvl.h"
#include "ui_selectlvl.h"

Selectlvl::Selectlvl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selectlvl)
{
    ui->setupUi(this);

    selected=1;
    ui->lvl1->setChecked(true);

}

Selectlvl::~Selectlvl()
{
    delete ui;
}

int Selectlvl::getLvl()
{
    return selected;
}

void Selectlvl::increase()
{
    selected++;
}

void Selectlvl::on_ok_clicked()
{
    if(ui->lvl1->isChecked()){
        selected=1;
    }
    else if(ui->lvl2->isChecked()){
        selected=2;
    }
    else if(ui->lvl3->isChecked()){
        selected=3;
    }
    else if(ui->lvl4->isChecked()){
        selected=4;
    }
    else if(ui->lvl5->isChecked()){
        selected=5;
    }
    this->close();
}
