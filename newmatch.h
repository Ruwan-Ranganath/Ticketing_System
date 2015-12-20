#ifndef NEWMATCH_H
#define NEWMATCH_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class newmatch;
}

class newmatch : public QDialog
{
    Q_OBJECT

public:
    explicit newmatch(QWidget *parent = 0);
    ~newmatch();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newmatch *ui;
};

#endif // NEWMATCH_H
