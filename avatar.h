#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef AVATAR_H
#define AVATAR_H


//classe per il movimento di map2
class movgame {
public:
	//costruttore
	movgame();

	//metodi
	void up_g(sf::RenderWindow& window);
	void down_g(sf::RenderWindow& window);
	void left_g(sf::RenderWindow& window);
	void right_g(sf::RenderWindow& window);

	// Getter per posizione
    float getPosX() const { return posx_g; }
    float getPosY() const { return posy_g; }

	//metodo test
	void setPos(float x, float y) {
        posx_g = x;
        posy_g = y;
    }

private:
	//membri
	float posx_g;
	float posy_g;
	float offset;

	float cx1;
	float cx2;
	float cx22;
	float cx3;
	float cx33;
	float cx4;
	float cx44;
	float cx5;
	float cx6;
	float cx62;
	float cx7;
	float cx8;
	float cx9;
	float cx10;
	float cx11;

	float cy1;
	float clonecy1;
	float cy2;
	float cy3;
	float clonecy3;
	float cy4;
	float cy44;
	float cy5;
	float clonecy5;
	float cy3N;

	float bsx; //bosco

	float zoy;  //zoo
	float clonezoy;

	float gy1;
	float gy2;

	float GY1;

	float lx;
	float ly;
	float gx;
	float gy;


	bool gatef;
	bool gatel;
	bool gateg;
	bool gatec;
	bool gatem;
	bool gateb;
	bool gatez;

};





#endif // !X