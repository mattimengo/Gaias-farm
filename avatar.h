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

//classe per il movimento interno al recinto dx
class movint {

public:

	//movimento interno recinto dx
	movint() {
		pos_xr = 500.0f;
		pos_yr = 650.0f;
		stepr = 1.0f;
		max_widht = 1768.0f;
		corner2r = 990.0f;
		clone_maxw = 1768.0f;
		clone_crn2 = 990.0f;
	}

	//metodi
	//void up_i(sf::RenderWindow& window);
	//void down_i(sf::RenderWindow& window);
	void left_i(sf::RenderWindow& window);
	void right_i(sf::RenderWindow& window);


	//membri
	float pos_xr;
	float pos_yr;
	float stepr;
	float max_widht;
	float clone_maxw;
	float corner2r;
	float clone_crn2;

	//distruttore
	~movint() {};


};

//classe per il movimento di map2
class movgame {
public:
	//costruttore
	movgame() {
		posx_g = 928.0f;
		posy_g = 600.0f;
		offset = 1.0f;

		cx1 = 872.0f;
		cx2 = 960.0f;
		cx22 = 970.0f;
		cx3 = 1627.0f;
		cx33 = 1640.0f;
		cx4 = 1760.0f;
		cx44 = 1780.0f;
		cx5 = 1750.0f;
		cx6 = 1452.0f;
		cx62 = 1460.0f;
		cx7 = 1530.0f;
		cx8 = 872.0f;
		cx9 = 1135.0f;
		cx10 = 430.0f;
		cx11 = 550.0f;

		cy1 = 620.0f;
		clonecy1 = 620.0f;
		cy2 = 772.0f;
		cy3 = 585.0f;
		clonecy3 = 585.0f;
		cy4 = 220.0f;
		cy44 = 200.0f;
		cy5 = 422.0f;
		clonecy5 = 422.0f;

		cy3N = 450.0f;



		bsx = 23.0f; //bosco

		zoy = 220.0f;  //zoo
		clonezoy = 220.0f;

		//posizioni di default nel gate recinto
		gy1 = 750.0f;
		gy2 = 680.0f;

		gatef = false;



		//posizioni di default nel gate laghetto
		lx = 1120.0f;
		ly = 770.0f;


		//posizioni di default nel campo di girasoli
		gx = 960.0f;
		gy = 400.0f;


		GY1 = 660.0f;
	}


	//metodi
	void up_g(sf::RenderWindow& window);
	void down_g(sf::RenderWindow& window);
	void left_g(sf::RenderWindow& window);
	void right_g(sf::RenderWindow& window);

	void gate_fienile(sf::RenderWindow& window);
	void gate_laghetto(sf::RenderWindow& window);
	void gate_girasoli(sf::RenderWindow& window);
	void gate_campo(sf::RenderWindow& window);
	void gate_magazzino(sf::RenderWindow& window);
	void gate_bosco(sf::RenderWindow& window);
	void gate_zoo(sf::RenderWindow& window);


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





//classe per il movimento nel recinto del fienile
class movf {
public:
	movf() {
		posx_f = 455.0f;
		posy_f = 625.0f;
		offsetf = 1.0f;


		fy = 390.0f;
		ry = 435.0f;
		cxf = 430.0f;
	}

	//metodi
	void up_f(sf::RenderWindow& window);
	void down_f(sf::RenderWindow& window);



	//membri
	float posx_f;
	float posy_f;
	float offsetf;

	float fy;
	float ry;
	float cxf;

};

//classe per il movimento interno al recinto del fienile dx in basso
class movr {
public:
	movr() {
		rx1 = 960.0f;
		rx2 = 1630.0f;

		stepr = 1.0f;
		posx_r = 1515.0f;
		posy_r = 800.0f;
	}

	//metodi
	void left_r(sf::RenderWindow& window);
	void right_r(sf::RenderWindow& window);



	//membri
	float rx1;
	float rx2;


	float stepr;
	float posx_r;
	float posy_r;


};

//classe per il movimento interno al campo sx
class movc {
public:
	movc() {
		posx_c = 750.0f;
		posy_c = 800.0f;
		stepc = 1.0f;

		bsx = 23.0f;
		bdx = 776.0f;
	}
	//metodi
	void left_c(sf::RenderWindow& window);
	void right_c(sf::RenderWindow& window);



	//membri
	float posx_c;
	float posy_c;
	float stepc;
	float bsx;
	float bdx;

};






//classe per l'interazione con il menu dei comandi
class joincmdmenu {
public:

	joincmdmenu() {
		cmdjoined = false;
	}

	void join();

	bool cmdjoined;

};
#endif // !X