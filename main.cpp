#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "avatar.h"





//dichiarazioni funzioni
int gioco(sf::RenderWindow& window, sf::Event& event, bool* TP, bool* TM, bool* TG, bool* MT, bool* FO, bool* BA, bool* CA, bool* CO, bool* UV, bool* OL, bool* F, bool* D, bool* S1, bool* N1, bool* S2, bool* N2);


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Esame");
    sf::Event event;

    bool TP = false, TM = false, TG = false, MT = false, FO = false, BA = false, CA = false, CO = false, UV = false, OL = false, F = false, D = false, S1 = false, N1 = false, S2 = false, N2 = false;

    return gioco(window, event, &TP, &TM, &TG, &MT, &FO, &BA, &CA, &CO, &UV, &OL, &F, &D, &S1, &N1, &S2, &N2);
}



//funzione per il gioco
int gioco(sf::RenderWindow& window, sf::Event& event, bool* TP, bool* TM, bool* TG, bool* MT, bool* FO, bool* BA, bool* CA, bool* CO, bool* UV, bool* OL, bool* F, bool* D, bool* S1, bool* N1, bool* S2, bool* N2) {
	// Caricamento della texture solo quando necessario
	sf::Texture texture;
	if (!texture.loadFromFile("assets/map1.jpg")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite sprite(texture);



	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// Caricamento immagine avatar
	sf::Texture texta;
	if (!texta.loadFromFile("assets/avatar_w_b.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritea(texta);
	spritea.setPosition(928, 600); // Posiziona l'avatar sopra lo sfondo

	

	
	

	
	// Costruzione mappa e muri
    Mappa mappa;
    // Aggiungi muri con coordinate (esempio)
    mappa.aggiungiMuro(Muro(871, 600, 960, 620));
    mappa.aggiungiMuro(Muro(1120, 770, 1130, 780));
    // ... aggiungi tutti i muri necessari

    // Crea personaggio nella posizione iniziale
    Personaggio avatar(928.0f, 600.0f, mappa);



	
	





	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}



		// Posizione del cursore
		sf::Vector2i mouse = sf::Mouse::getPosition(window);


		// Gestione input movimento
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) avatar.muoviSu();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) avatar.muoviGiu();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) avatar.muoviSinistra();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) avatar.muoviDestra();

		

		// Aggiorna posizione sprite avatar
        spritea.setPosition(avatar.getX(), avatar.getY());


		


		window.clear(sf::Color::Black);
		window.draw(sprite);			
		window.draw(spritea);		
		window.display();
	}

	return 0;
}



