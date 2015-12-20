#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T23:13:31
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ticketins-System
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    home.cpp \
    newmatch.cpp

HEADERS  += mainwindow.h \
    home.h \
    newmatch.h

FORMS    += mainwindow.ui \
    home.ui \
    newmatch.ui
