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
    this->coeff_eval();
}

ROOT_TYPE Equation::operator()(ROOT_TYPE x) {
    ROOT_TYPE res(1);

    for (auto xi : roots) {
        res *= (x - xi);
    }

    return res;
}

ROOT_TYPE Equation::Horner(ROOT_TYPE x) {
    ROOT_TYPE res(coeff[roots.size()]);
    for (size_t i = roots.size(); i > 0; i--) {
        res = coeff[i-1] + x * res;
    }

    return res;
}

ROOT_TYPE& Equation::operator[](size_t i) { return roots[i]; }

size_t Equation::size() { return roots.size(); }

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

ROOT_TYPE Equation::Horner_dfdx(ROOT_TYPE x) {
    ROOT_TYPE res(dirr_coeff[roots.size() - 1]);
    for (size_t i = roots.size() - 1; i > 0; i--) {
        res = dirr_coeff[i-1] + x * res;
    }

    return res;
}

ROOT_TYPE Equation::fdf(ROOT_TYPE x) {
    ROOT_TYPE res(0);
    ROOT_TYPE ONE(1);

    for (size_t i = 0; i < roots.size(); i++) {
        res += ONE / (x - roots[i]);
    }

    return ONE / res;
}

void Equation::coeff_eval() {
    coeff.clear();
    coeff_eval(roots.size());
    dirr_coeff_eval();
}

void Equation::coeff_eval(size_t deg) {
    if (deg == 1) {
        coeff.push_back(-roots[deg - 1]);
        coeff.push_back(ROOT_TYPE(1));
    } else {
        coeff_eval(deg - 1);
        coeff.push_back(coeff[deg-1]);
        for (size_t i = deg-1; i > 0; i--) {
            coeff[i] = coeff[i - 1] - roots[deg - 1] * coeff[i];
        }
        coeff[0] *= (-roots[deg - 1]);
    }
}

void Equation::print_coeff() {
    std::cout << "Coefficients: ";
    auto itr = coeff.begin();
    while (itr != coeff.end()) {
        std::cout << *itr << " ";
        itr++;
    }
}

void Equation::dirr_coeff_eval() {
    dirr_coeff.clear();
    for (int i = 1; i < coeff.size(); i++) {
        dirr_coeff.push_back(ROOT_TYPE(i) * coeff[i]);
    }
}

void Equation::print_dirr_coeff() {
    std::cout << "Derivative coefficients: ";
    auto itr = dirr_coeff.begin();
    while (itr != dirr_coeff.end()) {
        std::cout << *itr << " ";
        itr++;
    }
}

