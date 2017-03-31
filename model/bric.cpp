#include "bric.h"

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
    side_ = temp.size();
}

std::vector<Position> Bric::getShape() const{
    return shape_;
}

unsigned Bric::getSide() const{
    return side_;
}

unsigned Bric::getHigherY(){
    Position temp {0,0};
    for(Position p : shape_){
        if(temp > p)
            temp = p;
    }
    return temp.getY();
}

void Bric::move(Direction dir){
    switch(dir){
    case Direction::LEFT:
        for(unsigned i = 0; i < shape_.size(); ++i){
            shape_.at(i).setX(-1);
        }
        break;
    case Direction::RIGHT:
        for(unsigned i = 0; i < shape_.size(); ++i){
            shape_.at(i).setX(1);
        }
        break;
    default:     //bas
        for(unsigned i = 0; i < shape_.size(); ++i){
            shape_.at(i).setY(1);
        }
        break;
    }
}

void Bric::rotate(){

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

std::string Bric::to_string() const{
std::string s;
for(auto it = shape_.begin(); it != shape_.end(); ++it){
    s += it->to_string();
}
return s;
}

std::ostream & operator<<(std::ostream & out, const Bric & in){
out << in.to_string();
return out;
}
