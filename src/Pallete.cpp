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
    NUMBER_TYPE min_dist = id_dists[min_id];

    for (size_t i = 1; i < id_dists.size(); i++) {
        if (id_dists[i] < min_dist) {
            min_id = i;
            min_dist = id_dists[i];
        }
    }

    return colors[min_id];

    // sf::Color colr(0, 0, 0);
    // NUMBER_TYPE avg = 0;
    // NUMBER_TYPE sum_ex = 0;

    // for (size_t i = 1; i < id_dists.size(); i++) {
    //     avg += id_dists[i];
    // }
    // avg /= id_dists.size();

    // for (size_t i = 1; i < id_dists.size(); i++) {
    //     NUMBER_TYPE k = exp(id_dists[i] - avg);
    //     colr.r += colors[i].r * k;
    //     colr.g += colors[i].g * k;
    //     colr.b += colors[i].b * k;

    //     sum_ex += k;
    // }

    // colr.r /= sum_ex;
    // colr.g /= sum_ex;
    // colr.b /= sum_ex;

    // return colr;
}

size_t Pallete::size() {
    return colors.size();
}

sf::Color& Pallete::operator[](size_t i) {
    return colors[i];
}
