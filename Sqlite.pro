#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T02:21:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sqlite
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    searchnote.cpp \
    note.cpp \
    createuser.cpp \
    profile.cpp

HEADERS  += login.h \
    searchnote.h \
    note.h \
    createuser.h \
    profile.h

FORMS    += login.ui \
    searchnote.ui \
    createuser.ui \
    profile.ui

RESOURCES += \
    pics.qrc
