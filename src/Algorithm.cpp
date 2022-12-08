#include "Algorithm.h"

ROOT_TYPE newton_algorithm(Equation& eq, ROOT_TYPE x0, size_t N) {
    if (N == 0) { return x0; }

    ROOT_TYPE target = x0;
    ROOT_TYPE step;
    for (size_t i = 0; i < N; i++) {
        step = eq(target) / eq.dfdx(target);
        target -= step;
    }

    return target;
}

void dist(Equation& eq, ROOT_TYPE x, std::vector<NUMBER_TYPE>& id_dists) {
    for (size_t i = 0; i < eq.size(); i++) {
        id_dists[i] = std::abs(eq[i] - x);
    }
}
