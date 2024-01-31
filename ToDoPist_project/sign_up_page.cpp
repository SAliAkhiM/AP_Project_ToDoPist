#include "sign_up_page.h"
#include "ui_sign_up_page.h"

Sign_up_page::Sign_up_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_up_page)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(this, &Sign_up_page::newMessage, this, &Sign_up_page::displayMessage);
    connect(socket, &QTcpSocket::readyRead, this, &Sign_up_page::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &Sign_up_page::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &Sign_up_page::displayError);

    socket->connectToHost(QHostAddress::LocalHost,8080);

    if(socket->waitForConnected())
        qDebug()<<"Connected to Server";
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        exit(EXIT_FAILURE);
    }
}

Sign_up_page::~Sign_up_page()
{
    if(socket->isOpen())
        socket->close();
    delete ui;
}
void Sign_up_page::discardSocket()
{
    socket->deleteLater();
    socket=nullptr;
    qDebug()<< "Disconnected!";
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

