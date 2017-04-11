#include "bric.h"
#include "direction.h"
#include <algorithm>

using namespace GJ_GW;

Bric::Bric(){}

Bric::Bric(std::vector<Position> &shape, Color color){
    shape_ = validate(shape);
    color_ = color;

    std::cout << ", "
              << this->to_string()
              << std::endl;

}

std::vector<Position> Bric::validate(std::vector<Position> shape){
    std::vector<Position> tested;
    std::vector<unsigned> tempX;
    std::vector<unsigned> tempY;

    if(shape.at(0).getY() != 0){
        throw std::invalid_argument(message());
    }
    tested.push_back(shape.at(0));
    tempX.push_back(shape.at(0).getX());
    tempY.push_back(shape.at(0).getY());
    for(Position p : shape){
        if(tested.size() > 1){
            if(! isAdjacent(tested, p)){
                throw std::invalid_argument(message());
            }
        }
        tested.push_back(p);
        tempX.push_back((p.getX()));
        tempY.push_back(p.getY());
    }
    std::sort(tempX.begin(), tempX.end());
    if(tempX.at(0) != 0){
        adjustPositions(shape, tempX.at(0));
    }
    tempX.erase(std::unique(tempX.begin(), tempX.end()), tempX.end());
    unsigned sideX = tempX.size();
    std::sort(tempY.begin(), tempY.end());
    tempY.erase(std::unique(tempY.begin(), tempY.end()), tempY.end());
    unsigned sideY = tempY.size();
    if(sideX > 6 || sideX < sideY){
        throw std::invalid_argument(message());
    }
    if(sideX % 2 == 0){
        even_ = 1;
        middle_ = Position((sideX/2)-1, (sideX/2)-1);
    } else{
        even_ = 0;
        middle_ = Position(sideX/2, sideX/2);
    }

    std::cout << "side : "
              << sideX;

    return shape;
}

bool Bric::isAdjacent(std::vector<Position> &tested, Position &pos) const{
    bool ok {0};
    unsigned count {0};
    while(! ok && count < tested.size()){
        ok = tested.at(count).isAdjacent(pos);
        ++count;
    }
    return ok;
}

void Bric::adjustPositions(std::vector<Position> &shape, unsigned xMin){
    for(auto it {shape.begin()}; it != shape.end(); ++it){
        it->setX(xMin*-1);
    }
}

std::string Bric::message() const{
    return "Votre brique n'est pas valide, veuillez vérifier que :\n"
           "    - la 1ère case touche le haut du repère\n"
           "    - toutes les cases sont adjacentes à une autre\n"
           "    - la brique est placées horizontalement\n"
           "    - la taille de côté de la brique n'excède pas "+ std::to_string(MAXIMUM_SIDE);
}

std::vector<Position> Bric::getShape() const{
    return shape_;
}

Position Bric::getMiddle() const{
    return middle_;
}

bool Bric::isEven() const{
    return even_;
}

Color Bric::getColor() const{
    return color_;
}

unsigned Bric::getHigherY(){
    Position temp {shape_.at(0)};
    for(Position p : shape_){
        if(temp > p)
            temp = p;
    }
    return temp.getY();
}

void Bric::move(Direction dir){
    switch(dir){
    case Direction::LEFT:
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setX(-1);
        }
        middle_.setX(-1);
        break;
    case Direction::RIGHT:
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setX(1);
        }
        middle_.setX(1);
        break;
    case Direction::UP:
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setY(-1);
        }
        middle_.setY(-1);
        break;
    default:     //bas
        for(unsigned u = 0; u < shape_.size(); ++u){
            shape_.at(u).setY(1);
        }
        middle_.setY(1);
        break;
    }
}

void Bric::rotate(){
    double midX = middle_.getX(), midY = middle_.getY();
    if(even_){
        midX += 0.5;
        midY += 0.5;
    }
    for(unsigned u {0}; u < shape_.size(); ++u){
        shape_.at(u) = Position (
                    //middle_.getX() - shape_.at(u).getY() + middle_.getY(),
                    //middle_.getY() + shape_.at(u).getX() - middle_.getX());
                    midX - shape_.at(u).getY() + midY, midY + shape_.at(u).getX() - midX);

    }
}

bool Bric::contains(Position & pos) const{
    bool ok {0};
    for(Position p : shape_){
        if(p == pos){
            ok = 1;
        }
    }
    return ok;
}



std::string Bric::to_string() const{
    std::string s;
    for(auto it = shape_.begin(); it != shape_.end(); ++it){
        s += it->to_string();
    }
    s += ", milieu : " + middle_.to_string();
    return s;
}

namespace GJ_GW {
std::ostream & operator<<(std::ostream & out, const Bric & in){
    out << in.to_string();
    return out;
}
}
