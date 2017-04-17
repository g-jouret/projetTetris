#include "bric.h"
#include "direction.h"
#include <algorithm>
#include <stdexcept>

using namespace GJ_GW;

Bric::Bric(){
    side_ = 0;
}

Bric::Bric(std::vector<Position> &shape, Color color){
    shape_ = validateShape(shape);
    side_ = validateSide().at(0);
    if(side_ % 2 == 0){
        middle_ = Position((side_/2)-1, (side_/2)-1);
    } else{
        middle_ = Position(side_/2, side_/2);
    }
    if(validateSide().at(1) == 1 && side_ > 1){
        middle_.setY(-1);
    }
    color_ = color;
}

unsigned Bric::calculateSideSize(std::vector<unsigned> side){
    std::sort(side.begin(), side.end());
    side.erase(std::unique(side.begin(), side.end()), side.end());
    return side.size();
}

std::vector<unsigned> Bric::validateSide(){
    std::vector<unsigned> tempX;
    std::vector<unsigned> tempY;
    unsigned sideX;
    unsigned sideY;
    for(Position p : shape_){
        tempX.push_back((p.x_));
        tempY.push_back(p.y_);
    }
    std::sort(tempX.begin(), tempX.end());
    if(tempX.at(0) != 0){
        adjustPositions(tempX.at(0));
    }
    sideX = calculateSideSize(tempX);
    sideY = calculateSideSize(tempY);
    if(sideX < sideY){
        throw std::invalid_argument(message("la brique n'est pas placées horizontalement"));
    }
    if(sideX > MAXIMUM_SIDE){
        throw std::invalid_argument(message("la taille de côté de la brique excède "+ std::to_string(MAXIMUM_SIDE)));
    }
    return {sideX, sideY};
}

std::vector<Position> Bric::validateShape(std::vector<Position> shape) const{
    std::vector<Position> tested;
    if(shape.at(0).getY() != 0){
        throw std::invalid_argument(message("la 1ère case ne touche pas le haut du repère"));
    }
    tested.push_back(shape.at(0));
    for(Position p : shape){
        if(tested.size() > 1){
            if(! isAdjacent(tested, p)){
                throw std::invalid_argument(message("toutes les cases ne sont pas adjacentes à une autre"));
            }
        }
        tested.push_back(p);
    }
    return shape;
}

bool Bric::isAdjacent(std::vector<Position> &tested, Position &pos){
    bool ok {0};
    unsigned count {0};
    while(! ok && count < tested.size()){
        ok = tested.at(count).isAdjacent(pos);
        ++count;
    }
    return ok;
}

void Bric::adjustPositions(unsigned xMin){
    for(auto it {shape_.begin()}; it != shape_.end(); ++it){
        it->setX(-xMin);
    }
}

std::string Bric::message(std::string exception) const{
    return "Votre brique n'est pas valide, car " + exception;
}


unsigned Bric::getSide() const{
    return side_;
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
    return temp.y_;
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
    double midX = middle_.x_, midY = middle_.y_;
    if(side_%2 == 0){
        midX += 0.5;
        midY += 0.5;
    }
    for(unsigned u {0}; u < shape_.size(); ++u){
        shape_.at(u) = Position (midX - shape_.at(u).getY() + midY,
                                 midY + shape_.at(u).getX() - midX);
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
