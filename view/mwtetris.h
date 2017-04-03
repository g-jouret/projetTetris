#ifndef MWTETRIS_H
#define MWTETRIS_H

#include "configdialog.h"
#include "observer/observer.h"
#include "model/tetris.h"
#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class MWTetris;
}
using namespace GJ_GW;

class MWTetris : public QMainWindow, public GJ_GW::Observer{
    Q_OBJECT
    Tetris game_;
    Ui::MWTetris *ui;
    QElapsedTimer timer_;

public:
    explicit MWTetris(Tetris game, QWidget *parent = 0);
    void update(GJ_GW::Subject *);
    ~MWTetris() noexcept;

private:
    void connexion();
    void generateBoard();
    void resetBoard();

private slots:
    void createGame();
    void quitGame();
    void rotate();
    void drop();
    void left();
    void right();
    void time();

};

#endif // MWTETRIS_H
