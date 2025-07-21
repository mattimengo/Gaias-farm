#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "avatar.h"

using namespace std::chrono;

//dichiarazioni funzioni
int gioco1(sf::RenderWindow& window, sf::Event event, bool* TP, bool* TM, bool* TG, bool* MT, bool* FO, bool* BA, bool* CA, bool* CO, bool* UV, bool* OL, bool* F, bool* D, bool* S1, bool* N1, bool* S2, bool* N2);




//funzione per il gioco
int gioco1(sf::RenderWindow& window, sf::Event event, bool* TP, bool* TM, bool* TG, bool* MT, bool* FO, bool* BA, bool* CA, bool* CO, bool* UV, bool* OL, bool* F, bool* D, bool* S1, bool* N1, bool* S2, bool* N2) {
	// Caricamento della texture solo quando necessario
	sf::Texture texture;
	if (!texture.loadFromFile("assets/map_2.jpg")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite sprite(texture);



	//creazione testo di riepilogo
	// Caricamento del font
	sf::Font font;
	if (!font.loadFromFile("font/G_ari_bd.ttf")) {
		std::cerr << "Errore nel caricamento del font!" << std::endl;
		return -1;
	}

	// Creazione del testo
	sf::Text recap;
	recap.setFont(font);
	recap.setCharacterSize(40);
	recap.setFillColor(sf::Color::White);
	recap.setOutlineColor(sf::Color::Black);
	recap.setOutlineThickness(5.0f);
	recap.setPosition(50, 700);

	//Testo COMANDI
	sf::Text comandi;
	comandi.setFont(font);
	comandi.setCharacterSize(35);
	comandi.setFillColor(sf::Color::Yellow);
	comandi.setOutlineColor(sf::Color::Black);
	comandi.setOutlineThickness(5.0f);
	comandi.setPosition(50, 50);

	//Testo COMANDI2
	sf::Text comandi2;
	comandi2.setFont(font);
	comandi2.setCharacterSize(40);
	comandi2.setFillColor(sf::Color::Yellow);
	comandi2.setOutlineColor(sf::Color::Black);
	comandi2.setOutlineThickness(5.0f);
	comandi2.setPosition(50, 50);

	//Testo Zaino
	sf::Text zaino;
	zaino.setFont(font);
	zaino.setCharacterSize(40);
	zaino.setFillColor(sf::Color::Yellow);
	zaino.setOutlineColor(sf::Color::Black);
	zaino.setOutlineThickness(5.0f);
	zaino.setPosition(50, 550);

	//Testo Comandi Veicolo
	sf::Text comandiV;
	comandiV.setFont(font);
	comandiV.setCharacterSize(40);
	comandiV.setFillColor(sf::Color::Yellow);
	comandiV.setOutlineColor(sf::Color::Black);
	comandiV.setOutlineThickness(5.0f);
	comandiV.setPosition(500, 50);




	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// Testo ENTRA
	sf::Text enter;
	enter.setFont(font);
	enter.setCharacterSize(40);
	enter.setFillColor(sf::Color::Yellow);
	enter.setOutlineColor(sf::Color::Black);
	enter.setOutlineThickness(5.0f);
	enter.setPosition(300, 500);

	// Testo INTERAZIONI BURRO
	sf::Text inter;
	inter.setFont(font);
	inter.setCharacterSize(30);
	inter.setFillColor(sf::Color::White);
	inter.setOutlineColor(sf::Color::Black);
	inter.setOutlineThickness(5.0f);
	inter.setPosition(600, 600);

	//Testo Saluto Burro
	sf::Text saluto;
	saluto.setFont(font);
	saluto.setCharacterSize(30);
	saluto.setFillColor(sf::Color::White);
	saluto.setOutlineColor(sf::Color::Black);
	saluto.setOutlineThickness(5.0f);
	saluto.setPosition(300, 600);


	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	//Testo Entrata Laghetto
	sf::Text EntrataL;
	EntrataL.setFont(font);
	EntrataL.setCharacterSize(40);
	EntrataL.setFillColor(sf::Color::Yellow);
	EntrataL.setOutlineColor(sf::Color::Black);
	EntrataL.setOutlineThickness(5.0f);
	EntrataL.setPosition(1700, 500);

	//Testo Uscita Laghetto
	sf::Text exit;
	exit.setFont(font);
	exit.setCharacterSize(40);
	exit.setFillColor(sf::Color::Yellow);
	exit.setOutlineColor(sf::Color::Black);
	exit.setOutlineThickness(5.0f);
	exit.setPosition(1200, 880);

	//Testo Cattura
	sf::Text capture;
	capture.setFont(font);
	capture.setCharacterSize(35);
	capture.setFillColor(sf::Color::Yellow);
	capture.setOutlineColor(sf::Color::Black);
	capture.setOutlineThickness(5.0f);
	capture.setPosition(1700, 930);

	//Testo Cattura2
	sf::Text capture2;
	capture2.setFont(font);
	capture2.setCharacterSize(35);
	capture2.setFillColor(sf::Color::Yellow);
	capture2.setOutlineColor(sf::Color::Black);
	capture2.setOutlineThickness(5.0f);
	capture2.setPosition(1700, 750);

	//Testo Cattura3
	sf::Text capture3;
	capture3.setFont(font);
	capture3.setCharacterSize(35);
	capture3.setFillColor(sf::Color::Yellow);
	capture3.setOutlineColor(sf::Color::Black);
	capture3.setOutlineThickness(5.0f);
	capture3.setPosition(1700, 930);

	//Testo Cattura4
	sf::Text capture4;
	capture4.setFont(font);
	capture4.setCharacterSize(35);
	capture4.setFillColor(sf::Color::Yellow);
	capture4.setOutlineColor(sf::Color::Black);
	capture4.setOutlineThickness(5.0f);
	capture4.setPosition(1600, 930);

	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	//Testo Entrata Recinto Girasoli
	sf::Text enterg;
	enterg.setFont(font);
	enterg.setCharacterSize(40);
	enterg.setFillColor(sf::Color::Yellow);
	enterg.setOutlineColor(sf::Color::Black);
	enterg.setOutlineThickness(5.0f);
	enterg.setPosition(1150, 360);

	//Testo Uscita Recinto Girasoli
	sf::Text exitg;
	exitg.setFont(font);
	exitg.setCharacterSize(40);
	exitg.setFillColor(sf::Color::Yellow);
	exitg.setOutlineColor(sf::Color::Black);
	exitg.setOutlineThickness(5.0f);
	exitg.setPosition(1150, 640);

	//Testo Semina 1
	sf::Text semina;
	semina.setFont(font);
	semina.setCharacterSize(40);
	semina.setFillColor(sf::Color::Yellow);
	semina.setOutlineColor(sf::Color::Black);
	semina.setOutlineThickness(5.0f);
	semina.setPosition(1450, 550);


	//Testo Raccogli
	sf::Text raccogli;
	raccogli.setFont(font);
	raccogli.setCharacterSize(40);
	raccogli.setFillColor(sf::Color::Yellow);
	raccogli.setOutlineColor(sf::Color::Black);
	raccogli.setOutlineThickness(5.0f);
	raccogli.setPosition(1450, 420);

	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testo Entra Campo 
	sf::Text enterc;
	enterc.setFont(font);
	enterc.setCharacterSize(40);
	enterc.setFillColor(sf::Color::Yellow);
	enterc.setOutlineColor(sf::Color::Black);
	enterc.setOutlineThickness(5.0f);
	enterc.setPosition(700, 760);

	//Testo Esci Campo
	sf::Text exitc;
	exitc.setFont(font);
	exitc.setCharacterSize(40);
	exitc.setFillColor(sf::Color::Yellow);
	exitc.setOutlineColor(sf::Color::Black);
	exitc.setOutlineThickness(5.0f);
	exitc.setPosition(500, 650);

	//Testo Raccolta
	sf::Text raccolta;
	raccolta.setFont(font);
	raccolta.setCharacterSize(40);
	raccolta.setFillColor(sf::Color::Blue);
	raccolta.setOutlineColor(sf::Color::Black);
	raccolta.setOutlineThickness(5.0f);
	raccolta.setPosition(850, 780);

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testo Blocco magazzino
	sf::Text blocco;
	blocco.setFont(font);
	blocco.setCharacterSize(40);
	blocco.setFillColor(sf::Color::Red);
	blocco.setOutlineColor(sf::Color::Black);
	blocco.setOutlineThickness(5.0f);
	blocco.setPosition(300, 500);

	//Testo Esci magazzino
	sf::Text exitm;
	exitm.setFont(font);
	exitm.setCharacterSize(40);
	exitm.setFillColor(sf::Color::Yellow);
	exitm.setOutlineColor(sf::Color::Black);
	exitm.setOutlineThickness(5.0f);
	exitm.setPosition(1800, 1);

	//Testo Svuotatura
	sf::Text svuotatura;
	svuotatura.setFont(font);
	svuotatura.setCharacterSize(40);
	svuotatura.setFillColor(sf::Color::Yellow);
	svuotatura.setOutlineColor(sf::Color::Black);
	svuotatura.setOutlineThickness(5.0f);
	svuotatura.setPosition(1350, 600);


	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// Caricamento immagine avatar
	sf::Texture texta;
	if (!texta.loadFromFile("assets/avatar_w_b.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritea(texta);
	spritea.setPosition(928, 600); // Posiziona l'avatar sopra lo sfondo

	//Caricamento immagine burro
	sf::Texture textb;
	if (!textb.loadFromFile("assets/burro.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spriteb(textb);
	spriteb.setPosition(-999, -999);

	//Caricamento immagine pesci
	sf::Texture textp;
	if (!textp.loadFromFile("assets/pesci.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritep(textp);
	spritep.setPosition(-999, -999);


	//Caricamento immagine pesci laghetto dx
	sf::Texture textp2;
	if (!textp2.loadFromFile("assets/pesci2.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritep2(textp2);
	spritep2.setPosition(-999, -999);

	//Caricamento immagini pesci laghetto dx
	sf::Texture textp21;
	if (!textp21.loadFromFile("assets/pesci21.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spritep21(textp21);
	spritep21.setPosition(-999, -999);


	sf::Texture textp22;
	if (!textp22.loadFromFile("assets/pesci22.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spritep22(textp22);
	spritep22.setPosition(-999, -999);



	sf::Texture textp23;
	if (!textp23.loadFromFile("assets/pesci23.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spritep23(textp23);
	spritep23.setPosition(-999, -999);


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


	//immagine girasoli 2
	sf::Texture textg2;
	if (!textg2.loadFromFile("assets/girasoli2.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spriteg2(textg2);
	spriteg2.setPosition(-999, -999);

	//immagine girasoli 3
	sf::Texture textg3;
	if (!textg3.loadFromFile("assets/girasoli3.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spriteg3(textg3);
	spriteg3.setPosition(-999, -999);

	//immagine girasoli 4
	sf::Texture textg4;
	if (!textg4.loadFromFile("assets/girasoli4.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spriteg4(textg4);
	spriteg4.setPosition(-999, -999);

	//sprite TP
	sf::Texture tpdx;
	if (!tpdx.loadFromFile("assets/tpdx.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spritetpdx(tpdx);
	spritetpdx.setPosition(-999, -999);

	//sprite TP2
	sf::Texture tpsx;
	if (!tpsx.loadFromFile("assets/tpsx.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}
	sf::Sprite spritetpsx(tpsx);
	spritetpsx.setPosition(-999, -999);

	//sprite fiori2
	sf::Texture fiori2;
	if (!fiori2.loadFromFile("assets/fiori2.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritefiori2(fiori2);
	spritefiori2.setPosition(-999, -999);

	//sprite fiori3
	sf::Texture fiori3;
	if (!fiori3.loadFromFile("assets/fiori3.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritefiori3(fiori3);
	spritefiori3.setPosition(-999, -999);

	//sprite fiori4
	sf::Texture fiori4;
	if (!fiori4.loadFromFile("assets/fiori4.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritefiori4(fiori4);
	spritefiori4.setPosition(-999, -999);

	//sprite fiori5
	sf::Texture fiori5;
	if (!fiori5.loadFromFile("assets/fiori5.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritefiori5(fiori5);
	spritefiori5.setPosition(-999, -999);


	//sprite magazzino
	sf::Texture magazzino;
	if (!magazzino.loadFromFile("assets/magazzino.png")) {
		std::cerr << "Failed to create texture from file!" << std::endl;
		return -1;
	}

	sf::Sprite spritemagazzino(magazzino);
	spritemagazzino.setPosition(-9999, -9999);





	//movimento avatar
	movgame avatar;

	//movimento avatar recinto fienile
	movf avatarf;

	//movimento avatar recinto basso dx
	movr avatarR;

	//movimento avatar campo sx
	movc avatarc;

	

	//interazione menu cmd
	joincmdmenu input;

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

		//ingresso vari gate
		avatar.gate_fienile(window);
		avatar.gate_laghetto(window);
		avatar.gate_girasoli(window);
		avatar.gate_campo(window);
		avatar.gate_magazzino(window);
		avatar.gate_bosco(window);
		avatar.gate_zoo(window);

		//interazione menu comandi
		input.join();

		//movimento interno campo
		avatarc.left_c(window);
		avatarc.right_c(window);

	





		// Aggiorna la posizione dello sprite dell'avatar
		spritea.setPosition(avatar.posx_g, avatar.posy_g);



		//VEICOLI + F + S1 + S2
		//combinazione 1
		if (*TP && *F && *S1 && *S2) {
			animalsShown = true;

			if (animalsShown) {
				//spawn di burro
				spriteb.setPosition(605, 450);
				//spawn dei pesci
				spritep.setPosition(755, 489);
				//spawn pesci laghetto dx
				spritep2.setPosition(1700, 785);


			}


			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");

			comandi.setString("Lista dei Comandi: \n   premi  I ");






			//blocco per cancellare il testo di recap e dello zaino
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				recapShown = false;
			}
			if (!recapShown) {
				recap.setString("");
				comandi.setString("");
			}





			//menu comandi
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
				comandi2.setString(" Lista dei Comandi: \n W = in s� \n A = a sx \n D = a dx \n S = in gi� \n I = mostra i comandi \n Z = apri zaino \n U = comandi veicoli \n G = Riponi ogg. magaz \n H = Prendi ogg.magaz ");
				comandiShown = true;
			}
			if (comandiShown) {
				comandi.setString("");
			}
			if (input.cmdjoined) {
				comandi2.setString(" Lista dei Comandi: \n W = in s� \n A = a sx \n D = a dx \n S = in gi� \n I = mostra i comandi \n Z = apri zaino \n U = comandi veicoli \n G = Riponi ogg. magaz \n H = Prendi ogg. magaz ");
			}

			//Zaino
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				zaino.setString("Elenco oggetti:");
			}

			//Comandi Veicoli
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
				comandiV.setString("Comandi Veicoli: \n C = a sx \n V = a dx \n R = raccogli");
			}





			//blocco per cancellare il testo dei comandi
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
				comandiDisappear = true;
			}
			if (comandiDisappear) {
				comandi2.setString("");
				zaino.setString("");
				comandiV.setString("");
				raccolta.setString("");
				comandiDisappear = false;
			}


			//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//gate fienile
			static bool JoinedG = false;

			if (avatar.gatef) {

				//movimento interno recinto alto sx
				avatarf.up_f(window);
				avatarf.down_f(window);

				enter.setString("ENTRA");
				recap.setString("");

				if (mouse.x >= 300 && mouse.x <= 450 && mouse.y >= 450 && mouse.y <= 550) {

					JoinedG = true;

					enter.setString("");

					//muovi lo sprite sopra cy3 e in una determinata posizione
					spritea.setPosition(avatarf.posx_f, avatarf.posy_f);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						//mostra il testo delle interazioni
						inter.setString("Premi B per salutare Burro e i Pesciolini!");

					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
						inter.setString("");
						//testo
						saluto.setString("Ciao Burro e Ciao Pesciolini!!!");
					}

				}
				else {
					// Ripristina i testi di default
					enter.setString("ENTRA");

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						//mostra il testo delle interazioni
						inter.setString("Premi B per salutare Burro e i Pesciolini!");

					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
						inter.setString("");
						//testo
						saluto.setString("Ciao Burro e Ciao Pesciolini!!!");
					}

					if (JoinedG) {
						spritea.setPosition(avatarf.posx_f, avatarf.posy_f);
						enter.setString("");
					}

				}
			}


			//cancella il testo entra
			if (avatar.gatef == false) {
				enter.setString("");
				inter.setString("");
				saluto.setString("");
				JoinedG = false;
			}


			//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//gate laghetto

			static bool GateON = false;
			static bool ExitON = false;
			bool captureON = false;

			bool newZaino = false;

			static bool ZON2 = false;

			static bool LAGHETTO = false;
			static bool CAMPO = false;
			static bool GIRASOLI = false;


			if (avatar.gatel) {

				EntrataL.setString("ENTRA");


				// Quando il mouse � nell'intervallo
				if (mouse.x >= 1700 && mouse.x <= 1850 && mouse.y >= 450 && mouse.y <= 550) {

					GateON = true;

					EntrataL.setString("");
					exit.setString("ESCI");

					captureON = true;

					// Mantieni lo sprite nella posizione fissa
					spritea.setPosition(avatarR.posx_r, avatarR.posy_r);


					//lo sprite non esce involontariamente
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						spritea.setPosition(avatarR.posx_r, avatarR.posy_r);
					}

				}
				else if (GateON) {

					//fa rimanere fermo lo sprite
					spritea.setPosition(avatarR.posx_r, avatarR.posy_r);

					EntrataL.setString("");
					exit.setString("ESCI");
					//capture.setString("CATTURA");
					captureON = true;

					//lo sprite non esce involontariamente
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						spritea.setPosition(avatarR.posx_r, avatarR.posy_r);
					}
				}




				static bool lock1 = false;
				static bool lock2 = false;


				if (captureON && !lock1 && !lock2) {
					capture.setString("CATTURA");

					//funzionamento bottone CATTURA
					if (mouse.x >= 1700 && mouse.x <= 1770 && mouse.y >= 930 && mouse.y <= 970) {



						lock1 = true;

						capture.setString("");
						capture2.setString("CATTURA");
						spritep21.setPosition(1700, 785);


					}
					else if (lock1) {

						lock1 = true;

						capture.setString("");
						capture2.setString("CATTURA");
						spritep21.setPosition(1700, 785);

					}
				}





				static bool switchON = false;
				static bool spritep23Active = false;

				//funzionamento bottone CATTURA2
				if (mouse.x >= 1700 && mouse.x <= 1770 && mouse.y >= 750 && mouse.y <= 790) {


					lock2 = true;



					capture2.setString("");
					capture3.setString("CATTURA");
					switchON = true;


					spritep22.setPosition(1700, 785);
					spritep21.setPosition(-999, -999);


				}

				static bool switch2ON = false;
				static bool spritep24Active = false;

				if (switchON) {
					if (mouse.x >= 1700 && mouse.x <= 1770 && mouse.y >= 930 && mouse.y <= 970) {
						if (!spritep23Active) {  // Solo se non � gi� attivo
							capture3.setString("");
							capture4.setString("CATTURA");
							spritep23.setPosition(1700, 785);
							spritep22.setPosition(-999, -999);
							spritep23Active = true;  // Segnala che � attivo

							switch2ON = true;
						}
					}
					else if (spritep23Active) {  // Quando il mouse esce dall'area
						spritep23.setPosition(1700, 785);
						spritep23Active = false;  // Resetta lo stato
					}
				}

				if (switch2ON) {
					if (mouse.x >= 1600 && mouse.x <= 1670 && mouse.y >= 930 && mouse.y <= 970) {
						if (!spritep24Active) {  // Solo se non � gi� attivo
							capture4.setString("");
							spritep24.setPosition(1647, 775);
							spritep23.setPosition(-999, -999);
							spritep24Active = true;  // Segnala che � attivo

						}
					}
					else if (spritep24Active) {  // Quando il mouse esce dall'area
						spritep24.setPosition(1647, 775);
						spritep23.setPosition(-999, -999);
						spritep24Active = false;  // Resetta lo stato

					}



					//blocco per cancellare il testo dei comandi
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						comandiDisappear = true;
					}



				}









				//funzionamento bottone ESCI
				if (mouse.x >= 1200 && mouse.x <= 1290 && mouse.y >= 880 && mouse.y <= 950) {
					ExitON = true;
					exit.setString("");
					capture.setString("");
					capture2.setString("");
					spritea.setPosition(1470, 600);

					newZaino = true;
					ZON2 = true;

					LAGHETTO = true;

				}
				else if (ExitON) {

					newZaino = true;
					ZON2 = true;

					exit.setString("");
					capture.setString("");
					capture2.setString("");
					spritea.setPosition(1470, 600);

					LAGHETTO = true;
				}




			}

			if (avatar.gatel == false) {
				EntrataL.setString("");

				//Zaino post laghetto
				if (newZaino) {                                                             //COLLEGAMENTO OK
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x10 Pesciolini");
					}

				}

				if (ExitON) {
					exit.setString("");
					capture.setString("");
					capture2.setString("");

					ExitON = false;


				}

				GateON = false;



			}

			if (LAGHETTO) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x10 Pesciolini");
				}
			}


			//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//gate girasoli

			static bool GateGON = false;
			static bool ExitGON = false;
			static bool G1 = false;





			if (avatar.gateg) {

				//bottone ENTRA
				enterg.setString("ENTRA");
				if (mouse.x >= 1150 && mouse.x <= 1300 && mouse.y >= 360 && mouse.y <= 420) {

					GateGON = true;

					semina.setString("SEMINA");

					enterg.setString("");
					exitg.setString("ESCI");

					//sposta l'avatar dentro il recinto
					spritea.setPosition(avatar.gx, avatar.gy);


				}
				else if (GateGON) {
					enterg.setString("");
					exitg.setString("ESCI");

					//sposta l'avatar dentro il recinto
					spritea.setPosition(avatar.gx, avatar.gy);

				}


				//bottone SEMINA
				if (mouse.x >= 1450 && mouse.x <= 1550 && mouse.y >= 550 && mouse.y <= 600) {

					G1 = true;

					semina.setString("");
					spriteg2.setPosition(1120, 435);
					raccogli.setString("RACCOGLI");
				}
				else if (G1) {

					semina.setString("");
					spriteg3.setPosition(1120, 435);
					raccogli.setString("RACCOGLI");
				}


				static bool R = false;
				//bottone RACCOGLI
				if (mouse.x >= 1450 && mouse.x <= 1550 && mouse.y >= 420 && mouse.y <= 470) {
					raccogli.setString("");
					spriteg3.setPosition(-999, -999);
					spriteg4.setPosition(1120, 435);

					R = true;
				}
				else if (R) {
					raccogli.setString("");
					spriteg3.setPosition(-999, -999);
					spriteg4.setPosition(1120, 435);
				}




				//bottone EXIT
				if (mouse.x >= 1050 && mouse.x <= 1200 && mouse.y >= 640 && mouse.y <= 700) {
					ExitGON = true;

					exitg.setString("");

					//fa "uscire l'avatar
					spritea.setPosition(900, avatar.cy3);



					GIRASOLI = true;


				}
				else if (ExitGON) {
					exitg.setString("");

					//fa "uscire l'avatar
					spritea.setPosition(900, avatar.cy3);

					GIRASOLI = true;


				}

			}

			if (avatar.gateg == false) {
				enterg.setString("");
				exitg.setString("");
				raccogli.setString("");

				GateGON = false;
				ExitGON = false;
			}

			if (GIRASOLI) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x9 Girasoli");
				}
			}






			//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//gate campo

			static bool GateCON = false;
			static bool EnterCON = false;
			static bool ExitCON = false;






			if (avatar.gatec) {



				enterc.setString("ENTRA");

				GateCON = true;


				//bottone ENTRA
				if (mouse.x >= 700 && mouse.x <= 760 && mouse.y >= 760 && mouse.y <= 820) {



					enterc.setString("");

					EnterCON = true;

					exitc.setString("ESCI");

					//posiziona lo sprite dentro il recinto

					//spritea cambia texture
					spritea.setTexture(tpsx);
					spritea.setPosition(avatarc.posx_c, avatarc.posy_c);

				}
				else if (EnterCON) {



					enterc.setString("");

					//spritea cambia texture
					spritea.setTexture(tpsx);
					spritea.setPosition(avatarc.posx_c, avatarc.posy_c);
				}





				//switch sx - dx
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
					spritea.setTexture(tpdx);
					spritea.setPosition(avatarc.posx_c, avatarc.posy_c);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					spritea.setTexture(tpsx);
					spritea.setPosition(avatarc.posx_c, avatarc.posy_c);
				}


				//raccolta 1
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					raccolta.setString("Hai raccolto 4 papaveri");
					spritefiori2.setPosition(1, 735);
				}


				bool R2 = false;
				//raccolta 2
				if (avatarc.posx_c < 548 && avatarc.posx_c > 500 && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					R2 = true;
					raccolta.setString("Hai raccolto 12 papaveri");
					spritefiori3.setPosition(1, 735);
				}


				bool R3 = false;
				if (R2) {
					spritefiori4.setPosition(1, 735);
				}


				if (avatarc.posx_c < 310 && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					raccolta.setString("hai raccolto 4 papaveri");
					spritefiori5.setPosition(1, 735);
				}







				//bottone ESCI
				if (mouse.x >= 500 && mouse.x <= 600 && mouse.y >= 650 && mouse.y <= 820) {
					exitc.setString("");



					ExitCON = true;
					CAMPO = true;

					//spritea cambia texture
					spritea.setTexture(texta);
					spritea.setPosition(avatar.posx_g, avatar.posy_g);

				}
				else if (ExitCON) {
					exitc.setString("");

					CAMPO = true;


					//spritea cambia texture
					spritea.setTexture(texta);
					spritea.setPosition(avatar.posx_g, avatar.posy_g);
				}



			}


			if (avatar.gatec == false) {
				enterc.setString("");
				exitc.setString("");

				GateCON = false;
				EnterCON = false;
				ExitCON = false;
			}

			if (CAMPO) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x20 Papaveri");
				}
			}


			//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//zaino 

			//girasoli + laghetto
			if (GIRASOLI && LAGHETTO) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x9 Girasoli \n - x10 Pesciolini");
				}
			}

			//girasoli + campo
			if (GIRASOLI && CAMPO) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x9 Girasoli \n - x20 Papaveri");
				}
			}


			//laghetto + campo
			if (LAGHETTO && CAMPO) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x10 Pesciolini \n - x20 Papaveri");
				}
			}

			//campo + girasoli
			if (GIRASOLI && CAMPO) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x9 Girasoli \n - x20 Papaveri");
				}
			}


			static bool KEY = false;
			//girasoli + laghetto + campo
			if (GIRASOLI && LAGHETTO && CAMPO) {
				KEY = true;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					zaino.setString("Elenco oggetti: \n - x9 Girasoli \n - x10 Pesciolini \n - x20 Papaveri");
				}
			}

			//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//magazzino

			static bool exitmON = false;
			static bool STOREON = false;
			static bool ZAINOON = false;
			static bool ZAINOFULL = false;

			//entrata magazzino
			if (avatar.gatem && avatar.posx_g >= 1345 && avatar.posx_g <= 1461 && avatar.posy_g <= 222 && KEY) {

				

				sprite.setTexture(magazzino);
				spriteb.setPosition(-999, -999);
				spritep.setPosition(-999, -999);
				spritep2.setPosition(-999, -999);
				spritep21.setPosition(-999, -999);
				spritep22.setPosition(-999, -999);
				spritep23.setPosition(-999, -999);
				spritep24.setPosition(-999, -999);
				spriteg.setPosition(-999, -999);
				spriteg2.setPosition(-999, -999);
				spriteg3.setPosition(-999, -999);
				spriteg4.setPosition(-999, -999);
				spritefiori2.setPosition(-999, -999);
				spritefiori3.setPosition(-999, -999);
				spritefiori4.setPosition(-999, -999);
				spritefiori5.setPosition(-999, -999);


				spritea.setPosition(1000, 475);
				spritea.setScale(1.75f, 1.75f);

				exitm.setString("ESCI");

				STOREON = true;




				//Ripongo Oggetti
				if (STOREON) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {

						// testo : hai svuotato il tuo zaino
						svuotatura.setString("Hai svuotato il tuo zaino!");

						//aggiornamento zaino
						zaino.setString("Elenco oggetti: \n - x0 Pesciolini \n - x0 Girasoli \n - x0 Papaveri");


						ZAINOON = true;


					}
				}

				//Prelevo Oggetti
				if (STOREON) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {

						// testo : hai svuotato il tuo zaino
						svuotatura.setString("Hai riempito il tuo zaino!");

						//aggiornamento zaino
						zaino.setString("Elenco oggetti: \n - x9 Pesciolini \n - x10 Girasoli \n - x20 Papaveri");


						ZAINOFULL = true;


					}
				}




				
				//bottone esci
				if (mouse.x >= 1800 && mouse.x <= 1850 && mouse.y >= 1 && mouse.y <= 30) {
					exitmON = true;

					sprite.setTexture(texture);
					spritea.setScale(1.0f, 1.0f);
					spritep24.setPosition(1647, 775);
					spritefiori5.setPosition(1, 735);
					spriteg4.setPosition(1120, 435);
					spriteb.setPosition(605,450);
					spritep.setPosition(755,489);
					exitm.setString("");
					svuotatura.setString("");
					zaino.setString("");

				}
				else if (exitmON) {
					sprite.setTexture(texture);
					spritea.setScale(1.0f, 1.0f);
					spritep24.setPosition(1647, 775);
					spritefiori5.setPosition(1, 735);
					spriteg4.setPosition(1120, 435);
					spriteb.setPosition(605, 450);
					spritep.setPosition(755, 489);
					exitm.setString("");
					svuotatura.setString("");
					zaino.setString("");
				}


				




				//aggiornamento zaino con ZainoOn
				if (ZAINOON) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x0 Pesciolini \n - x0 Girasoli \n - x0 Papaveri");
					}
				}
				else if (ZAINOON) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x0 Pesciolini \n - x0 Girasoli \n - x0 Papaveri");
					}
				}

				//aggiornamento zaino con ZAINOFULL
				if (ZAINOFULL) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x9 Pesciolini \n - x10 Girasoli \n - x20 Papaveri");
					}
				}else if(ZAINOFULL) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x9 Pesciolini \n - x10 Girasoli \n - x20 Papaveri");
					}
				}
				

			}
			
			
			if (avatar.gatem == false && exitmON) {

				exitmON = false;

				sprite.setTexture(texture);
				spritea.setScale(1.0f, 1.0f);
				spritep24.setPosition(1647, 775);
				spritefiori5.setPosition(1, 735);
				spriteg4.setPosition(1120, 435);
				spriteb.setPosition(605, 450);
				spritep.setPosition(755, 489);
				exitm.setString("");

			}


			//aggiornamento zaino svuotato
			if (avatar.gatem == false && ZAINOON) {
				
				//aggiornamento zaino
				if (ZAINOON) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x0 Pesciolini \n - x0 Girasoli \n - x0 Papaveri");
					}
				}
				else if (ZAINOON) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x0 Pesciolini \n - x0 Girasoli \n - x0 Papaveri");
					}
				}
			}

				
			//aggiornamento zaino pieno
			if(avatar.gatem==false && ZAINOFULL){
				
				if (ZAINOFULL) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x9 Pesciolini \n - x10 Girasoli \n - x20 Papaveri");
					}
				}
				else if (ZAINOFULL) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						zaino.setString("Elenco oggetti: \n - x9 Pesciolini \n - x10 Girasoli \n - x20 Papaveri");
					}
				}
			}
			


			//vietato accesso magazzino
			if (avatar.posx_g >= 1345 && avatar.posx_g <= 1461 && avatar.posy_g <= 222 && !KEY) {
				blocco.setString("                                         ACCESSO VIETATO! \n COMPLETA TUTTE LE MISSIONI PRIMA DI ACCEDERE AL MAGAZZINO");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				blocco.setString("");

			}
			


			
			//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//collegamento con bosco
			if (avatar.gateb) {
				//bosco(window, event, TP, TM, TG, MT, FO, BA, CA, CO, UV, OL, F, D, S1, N1, S2, N2);
			}
			//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//collegamento con zoo
			if (avatar.gatez) {
				//zoo(window, event, TP, TM, TG, MT, FO, BA, CA, CO, UV, OL, F, D, S1, N1, S2, N2);
			}
			//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		}

		//combinazione 2
		if (*TM && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 3
		if (*TG && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 4
		if (*MT && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 5
		if (*FO && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 6
		if (*BA && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 7
		if (*CA && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 8
		if (*CO && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 9
		if (*UV && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 10
		if (*OL && *F && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}





		//-------------------------------------------------------------------------------------------------------------------




		//VEICOLI + D + S1 + S2
		//combinazione 11
		if (*TP && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 12
		if (*TM && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 13
		if (*TG && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 14
		if (*MT && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 15
		if (*FO && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 16
		if (*BA && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 17
		if (*CA && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 18
		if (*CO && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 19
		if (*UV && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}

		//combinazione 20
		if (*OL && *D && *S1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: SI ");
		}




		//-------------------------------------------------------------------------------------------------------------------



		//VEICOLI + F + N1 + S2
		//combinazione 21
		if (*TP && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 22
		if (*TM && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 23
		if (*TG && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 24
		if (*MT && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 25
		if (*FO && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 26
		if (*BA && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 27
		if (*CA && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 28
		if (*CO && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 29
		if (*UV && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 30
		if (*OL && *F && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}



		//-------------------------------------------------------------------------------------------------------------------

		//VEICOLI + D + N1 + S2
		//combinazione 31
		if (*TP && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 32
		if (*TM && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 33
		if (*TG && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 34
		if (*MT && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 35
		if (*FO && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 36
		if (*BA && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 37
		if (*CA && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 38
		if (*CO && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 39
		if (*UV && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}

		//combinazione 40
		if (*OL && *D && *N1 && *S2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: SI ");
		}



		//-------------------------------------------------------------------------------------------------------------------


		//VEICOLI + F + S1 + N2
		//combinazione 41
		if (*TP && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 42
		if (*TM && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 43
		if (*TG && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 44
		if (*MT && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 45
		if (*FO && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 46
		if (*BA && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 47
		if (*CA && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 48
		if (*CO && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 49
		if (*UV && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 50
		if (*OL && *F && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Facile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}


		//-------------------------------------------------------------------------------------------------------------------


		//VEICOLI + D + S1 + N2
		//combinazione 51
		if (*TP && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 52
		if (*TM && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 53
		if (*TG && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 54
		if (*MT && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 55
		if (*FO && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 56
		if (*BA && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 57
		if (*CA && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 58
		if (*CO && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 59
		if (*UV && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}

		//combinazione 60
		if (*OL && *D && *S1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Difficile \n - Spawn Animali Selvatici: SI \n - Missioni: NO ");
		}


		//-------------------------------------------------------------------------------------------------------------------

		//VEICOLI + F + N1 + N2
		//combinazione 61
		if (*TP && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 62
		if (*TM && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 63
		if (*TG && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 64
		if (*MT && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 65
		if (*FO && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 66
		if (*BA && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 67
		if (*CA && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 68
		if (*CO && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 69
		if (*UV && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 70
		if (*OL && *F && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Facile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}


		//-------------------------------------------------------------------------------------------------------------------

		//VEICOLI + D + N1 + N2
		//combinazione 71
		if (*TP && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Piccolo \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 72
		if (*TM && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Medio \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 73
		if (*TG && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Trattore Grande \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 74
		if (*MT && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Mietitrice \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 75
		if (*FO && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Foraggio \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 76
		if (*BA && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Barbabietole \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 77
		if (*CA && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Canne da Zucchero \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 78
		if (*CO && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Miet. Cotone \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 79
		if (*UV && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Uva \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}

		//combinazione 80
		if (*OL && *D && *N1 && *N2) {
			recap.setString("Ecco qui cosa hai selezionato! \n - Racc. Olive \n - Mod. Difficile \n - Spawn Animali Selvatici: NO \n - Missioni: NO ");
		}



		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.draw(semina);
		window.draw(raccogli);
		window.draw(spriteg);
		window.draw(spriteg2);
		window.draw(spriteg3);
		window.draw(spriteg4);
		window.draw(spritetpdx);
		window.draw(spritetpsx);
		window.draw(spritefiori2);
		window.draw(spritefiori3);
		window.draw(spritefiori4);
		window.draw(spritefiori5);
		window.draw(spritemagazzino);
		window.draw(spritea);
		window.draw(spriteb);
		window.draw(spritep);
		window.draw(spritep2);
		window.draw(spritep21);
		window.draw(spritep22);
		window.draw(spritep23);
		window.draw(spritep24);
		window.draw(recap);
		window.draw(comandi);
		window.draw(comandi2);
		window.draw(zaino);
		window.draw(comandiV);
		window.draw(enter);
		window.draw(inter);
		window.draw(saluto);
		window.draw(EntrataL);
		window.draw(exit);
		window.draw(exitg);
		window.draw(exitc);
		window.draw(exitm);
		window.draw(enterg);
		window.draw(enterc);
		window.draw(capture);
		window.draw(capture2);
		window.draw(capture3);
		window.draw(capture4);
		window.draw(raccolta);
		window.draw(blocco);
		window.draw(svuotatura);
		window.display();
	}

	return 0;
}



