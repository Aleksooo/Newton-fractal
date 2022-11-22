#include <iostream>
#include <complex>
#include <vector>

typedef double NUMBER_TYPE;
typedef std::complex<NUMBER_TYPE> ROOT_TYPE;

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
    ROOT_TYPE operator()(ROOT_TYPE x);
    ROOT_TYPE dfdx(ROOT_TYPE x);
private:
    std::vector<ROOT_TYPE> roots;
};
