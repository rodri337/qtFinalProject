#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>
#include "login.h"
#include "searchnote.h"




namespace Ui {
class Profile;
}

class Profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = 0);
    ~Profile();

private slots:
    void on_actionAdd_Note_triggered();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
