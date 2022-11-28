#include "Pool.h"

// RAII
Pool::Pool(const Pool& lhs) {}
Pool::Pool(Pool&& rhs) {}
Pool& Pool::operator=(const Pool& lhs) {}
Pool& Pool::operator=(Pool&& lhs) {}
// ~Pool();

void Pool::create_plane(ComplexPlane plane_) {}

void set_equation(Equation eq_) {}

Pool::Pool() {}
Pool::Pool(sf::VideoMode mode_, ComplexPlane plane_, size_t DEEP_) :
    WIDTH(mode_.width),
    HEIGHT(mode_.height),
    x_left(plane_.x_left),
    x_right(plane_.x_right),
    y_up(plane_.y_up),
    y_down(plane_.y_down),
    DEEP(DEEP_) {
        dx = (x_right - x_left) / (WIDTH - 1);
        dy = (y_up - y_down) / (HEIGHT - 1);

        pixels.setPrimitiveType(sf::Points);
        pixels.resize(WIDTH * HEIGHT);
    }

void Pool::render(Equation eq_) {
    // 'Y' coord
    for (size_t i = 0; i < HEIGHT; i++) {
        // 'X' coord
        for (size_t j = 0; j < WIDTH; j++) {
            ROOT_TYPE xi(j * dx + x_left, i * dy + y_down);
            int id = dist(eq_, newton_algorithm(eq_, xi, DEEP));
            pixels[WIDTH * i + j].position = sf::Vector2f(j, i);

            if (id == 0) {
                pixels[WIDTH * i + j].color = sf::Color::Green;
            } else if (id == 1) {
                pixels[WIDTH * i + j].color = sf::Color::Red;
            } else if (id == 2) {
                pixels[WIDTH * i + j].color = sf::Color::Blue;
            } else if (id == 3) {
                pixels[WIDTH * i + j].color = sf::Color::Yellow;
            }
        }
    }

    for (size_t i = 0; i < eq_.size(); i++) {
        sf::CircleShape circ(r);
        circ.setPosition(sf::Vector2f((eq_[i].real() - x_left) / dx - r, (eq_[i].imag() - y_down) / dy - r));
        circ.setFillColor(sf::Color::Black);
        points.push_back(circ);
    }
}

void Pool::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // states.transform *= getTransform();
    // states.texture = NULL;

    target.draw(pixels, states);

    for (auto circ : points) {
        target.draw(circ, states);
    }
}
