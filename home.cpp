
#include "home.h"
#include "ui_home.h"
#include "newmatch.h"

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::on_pushButton_5_clicked()
{
     newmatch nwmtch;
     nwmtch.setModal(true);
     nwmtch.exec();
}

void Home::on_pushButton_2_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.myDB);



    qry->prepare("select id,fcountry,scountry,matchtype from  match where matchtype='Test'");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->comboBox->setModel(modal);

    conn.connClose();

    qDebug() << (modal->rowCount());
}

void Home::on_pushButton_3_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.myDB);



    qry->prepare("select id,fcountry,scountry,matchtype from  match where matchtype='ODI'");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->comboBox->setModel(modal);

    conn.connClose();

    qDebug() << (modal->rowCount());
}

void Home::on_pushButton_4_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.myDB);



    qry->prepare("select id,fcountry,scountry,matchtype from  match where matchtype='T-20'");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->comboBox->setModel(modal);

    conn.connClose();

    qDebug() << (modal->rowCount());
}

void Home::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox->currentText();

    ui->txtsearch->setText(name);
}

void Home::on_pushButton_7_clicked()
{
    MainWindow conn;

    QString updatetxt,txtsearch;

    txtsearch=ui->txtsearch->text();
    updatetxt=ui->updatetxt->text();


    if(!conn.connOpen()){
        qDebug() << "No Connection to Database found";
        return;
    }

    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("UPDATE match SET slots=slots-'"+updatetxt+"' WHERE id='"+txtsearch+"' ");

    if(qry.exec())
    {
        if (qry.next())
        {
            QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            conn.connClose();
        }else{


            QMessageBox::about(this,tr("Update.."),tr("Succssfully Updated ! !"));
            conn.connClose();
        }
}

}
