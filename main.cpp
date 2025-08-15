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

	// Bordi schermo (esempio coordinate, da adattare se necessario)
    mappa.aggiungiMuro(Muro(0, 0, 1920, 329));     // muro sopra (bordo superiore a y=330)
    mappa.aggiungiMuro(Muro(0, 765, 1920, 1080));  // muro sotto (bordo inferiore a y=764)
    mappa.aggiungiMuro(Muro(0, 0, 763, 1080));     // muro sinistro (bordo sinistro a x=764)
    mappa.aggiungiMuro(Muro(1769, 0, 1920, 1080)); // muro destro (bordo destro a x=1768)

    // Recinti verticali e orizzontali (coordinate approssimate dai controlli originali)
    // Recinto alto sx: blocca posY > 370 e posX < 770
    mappa.aggiungiMuro(Muro(0, 371, 770, 1080)); // muro verticale recinto sx da y=371 in giù

    // Recinto alto dx: blocca posY > 370 e posX > 990
    mappa.aggiungiMuro(Muro(991, 371, 1920, 1080)); // muro verticale recinto dx da y=371 in giù

    // Recinto verticale sx: blocca posX < 770 e posY > 370
    // Già coperto sopra con muro verticale da (0,371) a (770,1080)

    // Recinto verticale dx: blocca posX > 990 e posY > 370
    // Già coperto sopra con muro verticale da (991,371) a (1920,1080)


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



