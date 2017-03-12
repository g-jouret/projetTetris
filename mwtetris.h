#ifndef MWTETRIS_H
#define MWTETRIS_H

#include <QMainWindow>
#include <QLabel>
#include "configdialog.h"
#include "game.h"

namespace Ui {
class MWTetris;
}

class MWTetris : public QMainWindow{
    Q_OBJECT
    GJ_GW::Game * game_;
    Ui::MWTetris *ui;

public:
    explicit MWTetris(GJ_GW::Game * game, QWidget *parent = 0);
    ~MWTetris();

private:
    void connexion();
    void generateBoard();
    void setName();

private slots:
    void createGame();
    void closeGame();
    void turn();
    void drop();
    void left();
    void right();
};

#endif // MWTETRIS_H
