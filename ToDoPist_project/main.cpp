#include "mainwindow.h"
#include "Logo.h"
#include <QApplication>
#include <QPropertyAnimation>
#include "user.h"
#include "Data.h"

QVector<user>::iterator Data::it;
QVector<user> Data::users;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logo logo;
    logo.show();
    return a.exec();

}
