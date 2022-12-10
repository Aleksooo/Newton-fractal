#include "handler.h"
#include <vector>
#include <iterator>
#include "Equation.h"

#ifndef ALGORITHM_H
#define ALGORITHM

ROOT_TYPE newton_algorithm(Equation& eq, ROOT_TYPE x0, size_t N);

void dist(Equation& eq, ROOT_TYPE x, std::vector<NUMBER_TYPE>& id_dists);

#endif
