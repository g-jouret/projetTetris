#-------------------------------------------------
#
# Project created by QtCreator 2017-03-08T23:26:00
#
#-------------------------------------------------

QT += core \
gui \
widgets \
network \
concurrent

TARGET = projetTetris
TEMPLATE = app
CONFIG += C++14

SOURCES += model/board.cpp \
    model/bric.cpp \
    model/bricsBag.cpp \
    model/player.cpp \
    model/position.cpp \
    observer/subject.cpp \
    view/configdialog.cpp \
    view/mwtetris.cpp \
    model/tetris.cpp \
    view/setbricsdialog.cpp \
    main.cpp \
    model/color.cpp \
    network/multitetris.cpp \
    network/server.cpp \
    network/client.cpp \
    network/netmsg.cpp \
    view/confirmlaunchdialog.cpp

HEADERS  += model/board.h \
    model/bric.h \
    model/bricsBag.h \
    model/player.h \
    model/position.h \
    observer/observer.h \
    observer/subject.h \
    view/configdialog.h \
    view/mwtetris.h \
    model/tetris.h \
    model/direction.h \
    view/setbricsdialog.h \
    model/linestate.h \
    model/gamestate.h \
    model/color.h \
    network/multitetris.h \
    network/server.h \
    network/client.h \
    network/netmsg.h \
    view/confirmlaunchdialog.h \
    network/gamemode.h

FORMS    += view/configdialog.ui \
    view/mwtetris.ui \
    view/setbricsdialog.ui \
    view/confirmlaunchdialog.ui
