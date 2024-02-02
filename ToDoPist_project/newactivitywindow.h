#ifndef NEWACTIVITYWINDOW_H
#define NEWACTIVITYWINDOW_H

#include <QDialog>
#include <QDate>
#include <QCheckBox>
#include "activity.h"
#include <QMessageBox>

namespace Ui {
class newactivitywindow;
}

class newactivitywindow : public QDialog
{
    Q_OBJECT

public:
    explicit newactivitywindow(QWidget *parent = 0);
    ~newactivitywindow();
    QString getName();
    QString getAuthor();
    QDate setDate();
    QDate getDate();
    bool isImp();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::newactivitywindow *ui;
    QString name;
    QString author;
    QDate data;
    bool important;
    Activity* a;
};

#endif // NEWACTIVITYWINDOW_H
