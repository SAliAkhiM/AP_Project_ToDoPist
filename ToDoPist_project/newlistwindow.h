#ifndef NEWLISTWINDOW_H
#define NEWLISTWINDOW_H

#include <QDialog>

namespace Ui {
class newlistwindow;
}

class newlistwindow : public QDialog
{
    Q_OBJECT

public:
    explicit newlistwindow(QWidget *parent = 0);
    ~newlistwindow();
    QString getName();
    QString getType();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::newlistwindow *ui;
    QString name;
    QString type;
};

#endif // NEWLISTWINDOW_H
