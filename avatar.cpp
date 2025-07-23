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




void movint::right_i(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_xr += stepr;  // Movimento verso l'alto
        std::cout << "D pressed: New pos_x = " << pos_xr << std::endl;
    }

    //bordo destro
    if (pos_xr > max_widht) {
        pos_xr = clone_maxw;
    }


}

void movint::left_i(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos_xr -= stepr; // Movimento verso sinistra
        std::cout << "A pressed: New pos_x = " << pos_xr << std::endl;
    }

    //bordo sinistro
    if (pos_xr < corner2r) {
        pos_xr = clone_crn2;
    }

}




void movgame::up_g(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        posy_g -= offset;  // Movimento verso l'alto
        std::cout << "W pressed: New pos_y = " << posy_g << std::endl;
    }

    //limite con zoo
    //if (posy_g < zoy) {
        //limite
    //    posy_g = clonezoy;
        //collegamento con lo zoo
    //}

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

void movgame::down_g(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        posy_g += offset; // Movimento verso il basso
        std::cout << "S pressed: New pos_y = " << posy_g << std::endl;
    }


    //limite con cy2
    if (posy_g > cy2) {
        posy_g = cy2;
    }

    //limte con cy1 sx
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

void movgame::left_g(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
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
    //if (posx_g < bsx) {
     //   posx_g = bsx;
    //}




}

void movgame::right_g(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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

//funzione che gestisce il gate del fienile
void movgame::gate_fienile(sf::RenderWindow& window) {
    if (posx_g > cx10 && posx_g < cx11) {
        gatef = true;
    }
    else {
        gatef = false;
    }
}

//funzione che gestisce il gate del laghetto
void movgame::gate_laghetto(sf::RenderWindow& window) {
    if (posx_g > cx33 && posx_g < cx44) {
        gatel = true;
    }
    else {
        gatel = false;
    }
}

//funzione che gestisce il gate del girasole
void movgame::gate_girasoli(sf::RenderWindow& window) {
    if (posx_g > cx1 && posx_g < cx2 && posy_g < cy3N && posy_g > cy4) {
        gateg = true;
    }
    else {
        gateg = false;
    }
}

//funzione che gestisce il gate del campo
void movgame::gate_campo(sf::RenderWindow& window) {
    if (posx_g > cx1 && posx_g < cx2 && posy_g > GY1) {
        gatec = true;
    }
    else {
        gatec = false;
    }
}

//funzione che gestisce il gate del magazzino
void movgame::gate_magazzino(sf::RenderWindow& window) {
    if (posx_g > 1345 && posx_g <= 1461 && posy_g <= 222) {
        gatem = true;
    }
    else {
        gatem = false;
    }
}

//funzione che gestisce il gate del bosco
void movgame::gate_bosco(sf::RenderWindow& window) {
    //limite con bosco
    if (posx_g < bsx) {
        gateb = true;
    }
    else {
        gateb = false;
    }
}

//funzione che gestisce il gate dello zoo
void movgame::gate_zoo(sf::RenderWindow& window) {
    //limite con zoo
    if (posy_g < zoy) {
        gatez = true;
    }
    else {
        gatez = false;
    }
}



void movf::up_f(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        posy_f -= offsetf;  // Movimento verso l'alto
        std::cout << "W pressed: New pos_y = " << posy_f << std::endl;
    }

    //limite con fienile
    if (posy_f < fy) {
        posy_f = fy;
    }





}

void movf::down_f(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        posy_f += offsetf; // Movimento verso il basso
        std::cout << "S pressed: New pos_y = " << posy_f << std::endl;
    }

    if (posy_f > ry) {
        posy_f = ry;
    }
}




void movr::left_r(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        posx_r -= stepr; // Movimento verso sinistra
        std::cout << "A pressed: New pos_x = " << posx_r << std::endl;
    }
    //bordo sinistro
    if (posx_r < rx1) {
        posx_r = rx1;
    }
}

void movr::right_r(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        posx_r += stepr;  // Movimento verso destra
        std::cout << "D pressed: New pos_x = " << posx_r << std::endl;
    }

    //bordo destro
    if (posx_r > rx2) {
        posx_r = rx2;
    }
}





void joincmdmenu::join() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        bool cmdjoined = true;
    }
}







void movc::left_c(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        posx_c -= stepc; // Movimento verso sinistra
        std::cout << "C pressed: New pos_x = " << posx_c << std::endl;
    }

    //bordo sinistro
    if (posx_c < bsx) {
        posx_c = bsx;
    }
}

void movc::right_c(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        posx_c += stepc; // Movimento verso sinistra
        std::cout << "V pressed: New pos_x = " << posx_c << std::endl;
    }

    //bordo destro
    if (posx_c > bdx) {
        posx_c = bdx;
    }
}




