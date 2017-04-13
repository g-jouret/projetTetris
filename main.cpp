#include "view/mwtetris.h"
#include <QApplication>

using namespace GJ_GW;

int main(int argc, char *argv[]){
    try{
        QApplication a(argc, argv);
        std::string name {"Joueur"};
        Tetris game(name);
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
 * bouton début partie
 * amélioration graphique (resize auto)
 * amélioration rotation des briques
 * condition de victoire ignorable (checkbox)
 * gestion erreur bric verticale
 * choix couleur brique perso (qcolordialog)
 * pause / stopper temps (save elapsed, delete => pointeur?)
 * multi-langue
 * aide? cf qtpendu.pdf
 */
