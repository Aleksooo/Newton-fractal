#include "handler.h"

#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

#include "Pool.h"
#include "Equation.h"

// #include <SFML/Graphics.hpp>

// int main() {
//     ROOT_TYPE x1(2, 1);
//     ROOT_TYPE x2(-3, 5);
//     ROOT_TYPE x0(-2.5, 4);

//     Equation eq;
//     eq.add_root(x1);
//     eq.add_root(x2);
//     std::cout << eq(x0) << " " << eq.dfdx(x0) << "\n";

//     ROOT_TYPE target = newton_algorithm(eq, x0, 10);

//     std::cout << "result: " << target << "\n";
//     std::cout << "nearest: " << dist(eq, target) << std::endl;

//     // App app;
//     // app.create(sf::VideoMode(800, 600), "Pool");
//     // app.run();

//     return 0;
// }

// int main()
// {
//     size_t WIDTH = 1300;
//     size_t HEIGHT = 1300;
//     size_t DEEP = 50;

//     double r = 10;

//     double x_left = -1;
//     double x_right = 1;
//     double y_down = -1;
//     double y_up = 1;

//     double x_center = (x_left + x_right) / 2;
//     std::cout << "x_center: " << x_center << "\n";
//     double y_center = (y_up + y_down) / 2;
//     std::cout << "y_center: " << y_center << "\n";

//     double dx = (x_right - x_left) / (WIDTH - 1);
//     std::cout << "dx: " << dx << "\n";
//     double dy = (y_up - y_down) / (HEIGHT - 1);
//     std::cout << "dy: " << dy << "\n";

//     sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
//     ROOT_TYPE x1(0, 0);
//     ROOT_TYPE x2(1, 0);
//     ROOT_TYPE x3(-std::sqrt(2)/2, std::sqrt(2)/2);
//     ROOT_TYPE x4(-0.5, -std::sqrt(3)/2);
//     // ROOT_TYPE x1(2, 1);
//     sf::CircleShape x1_c(r);
//     x1_c.setPosition(sf::Vector2f((x1.real() - x_left) / dx - r, (x1.imag() - y_down) / dy - r));
//     x1_c.setFillColor(sf::Color::Black);
//     std::cout << x1_c.getPosition().x << " " << x1_c.getPosition().y << "\n";
//     // std::cout << x1.real() / dx + WIDTH/2 << " " << x1.imag() / dy + HEIGHT/2 << "\n";
//     // ROOT_TYPE x2(-3, 4);
//     sf::CircleShape x2_c(r);
//     x2_c.setPosition(sf::Vector2f((x2.real() - x_left) / dx - r, (x2.imag() - y_down) / dy - r));
//     x2_c.setFillColor(sf::Color::Black);
//     std::cout << x2_c.getPosition().x << " " << x2_c.getPosition().y << "\n";
//     // std::cout << x2.real() / dx + WIDTH/2 << " " << x2.imag() / dy + HEIGHT/2 << "\n";
//     // ROOT_TYPE x3(-2.5, -4);
//     sf::CircleShape x3_c(r);
//     x3_c.setPosition(sf::Vector2f((x3.real() - x_left) / dx - r, (x3.imag() - y_down) / dy - r));
//     x3_c.setFillColor(sf::Color::Black);
//     std::cout << x3_c.getPosition().x << " " << x3_c.getPosition().y << "\n";
//     // std::cout << x3.real() / dx + WIDTH/2 << " " << x3.imag() / dy + HEIGHT/2 << "\n";
//     sf::CircleShape x4_c(r);
//     x4_c.setPosition(sf::Vector2f((x4.real() - x_left) / dx - r, (x4.imag() - y_down) / dy - r));
//     x4_c.setFillColor(sf::Color::Black);
//     std::cout << x4_c.getPosition().x << " " << x4_c.getPosition().y << "\n";

//     ROOT_TYPE x(-0.5, 0.5);

//     Equation eq;
//     // eq.add_root(x1);
//     eq.add_root(x2);
//     eq.add_root(x3);
//     eq.add_root(x4);
//     // std::cout << dist(eq, x) << "\n";

//     sf::VertexArray pixels(sf::Points, WIDTH * HEIGHT);

    // // 'Y' coord
    // for (size_t i = 0; i < HEIGHT; i++) {
    //     // 'X' coord
    //     for (size_t j = 0; j < WIDTH; j++) {
    //         ROOT_TYPE xi(j * dx + x_left, i * dy + y_down);
    //         // std::cout << xi << "\n";
    //         // ROOT_TYPE target = newton_algorithm(eq, xi, 10);
    //         int id = dist(eq, newton_algorithm(eq, xi, DEEP));
    //         // std::cout << target << ": " << id << "\n";
    //         // std::cout << id << "\n";
    //         pixels[WIDTH * i + j].position = sf::Vector2f(j, i);

    //         if (id == 0) {
    //             pixels[WIDTH * i + j].color = sf::Color::Green;
    //         } else if (id == 1) {
    //             pixels[WIDTH * i + j].color = sf::Color::Red;
    //         } else if (id == 2) {
    //             pixels[WIDTH * i + j].color = sf::Color::Blue;
    //         } else if (id == 3) {
    //             pixels[WIDTH * i + j].color = sf::Color::Yellow;
    //         }
    //     }
    // }

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();

//         window.draw(pixels);
//         // window.draw(x1_c);
//         window.draw(x2_c);
//         window.draw(x3_c);
//         window.draw(x4_c);

//         window.display();
//     }

//     return 0;
// }

int main() {
    size_t WIDTH = 1400;
    size_t HEIGHT = 1400;
    size_t DEEP = 50;

    ROOT_TYPE x1(1, 0);
    ROOT_TYPE x2(0, 1);
    ROOT_TYPE x3(-std::sqrt(3)/2, 0.5);
    ROOT_TYPE x4(-std::sqrt(2)/2, std::sqrt(2)/2);

    Equation eq;
    eq.add_root(x1);
    eq.add_root(x2);
    eq.add_root(x3);
    eq.add_root(x4);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pool");
    Pool pool(sf::VideoMode(WIDTH, HEIGHT), ComplexPlane(-1.0, 1.0, -1.0, 1.0), DEEP);
    pool.render(eq);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(pool);

        window.display();
    }

    return 0;
}
