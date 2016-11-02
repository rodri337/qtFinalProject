#ifndef NOTECREATOR_H
#define NOTECREATOR_H

#include <QMainWindow>
#include "profile.h"
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class NoteCreator;
}

class NoteCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit NoteCreator(QWidget *parent = 0);
    ~NoteCreator();

private slots:
    void on_actionCopy_triggered();

    void on_actionSave_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::NoteCreator *ui;
    QString filePath;
};

#endif // NOTECREATOR_H
