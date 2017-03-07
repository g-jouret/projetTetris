
#include <vector>
#include <ostream>
#include <iomanip>
#include "player.h"

namespace GJ_GW{

Player::Player(std::string name, unsigned width, unsigned height):
    name_ {name}, board_{Board(width, height)}, bag_{BricsBag()}
{}

void Player::checkLines(){
    for(unsigned i = 0; i < board_.getHeight(); ++i){
        if(board_.checkLine(board_.getLine(i)) == 1){
            board_.swapLine(board_.getLine(i));
            board_.gridActualisation(i);
        }

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
                ok = board_.getCase(destination.getShape().at(count))->isFilled();
            }
            ++count;
        }
        if(ok){
            for(Position p : currentBric_.getShape()){
                board_.swapFill(p);
            }
            currentBric_.move(direction);
            for(Position p : currentBric_.getShape()){
                board_.swapFill(p);
            }
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
