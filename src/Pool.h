#include "handler.h"
#include "Equation.h"
#include "Complex_plane.h"
#include "Algorithm.h"
#include <SFML/Graphics.hpp>

#ifndef POOL_H
#define POOL_H

class Pool : public sf::Drawable{
public:
    // RAII
    Pool(const Pool& lhs);
    Pool(Pool&& rhs);
    Pool& operator=(const Pool& lhs);
    Pool& operator=(Pool&& lhs);
    // ~Pool();

    void create_plane(ComplexPlane plane_);
    void set_equation(Equation eq_);

    Pool();
    Pool(sf::VideoMode mode_, ComplexPlane plane_, size_t DEEP_);

    void render(Equation eq_);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    size_t WIDTH, HEIGHT;
    NUMBER_TYPE x_left, x_right, y_up, y_down;
    NUMBER_TYPE dx, dy;
    size_t DEEP;

    std::vector<sf::CircleShape> points;
    size_t r = 10;

    sf::VertexArray pixels;
};

#endif
