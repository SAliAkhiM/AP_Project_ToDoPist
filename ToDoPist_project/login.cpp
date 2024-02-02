#include "login.h"
#include "ui_login.h"
#include <QRadioButton>
#include <QMessageBox>
#include <fstream>
#include "Data.h"
#include "user.h"
#include "sign_up_page.h"
#include "mainwindow.h"

LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);

    setFixedSize(358, 333);

//    QPixmap qpm(":/background/backgrounds/istockphoto-520123098-612x612.png");
//    qpm = qpm.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette qp;
//    qp.setBrush(QPalette::Window, qpm);
//    this->setPalette(qp);

    QFile f("Players.json");
    f.open(QIODevice::ReadOnly);
    if (f.isOpen() && Data::get_players().isEmpty()) {
        QJsonDocument d = QJsonDocument::fromJson(f.readAll());
        QJsonObject o = d.object();
        QJsonObject temp;
        user u;
        QStringList sl = o.keys();
        for (int i = 0; i < sl.size(); i++) {
            temp = o[sl[i]].toObject();
            u.set_name(temp["Name"].toString());
            u.set_username(temp["Username"].toString());
            u.set_password(temp["Password"].toString());
            u.set_email(temp["Email"].toString());


            Data::get_players().append(u);

            qDebug() <<"time :::" << time(NULL);
        }
    }
    f.close();


}

LogIn::~LogIn()
{
    delete ui;
}



void LogIn::on_radioButton_toggled(bool checked)
{
    QIcon hideicon(":/icon/hide.png");
    QIcon showicon(":/icon/show.png");

    if(checked){
        ui->password->setEchoMode(QLineEdit::Normal);
        ui->radioButton->setIcon(showicon);
    }
    else{
        ui->password->setEchoMode(QLineEdit::Password);
        ui->radioButton->setIcon(hideicon);

    }
}


void LogIn::on_pushButton_clicked()
{
    if (ui->username->text().isEmpty() || ui->password->text().isEmpty()) {
        QMessageBox::warning(this, "Error!", "Username and password cannot be empty!");
        return;
    }
    for (int i = 0; i < (Data::get_players()).size(); i++)
        if (ui->username->text() == Data::get_players()[i].get_username()) {
            if (ui->password->text() == Data::get_players()[i].get_password()) {
                Data::set_iterator(Data::get_players().begin() + i);
                this->close();

//                Data::get_iterator()->get_farm().Get_MyThread().set_first_SizeofMilk(Data::get_iterator()->get_farm().get_storage().Get_milk().Get_Number());
//                Data::get_iterator()->get_farm().Get_MyThread().start();

//                Data::get_iterator()->get_farm().Show_Farm_Class();
//                Data::get_iterator()->get_farm().show();
                return;
            }
            else {
                QMessageBox::warning(this, "تذکر", "رمز عبور اشتباه است!");
                return;
            }
        }
//    QMessageBox::warning(this, "تذکر", "نام کاربری یافت نشد!");
//    this->close();
//    MainWindow* m = new MainWindow;
//    m->show();
}


void LogIn::on_pushButton_2_clicked()
{
    Sign_up_page* su = new Sign_up_page();
    this->close();
    su->show();
}

