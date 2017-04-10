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
    /*brics_.push_back(Bric(bricI, std::vector<unsigned>{0x20,0xb2,0xaa}));
    brics_.push_back(Bric(bricO, std::vector<unsigned>{0xff,0xd7,0x00}));
    brics_.push_back(Bric(bricT, std::vector<unsigned>{0x80,0x00,0x80}));
    brics_.push_back(Bric(bricL, std::vector<unsigned>{0xda,0xa5,0x20}));
    brics_.push_back(Bric(bricJ, std::vector<unsigned>{0x00,0x00,0xff}));
    brics_.push_back(Bric(bricZ, std::vector<unsigned>{0xcd,0x5c,0x5c}));
    brics_.push_back(Bric(bricS, std::vector<unsigned>{0x00,0x80,0x00}));*/
    brics_.push_back(Bric(bricI, std::vector<unsigned>{32,178,170}));
    brics_.push_back(Bric(bricO, std::vector<unsigned>{255,215,0}));
    brics_.push_back(Bric(bricT, std::vector<unsigned>{128,0,128}));
    brics_.push_back(Bric(bricL, std::vector<unsigned>{218,165,32}));
    brics_.push_back(Bric(bricJ, std::vector<unsigned>{0,0,255}));
    brics_.push_back(Bric(bricZ, std::vector<unsigned>{205,92,92}));
    brics_.push_back(Bric(bricS, std::vector<unsigned>{0,128,0}));
}

BricsBag::BricsBag(std::vector<Bric> & brics): brics_ {brics}
{}

Bric BricsBag::getNextBric() const{
    return brics_.at(1);
}

Bric BricsBag::getCurrentBric() const{
    return brics_.at(0);
}

void BricsBag::add(Bric & bric){
    brics_.push_back(bric);
}

void BricsBag::shuffle(bool first){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    if(first){
        std::shuffle(brics_.begin(), brics_.end(), std::default_random_engine(seed));
    } else{
        std::swap(brics_.at(0), brics_.at(brics_.size()-1));
        std::swap(brics_.at(0), brics_.at(1));
        std::random_shuffle(++brics_.begin(), --brics_.end());
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

