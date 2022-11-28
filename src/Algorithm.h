#include "handler.h"
#include "Equation.h"

#ifndef ALGORITHM_H
#define ALGORITHM

ROOT_TYPE newton_algorithm(Equation& eq, ROOT_TYPE x0, size_t N);

size_t dist(Equation& eq, ROOT_TYPE x);

#endif
