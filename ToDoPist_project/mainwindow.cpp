#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{



        if(!ui->lineEdit->text().isEmpty()){
            QTreeWidgetItem* newItem = new QTreeWidgetItem(ui->treeWidget);
            newItem->setText(0, "New Item");
        }


}

