#include "handler.h"

#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <cmath>

#include "Pool.h"
#include "Equation.h"
#include "../libs/json.hpp"
using json = nlohmann::json;

int main() {
    std::string path("config.json");
    std::ifstream f(path);
    json config = json::parse(f);

    size_t WIDTH = config["WIDTH"];
    size_t HEIGHT = config["HEIGHT"];
    size_t DEEP = config["DEEP"];
    auto roots = config["roots"];

    Equation eq;
    for (auto root : roots) {
        eq.add_root(ROOT_TYPE(root[0], root[1]));
    }

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pool");
    Pool pool(sf::VideoMode(WIDTH, HEIGHT), ComplexPlane(config["x_left"], config["x_right"], config["y_up"], config["y_down"]), DEEP);
    pool.render(eq);

    NUMBER_TYPE sx = 1;
    NUMBER_TYPE sy = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    sx += 0.2;
                    sy += 0.2;
                    pool.scale(sx, sy);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    sx -= 0.2;
                    sy -= 0.2;
                    pool.scale(sx, sy);
                }
            }
        }

        window.clear();

        window.draw(pool);

        window.display();
    }

    return 0;
}
