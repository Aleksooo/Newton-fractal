#include "handler.h"

#ifndef COMPELEXPLANE_H
#define COMPELEXPLANE_H

struct ComplexPlane {
    NUMBER_TYPE x_left, x_right, y_up, y_down;
    ComplexPlane(NUMBER_TYPE x_left_, NUMBER_TYPE x_right_, NUMBER_TYPE y_up_, NUMBER_TYPE y_down_) :
        x_left(x_left_),
        x_right(x_right_),
        y_up(y_up_),
        y_down(y_down_) {}
};

#endif
