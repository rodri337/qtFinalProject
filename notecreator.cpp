#include "notecreator.h"
#include "ui_notecreator.h"


NoteCreator::NoteCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NoteCreator)
{
    ui->setupUi(this);
}

NoteCreator::~NoteCreator()
{
    delete ui;
}


/*
 * copy what is in clipboard
 */
void NoteCreator::on_actionCopy_triggered()
{
    ui->writeSpace->copy();
}


/*
 * create the save function to save it in an specific file
 */
void NoteCreator::on_actionSave_triggered()
{

    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->writeSpace->toPlainText();
    out << text;
    file.flush();
    file.close();
}


/*
 *Errases everything on the screen
 *
*/
void NoteCreator::on_actionCut_triggered()
{
    ui->writeSpace->cut();
}


//paste what ever is in your
void NoteCreator::on_actionPaste_triggered()
{
    ui->writeSpace->paste();
}


//erase everything from the writeSpace to start new writing
void NoteCreator::on_actionNew_triggered()
{
    filePath = "";
    ui->writeSpace->setText("");
}

//open an existing file
void NoteCreator::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->writeSpace->setText(text);
    file.close();
}


/*
 * Saves to a specific location
 */
void NoteCreator::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->writeSpace->toPlainText();
    out << text;
    file.flush();
    file.close();
}
