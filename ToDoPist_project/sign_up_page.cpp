#include "sign_up_page.h"
#include "ui_sign_up_page.h"
#include "mainwindow.h"
#include "user.h"
#include "login.h"


Sign_up_page::Sign_up_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_up_page)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    //connect(this, &Sign_up_page::newMessage, this, &Sign_up_page::displayMessage);
    connect(socket, &QTcpSocket::readyRead, this, &Sign_up_page::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &Sign_up_page::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &Sign_up_page::displayError);

    socket->connectToHost("172.27.105.127",5713);

//    if(socket->waitForConnected())
//        qDebug()<<"Connected to Server";
//    else{
//        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
//        exit(EXIT_FAILURE);
//    }
//    setFixedSize(300, 358);

//    QPixmap qpm(":/background/backgrounds/istockphoto-1127237731-612x612 (1).png");
//    qpm = qpm.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette qp;
//    qp.setBrush(QPalette::Window, qpm);
//    this->setPalette(qp);

}

Sign_up_page::~Sign_up_page()
{
//    if(socket->isOpen())
//        socket->close();
    delete ui;
}
void Sign_up_page::discardSocket()
{
//    socket->deleteLater();
//    socket=nullptr;
//    qDebug()<< "Disconnected!";
}

void Sign_up_page::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}


void Sign_up_page::on_signUp_clicked()
{
    if (ui->userName->text().isEmpty() || ui->password->text().isEmpty()) {
        QMessageBox::warning(this, "Error!", "UserName and Password cannot be empty!");
        return;
    }
    else{
        QString folderPath = QDir::currentPath()+"/Users";
        QDir().mkpath(folderPath);
        QDir dir(folderPath);
        QStringList fileList = dir.entryList(QDir::Files);
        //qDebug()<<fileList;
        if(fileList.contains(ui->userName->text()+".json")){
            QMessageBox::warning(this, "Error!", "Duplicate Username! Try another one...");
            return;

        }
        else{
            QJsonObject jsonObj;
            jsonObj["userName"] = ui->userName->text();
            jsonObj["firstName"] = ui->firstName->text();
            jsonObj["lastName"] = ui->lastName->text();
            jsonObj["password"] = ui->password->text();
            QJsonDocument jsonDoc(jsonObj);

            QFile f(QDir::currentPath()+"/Users/"+ui->userName->text()+".json");
            f.open(QIODevice::WriteOnly);
            f.write(jsonDoc.toJson());
            //qDebug()<< QDir::currentPath();
            user p;
//            p.set_name(ui->nameLE->text());
//            p.set_username(ui->usernameLE->text());
//            p.set_password(ui->passLE->text());
//            p.set_email(ui->emailLE->text());
//            p.set_coin(20);
//            p.set_level(1);
//            p.set_experience(0);
//            p.set_experience_required_for_levelUp(2 * p.get_experience() + 10);
//            p.get_farm().Get_MyThread().Set_time_login(time(NULL));
//            Data::get_players().append(p);

//            QFile f("Players.json");
//            f.open(QIODevice::ReadOnly);
//            QJsonDocument d = QJsonDocument::fromJson(f.readAll());
//            f.close();
//            QJsonObject o = d.object();
//            QJsonObject temp;
//            temp["Name"] = p.get_name();
//            temp["Username"] = p.get_username();
//            temp["Password"] = p.get_password();
//            temp["Email"] = p.get_email();
//            temp["Coin"] = p.get_coin();
//            temp["Level"] = p.get_level();
//            temp["Experience"] = p.get_experience();
//            temp["Experience required for levelUp"] = p.get_experience_required_for_levelUp();
//            temp["SignUp time"] = p.get_farm().Get_MyThread().Get_time_login();
//            temp["last_time_set"] = p.get_farm().Get_MyThread().Get_last_time_set();
//            temp["upgrade_Storage time"] = 0;
//            temp["upgrade_Siloo time"] = 0;
//            temp["buy_Milk time"] = 0;
//            temp["ChickenHome is build"] = false;
//            temp["CowHome is build"] = false;
//            temp["SheepHome is build"] = false;
//            temp["YonjehFarm is build"] = false;
//            temp["YonjehFarm is plantable"] = false;
//            temp["upgrade_ChickenHome time"] = 0;
//            temp["build_ChickenHome time"] = 0;
//            temp["feed_time_chicken"] = 0;
//            temp["upgrade_CowHome time"] = 0;
//            temp["build_CowHome time"] = 0;
//            temp["feed_time_cow"] = 0;
//            temp["upgrade_SheepHome time"] = 0;
//            temp["build_SheepHome time"] = 0;
//            temp["feed_time_sheep"] = 0;
//            temp["upgrade_Gandomfarm time"] = 0;
//            temp["Collect_from_GandomFarm time"] = 0;
//            temp["Planting_from_GandomFarm time"] = 0;
//            temp["Planting_from_YonjeFarm time"] = 0;
//            temp["upgrade_Yonjehfarm time"] = 0;
//            temp["Collect_from_YonjehFarm time"] = 0;
//            temp["Build_YonjehFarm time"] = 0;
//            temp["Plow_YonjehFarm time"] = 0;
//            temp["Mikh number"] = 1;
//            temp["Bill number"] = 0;
//            temp["Yonjeh number"] = 1;
//            temp["Egg number"] = 0;
//            temp["Milk number"] = 0;
//            temp["Pashm number"] = 0;
//            temp["Storage capacity"] = 5;
//            temp["Storage level"] = 1;
//            temp["Storage occupied capacity"] = 2;
//            temp["Gandom number"] = 1;
//            temp["Siloo capacity"] = 10;
//            temp["Siloo level"] = 1;
//            temp["Siloo occupied capacity"] = 1;
//            temp["ChickenHome capacity"] = 0;
//            temp["ChickenHome level"] = 1;
//            temp["ChickenHome stock"] = 0;
//            temp["CowHome capacity"] = 0;
//            temp["CowHome level"] = 1;
//            temp["CowHome stock"] = 0;
//            temp["SheepHome capacity"] = 0;
//            temp["SheepHome level"] = 1;
//            temp["SheepHome stock"] = 0;
//            temp["GandomFarm area"] = 5;
//            temp["GandomFarm level"] = 1;
//            temp["YonjehFarm area"] = 4;
//            temp["YonjehFarm level"] = 1;
//            o[p.get_username()] = temp;
//            d.setObject(o);
//            f.open(QIODevice::WriteOnly);
//            f.write(d.toJson());
//            f.close();
            QMessageBox::information(this, "تکمیل ثبت نام", "ثبت نام شما با موفقیت انجام شد");

        }

    }
}

