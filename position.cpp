#include "position.h"

//namespace GJ_GW{

Position::Position(): Position(0,0)
{}

Position::Position(unsigned x, unsigned y): x_{x}, y_{y}, filled_{0}
{}

void Position::swapFilled(){
    if(filled_){
        filled_ = 0;
    } else{
        filled_ = 1;
    }
    //filled_ = (filled_)? 0 : 1;
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

/*std::string Position::to_string() const{
std::string s;
s += "(";
s += std::to_string(x_);
s += ", ";
s += std::to_string(y_);
s += ") : ";
s += std::to_string(filled_);
return s;
}*/

/*std::ostream & operator<<(std::ostream & out, const Position & in){
out << in.to_string();
return out;
}*/

//} //namespace GJ_GW
