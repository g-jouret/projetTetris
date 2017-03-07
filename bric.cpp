#include "bric.h"

#include <algorithm>
#include <ostream>

namespace GJ_GW{

Bric::Bric():shape_{Position(0,0)}, side_{0}
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

//Bric::Bric(const Bric & other): shape_{other.shape_}, side_{other.side_}{}
// NOTE à voir si utile

void Bric::move(unsigned direction){
    switch(direction){
    case 1:     //bas
        for(unsigned i = 0; i < shape_.size(); ++i){
            shape_.at(i).setY(1);
        }
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
    case 4:     //drop
// TODO implémentation drop
        break;
    default:
// TODO implémentation TetrisException
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

        // NOTE peut-être mieux avec un sort direct?
    }
}*/

}
