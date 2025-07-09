#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "avatar.h"








int main(const movement& up) {

    
    

    // Creazione finestra
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Fattoria");

    //----------------------------------------------------------------------------------------------------------------
    // Caricamento immagine sfondo
    sf::Texture texture;
    if (!texture.loadFromFile("assets/map1.jpg")) {
        std::cerr << "Failed to create texture from file!" << std::endl;
        return -1;
    }

    // Creazione sprite e abbinamento con texture
    sf::Sprite sprite(texture);

    //-------------------------------------------------------------------------------------------------------------------
    // Caricamento immagine avatar
    sf::Texture texta;
    if (!texta.loadFromFile("assets/avatar2d.png")) {
        std::cerr << "Failed to create texture from file!" << std::endl;
        return -1;
    }

    sf::Sprite spritea(texta);
    spritea.setPosition(907, 439); // Posiziona l'avatar sopra lo sfondo


    sf::Clock repairClock;  // Orologio per tracciare il tempo

    // Collegamento con il movimento
    movement player;

    // Loop principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Gestione movimento e input
        player.up(window);
        player.down(window);
        player.left(window);
        player.right(window);

        // Aggiorna la posizione dello sprite dell'avatar
        spritea.setPosition(player.pos_x, player.pos_y);




       // window.clear(sf::Color::Black);
        window.draw(sprite);   // Sfondo

        window.draw(spritea);  // Avatar aggiornato


        window.display();
    }



    return 0;
}
