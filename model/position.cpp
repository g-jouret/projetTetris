#include "position.h"

using namespace GJ_GW;

Position::Position(): Position(0,0)
{}

Position::Position(unsigned x, unsigned y): x_{x}, y_{y}
{}

void Position::setX(int x){
    x_ += x;
}

void Position::setY(int y){
    y_ += y;
}

bool Position::isAdjacent(const unsigned &x, const unsigned &y){
    return (x_ == x && (y_ == y-1 || y_ == y+1)) || (y_ == y && (x_ == x-1 || x_ == x+1));
}

bool Position::isAdjacent(const Position & other){
    return isAdjacent(other.x_, other.y_);
}



std::string Position::to_string() const{
    std::string s;
    s += "(";
    s += std::to_string(x_);
    s += ", ";
    s += std::to_string(y_);
    s += ")";
    return s;
}
namespace GJ_GW {
std::ostream & operator<<(std::ostream & out, const Position & in){
    out << in.to_string();
    return out;
}
}

