#include "game.h"
#include <vector>
#include <ostream>
#include <iomanip>

namespace GJ_GW {

Game::Game():
    level_ {0}, timer_ {MAXIMUM_TIMER},
    //players_ {std::vector<Player> {   pour plus tard
    player_ {Player("Joueur1", DEFAULT_WIDTH, DEFAULT_HEIGHT)}
{}
/*
unsigned Game::validate(unsigned value, unsigned def){
    return (value == 0)? def : value;
}*/
/* WARNING : revoir les constructeur de copies / destructeurs etc
void Game::setPlayer(std::string name1, std::string name2, unsigned width, unsigned height){
    players_.emplace(players_.begin()-1,
            Player(name1, validate(width, DEFAULT_WIDTH), validate(height, DEFAULT_HEIGHT),
                                      }));
            players_.emplace_back(
                Player(name2, validate(width, DEFAULT_WIDTH), validate(height, DEFAULT_HEIGHT),
                                          }));

}
*/

/*std::string Game::to_string() const{
    return player_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Game & in){
    out << in.to_string();
    return out;
}*/
/*unsigned Game::upDificulty(unsigned lvl,unsigned lineDel){
>>>>>>> refs/remotes/origin/master
    if(lineDel == 5 | 10 | 15) lvl+=1;
    return lvl;
}
//NOTE Pas d'idée de nom
unsigned Game::upTimer(unsigned lvl, unsigned timer){
    switch ( lvl ){
       case 0:
        timer=2000;
       case 1:
        timer=1500;
        break;
       case 2:
        timer=1000;
       case 3:
        timer=500;
       default  :
        //TODO Exception
        break;
    }
    return timer;
}
<<<<<<< HEAD
=======
*/
}

