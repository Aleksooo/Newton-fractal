#include <iostream>
#include <complex>
#include <vector>

#include "App.h"
#include "Equation.h"

// #include <SFML/Graphics.hpp>

int main() {
    // std::complex<double> x1(2, 1);
    // std::complex<double> x2(3, 5);

    // Equation eq;
    // eq.add_root(x1);
    // eq.add_root(x2);
    // std::cout << eq(1) << " " << eq.dfdx(1) << std::endl;

    App app;
    app.create(sf::VideoMode(800, 600), "Pool");
    app.run();

    return 0;
}

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }
