#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QtSql/QSqlDriver>
#include <QSql>
#include <QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

// Database path -- Need proper Upgrade .
#define Path_to_DB "E:/qt-projects/Ticketins-System/ticket-booking.sqlite"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase myDB;

    void connClose()
    {
        myDB.close();
        myDB.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {

        myDB = QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName(Path_to_DB);
        QFileInfo checkFile(Path_to_DB);

        if (checkFile.isFile())
        {
            if(myDB.open())
            {
               qDebug()<<("[+] Connected to Database");
               return true;
            }
        }else {
               qDebug()<<("'<b>[+] Lost Connection to database</b>");
                return false;
        }
        return 0;
    }




public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
