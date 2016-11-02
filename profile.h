#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include "login.h"
#include "searchnote.h"
#include "note.h"
#include <QDebug>
#include "notecreator.h"

namespace Ui {
class Profile;

}

class Profile : public QMainWindow
{
    Q_OBJECT



public:
    explicit Profile(QWidget *parent = 0);
    Profile(QString id);
    ~Profile();




private slots:
    void on_actionAdd_Note_triggered();

    void on_actionCreate_Note_triggered();

    void on_load_clicked();

private:
    Ui::Profile *ui;

private:
    QString name;
    QString major;
    QString school;
    Note myNoteList;


public:
    void myNoteListAdd(QString newName);

};

#endif // PROFILE_H
