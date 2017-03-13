#ifndef MWTETRIS_H
#define MWTETRIS_H

#include "game.h"
#include <QMainWindow>

namespace Ui {
class MWTetris;
}

class MWTetris : public QMainWindow{
    Q_OBJECT
    GJ_GW::Game * game_;

public:
    explicit MWTetris(GJ_GW::Game *game, QWidget *parent = 0);
    ~MWTetris() noexcept;

private:
    Ui::MWTetris *ui;

    void connexion();
    void generateBoard();
    void setName();
    void printFilled();
    void generateBric();
    void resetGame();

private slots:
    void createGame();
    void closeGame();
    void down();
    void turn();
    void drop();
    void left();
    void right();

};

#endif // MWTETRIS_H
