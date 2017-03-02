#include "player.h"
#include <vector>
#include <ostream>
#include <iomanip>

namespace GJ_GW{

Player::Player(std::string name, unsigned width, unsigned height):
    name_ {name}, board_{Board(width, height)}, bag_{BricsBag()}
{}

void Player::checkLines(){
    std::vector<unsigned> lines {board_.checkLines()};
    if(! lines.empty()){
        for(unsigned l : lines){
            board_.line(l);
        }
        score_ += lines.size();
        // TODO : compteur de lignes traversées par le drop
    }
}

void Player::rotateBric(){

}

/*std::vector<Position> Player::moveBric(unsigned direction){
    switch(direction){
    case 1:     //bas
        if(board_.checkCase()){

        }
        break;
    case 2:     //gauche
        for(int i = 0; i < shape_.size(); ++i){
            shape_.at(i).setX(-1);
        }
        break;
    case 3:     //droite
        for(int i = 0; i < shape_.size(); ++i){
            shape_.at(i).setX(1);
        }
        break;
    case 4:     //drop
// TODO implémentation drop
        break;
    default:
// TODO implémentation TetrisException
        break;
    }
    currentBric_.move(direction);
}*/

/*std::string Player::to_string() const{
    return board_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Player & in){
    out << in.to_string();
    return out;
}*/

}
