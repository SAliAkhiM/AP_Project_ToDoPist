#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listmanager.h"
#include "listwidget_mainwindow.h"
#include "activity.h"
#include "activityinfo.h"
#include <QDate>
#include <QErrorMessage>
#include <QMessageBox>
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    listModel = new QStandardItemModel();
    this->setWindowTitle("ToDo List");
    lastRowSelectedList = 0;
    lastRowSelectedActivities = 0;
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

