#include <stdexcept>
#include "board.h"

namespace g40853{
Board::Board(): Board(10, 20)
{}
Board::Board(unsigned width, unsigned height):
width_{width}, height_{height} {
    validate(width, 10);
    validate(height, 20);
}

unsigned Board::validate(unsigned value, unsigned def){
    return (value == 0)? def : value;
}

}
