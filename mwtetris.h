#ifndef MWTETRIS_H
#define MWTETRIS_H

#include <QMainWindow>

namespace Ui {
class MWTetris;
}

class MWTetris : public QMainWindow
{
    Q_OBJECT


public:
    explicit MWTetris(QWidget *parent = 0);
    ~MWTetris();

private:
    Ui::MWTetris *ui;
    void connexion();

private slots:
    void createGame();
    void closeGame();

};

#endif // MWTETRIS_H
