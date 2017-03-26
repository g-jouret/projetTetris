#include "board.h"

using namespace GJ_GW;

Board::Board(unsigned width, unsigned height): width_{width}, height_{height}{
    for(unsigned u {0}; u < width; ++u){
        for(unsigned j{0}; j < height; ++j){
            grid_.emplace(std::pair<Position,bool>{Position(u, j), 0});
        }
    }
}

std::map<Position, bool> Board::getGrid() const{
    return grid_;
}

unsigned Board::getHeight() const{
    return height_;
}

unsigned Board::getWidth() const{
    return width_;
}

bool Board::contains(Position & pos) const{
    return pos.getX() < width_ && pos.getY() < height_;
}

bool Board::checkCase(Position & pos) const{
    if(contains(pos))
        return ! grid_.at(pos);
    return 0;
}

void Board::swapCase(Position &pos){
    (grid_.at(pos))? grid_.at(pos) = 0 : grid_.at(pos) = 1;
}

std::map<Position, bool> Board::getLine(unsigned lineNum) const{
    /*std::map<Position, bool> theLine;
    for(auto it = grid_.begin(); it != grid_.end(); ++it){
        if(){
            theLine.push_back(p);
        }
    }
    return theLine;
}

void Board::swapCase(Position & pos){
    grid_.at(pos) = grid_.at(pos)%1;*/
}

unsigned Board::checkLine(std::map<Position, bool> line){
    /*unsigned check;
    bool fill;
    fill = line.at(0).isFilled();
    fill? check = 1 : check = 0;
    for(Position p : line){
        if((p.isFilled() && ! fill) || (! p.isFilled() &&  fill)){
            check = 2;
        }
    }
    return check;*/
}

void Board::swapLine(std::map<Position, bool> line){
    /*for(Position p : line){
        getCase(p).swapFilled();
    }*/
}

void Board::moveLine(std::map<Position, bool> line, unsigned lineNb){
    /*for(Position p : line){
        if(p.isFilled()){
            getCase(p).swapFilled();
            Position pos = Position(p.getX(),p.getY()+lineNb);
            getCase(pos).swapFilled();
        }
    }*/
}

unsigned Board::gridActualisation(unsigned lineNum){
    /*unsigned lineCount {1}, check;
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
    return lineCount;*/
}

std::string Board::to_string() const{
    /*std::string s;
    for(unsigned i = 0; i < height_; ++i){
        for(Position p : this->getLine(i)){
            s += "|";
            (p.isFilled())? s+="B" : s+=" ";
        }
        s += "\n";
    }
    return s;*/
}

std::ostream & operator<<(std::ostream & out, const Board & in){
    out << in.to_string();
    return out;
}
