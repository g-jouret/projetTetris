#ifndef MWTETRIS_H
#define MWTETRIS_H

#include <QMainWindow>
#include "configdialog.h"
#include "observer.h"
#include "game.h"
#include <QElapsedTimer>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <iostream>

namespace Ui {
class MWTetris;
}

class MWTetris : public QMainWindow, public /*GJ_GW::*/Observer{
    Q_OBJECT
    /*GJ_GW::*/Game *game_;
    Ui::MWTetris *ui;
    QElapsedTimer timer_;

public:
    explicit MWTetris(/*GJ_GW::*/Game *game, QWidget *parent = 0);
    void update(Subject *);
    ~MWTetris() noexcept;

private:
    void connexion();
    void generateBoard();
    void generateBric();
    void resetBoard();

private slots:
    void createGame();
    void quitGame();
    void down();
    void turn();
    void drop();
    void left();
    void right();
    void time();

};

#endif // MWTETRIS_H
