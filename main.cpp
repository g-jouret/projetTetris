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
 * bug : lorsqu'on relance une nouvelle partie, on a 2 briques courantes
 *
 * rotation des briques
 * Gestion du niveau de difficulté & itératif
 * vérification de fin de partie (le endgame gère tout)
 * implémentation de la gestion des collisions en mouvement
 * renforcement du random de getNextBric
 * couleur des briques
 */
