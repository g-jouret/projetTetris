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
 * mettre les limitations de la partie view aussi dans la partie model, sinon c'est pas propre
 * amélioration graphique (resize auto)
 * renforcement du random de getNextBric
 * gestion score si win au score
 * optimisation mémoire (board - itératif à la place de récursif) /!\ drop de secondes! certains rafraichissements toutes les 2 secondes au lieu d'une
 * amélioration rotation des briques + génération (pair & impair)
 * implémentation briques perso
 * vision de la nouvelle brique
 * couleur des briques
 */
