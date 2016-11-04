#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    if(!connOpen()){
        ui->statusLabel->setText("Failed to open the database");
    }
    else{
        ui->statusLabel->setText("Connected");
    }

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
    username = ui->lineEditUser->text();
    password = ui->lineEditPassword->text();

    if(!connOpen()){
        qDebug() << "Failed to open the database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select *from Users where Name='"+username+"' and userId='"+password+"'");

    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->statusLabel->setText("username and password is correct");
            connClose();    //close the connection with data base
            this->hide(); //hide the current page
            Profile *userProfile = new Profile(this);
            userProfile->show();

        }
        else if(count > 1)
        {
            ui->statusLabel->setText("Duplicate username and password");
        }
        else if(count < 1)
        {
            ui->statusLabel->setText("username and password are not correct");
        }
    }

}


//take to the create user window

void Login::on_pushButton_2_clicked()
{
    connClose();
    CreateUser openCreate;
    openCreate.setModal(true);
    this->hide();
    openCreate.exec();

}
