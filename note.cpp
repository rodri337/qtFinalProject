#include "Note.h"
#include <iostream>
#include <string>
#include <fstream>
#include <fstream>
#include <cstdlib>
#include <QDebug>


using namespace std;


Note::Note() {
    indexCounter = 0;
}

Note::Note(QString name) {
    oneNote current;
    current.noteName = name;
    current.NoteId = indexCounter; //save the index counter as an ID
    myList[indexCounter] = current;
    indexCounter++;
}

void Note::printNoteList() {

    cout << "---------------Note List-----------------" << endl;

    for (int i = 0; i < indexCounter; i++) {
        oneNote current;
        current = myList[i];
        qDebug()<<current.noteName;

    }
}


void Note::addNote(QString note) {

    oneNote current;
    current.noteName = note;
    current.NoteId = indexCounter; //save the index counter as an ID
    myList[indexCounter] = current;
    indexCounter++;
}


/*void Note::writeNote(string fileName, string noteName) {
    cout << "------------------------------------------------" << endl;
    cout << endl;
    cout << "Content on file: " << endl;
    cout << "***********************************************" << endl;
    this->readFile(fileName);
    cout << "-----------------------------------------------" << endl;
    cout << "Add File?(Yes or No): ";
    string answer;
    cin >> answer;
    if (answer == "Yes") {
        this->linkFile(fileName, noteName);
    }
    else {
        cout <<"File not added" << endl;
    }


}*/



void Note::readFile(string fileName) {
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file";

}



void Note::linkFile(string fileName, string newFile) {
    ifstream fin;
    fin.open(fileName);
    ofstream fout;
    fout.open(newFile);
    char ch;
    while (!fin.eof()) {
        fin.get(ch);
        fout << ch;
    }
    fin.close();
}

/*void Note::addComments(string comments) {
//noteComments = comments;
}

void Note::changeName(string name) {
//noteName = name;
}*/
