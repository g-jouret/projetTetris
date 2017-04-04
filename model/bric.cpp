#include "bric.h"
#include <algorithm>

using namespace GJ_GW;

Bric::Bric(){}

Bric::Bric(std::vector<Position> shape): shape_ {shape}{
    // TODO : à la création d'une forme perso : vérification que la brique est dans la longueur (il y a plus de X que de Y)
    std::vector<unsigned> temp;
    for(Position pos : shape_){
        temp.push_back(pos.getX());
    }
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
    unsigned side = temp.size();
    middle_ = Position(side/2, side/2);
}

std::vector<Position> Bric::getShape() const{
    return shape_;
}

Position Bric::getMiddle() const{
    return middle_;
}

unsigned Bric::getHigherY(){
    Position temp {shape_.at(0)};
    for(Position p : shape_){
        if(temp > p)
            temp = p;
    }
    return temp.getY();
}

void Bric::move(Direction dir){
    switch(dir){
    case Direction::LEFT:
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setX(-1);
        }
        middle_.setX(-1);
        break;
    case Direction::RIGHT:
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setX(1);
        }
        middle_.setX(1);
        break;
    case Direction::UP:
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setY(-1);
        }
        middle_.setY(-1);
        break;
    default:     //bas
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setY(1);
        }
        middle_.setY(1);
        break;
    }
}

void Bric::rotate(){
    for(unsigned u {0}; u < shape_.size(); ++u){
        shape_.at(u) = Position (
                    middle_.getX() - shape_.at(u).getY() + middle_.getY(),
                    middle_.getY() + shape_.at(u).getX() - middle_.getX());
    }
}

bool Bric::contains(Position & pos) const{
    bool ok {0};
    for(Position p : shape_){
        if(p == pos){
            ok = 1;
        }
    }
    return ok;
}

/*std::string Bric::to_string() const{
    std::string s;
    for(auto it = shape_.begin(); it != shape_.end(); ++it){
        s += it->to_string();
    }
    s += ", milieu : " + middle_.to_string();
    return s;
}

namespace GJ_GW {
std::ostream & operator<<(std::ostream & out, const Bric & in){
    out << in.to_string();
    return out;
}
}*/
