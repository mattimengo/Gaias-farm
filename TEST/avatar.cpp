#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "avatar.h"




void movement::up(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos_y -= step;  // Movimento verso l'alto
        std::cout << "W pressed: New pos_y = " << pos_y << std::endl;
    }

    //bordo superiore
    if (pos_y < max_heightchngd) {
        pos_y = clone_y;
    }
}

void movement::down(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos_y += step; // Movimento verso il basso
        std::cout << "S pressed: New pos_y = " << pos_y << std::endl;
    }

    //bordo inferiore
    if (pos_y > min_heightchngd) {
        pos_y = c_y;
    }

    //recinto alto sx
    if (pos_y > recintos_y && pos_x < corner1_x) {
        pos_y = clones_y;
    }

    //recinto alto dx
    if (pos_y > recintos_y && pos_x > corner2_x) {
        pos_y = clones_y;
    }
}

void movement::left(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos_x -= step; // Movimento verso sinistra
        std::cout << "A pressed: New pos_x = " << pos_x << std::endl;
    }    

    //bordo sinistro
    if (pos_x < min_widhtchngd) {
        pos_x = c_x;
    }


    //recinto verticale sx
    if (pos_x < corner1_x && pos_y > recintos_y) {
        pos_x = clones_x;
    }
}

void movement::right(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_x += step; // Movimento verso destra
        std::cout << "D pressed: New pos_x = " << pos_x << std::endl;
    }   

    //bordo destro
    if (pos_x > max_widhtchngd) {
        pos_x = clone_x;
    }


    //recinto verticale dx
    if (pos_x > corner2_x && pos_y > recintos_y) {
        pos_x = corner2_x;

    }
}











