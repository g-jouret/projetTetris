#include "board.h"
#include <stdexcept>
#include <ostream>
#include <iomanip>

namespace GJ_GW{

Board::Board(unsigned width, unsigned height):
width_{width}, height_{height}
{
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            grid_.push_back(Position(j,i));
        }
    }
}

// TODO : descendre les lignes au dessus de la ligne enlevé
// le faire à chaque fois, pourrait y avoir des cas spéciaux
std::vector<Position> Board::getLine(unsigned lineNum){
    std::vector<Position> theLine;
    for(Position p : grid_){
        if(p.getY() == lineNum){
            theLine.push_back(p);
        }
    }
    return theLine;
}

unsigned Board::checkLine(std::vector<Position> line){
    unsigned check;
    bool fill;
    fill = line.at(0).isFilled();
    fill? check = 1 : check = 0;
    for(Position p : line){
        if((p.isFilled() && ! fill) || (! p.isFilled() &&  fill)){
            check = 2;
        }
    }
    return check;
}

void Board::swapLine(std::vector<Position> line){
    for(Position p : line){
        p.swapFilled();
    }
}

Position * Board::getCase(Position destination){
    Position * pntPos {};
    for(Position p : grid_){
        if(p == destination){
            pntPos = &p;
        }
    }
    return pntPos;
}

void Board::swapFill(Position &toSwap){
    // NOTE : pourrait être intéressant de mettre une 2e vérif au cas où
    // pour être sur que toutes les positions font bien le même swap
        toSwap.swapFilled();
}

void Board::emptyLine(std::vector<Position> line){
    Position tmpPos;
    for(Position p : line){
            if(p.isFilled()){
                p.swapFilled();
                tmpPos = *getCase(Position(p.getX(),p.getY()+1));
                tmpPos.swapFilled();
            }
        }
}

void Board::gridActualisation(unsigned lineNum){
    // TODO implémentation
}

/*std::string Board::to_string() const{
    std::string s;
    for(Position p : grid_){
        s += "|";
        (p.isFilled())? s+="B" : s+=" ";
        if(p.getX() == width_){
            s += "|\n";
        }
    }
    return s;
}

std::ostream & operator<<(std::ostream & out, const Board & in){
    out << in.to_string();
    return out;
}*/

}
