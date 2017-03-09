#include "position.h"

namespace GJ_GW{

Position::Position(): Position(0,0)
{}

Position::Position(unsigned x, unsigned y): x_{x}, y_{y}, filled_{0}
{}

void Position::swapFilled(){
    filled_ = (filled_)? 0 : 1;
}

}
