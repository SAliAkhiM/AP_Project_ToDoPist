#include "Logo.h"
#include "ui_logo.h"
#include "login.h"

Logo::Logo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint);//Rimless //remove exit, minimize and maximize buttons

    setAttribute(Qt::WA_TranslucentBackground);//Transparent background


    QMovie *movie = new QMovie(":/Background/f1 car gif.gif");

    ui->lbl_gif->setMovie(movie);

    movie->start();

    t1 = new QTimer(this);
    t1->setInterval(3500);
    connect(t1, SIGNAL(timeout()), this, SLOT(logo_show()));
    t1->start();

    t2 = new QTimer(this);
    t2->setInterval(600);
    connect(t2, SIGNAL(timeout()), this, SLOT(set_text()));
    t2->start();

    timer = 0;
}

Logo::~Logo()
{
    delete ui;
}

void Logo::logo_show()
{
    t1->stop();
    this->close();
    LogIn* login = new LogIn;
    login->show();
}

void Logo::set_text() {
    if (timer % 3 == 0) {
        ui->label->setText("Please wait a moment.");
        timer++;
        return;
    }
    if (timer % 3 == 1) {
        ui->label->setText("Please wait a moment..");
        timer++;
        return;
    }
    if (timer % 3 == 2) {
        ui->label->setText("Please wait a moment...");
        timer++;
        return;
    }
}
