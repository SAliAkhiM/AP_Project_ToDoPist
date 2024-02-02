#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "user.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


using namespace std;


class Data
{

private:
    static QVector<user>::iterator it;
    static QVector<user> users;

public:
    static void set_iterator(QVector<user>::iterator _it){ it=_it; }

    static QVector<user>::iterator& get_iterator(){ return it; }

    static void set_players(QVector<user>& _users){ users=_users; }

    static QVector<user>& get_players() { return users; }


    static void write_on_file() {
        QFile f("Players.json");
        f.open(QIODevice::ReadOnly);
        QJsonDocument d = QJsonDocument::fromJson(f.readAll());
        f.close();
        QJsonObject o = d.object();
        QJsonObject temp = o[get_iterator()->get_username()].toObject();
        temp["Name"] = get_iterator()->get_name();
        temp["Username"] = get_iterator()->get_username();
        temp["Password"] = get_iterator()->get_password();
        temp["Email"] = get_iterator()->get_email();
        temp["Coin"] = get_iterator()->get_coin();
        temp["Level"] = get_iterator()->get_level();
        temp["Experience"] = get_iterator()->get_experience();
        o[get_iterator()->get_username()] = temp;
        d.setObject(o);
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();
    }
};

#endif // DATA_H
