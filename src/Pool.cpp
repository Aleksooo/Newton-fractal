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
    xc(0), yc(0),
    DEEP(DEEP_) {
        pixels.setPrimitiveType(sf::Points);
        pixels.resize(WIDTH * HEIGHT);
        for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
            pixels[i].position = sf::Vector2f(i % WIDTH, i / WIDTH);
        }

        data.reserve(WIDTH * HEIGHT);
        for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
            data.push_back(sf::Color::Black);
        }
    }

void Pool::render(Equation eq_) {
    NUMBER_TYPE dx = (x_right - x_left) / (WIDTH - 1);
    NUMBER_TYPE dy = (y_up - y_down) / (HEIGHT - 1);
    std::vector<NUMBER_TYPE> id_dists;
    for (size_t i = 0; i < eq_.size(); i++) {
        id_dists.push_back(0);
    }

    // 'Y' coord
    for (size_t i = 0; i < HEIGHT; i++) {
        // 'X' coord
        for (size_t j = 0; j < WIDTH; j++) {
            ROOT_TYPE xi(x_left + (xc + j / sx) * dx, y_down + (yc + i / sy) * dy);
            dist(eq_, newton_algorithm(eq_, xi, DEEP), id_dists);

            data[WIDTH * i + j] = pallete.color(id_dists);
        }
    }

    for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i].color = data[i];
    }

    points.clear();
    for (size_t i = 0; i < eq_.size(); i++) {
        sf::CircleShape circ(r);
        circ.setPosition(sf::Vector2f(((eq_[i].real() - x_left) / dx - xc) * sx - r, ((eq_[i].imag() - y_down) / dy - yc) - r));
        circ.setFillColor(sf::Color::Black);
        points.push_back(circ);
    }

    x_left += xc * dx;
    x_right = x_left + (WIDTH - 1) * dx / sx;
    y_down += yc * dy;
    y_up = y_down + (HEIGHT - 1) * dy / sy;

    std::cout << "x_left : " << x_left << "\n";
    std::cout << "x_right : " << x_right << "\n";
    std::cout << "y_down : " << y_down << "\n";
    std::cout << "y_up : " << y_up << "\n";

    sx = 1;
    sy = 1;

    xc = 0;
    yc = 0;
}

void Pool::zoom(NUMBER_TYPE dsxy_) {
    xc += WIDTH * dsxy_ / sx / (1 + dsxy_) / 2;
    yc += HEIGHT * dsxy_ / sy / (1 + dsxy_) / 2;

    sx *= (1 + dsxy_);
    sy *= (1 + dsxy_);

    // std::cout << "corner : (" << xc << ", " << yc << ")\n";
    std::cout << "scale : (" << sx << ", " << sy << ")\n";
}

void Pool::update() {
    // 'Y' coord
    for (int i = 0; i < HEIGHT; i++) {
        // 'X' coord
        for (int j = 0; j < WIDTH; j++) {
            int x = static_cast<int>(std::round(xc + j / sx));
            int y = static_cast<int>(std::round(yc + i / sy));

            if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0) {
                // std::cout << "(" << j << ", " << i << ") - > (" << x << ", " << y << ")\n";
                pixels[WIDTH * i + j].color = sf::Color::Black;
            } else {
                pixels[WIDTH * i + j].color = data[WIDTH * y + x];
            }
        }
    }
}

void Pool::move(NUMBER_TYPE dx_, NUMBER_TYPE dy_) {
    xc += dx_ / sx;
    yc += dy_ / sy;
    // std::cout << "corner : (" << xc << ", " << yc << ")\n";
}

void Pool::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = NULL;

    target.draw(pixels, states);

    for (auto circ : points) {
        target.draw(circ, states);
    }
}
