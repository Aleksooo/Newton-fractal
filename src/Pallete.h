#include "handler.h"
#include <vector>
#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>

class Pallete {
public:
    Pallete();

    sf::Color color(std::vector<NUMBER_TYPE>& id_dists);

    inline size_t size();
    inline sf::Color operator[](size_t i);

private:
    std::vector<sf::Color> colors;
};
