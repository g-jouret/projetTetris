#include "bricsBag.h"
#include <algorithm>
#include <chrono>

using namespace GJ_GW;

BricsBag::BricsBag(){
    std::vector<Position> bricI {Position(0,0),Position(1,0),Position(2,0),Position(3,0)};
    std::vector<Position> bricO {Position(0,0),Position(1,0),Position(0,1),Position(1,1)};
    std::vector<Position> bricT {Position(1,0),Position(1,1),Position(0,1),Position(2,1)};
    std::vector<Position> bricL {Position(2,0),Position(2,1),Position(1,1),Position(0,1)};
    std::vector<Position> bricJ {Position(0,0),Position(0,1),Position(1,1),Position(2,1)};
    std::vector<Position> bricZ {Position(0,0),Position(1,0),Position(1,1),Position(2,1)};
    std::vector<Position> bricS {Position(2,0),Position(1,0),Position(1,1),Position(0,1)};

    brics_.push_back(Bric(bricI, Color(std::vector<unsigned> {130,180,190})));
    brics_.push_back(Bric(bricO, Color(std::vector<unsigned> {255,215,0})));
    brics_.push_back(Bric(bricT, Color(std::vector<unsigned> {128,0,128})));
    brics_.push_back(Bric(bricL, Color(std::vector<unsigned> {218,165,32})));
    brics_.push_back(Bric(bricJ, Color(std::vector<unsigned>{150,0,255})));
    brics_.push_back(Bric(bricZ, Color(std::vector<unsigned>{150,20,30})));
    brics_.push_back(Bric(bricS, Color(std::vector<unsigned>{150,200,7})));
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



std::string BricsBag::to_string() const{
    std::string s;
    for(Bric b : brics_){
        s += b.to_string() + "\n";
    }
    return s;
}

namespace GJ_GW {
std::ostream & operator<<(std::ostream & out, const BricsBag & in){
    out << in.to_string();
    return out;
}
}

