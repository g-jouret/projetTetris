#include "board.h"
#include "linestate.h"

using namespace GJ_GW;

Board::Board(unsigned width, unsigned height): width_{width}, height_{height}{
    for(unsigned u {0}; u < width; ++u){
        for(unsigned j{0}; j < height; ++j){
            grid_.emplace(std::pair<Position,Color>{Position(u, j), Color()});
        }
    }
}

std::map<Position, Color> Board::getGrid() const{
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
        return grid_.at(pos) == Color();
    return 0;
}

bool Board::checkCase(unsigned &x, unsigned &y) const{
    return grid_.at(Position(x, y)) == Color();
}

unsigned Board::checkColumn(unsigned y){
    LineState state {LineState::NONE};
    unsigned u {height_-1};
    if(y > u){
        throw std::invalid_argument("la ligne est hors de la grille");
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
            state = LineState::EMPTY;
        } else{
            state = LineState::FILL;
        }
    }
    if((state == LineState::FILL && checkCase(x,y)) || (state == LineState::EMPTY && ! checkCase(x,y))){
        state = LineState::BOTH;
    } else{
        if(x < width_-1){
            ++x;
            checkRow(x, y, state);
        }
    }
    return state;
}

void Board::swapCase(Position &pos, Color color){
    (grid_.at(pos) == Color())? grid_.at(pos) = color : grid_.at(pos) = Color();
}

void Board::EmptyRow(unsigned y){
    for(unsigned u {0}; u < width_; ++u){
        Position pos {Position(u, y)};
        swapCase(pos, Color());
    }
}

void Board::moveLine(unsigned y, unsigned lineNb){
    for(unsigned u {0}; u < width_; ++u){
        if(! checkCase(u, y)){
            Position pos {Position(u, y)};
            Color temp {grid_.at(pos)};
            swapCase(pos, Color());
            pos = Position(pos.getX(),pos.getY()+lineNb);
            swapCase(pos, temp);
        }
    }
}

unsigned Board::gridActualisation(unsigned lineNum){
    unsigned lineCount {1};
    LineState state;
    EmptyRow(lineNum);
    do {
        state = LineState::NONE;
        --lineNum;
        state = checkRow(0, lineNum, state);
        if(state == LineState::FILL){
            ++lineCount;
            EmptyRow(lineNum);
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
