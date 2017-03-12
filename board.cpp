#include "board.h"
#include <stdexcept>
#include <ostream>
#include <iomanip>

namespace GJ_GW{

Board::Board(unsigned width, unsigned height): width_{width}, height_{height}{
    for(unsigned i = 0; i < height; ++i){
        for(unsigned j = 0; j < width; ++j){
            grid_.emplace_back(Position(j, i));
        }
    }
}

unsigned Board::validateHeight(unsigned value){
    return (value == 0)? height_ : value;
}

unsigned Board::validateWidth(unsigned value){
    return (value == 0)? width_ : value;
}

Position * Board::getCase(Position destination){
    Position * pntPos {0};
    for(Position p : grid_){
        if(p == destination){
            pntPos = &p;
        }
    }
    return pntPos;
}

// TODO : descendre les lignes au dessus de la ligne enlevé
// le faire à chaque fois, pourrait y avoir des cas spéciaux
std::vector<Position> Board::getLine(unsigned lineNum) const{
    std::vector<Position> theLine;
    for(Position p : grid_){
        if(p.getY() == lineNum){
            theLine.push_back(p);
        }
    }
    return theLine;
}

bool Board::checkCase(Position pos){
    return this->getCase(pos)->isFilled();
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

void Board::swapCase(Position toSwap){
    this->getCase(toSwap)->swapFilled();
}

void Board::swapLine(std::vector<Position> line){
    for(Position p : line){
        this->getCase(p)->swapFilled();
    }
}

void Board::moveLine(std::vector<Position> line, unsigned lineNb){
    for(Position p : line){
        if(p.isFilled()){
            this->getCase(p)->swapFilled();
            this->getCase(Position(p.getX(),p.getY()+lineNb))->swapFilled();
        }
    }
}

unsigned Board::gridActualisation(unsigned lineNum){
    unsigned lineCount {1}, check;
    this->swapLine(this->getLine(lineNum));
    std::vector<Position> aboveLine;
    do {
        aboveLine = this->getLine(--lineNum);
        check = this->checkLine(aboveLine);
        if(check == 1){
            ++lineCount;
            this->swapLine(aboveLine);
        } else{
            this->moveLine(aboveLine, lineCount);
        }
    } while(check != 0 && lineNum != 0);
    return lineCount;
}

std::string Board::to_string() const{
    std::string s;
    for(unsigned i = 0; i < height_; ++i){
        for(Position p : this->getLine(i)){
            s += "|";
            (p.isFilled())? s+="B" : s+=" ";
        }
        s += "\n";
    }
    return s;
}

std::ostream & operator<<(std::ostream & out, const Board & in){
    out << in.to_string();
    return out;
}

}
