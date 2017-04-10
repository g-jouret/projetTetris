#include "view/mwtetris.h"
#include <QApplication>

using namespace GJ_GW;

int main(int argc, char *argv[]){
    try{
        QApplication a(argc, argv);
        Tetris game;
        MWTetris w(game);
        w.show();
        return a.exec();
    } catch(const std::invalid_argument & e){
        std::cerr << "Erreur au lancement : "
                  << e.what()
                  << std::endl;
        std::exit(1);
    }
}

/* TODO Principal :
 * amélioration graphique (resize auto)
 * optimisation mémoire (board - itératif à la place de récursif) /!\ drop de secondes! certains rafraichissements toutes les 2 secondes au lieu d'une
 * implémentation briques perso
 * vision de la nouvelle brique
 * amélioration rotation des briques
 * condition de victoire ignorable (checkbox)
 * multi-langue
 * pause / stopper temps (save elapsed, delete => pointeur?)
 * aide? cf qtpendu.pdf
 */
