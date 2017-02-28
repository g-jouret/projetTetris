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

void Player::moveBric(unsigned direction){

}

/*std::string Player::to_string() const{
    return board_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Player & in){
    out << in.to_string();
    return out;
}*/

}
