TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pedantic-errors

SOURCES += main.cpp \
    player.cpp \
    bric.cpp \
    bricsBag.cpp \
    game.cpp \
    position.cpp \
    board.cpp

HEADERS += \
    player.h \
    bric.h \
    bricsBag.h \
    position.h \
    game.h \
    board.h
