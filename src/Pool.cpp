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
            pixels[i].position = sf::Vector2f(i / WIDTH, i % WIDTH);
        }

        // data.reserve(WIDTH * HEIGHT);
        for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
            data.push_back(sf::Color::Black);
        }
    }

void Pool::render(Equation eq_) {
    // std::cout << "x_left : " << x_left << "\n";
    // std::cout << "x_right : " << x_right << "\n";
    // std::cout << "y_down : " << y_down << "\n";
    // std::cout << "y_up : " << y_up << "\n";

    NUMBER_TYPE dx = (x_right - x_left) / (WIDTH - 1);
    NUMBER_TYPE dy = (y_up - y_down) / (HEIGHT - 1);
    // 'Y' coord
    for (size_t i = 0; i < HEIGHT; i++) {
        // 'X' coord
        for (size_t j = 0; j < WIDTH; j++) {
            ROOT_TYPE xi(x_left + (xc + j / sx)* dx, y_down + (yc + i / sy) * dy);
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

    points.clear();
    for (size_t i = 0; i < eq_.size(); i++) {
        sf::CircleShape circ(r);
        circ.setPosition(sf::Vector2f((eq_[i].real() * sx - x_left) / dx - r, (eq_[i].imag() * sy - y_down) / dy - r));
        circ.setFillColor(sf::Color::Black);
        points.push_back(circ);
    }

    x_left += sx * xc * dx;
    x_right += (sx * xc - WIDTH * (sx - 1)) * dx;
    y_down += sy * yc * dy;
    y_up += (sy * yc - HEIGHT * (sy - 1)) * dy;

    sx = 1;
    sy = 1;

    xc = 0;
    yc = 0;
}

void Pool::zoom(NUMBER_TYPE dsxy_) {
    xc += WIDTH * dsxy_ / sx / (sx + dsxy_) / 2;
    yc += HEIGHT * dsxy_ / sy / (sy + dsxy_) / 2;

    sx += dsxy_;
    sy += dsxy_;

    std::cout << "corner : (" << xc << ", " << yc << ")\n";
    std::cout << "scale : (" << sx << ", " << sy << ")\n";
    changed = true;
}

void Pool::update() {
    // if (changed) {
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

        // changed = false;
    // }
}

void Pool::set_mouse_pos(NUMBER_TYPE xm_, NUMBER_TYPE ym_) {
    // dx = xm_;
    // dy = ym_;
}

void Pool::move(NUMBER_TYPE dx_, NUMBER_TYPE dy_) {
    yc -= dx_;
    xc -= dy_;
    std::cout << "corner : (" << xc << ", " << yc << ")\n";

    changed = true;
}

void Pool::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = NULL;

    target.draw(pixels, states);

    for (auto circ : points) {
        target.draw(circ, states);
    }
}
