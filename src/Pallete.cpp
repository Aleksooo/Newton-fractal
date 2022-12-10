#include "Pallete.h"

Pallete::Pallete() {
    colors.push_back(sf::Color(64, 64, 122)); // Purple
    colors.push_back(sf::Color(255, 82, 82)); // Red
    colors.push_back(sf::Color(52, 172, 224)); // Blue
    colors.push_back(sf::Color(255, 218, 121)); // Yellow
    colors.push_back(sf::Color(51, 217, 178)); // Green
    colors.push_back(sf::Color(255, 121, 63)); // Orange
}

sf::Color Pallete::color(std::vector<NUMBER_TYPE>& id_dists) {
    size_t min_id = 0;
    NUMBER_TYPE min_dist = id_dists[0];

    for (size_t i = 1; i < id_dists.size(); i++) {
        if (id_dists[i] < min_dist) {
            min_id = i;
            min_dist = id_dists[i];
        }
    }

    return colors[min_id];
}

inline size_t Pallete::size() {
    return colors.size();
}

inline sf::Color Pallete::operator[](size_t i) {
    return colors[i];
}
