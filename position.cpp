#include "position.h"

namespace GJ_GW{

Position::Position(): x_ {0}, y_ {0}, filled_ {0}
{}

Position::Position(unsigned x, unsigned y): x_{x}, y_{y}, filled_{0}
{}

//unsigned Position::validate(unsigned value, unsigned limit){}

void Position::swapFilled(){
    filled_ = (filled_)? 0 : 1;
}

}
