#include "searchnote.h"
#include "ui_searchnote.h"
#include <qFile>
#include <qTextStream>
#include <qMessageBox>


SearchNote::SearchNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchNote)
{
    ui->setupUi(this);
}

SearchNote::~SearchNote()
{
    delete ui;
}



void SearchNote::on_searchButton_clicked()
{
    QFile myFile("C:\\Users\\rjuan\\OneDrive\\Documents\\Sqlite\\List.txt"); //path with double slashes
    if(!myFile.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", myFile.errorString());
    QTextStream in(&myFile);
    ui->previewWindow->setText(in.readAll());
}



//Adds the note to the list array after all the
//information has been enter
//stores it in the note variables
void SearchNote::on_addNoteYes_clicked()
{
    QString name = ui->nameLineEdit->text();

}

//add note button
//must add to the array of list

void SearchNote::on_quitButton_clicked()
{
    this->hide();
}
