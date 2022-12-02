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
    sx(1), sy(1),
    DEEP(DEEP_) {
        pixels.setPrimitiveType(sf::Points);
        pixels.resize(WIDTH * HEIGHT);
        for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
            pixels[i].position = sf::Vector2f(i / WIDTH, i % WIDTH);
        }

        // data.reserve(WIDTH * HEIGHT);
        for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
            data.push_back(sf::Color::Black);
        }
    }

void Pool::render(Equation eq_) {
    NUMBER_TYPE dx = (x_right - x_left) * sx / (WIDTH - 1);
    NUMBER_TYPE dy = (y_up - y_down) * sy / (HEIGHT - 1);
    // 'Y' coord
    for (size_t i = 0; i < HEIGHT; i++) {
        // 'X' coord
        for (size_t j = 0; j < WIDTH; j++) {
            ROOT_TYPE xi(j * dx + x_left, i * dy + y_down);
            int id = dist(eq_, newton_algorithm(eq_, xi, DEEP));

            if (id == 0) {
                data[WIDTH * i + j] = sf::Color::Green;
            } else if (id == 1) {
                data[WIDTH * i + j] = sf::Color::Red;
            } else if (id == 2) {
                data[WIDTH * i + j] = sf::Color::Blue;
            } else if (id == 3) {
                data[WIDTH * i + j] = sf::Color::Yellow;
            } else if (id == 4) {
                data[WIDTH * i + j] = sf::Color::Magenta;
            }
        }
    }

    for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i].color = data[i];
    }

    for (size_t i = 0; i < eq_.size(); i++) {
        sf::CircleShape circ(r);
        circ.setPosition(sf::Vector2f((eq_[i].real() - x_left) / dx - r, (eq_[i].imag() - y_down) / dy - r));
        circ.setFillColor(sf::Color::Black);
        points.push_back(circ);
    }
}

void Pool::scale(NUMBER_TYPE sx_, NUMBER_TYPE sy_) {
    // Rescale all paramets of pool
    sx = sx_;
    sy = sy_;

    // 'Y' coord
    for (int i = 0; i < HEIGHT; i++) {
        // 'X' coord
        for (int j = 0; j < WIDTH; j++) {
            int x = static_cast<int>(j + ((sx - 1) * (WIDTH / 2 - j)) / sx);
            int y = static_cast<int>(i + ((sy - 1) * (HEIGHT / 2- i)) / sy);

            if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0) {
                // std::cout << "(" << j << ", " << i << ") - > (" << x << ", " << y << ")\n";
                pixels[WIDTH * i + j].color = sf::Color::Black;
            } else {
                pixels[WIDTH * i + j].color = data[WIDTH * y + x];
            }
        }
    }
}

void Pool::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = NULL;

    target.draw(pixels, states);

    for (auto circ : points) {
        target.draw(circ, states);
    }
}
