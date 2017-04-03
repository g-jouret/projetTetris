#include "view/mwtetris.h"
#include <QApplication>

using namespace GJ_GW;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Tetris game;
    MWTetris w(game);
    w.show();

    return a.exec();
}

/* TODO Principal :
 * itératif
 * rotation des briques
 * renforcement du random de getNextBric
 * couleur des briques
 */
