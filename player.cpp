#include "player.h"
#include <vector>
#include <ostream>
#include <iomanip>

namespace GJ_GW{

Player::Player(std::string name, unsigned width, unsigned height, std::vector<Position> brics):
    name_ {name}, board_{Board(width, height)},
    bag_{BricsBag(std::vector<Bric> {
                  Bric(std::vector<Position> {brics.at(0),brics.at(1),brics.at(2),brics.at(3)}),  //I
                  Bric(std::vector<Position> {brics.at(4),brics.at(5),brics.at(6),brics.at(7)}),   //O
                  Bric(std::vector<Position> {brics.at(8),brics.at(9),brics.at(10),brics.at(11)}),   //T
                  Bric(std::vector<Position> {brics.at(12),brics.at(13),brics.at(14),brics.at(15)}),   //J
                  Bric(std::vector<Position> {brics.at(16),brics.at(17),brics.at(18),brics.at(19)}),   //L
                  Bric(std::vector<Position> {brics.at(20),brics.at(21),brics.at(22),brics.at(23)}),   //Z
                  Bric(std::vector<Position> {brics.at(24),brics.at(25),brics.at(26),brics.at(27)})   //S
                  })}
{}

void Player::checkLines(){
    std::vector<unsigned> lines {board_.checkLines()};
    if(! lines.empty()){
        for(unsigned l : lines){
            board_.line(l);
        }
        score_ += lines.size();
        // TODO : adaptation voir info du projet
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
