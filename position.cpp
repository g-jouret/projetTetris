#include "position.h"

namespace GJ_GW{

Position::Position(): Position(0,0)
{}

Position::Position(unsigned x, unsigned y): x_{x}, y_{y}, filled_{0}
{}

void Position::swapFilled(){
    filled_ = (filled_)? 0 : 1;
}

unsigned Position::getX(){
    return x_;
}

unsigned Position::getY(){
    return y_;
}

bool Position::isFilled(){
    return filled_;
}

void Position::setX(int x){
    x_ += x;
}

void Position::setY(int y){
    y_ += y;
}

}
