#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "profile.h"


namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase myDataBase;

    /*
     * **********************************************
     * Function to close the connection to the server
     *
     */
    void connClose(){
      myDataBase.close();
      myDataBase.removeDatabase(QSqlDatabase::defaultConnection);
    }

    /********************************************
     * Function to open the connection to the server
     *
     */
    bool connOpen(){
        myDataBase = QSqlDatabase::addDatabase("QSQLITE");
        myDataBase.setDatabaseName("C:/Users/rjuan/Desktop/sqLite/notesUser.sqlite");

        if(!myDataBase.open()){                     //if not connected to data base
            qDebug()<<("Failed to open the database");
            return false;
        }
        else{
            qDebug()<<("Connected"); //if connected to the database
            return true;
        }

    }



public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    //Profile *userProfile;
};

#endif // LOGIN_H
