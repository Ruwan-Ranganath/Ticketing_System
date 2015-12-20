#include "newmatch.h"
#include "ui_newmatch.h"

newmatch::newmatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newmatch)
{
    ui->setupUi(this);

    MainWindow conn;

    if (conn.connOpen()) {
        ui->connected->setText("Connected");
    } else {
        ui->connected->setText("Not Connected");
    }

}

newmatch::~newmatch()
{
    delete ui;
}

void newmatch::on_pushButton_clicked()
{

    MainWindow conn;

    QString venue,fcountry,scountry,ftime,stime,dateis,matchtype,slotsis;


    venue = ui->venue->text();
    fcountry = ui->fcountry->text();
    scountry = ui->scountry->text();
    ftime = ui->ftime->text();
    stime = ui->stime->text();
    dateis = ui->date->text();
    matchtype = ui->matchtype->currentText();
    slotsis = ui->slotsis->text();





    if(!conn.connOpen()){
        qDebug() << "No Connection to Database found";
        return;
    }

    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("INSERT INTO match ( venue , fcountry, scountry, ftime,stime,dateis, matchtype,slots) VALUES ('"+venue+"','"+fcountry+"','"+scountry+"','"+ftime+"','"+stime+"','"+dateis+"','"+matchtype+"','"+slotsis+"')");

    if(qry.exec())
    {
        if (qry.next())
        {
            QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            conn.connClose();
        }else{


            QMessageBox::about(this,tr("Saving.."),tr("Saved !"));
            conn.connClose();
        }
}

}
