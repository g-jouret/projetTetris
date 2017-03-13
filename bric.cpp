#include "bric.h"
#include <algorithm>

namespace GJ_GW{

Bric::Bric():Bric(std::vector<Position>{Position(0,0), Position(0,1)})
{}

Bric::Bric(std::vector<Position> shape): shape_ {shape}
{
    // TODO : à la création d'une forme perso : vérification que la brique est dans la longueur (il y a plus de X que de Y)
    std::vector<unsigned> temp;
    for(Position pos : shape_){
        temp.push_back(pos.getX());
    }
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
    side_ = temp.size();
}

std::vector<Position> Bric::getShape(){
    return shape_;
}

unsigned Bric::getSide(){
    return side_;
}

void Bric::move(unsigned direction){
    switch(direction){
    case 1:     //drop
        // TODO implémentation drop
        break;
    case 2:     //gauche
        for(unsigned i = 0; i < shape_.size(); ++i){
            shape_.at(i).setX(-1);
        }
        break;
    case 3:     //droite
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

bool Bric::isIn(Position toCheck){
    bool ok {0};
    for(Position p : shape_){
        if(p == toCheck){
            ok = 1;
        }
    }
    return ok;
}

/*std::vector<Position> Bric::below(){
    std::vector<Position> destination;
    unsigned temp {0};
    for(Position pos : shape_){

        // NOTE : peut-être mieux avec un sort direct?
    }
}*/

}
