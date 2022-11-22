#include "Equation.h"

Equation::Equation() {}

Equation::Equation(const Equation& lhs) {
    for (auto i : lhs.roots) {
        roots.push_back(i);
    }
}

Equation::Equation(Equation&& rhs) {
    for (auto i : rhs.roots) {
        roots.push_back(i);
    }
    rhs.roots.clear();
}

Equation& Equation::operator=(const Equation& lhs) {
    if (this == &lhs) { return *this; }

    Equation t(lhs);
    std::swap(roots, t.roots);

    return *this;
}

Equation& Equation::operator=(Equation&& lhs) {
    if (this == &lhs) { return *this; }

    Equation t(std::move(lhs));
    std::swap(roots, t.roots);

    return *this;
}


void Equation::add_root(ROOT_TYPE root) {
    roots.push_back(root);
}

ROOT_TYPE Equation::operator()(ROOT_TYPE x) {
    std::complex<double> res(1);

    for (auto xi : roots) {
        res *= (x - xi);
    }

    return res;
}


ROOT_TYPE Equation::dfdx(ROOT_TYPE x) {
    ROOT_TYPE res;

    for (size_t i = 0; i < roots.size(); i++) {
        ROOT_TYPE sum(1);
        for (size_t j = 0; j < roots.size(); j++) {
            if (i != j) { sum *= (x - roots[j]); }
        }

        res += sum;
    }

    return res;
}
