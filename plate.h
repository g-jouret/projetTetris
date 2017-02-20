#ifndef PLATE_H
#define PLATE_H

#include <vector>
#include <array>
#include "case.h"

namespace g40853{

class Plate{
public:
    Plate();
    Plate(unsigned height, unsigned width);
private:
    const unsigned height_ = 20;
    const unsigned width_ = 10;
    std::vector<std::vector<Case, width_>, height_> grid;

    int validate(int value);
};

//prototypes

//implémentations inline

//fonctions inline

//méthodes inline

}

#endif // PLATE_H
