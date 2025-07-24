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
	if (!texture.loadFromFile("assets/map_2.jpg")) {
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

	

	//immagine acqua 
	sf::Texture textp24;
	if (!textp24.loadFromFile("assets/acqua.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spritep24(textp24);
	spritep24.setPosition(-999, -999);



	//immagine campo girasoli
	sf::Texture textg;
	if (!textg.loadFromFile("assets/campogirasoli.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spriteg(textg);
	spriteg.setPosition(-999, -999);

	//campo girasoli
	spriteg.setPosition(1120, 435);


	

	





	//movimento avatar
	movgame avatar;

	
	

	

	bool recapShown = true;
	bool animalsShown = false;
	bool comandiShown = false;
	bool comandiDisappear = false;




	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}



		// Posizione del cursore
		sf::Vector2i mouse = sf::Mouse::getPosition(window);


		//movimento
		avatar.up_g(window);
		avatar.down_g(window);
		avatar.left_g(window);
		avatar.right_g(window);

		

		// Aggiorna la posizione dello sprite dell'avatar
		spritea.setPosition(avatar.getPosX(), avatar.getPosY());



		window.clear(sf::Color::Black);
		window.draw(sprite);		
		window.draw(spriteg);	
		window.draw(spritea);		
		window.display();
	}

	return 0;
}



