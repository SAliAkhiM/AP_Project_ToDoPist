#include "newlistwindow.h"
#include "ui_newlistwindow.h"


newlistwindow::newlistwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newlistwindow){
    ui->setupUi(this);
    this->setWindowTitle("Add a new list");
}

newlistwindow::~newlistwindow(){
    delete ui;
}

QString newlistwindow::getName(){
    return name;
}

QString newlistwindow::getType(){
    return type;
}

void newlistwindow::on_buttonBox_accepted(){
    name = ui->lineEdit->text();
    type = ui->lineEdit2->text();
}
