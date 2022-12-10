#include <chrono>
#include "handler.h"
#include "Equation.h"
#include "Complex_plane.h"
#include "Algorithm.h"
#include "Pallete.h"
#include <SFML/Graphics.hpp>

#ifndef POOL_H
#define POOL_H

class Pool : public sf::Drawable, public sf::Transformable{
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

    void render(Equation& eq_);
    void zoom(NUMBER_TYPE dsxy_);
    void update();
    void move(NUMBER_TYPE dx_, NUMBER_TYPE dy_);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int WIDTH, HEIGHT;
    NUMBER_TYPE x_left, x_right, y_up, y_down;
    NUMBER_TYPE sx, sy;
    NUMBER_TYPE xc, yc;
    size_t DEEP;

    std::vector<sf::CircleShape> points;
    size_t r = 10;

    sf::VertexArray pixels;
    std::vector<sf::Color> data;
    Pallete pallete;
};

#endif
