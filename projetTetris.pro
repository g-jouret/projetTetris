#-------------------------------------------------
#
# Project created by QtCreator 2017-03-08T23:26:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetTetris
TEMPLATE = app
CONFIG += C++14

SOURCES += model/board.cpp \
    model/bric.cpp \
    model/bricsBag.cpp \
    model/main.cpp \
    model/player.cpp \
    model/position.cpp \
    observer/subject.cpp \
    view/configdialog.cpp \
    view/mwtetris.cpp \
    model/tetris.cpp

HEADERS  += model/board.h \
    model/bric.h \
    model/bricsBag.h \
    model/player.h \
    model/position.h \
    observer/observer.h \
    observer/subject.h \
    view/configdialog.h \
    view/mwtetris.h \
    model/tetris.h

FORMS    += view/configdialog.ui \
    view/mwtetris.ui
