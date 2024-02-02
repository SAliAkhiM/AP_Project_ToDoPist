#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include "newlistwindow.h"
#include "newactivitywindow.h"
#include "activityinfo.h"
#include <QListWidgetItem>
#include <QListWidget>
#include "listwidget_mainwindow.h"
#include "listmanager.h"
#include "activity.h"
#include <QDate>
#include <QErrorMessage>
#include <QMessageBox>



#include <QMainWindow>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    QStandardItemModel *listModel;
    newlistwindow* newList;
    newactivitywindow* newActivity;
    activityinfo* windowActivity;
    std::vector<List> arrayListe;
    int lastRowSelectedList;
    int lastRowSelectedActivities;

};
#endif // MAINWINDOW_H
