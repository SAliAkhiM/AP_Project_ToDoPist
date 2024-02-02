#include "newactivitywindow.h"
#include "ui_newactivitywindow.h"
#include <QCheckBox>
newactivitywindow::newactivitywindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newactivitywindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a new activity");
}

newactivitywindow::~newactivitywindow(){
    delete ui;
}

QString newactivitywindow::getName(){
    return name;
}

QString newactivitywindow::getAuthor(){
    return author;
}

QDate newactivitywindow::setDate(){
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
}

QDate newactivitywindow::getDate(){
    return data;
}

bool newactivitywindow::isImp(){
    if (ui->checkBox->isChecked()==true){
        return true;
    }else{
        return false;
    }
}

void newactivitywindow::on_buttonBox_accepted(){
    name = ui->lineEdit->text();
    author = ui->lineEdit2->text();
    data = ui->dateEdit->date();
    important = ui->checkBox->isChecked();
}

