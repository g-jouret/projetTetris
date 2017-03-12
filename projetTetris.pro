#-------------------------------------------------
#
# Project created by QtCreator 2017-03-08T23:26:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetTetris
TEMPLATE = app


SOURCES += main.cpp\
        mwtetris.cpp \
    board.cpp \
    bric.cpp \
    bricsBag.cpp \
    game.cpp \
    player.cpp \
    position.cpp \
    configdialog.cpp

HEADERS  += mwtetris.h \
    board.h \
    bric.h \
    bricsBag.h \
    game.h \
    player.h \
    position.h \
    configdialog.h

FORMS    += mwtetris.ui \
    configdialog.ui
