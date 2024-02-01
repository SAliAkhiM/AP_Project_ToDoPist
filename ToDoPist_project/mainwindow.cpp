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
    ui->treeWidget->setWindowTitle("List Widget with Combo Boxes");

    // Create the first combo box with colors


        if(!ui->lineEdit->text().isEmpty()){
        comboBox1->addItems({ui->lineEdit->text(), "Project", "Member","Edit","Manage Team"});
        }

        QListWidgetItem *item1 = new QListWidgetItem;
           ui->listWidget->addItem(item1);
           ui->listWidget->setItemWidget(item1, comboBox1);

}

