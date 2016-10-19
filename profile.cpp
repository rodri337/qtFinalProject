#include "profile.h"
#include "ui_profile.h"


Profile::Profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
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
