#include "mwtetris.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Game * game = new Game();
    MWTetris w(game);
    w.show();

    return a.exec();
}