void Sign_up_page::readSocket()
{
    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

    socketStream.startTransaction();
    socketStream >> buffer;

    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
        emit newMessage(message);
        return;
    }

    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);

    if(fileType=="attachment"){
        QString fileName = header.split(",")[1].split(":")[1];
        QString ext = fileName.split(".")[1];
        QString size = header.split(",")[2].split(":")[1].split(";")[0];

        if (QMessageBox::Yes == QMessageBox::question(this, "QTCPServer", QString("You are receiving an attachment from sd:%1 of size: %2 bytes, called %3. Do you want to accept it?").arg(socket->socketDescriptor()).arg(size).arg(fileName)))
        {
            QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+fileName, QString("File (*.%1)").arg(ext));

            QFile file(filePath);
            if(file.open(QIODevice::WriteOnly)){
                file.write(buffer);
                QString message = QString("INFO :: Attachment from sd:%1 successfully stored on disk under the path %2").arg(socket->socketDescriptor()).arg(QString(filePath));
                emit newMessage(message);
            }else
                QMessageBox::critical(this,"QTCPServer", "An error occurred while trying to write the attachment.");
        }else{
            QString message = QString("INFO :: Attachment from sd:%1 discarded").arg(socket->socketDescriptor());
            emit newMessage(message);
        }
    }else if(fileType=="message"){
        QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
        emit newMessage(message);
    }
}

void Sign_up_page::on_back_clicked()
{
    LogIn* li = new LogIn();
    this->close();
    li->show();
}

