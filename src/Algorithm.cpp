#include "Algorithm.h"

ROOT_TYPE newton_algorithm(Equation& eq, ROOT_TYPE x0, size_t N) {
    if (N == 0) { return x0; }

    ROOT_TYPE target = x0;
    ROOT_TYPE step;
    for (size_t i = 0; i < N; i++) {
        step = eq(target) / eq.dfdx(target);
        target -= step;
        // std::cout << "iter " << i << ": " << target << "\n";
    }

    return target;
}

size_t dist(Equation& eq, ROOT_TYPE x) {
    size_t id = 0;
    NUMBER_TYPE id_mag = std::abs(eq[0] - x);
    // std::cout << 0 << ": " << eq[0] << " " << x << "\n";
    for (size_t i = 1; i < eq.size(); i++) {
        //std::cout << i << ": " << eq[i] << " " << x << "\n";
        if (std::abs(eq[i] - x) < id_mag) {
            id = i;
            id_mag = std::abs(eq[i] - x);
        }
    }

    return id;
}
