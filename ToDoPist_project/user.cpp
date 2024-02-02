#include "user.h"


user::user(QWidget *parent) :
    QMainWindow(parent){


    this->name = "";
    this->username = "";
    this->password = "";
    this->email = "";

    this->level = 1;
    this->experience = 0;
    this->coin = 20;


//    ui->Experience_lbl->setText(QString::number(this->experience));
//    ui->Name_lbl->setText(this->name);
////    ui->Num_Coins_lbl->setText(QString::number(this->coin));
//    ui->UserName_lbl->setText(this->username);
//    ui->Level_lbl->setText(QString::number(this->level));

}

user::user(const user& p){
    operator=(p);
}

user::~user()
{
    //delete ui;
}

void user::operator=(const user& u){
    name = u.name;
    username = u.username;
    password = u.password;
    email = u.email;
    coin = u.coin;
    level = u.level;
    experience = u.experience;
    experience_required_for_levelUp = u.experience_required_for_levelUp;
   // farm = p.farm;
}

void user::set_name(QString _name)
{
    name = _name;
}

QString user::get_name()const
{
    return name;
}

void user::set_username(QString _username)
{
    username = _username;
}

QString user::get_username()const
{
    return username;
}

void user::set_password(QString _password)
{
    password = _password;
}

QString user::get_password()const{
    return password;
}

void user::set_email(QString _email){
    email = _email;
}
QString user::get_email()const{
    return email;
}

void user::set_coin(int _coin){
    coin = _coin;
}

int user::get_coin()const{
    return coin;
}

void user::set_level(int _level){
    level = _level;
}

int user::get_level()const{
    return level;
}

void user::set_experience(int _experience){
    experience = _experience;
}

int user::get_experience()const{
    return experience;
}

void user::set_experience_required_for_levelUp(int _e){
    experience_required_for_levelUp = _e;
}

int user::get_experience_required_for_levelUp()const{
    return experience_required_for_levelUp;
}
