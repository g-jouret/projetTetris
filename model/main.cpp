#include "view/mwtetris.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Tetris * game = new Tetris();
    MWTetris w(game);
    w.show();

    return a.exec();
}
