#include "mainwindow.h"
#include "sign_up_page.h"
#include <QApplication>
#include <QPropertyAnimation>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Sign_up_page * su= new Sign_up_page();
    su->show();
    return a.exec();

}
