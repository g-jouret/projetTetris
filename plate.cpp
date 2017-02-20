#include "plate.h"

namespace g40853{
Plate::Plate(){
this->Plate(20,10);
}
Plate::Plate(unsigned height, unsigned width):
height_{height}, width_{width}{
    validate(height);
    validate(width);
}
int Plate::validate(int value){
        if (value <= 0){
            throw std::invalid_argument {"Zero and negative values are not allowed"};
        }
        return value;
    }
}
