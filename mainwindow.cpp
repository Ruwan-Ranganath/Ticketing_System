#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "home.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(connOpen())
    {
        ui->lblResult->setText("[+] Connected to Database");
    }else {
    ui->lblResult->setText("'<b>[+] Lost Connection to database</b>");
}
}

MainWindow::~MainWindow()
{
    delete ui;

    qDebug() << "Closing the connection to the database file on exit. ";
    myDB.close();
}

void MainWindow::on_btnLogin_clicked()
{



    QString Username , Password;

    Username = ui->txtUserName->text();
    Password = ui->txtPassword->text();

    if(!connOpen()){
        qDebug() << "No Connection to Database found";
        return;
    }

    connOpen();

    QSqlQuery qry;
    qry.prepare("SELECT Username, Password, Role FROM Users WHERE UserName=\'" + Username + "\' AND Password=\'"+Password+"\' ");

    if(qry.exec())
    {
        if (qry.next())
        {
            ui->lblResult->setText("[+] Valid User Name and Password");



            // Closing Connection
            connClose();

            //Close login form
            this->close();

            //open New windows
            Home home;
            home.setModal(true);
            home.exec();




        }else {
            ui->lblResult->setText("[-] Wrong Username and Password");
        }
    }




}
