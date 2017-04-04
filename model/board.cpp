#include "board.h"

using namespace GJ_GW;

void Board::debug(){
    swapRow(height_-1);
}

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

bool Board::checkCase(unsigned &x, unsigned &y) const{
    return grid_.at(Position(x, y));
}

unsigned Board::checkColumn(unsigned y){
    LineState state {LineState::NONE};
    unsigned u {height_-1};
    if(y > u){
        //throw new TetrisException
    }
    state = checkRow(0u, u, state);

    while(state != LineState::FILL && u > y){
        --u;
        state = LineState::NONE;
        state = checkRow(0, u, state);
    }
    if(state == LineState::FILL){
        u = gridActualisation(u);
    } else{
        u = 0;
    }

    return u;
}

LineState Board::checkRow(unsigned x, unsigned & y, LineState & state){
    if(state == LineState::NONE){
        if(checkCase(x,y)){
            state = LineState::FILL;
        } else{
            state = LineState::EMPTY;
        }
    }
    if((state == LineState::FILL && ! checkCase(x,y)) || (state == LineState::EMPTY && checkCase(x,y))){
        state = LineState::BOTH;
    } else{
        if(x < width_-1){
            ++x;
            checkRow(x, y, state);
        }
    }
    return state;
}

void Board::swapCase(Position &pos){
    (grid_.at(pos))? grid_.at(pos) = 0 : grid_.at(pos) = 1;
}

void Board::swapRow(unsigned y){
    for(unsigned u {0}; u < width_; ++u){
        Position pos {Position(u, y)};
        swapCase(pos);
    }
}

void Board::moveLine(unsigned y, unsigned lineNb){
    for(unsigned u {0}; u < width_; ++u){
        if(checkCase(u, y)){
            Position pos {Position(u, y)};
            swapCase(pos);
            pos = Position(pos.getX(),pos.getY()+lineNb);
            swapCase(pos);
        }
    }
}

unsigned Board::gridActualisation(unsigned lineNum){
    unsigned lineCount {1};
    LineState state;
    swapRow(lineNum);
    do {
        state = LineState::NONE;
        --lineNum;
        state = checkRow(0, lineNum, state);
        if(state == LineState::FILL){
            ++lineCount;
            swapRow(lineNum);
        } else{
            moveLine(lineNum, lineCount);
        }
    } while(state != LineState::EMPTY && lineNum != 0);
    return lineCount;
}

/*std::string Board::to_string() const{
    std::string s {""};
    for(auto it {grid_.begin()}; it != grid_.end(); ++it){
        if(it->second){
            s += it->first.to_string();
        }
    }
    return s;
}
namespace GJ_GW {
std::ostream & operator<<(std::ostream & out, const Board & in){
    out << in.to_string();
    return out;
}
}
*/
