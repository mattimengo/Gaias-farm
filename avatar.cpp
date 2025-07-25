#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "avatar.h"




movgame::movgame(): posx_g(928.0f), posy_g(600.0f), offset(1.0f),
        cx1(872.0f), cx2(960.0f), cx22(970.0f), cx3(1627.0f), cx33(1640.0f),
        cx4(1760.0f), cx44(1780.0f), cx5(1750.0f), cx6(1452.0f), cx62(1460.0f),
        cx7(1530.0f), cx8(872.0f), cx9(1135.0f), cx10(430.0f), cx11(550.0f),
        cy1(620.0f), clonecy1(620.0f), cy2(772.0f), cy3(585.0f), clonecy3(585.0f),
        cy4(220.0f), cy44(200.0f), cy5(422.0f), clonecy5(422.0f),
        cy3N(450.0f),
        bsx(23.0f),
        zoy(220.0f), clonezoy(220.0f),
        gy1(750.0f), gy2(680.0f),
        GY1(750.0f),
        lx(1120.0f), ly(770.0f),
        gx(960.0f), gy(400.0f),
        gatef(false), gatel(false), gateg(false),
		gatec(false), gatem(false), gateb(false), gatez(false) {}


void movgame::up_g(sf::RenderWindow& window, bool w_pressed) {
        if (w_pressed) {
            posy_g -= offset;  // Movimento verso l'alto
            std::cout << "W pressed: New pos_y = " << posy_g << std::endl;
        }

        //limite con zoo
        if (posy_g < zoy) {
            //limite
            posy_g = clonezoy;
            //collegamento con lo zoo
        }

        //limite con cy3 a sx
        if (posy_g < cy3 && posx_g < cx1) {
            posy_g = clonecy3;
        }


        //limite con cy3 tra cx2 e cx6
        if (posx_g > cx2 && posx_g < cx6) {
            if (posy_g < cy3 && posy_g > cy4) {
                posy_g = clonecy3;
            }
        }


        //limite con cy3 tra cx7 e cx5
        if (posx_g > cx7 && posx_g < cx5) {
            if (posy_g < cy3) {
                posy_g = clonecy3;
            }
        }





    }


void movgame::down_g(sf::RenderWindow& window, bool s_pressed) {

        if (s_pressed) {
            posy_g += offset;
            std::cout << "S pressed: New pos_y = " << posy_g << std::endl;
        }


        //limite con cy2
        if (posy_g > cy2) {
            posy_g = cy2;
        }

        //limite con cy1 sx
        if (posy_g > cy1 && posx_g < cx1) {
            posy_g = clonecy1;
        }

        //limite con cy3 tra cx2 e cx6
        if (posx_g > cx2 && posx_g < cx6) {
            if (posy_g > cy3 && posy_g < cy1) {
                posy_g = clonecy3;
            }
        }

        //limite con cy3 tra cx6 e cx7
        if (posx_g > cx6 && posx_g < cx7) {
            if (posy_g > cy3 && posy_g < cy1) {
                posy_g = clonecy3;
            }
        }



        //limite con cy3 tra cx7 e cx3
        if (posx_g > cx7 && posx_g < cx3) {
            if (posy_g > cy3 && posy_g < cy1) {
                posy_g = clonecy3;
            }
        }

        //limite con cy4 tra cx9 e cx6
        if (posx_g > cx9 && posx_g < cx6) {
            if (posy_g > cy4 && posy_g < cy3) {
                posy_g = clonecy5;
            }
        }


        //limite con cy4 tra cx2 e cx6
        if (posy_g < cy4 && posy_g > zoy && posx_g > cx2 && posx_g < cx6) {
            posy_g = zoy;
        }

        //limite con cy1 tra cx3 e cx4
        if (posy_g > cy1 && posy_g < cy2 && posx_g > cx3 && posx_g < cx4) {
            posy_g = cy1;
        }
    }    

    

void movgame::left_g(sf::RenderWindow& window, bool a_pressed) {

        if (a_pressed) {
            posx_g -= offset; // Movimento verso sinistra
            std::cout << "A pressed: New pos_x = " << posx_g << std::endl;
        }

        //limite con cx1 basso
        if (posx_g < cx1 && posy_g > cy1) {
            posx_g = cx1;
        }

        //limite con cx1 alto
        if (posx_g < cx1 && posy_g < cy3) {
            posx_g = cx1;
        }

        //limite con cy3 tra cx6 e cx7
        if (posx_g > cx6 && posx_g < cx7 && posy_g < cy3) {
            posx_g = cx62;
        }


        //limite con bosco
        if (posx_g < bsx) {
            posx_g = bsx;
        }




    }    

    
void movgame::right_g(sf::RenderWindow& window, bool d_pressed) {
   

        if (d_pressed) {
            posx_g += offset; // Movimento verso destra
            std::cout << "D pressed: New pos_x = " << posx_g << std::endl;
        }

        //limite con cx2 basso
        if (posx_g > cx2 && posy_g > cy1) {
            posx_g = cx2;
        }


        //limite con cx5
        if (posx_g > cx5) {
            posx_g = cx5;
        }

        //limite con cx2 tra cy3 e cy4
        if (posx_g > cx2 && posx_g < cx6 && posy_g < cy3 && posy_g > cy4) {
            posx_g = cx2;
        }








    }
   

    


















