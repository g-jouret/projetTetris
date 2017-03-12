#include "mwtetris.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GJ_GW::Game * game;
    game = new GJ_GW::Game();
    MWTetris w(game);
    w.show();

    return a.exec();
}
