#include "Algorithm.h"

ROOT_TYPE newton_algorithm(Equation& eq, ROOT_TYPE x0, size_t N) {
    if (N == 0) { return x0; }

    // NUMBER_TYPE epsilon = 1.0e-6;
    ROOT_TYPE target = x0;
    // ROOT_TYPE fx, dfx;
    for (size_t i = 0; i < N; i++) {
        // fx = eq(target);
        // fx = eq.Horner(target);
        // dfx = eq.dfdx(target);
        // dfx = eq.Horner_dfdx(target);

        // if (std::abs(fx) < epsilon || std::abs(dfx) < epsilon) {
        //     return target;
        // }

        // target -= fx / dfx;
        target -= eq.fdf(target);
    }

    return target;
}
