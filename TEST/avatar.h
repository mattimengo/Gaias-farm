#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef AVATAR_H
#define AVATAR_H

//classe per il movimento sulla mappa
class movement {

public:
	//costruttore
	//movimento sulla mappa
	movement() {
		pos_x = 907.0f;
		pos_y = 439.0f;
		step = 1.0f;
		clone_y = 330.0f;
		c_y = 764.0f;
		clone_x = 1768.0f;
		c_x = -60.0f;
		max_heightchngd = 330.0f;
		min_heightchngd = 764.0f;
		max_widhtchngd = 1768.0f;
		min_widhtchngd = -60.0f;
		recintos_y = 370.0f;
		corner1_x = 770.0f;
		corner2_x = 990.0f;
		clones_y = 370.0f;
		clones_x = 770.0f;
	}

	//metodi
	void up(sf::RenderWindow& window);
	void down(sf::RenderWindow& window);
	void left(sf::RenderWindow& window);
	void right(sf::RenderWindow& window);

	

	//membri
	float pos_x;
	float pos_y;
	float step;
	float clone_y;
	float c_y;
	float clone_x;
	float c_x;
	float max_heightchngd;
	float min_heightchngd;
	float max_widhtchngd;
	float min_widhtchngd;
	float recintos_y;
	float corner1_x;
	float corner2_x;
	float clones_x;
	float cr_x;
	float clones_y;
	float cr_y;

	//distruttore
	~movement() {};
	

};

#endif // AVATAR_H