#ifndef SIGN_UP_PAGE_H
#define SIGN_UP_PAGE_H

#include <QDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QAbstractSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>
#include <QDir>
#include <vector>

namespace Ui {
class Sign_up_page;
}

class Sign_up_page : public QDialog
{
    Q_OBJECT

signals:
    void newMessage(QString);

public:
    explicit Sign_up_page(QWidget *parent = nullptr);
    ~Sign_up_page();

private slots:
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);

    //void displayMessage(const QString& str);
    void on_signUp_clicked();

    void on_LogIn_clicked();

private:
    Ui::Sign_up_page *ui;
    QTcpSocket* socket;

};

#endif // SIGN_UP_PAGE_H
