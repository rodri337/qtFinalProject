#include "profile.h"
#include "ui_profile.h"


Profile::Profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
    Login conn;

    //check for the databaseConnection
   /* if(!conn.connOpen()){
        ui->connectionLabelStatus->setText("Failed to open database");
    }
    else{
        ui->connectionLabelStatus->setText("Connected");
    }
    */

    QString name = "Juan";

    if(!conn.connOpen()){
        qDebug()<<"Fail to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Users where name='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->userNameLine->setText(qry.value(7).toString()); //set the username
            ui->majorLine->setText(qry.value(5).toString()); //set major line
            ui->schoolLine->setText(qry.value(3).toString()); //set school line

        }
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}

Profile::Profile(QString id):
        //QMainWindow(parent),
        ui(new Ui::Profile)
    {
        ui->setupUi(this);
        Login conn;

        //check for the databaseConnection
       /* if(!conn.connOpen()){
            ui->connectionLabelStatus->setText("Failed to open database");
        }
        else{
            ui->connectionLabelStatus->setText("Connected");
        }
        */

        QString name = id;

        if(!conn.connOpen()){
            qDebug()<<"Fail to open the database";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("select * from Users where name='"+name+"'");
        if(qry.exec())
        {
            while(qry.next())
            {
                ui->userNameLine->setText(qry.value(7).toString()); //set the username
                ui->majorLine->setText(qry.value(5).toString()); //set major line
                ui->schoolLine->setText(qry.value(3).toString()); //set school line

            }
            conn.connClose();
        }
        else{
            QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
        }
}


Profile::~Profile()
{
    delete ui;
}

void Profile::on_actionAdd_Note_triggered()
{
    SearchNote openSearch;          //will send us the searchNote gui
    openSearch.setModal(true);
    openSearch.exec();

}

void Profile::myNoteListAdd(QString newName){
    myNoteList.addNote(newName);
}


//open the createNote screen
void Profile::on_actionCreate_Note_triggered()
{
    NoteCreator *userProfile = new NoteCreator(this);
    userProfile->show();
}

void Profile::on_load_clicked()
{
   /* QString name = "Juan";
    Login conn;
    if(!conn.connOpen()){
        qDebug()<<"Fail to open the database";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Users where name='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->userNameLine->setText(qry.value(7).toString()); //set the username
            ui->majorLine->setText(qry.value(5).toString()); //set major line
            ui->schoolLine->setText(qry.value(3).toString()); //set school line

        }
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
    */
}

