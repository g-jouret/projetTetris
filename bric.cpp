#include "bric.h"

#include <ostream>

namespace g40853{

/* WARNING DB : piste pour implémentation de DEFAULT_BRICS
 Bric::Bric(std::vector<Position> shape):
    shape_ {
        std::vector<Position> {Position(shape.at(0),shape.at(1)), Position(shape.at(2),shape.at(3)), Position(shape.at(4),shape.at(5)), Position(shape.at(6),shape.at(7))}
}
{}*/

Bric::Bric(std::vector<Position> shape): shape_ {shape}
{}

}
