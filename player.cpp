
#include <vector>
#include <ostream>
#include <iomanip>
#include "player.h"

namespace GJ_GW{

Player::Player(std::string name, unsigned width, unsigned height):
    name_ {name}, board_{Board(width, height)}, bag_{BricsBag()}, currentBric_{bag_.getNextBric()}
  // TODO : rearrange avant getnextbric
{}

void Player::checkLines(){
    for(unsigned i = board_.getHeight()-1; i != 0; --i){
        if(board_.checkLine(board_.getLine(i)) == 1){
            nbLine_ += board_.gridActualisation(i);
        }

        // TODO : compteur de lignes traversées par le drop
    }
}

void Player::generateBric(){
    bool ok {true};
    unsigned count{0};
    unsigned midBoard = board_.getWidth()/2;
    unsigned midSide = currentBric_.getSide()/2;
    for(unsigned i = 0; i < midBoard-midSide; ++i){
        currentBric_.move(3);
    }
    while(ok && count < currentBric_.getShape().size()){
        ok = ! board_.checkCase(currentBric_.getShape().at(count));
        ++count;
    }
    if(ok){
        for(Position p : currentBric_.getShape()){
            board_.swapCase(p);
        }
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
                ok = ! board_.checkCase(destination.getShape().at(count));
            }
            ++count;
        }
        if(ok){
            for(Position p : currentBric_.getShape()){
                board_.swapCase(p);
            }
            currentBric_.move(direction);
            for(Position p : currentBric_.getShape()){
                board_.swapCase(p);
            }
        }
}

// TODO : next currentBric_ + show next bric

/*std::string Player::to_string() const{
    return board_.to_string();
}

std::ostream & operator<<(std::ostream & out, const Player & in){
    out << in.to_string();
    return out;
}*/

}
