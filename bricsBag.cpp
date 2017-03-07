#include "bricsBag.h"
#include <vector>

namespace GJ_GW{

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

BricsBag::BricsBag(std::vector<Bric> brics): brics_ {brics}
{}

}
