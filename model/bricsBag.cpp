#include "bricsBag.h"
#include <algorithm>

using namespace GJ_GW;

BricsBag::BricsBag(){
    std::vector<Position> bricI {Position(0,0),Position(1,0),Position(2,0),Position(3,0)};
    std::vector<Position> bricO {Position(0,0),Position(1,0),Position(0,1),Position(1,1)};
    std::vector<Position> bricT {Position(1,0),Position(0,1),Position(1,1),Position(2,1)};
    std::vector<Position> bricJ {Position(0,0),Position(1,0),Position(2,0),Position(2,1)};
    std::vector<Position> bricL {Position(0,0),Position(1,0),Position(2,0),Position(0,1)};
    std::vector<Position> bricZ {Position(0,0),Position(1,0),Position(1,1),Position(2,1)};
    std::vector<Position> bricS {Position(1,0),Position(2,0),Position(0,1),Position(1,1)};
    // NOTE : condition de génération de Bric : 1ère position sur le bord => y = 0
    //      et la somme des y différents <= à la somme des x différents
    brics_.push_back(Bric(bricI));
    brics_.push_back(Bric(bricO));
    brics_.push_back(Bric(bricT));
    brics_.push_back(Bric(bricJ));
    brics_.push_back(Bric(bricL));
    brics_.push_back(Bric(bricZ));
    brics_.push_back(Bric(bricS));

}

BricsBag::BricsBag(std::vector<Bric> & brics): brics_ {brics}
{}

Bric BricsBag::getNextBric() const{
    return brics_.at(1);
}

Bric BricsBag::getCurrentBric() const{
    return brics_.at(0);
}

void BricsBag::shuffle(bool first){
    if(first){
        std::random_shuffle(brics_.begin(), brics_.end());
    } else{
        std::swap(brics_.at(0), brics_.at(brics_.size()-1));
        std::swap(brics_.at(0), brics_.at(1));
        std::random_shuffle(++brics_.begin(), --brics_.end());
    }
}

/*std::string BricsBag::to_string() const{
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
*/
