#include "mwtetris.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MWTetris w;
    w.show();

    return a.exec();
}
