#ifndef MWTETRIS_H
#define MWTETRIS_H

#include "observer/observer.h"
#include "model/tetris.h"
#include <QMainWindow>
#include <QElapsedTimer>
#include <QGridLayout>

namespace Ui {
class MWTetris;
//class ConfigDialog;
class QTimer;
//class QGridLayout;
}
using namespace GJ_GW;

class MWTetris : public QMainWindow, public GJ_GW::Observer{
    Q_OBJECT
    Tetris game_;

    Ui::MWTetris *ui;
    QElapsedTimer chrono_;
    QTimer * time_;
    QTimer * timer_;

public:
    explicit MWTetris(Tetris game, QWidget *parent = 0);
    void update(GJ_GW::Subject *);
    ~MWTetris() noexcept;

private:
    void connexion();
    void generateBoard();
    void resetBoard(QGridLayout * board);
    void showNextBric();
    void endGame();
    void initLang();

private slots:
    void createGame();
    void quitGame();
    void rotate();
    void drop();
    void left();
    void right();
    void time();
    void next();
};

#endif // MWTETRIS_H
