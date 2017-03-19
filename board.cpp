#include "board.h"

//namespace GJ_GW{

Board::Board():Board(DEFAULT_WIDTH, DEFAULT_HEIGHT)
{}

Board::Board(unsigned width, unsigned height): width_{width}, height_{height}{
    for(unsigned u {0}; u < width; ++u){
        for(unsigned j{0}; j < height; ++j){
            grid_.emplace_back(Position(u, j));
        }
    }
}

std::vector<Position> Board::getGrid(){
    return grid_;
}

unsigned Board::getHeight(){
    return height_;
}

unsigned Board::getWidth(){
    return width_;
}

Position &Board::getCase(Position & destination){
    auto it = grid_.begin();
    bool ok {0};
    while(it != grid_.end() && !ok){
        if(destination == *it){
            ok = 1;
        } else{
            ++it;
        }
    }
    return *it;
}

std::vector<Position> Board::getLine(unsigned lineNum) const{
    std::vector<Position> theLine;
    for(Position p : grid_){
        if(p.getY() == lineNum){
            theLine.push_back(p);
        }
    }
    return theLine;
}

bool Board::checkCase(Position & pos){
    return getCase(pos).isFilled();
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

void Board::swapCase(Position & toSwap){
    toSwap.swapFilled();
}

void Board::swapLine(std::vector<Position> line){
    for(Position p : line){
        getCase(p).swapFilled();
    }
}

void Board::moveLine(std::vector<Position> line, unsigned lineNb){
    for(Position p : line){
        if(p.isFilled()){
            getCase(p).swapFilled();
            Position pos = Position(p.getX(),p.getY()+lineNb);
            getCase(pos).swapFilled();
        }
    }
}

unsigned Board::gridActualisation(unsigned lineNum){
    unsigned lineCount {1}, check;
    swapLine(getLine(lineNum));
    std::vector<Position> aboveLine;
    do {
        aboveLine = getLine(--lineNum);
        check = checkLine(aboveLine);
        if(check == 1){
            ++lineCount;
            swapLine(aboveLine);
        } else{
            moveLine(aboveLine, lineCount);
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

//} //namespace GJ_GW
