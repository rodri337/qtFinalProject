#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

struct oneNote {
    int NoteId;
    QString noteName;
    QString noteComments; //store the comments
    QString noteCourse;
    QString pateString;
};



class Note : public oneNote {
private:
    oneNote myList[10];
    int indexCounter;
    void readFile(std::string fileName);
    void linkFile(std::string fileName, std::string newFile);

public:
    Note();
    Note(QString name);
    void addNote(QString note);
    void printNoteList();
    void writeNote(std::string fileName, std::string noteName);

    //void changeName(std::string name);
    //void addComments(std::string comments);

};

#endif // NOTE_H
