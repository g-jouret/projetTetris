#include "model/board.h"

Board::Board(unsigned width, unsigned height): width_{width}, height_{height}{
    for(unsigned u {0}; u < width; ++u){
        for(unsigned j{0}; j < height; ++j){
            grid_.emplace_back(Position(u, j));
        }
    }
}

std::vector<Position> Board::getGrid() const{
    return grid_;
}

unsigned Board::getHeight() const{
    return height_;
}

unsigned Board::getWidth() const{
    return width_;
}

Position &Board::getCase(Position & pos){
    auto it = grid_.begin();
    bool ok {0};
    while(it != grid_.end() && !ok){
        if(pos == *it){
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

bool Board::checkCaseFilled(Position & pos){
    return getCase(pos).isFilled();
}

bool Board::isIn(Position & pos){
    return pos.getX() < width_ && pos.getY() < height_;
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

void Board::swapCase(Position & pos){
    pos.swapFilled();
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
