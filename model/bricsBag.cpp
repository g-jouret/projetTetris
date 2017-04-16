#include "bricsBag.h"
#include <algorithm>
#include <chrono>

using namespace GJ_GW;

BricsBag::BricsBag(){
    std::vector<Position> shapeI {Position(0,0),Position(1,0),Position(2,0),Position(3,0)};
    std::vector<Position> shapeO {Position(0,0),Position(1,0),Position(0,1),Position(1,1)};
    std::vector<Position> shapeT {Position(1,0),Position(1,1),Position(0,1),Position(2,1)};
    std::vector<Position> shapeL {Position(2,0),Position(2,1),Position(1,1),Position(0,1)};
    std::vector<Position> shapeJ {Position(0,0),Position(0,1),Position(1,1),Position(2,1)};
    std::vector<Position> shapeZ {Position(0,0),Position(1,0),Position(1,1),Position(2,1)};
    std::vector<Position> shapeS {Position(2,0),Position(1,0),Position(1,1),Position(0,1)};
    std::vector<unsigned> colorI{130,180,190};
    std::vector<unsigned> colorO{255,215,0};
    std::vector<unsigned> colorT{50,50,160};
    std::vector<unsigned> colorL{220,120,30};
    std::vector<unsigned> colorJ{150,0,255};
    std::vector<unsigned> colorZ{150,20,30};
    std::vector<unsigned> colorS{150,200,7};
    brics_.push_back(Bric(shapeI, Color(colorI)));
    brics_.push_back(Bric(shapeO, Color(colorO)));
    brics_.push_back(Bric(shapeT, Color(colorT)));
    brics_.push_back(Bric(shapeL, Color(colorL)));
    brics_.push_back(Bric(shapeJ, Color(colorJ)));
    brics_.push_back(Bric(shapeZ, Color(colorZ)));
    brics_.push_back(Bric(shapeS, Color(colorS)));
}

BricsBag::BricsBag(std::vector<Bric> & brics): brics_ {brics}
{}

Bric BricsBag::getNextBric() const{
    if(brics_.size() == 1){
        return brics_.at(0);
    }
    return brics_.at(1);
}

Bric BricsBag::getCurrentBric() const{
    return brics_.at(0);
}

void BricsBag::add(std::vector<Bric> & newBrics){
    for(Bric b : newBrics){
        brics_.push_back(b);
    }
}

void BricsBag::shuffle(bool first){
    if(brics_.size() > 1){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        if(first){
            std::shuffle(brics_.begin(), brics_.end(), std::default_random_engine(seed));
        } else{
            std::swap(brics_.at(0), brics_.at(brics_.size()-1));
            std::swap(brics_.at(0), brics_.at(1));
            std::random_shuffle(++brics_.begin(), --brics_.end());
        }
    }
}
