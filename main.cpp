#include "game.h"
#include "player.h"
#include <iostream>

using namespace std;

int main()
{
    GJ_GW::Player p("joueur",10,20);
    cout << p.getBoard() << endl;
    p.generateBric();
    cout << p.getBoard() << endl;
    return 0;
}
