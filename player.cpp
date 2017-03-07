
#include <vector>
#include <ostream>
#include <iomanip>
#include "player.h"

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
        bool ok {1};
        unsigned count {0};
        Bric destination = currentBric_;
        destination.move(direction);
        while(ok && count < destination.getShape().size()){
            if(! currentBric_.isIn(destination.getShape().at(count))){
                ok = board_.checkCase(destination.getShape().at(count));
            }
            ++count;
        }
        if(ok){
            board_.swapFill(currentBric_.getShape()); //WARNING : problème d'allocator
            currentBric_.move(direction);
            board_.swapFill(currentBric_.getShape());
        }
}

/*std::string Player::to_string() const{
    return board_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Player & in){
    out << in.to_string();
    return out;
}*/

}
