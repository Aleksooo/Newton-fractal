#include "handler.h"
#include <iostream>
#include <complex>
#include <vector>

#ifndef EQUATION_H
#define EQUATION_H

class Equation final {
public:
    Equation();

    // RAII
    Equation(const Equation& lhs);
    Equation(Equation&& rhs);
    Equation& operator=(const Equation& lhs);
    Equation& operator=(Equation&& lhs);
    // ~Equation();

    void add_root(ROOT_TYPE root);
    ROOT_TYPE& operator[](size_t i);
    size_t size();

    ROOT_TYPE operator()(ROOT_TYPE x);
    ROOT_TYPE dfdx(ROOT_TYPE x);
private:
    std::vector<ROOT_TYPE> roots;
};

#endif
