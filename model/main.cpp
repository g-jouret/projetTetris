#include "view/mwtetris.h"
#include <QApplication>

using namespace GJ_GW;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Tetris * game = new Tetris();
    MWTetris w(game);
    w.show();

    return a.exec();
}
