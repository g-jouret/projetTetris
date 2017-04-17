#ifndef MWTETRIS_H
#define MWTETRIS_H

#include "../observer/observer.h"
#include "../model/tetris.h"
#include <QMainWindow>
#include <QElapsedTimer>
#include <QGridLayout>
#include <QLabel>

namespace Ui {
class MWTetris;
class QTimer;
}

class MWTetris : public QMainWindow, public GJ_GW::Observer{
    Q_OBJECT
    GJ_GW::Tetris game_;
    Ui::MWTetris *ui;
    QLabel * lbEnd_;
    QElapsedTimer chrono_;
    unsigned savedTime_;
    QTimer * time_;
    QTimer * timer_;

public:
    explicit MWTetris(GJ_GW::Tetris game, QWidget *parent = 0);
    void update(GJ_GW::Subject *);
    ~MWTetris() noexcept;

private:
    void connexion();
    void generateBoard(bool end = 0);
    void resetBoard(QGridLayout * board);
    void showNextBric();
    void endGame();
    void pause();
    void resume();

private slots:
    void createGame();
    void quitGame();
    void rotate();
    void drop();
    void left();
    void right();
    void pausePlay(bool checked);
    void time();
    void next();
};

#endif // MWTETRIS_H
