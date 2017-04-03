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
 * renforcement du random de getNextBric
 * amélioration rotation des briques + génération (pair & impair)
 * amélioration graphique (distorsion case + font de jeu (css))
 * couleur des briques
 */
