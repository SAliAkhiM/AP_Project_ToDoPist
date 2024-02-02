#ifndef LOGO_H
#define LOGO_H

#include "qdialog.h"
#include <QMainWindow>
#include <QTimer>
#include <QMovie>
#include <QLabel>

namespace Ui {
class Logo;
}


class Logo : public QDialog
{
    Q_OBJECT

public:
    explicit Logo(QWidget *parent = nullptr);
    ~Logo();

private:
    Ui::Logo *ui;
    QTimer* t1;
    QTimer* t2;
    int timer;

private slots:
    void logo_show();

    void set_text();

};

#endif // LOGO_H
