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
    std::string path_config("config.json");
    std::ifstream fc(path_config);
    json config = json::parse(fc);

    std::string path_settings("settings.json");
    std::ifstream fs(path_settings);
    json settings = json::parse(fs);

    NUMBER_TYPE button_zoom_speed = settings["button_zoom_speed"];
    NUMBER_TYPE button_move_speed = settings["button_move_speed"];

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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    pool.zoom(button_zoom_speed);
                    // pool.update();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    pool.zoom(-button_zoom_speed);
                    // pool.update();
                }

                if (event.key.code == sf::Keyboard::Space) {
                    pool.render(eq);
                    // pool.update();
                }
                // --------------------------------------------------
                if (event.key.code == sf::Keyboard::W) {
                    pool.move(0, -button_move_speed);
                }

                if (event.key.code == sf::Keyboard::S) {
                    pool.move(0, button_move_speed);
                }

                if (event.key.code == sf::Keyboard::A) {
                    pool.move(-button_move_speed, 0);
                }

                if (event.key.code == sf::Keyboard::D) {
                    pool.move(button_move_speed, 0);
                }
            }
        }

        window.clear();

        pool.update();
        window.draw(pool);

        window.display();
    }

    return 0;
}
