#include "pch.h"
#include <iostream>

// ----------------------------
// Movement
// ----------------------------
void Movement::up(bool pressed) {
    if (pressed) {
        pos_y -= step;
        std::cout << "W pressed: New pos_y = " << pos_y << std::endl;
    }
    if (pos_y < max_heightchngd) {
        pos_y = clone_y;
    }
}

void Movement::down(bool pressed) {
    if (pressed) {
        pos_y += step;
        std::cout << "S pressed: New pos_y = " << pos_y << std::endl;
    }
    if (pos_y > min_heightchngd) {
        pos_y = c_y;
    }
    if (pos_y > recintos_y && pos_x < corner1_x) {
        pos_y = clones_y;
    }
    if (pos_y > recintos_y && pos_x > corner2_x) {
        pos_y = clones_y;
    }
}

void Movement::left(bool pressed) {
    if (pressed) {
        pos_x -= step;
        std::cout << "A pressed: New pos_x = " << pos_x << std::endl;
    }
    if (pos_x < min_widhtchngd) {
        pos_x = c_x;
    }
    if (pos_x < corner1_x && pos_y > recintos_y) {
        pos_x = clones_x;
    }
}

void Movement::right(bool pressed) {
    if (pressed) {
        pos_x += step;
        std::cout << "D pressed: New pos_x = " << pos_x << std::endl;
    }
    if (pos_x > max_widhtchngd) {
        pos_x = clone_x;
    }
    if (pos_x > corner2_x && pos_y > recintos_y) {
        pos_x = corner2_x;
    }
}

// ----------------------------
// MovInt
// ----------------------------
void MovInt::right(bool pressed) {
    if (pressed) {
        pos_xr += stepr;
        std::cout << "D pressed: New pos_x = " << pos_xr << std::endl;
    }
    if (pos_xr > max_widht) {
        pos_xr = clone_maxw;
    }
}

void MovInt::left(bool pressed) {
    if (pressed) {
        pos_xr -= stepr;
        std::cout << "A pressed: New pos_x = " << pos_xr << std::endl;
    }
    if (pos_xr < corner2r) {
        pos_xr = clone_crn2;
    }
}

// ----------------------------
// MovGame
// ----------------------------
MovGame::MovGame() {
    // valori iniziali già presenti nel costruttore del .h
    // quindi non serve riscriverli qui
}

void MovGame::up(bool pressed) {
    if (pressed) {
        posy_g -= offset;
        std::cout << "W pressed: New pos_y = " << posy_g << std::endl;
    }
    if (posy_g < zoy) posy_g = clonezoy;
    if (posy_g < cy3 && posx_g < cx1) posy_g = clonecy3;

    if (posx_g > cx2 && posx_g < cx6) {
        if (posy_g < cy3 && posy_g > cy4) posy_g = clonecy3;
    }
    if (posx_g > cx7 && posx_g < cx5) {
        if (posy_g < cy3) posy_g = clonecy3;
    }
}

void MovGame::down(bool pressed) {
    if (pressed) {
        posy_g += offset;
        std::cout << "S pressed: New pos_y = " << posy_g << std::endl;
    }
    if (posy_g > cy2) posy_g = cy2;
    if (posy_g > cy1 && posx_g < cx1) posy_g = clonecy1;

    if (posx_g > cx2 && posx_g < cx6 && posy_g > cy3 && posy_g < cy1) posy_g = clonecy3;
    if (posx_g > cx6 && posx_g < cx7 && posy_g > cy3 && posy_g < cy1) posy_g = clonecy3;
    if (posx_g > cx7 && posx_g < cx3 && posy_g > cy3 && posy_g < cy1) posy_g = clonecy3;
    if (posx_g > cx9 && posx_g < cx6 && posy_g > cy4 && posy_g < cy3) posy_g = clonecy5;

    if (posy_g < cy4 && posy_g > zoy && posx_g > cx2 && posx_g < cx6) posy_g = zoy;
    if (posy_g > cy1 && posy_g < cy2 && posx_g > cx3 && posx_g < cx4) posy_g = cy1;
}

void MovGame::left(bool pressed) {
    if (pressed) {
        posx_g -= offset;
        std::cout << "A pressed: New pos_x = " << posx_g << std::endl;
    }
    if (posx_g < cx1 && posy_g > cy1) posx_g = cx1;
    if (posx_g < cx1 && posy_g < cy3) posx_g = cx1;
    if (posx_g > cx6 && posx_g < cx7 && posy_g < cy3) posx_g = cx62;
    if (posx_g < bsx) posx_g = bsx;
}

void MovGame::right(bool pressed) {
    if (pressed) {
        posx_g += offset;
        std::cout << "D pressed: New pos_x = " << posx_g << std::endl;
    }
    if (posx_g > cx2 && posy_g > cy1) posx_g = cx2;
    if (posx_g > cx5) posx_g = cx5;
    if (posx_g > cx2 && posx_g < cx6 && posy_g < cy3 && posy_g > cy4) posx_g = cx2;
}

void MovGame::gateFienile() {
    gatef = (posx_g > cx10 && posx_g < cx11);
}

void MovGame::gateLaghetto() {
    gatel = (posx_g > cx33 && posx_g < cx44);
}

void MovGame::gateGirasoli() {
    gateg = (posx_g > cx1 && posx_g < cx2 && posy_g < cy3N && posy_g > cy4);
}

void MovGame::gateCampo() {
    gatec = (posx_g > cx1 && posx_g < cx2 && posy_g > GY1);
}

void MovGame::gateMagazzino() {
    gatem = (posx_g > 1345 && posx_g <= 1461 && posy_g <= 222);
}

void MovGame::gateBosco() {
    gateb = (posx_g < bsx);
}

void MovGame::gateZoo() {
    gatez = (posy_g < zoy);
}

// ----------------------------
// MovF
// ----------------------------
void MovF::up(bool pressed) {
    if (pressed) {
        posy_f -= offsetf;
        std::cout << "W pressed: New pos_y = " << posy_f << std::endl;
    }
    if (posy_f < fy) posy_f = fy;
}

void MovF::down(bool pressed) {
    if (pressed) {
        posy_f += offsetf;
        std::cout << "S pressed: New pos_y = " << posy_f << std::endl;
    }
    if (posy_f > ry) posy_f = ry;
}

// ----------------------------
// MovR
// ----------------------------
void MovR::left(bool pressed) {
    if (pressed) {
        posx_r -= stepr;
        std::cout << "A pressed: New pos_x = " << posx_r << std::endl;
    }
    if (posx_r < rx1) posx_r = rx1;
}

void MovR::right(bool pressed) {
    if (pressed) {
        posx_r += stepr;
        std::cout << "D pressed: New pos_x = " << posx_r << std::endl;
    }
    if (posx_r > rx2) posx_r = rx2;
}

// ----------------------------
// MovC
// ----------------------------
void MovC::left(bool pressed) {
    if (pressed) {
        posx_c -= stepc;
        std::cout << "C pressed: New pos_x = " << posx_c << std::endl;
    }
    if (posx_c < bsx) posx_c = bsx;
}

void MovC::right(bool pressed) {
    if (pressed) {
        posx_c += stepc;
        std::cout << "V pressed: New pos_x = " << posx_c << std::endl;
    }
    if (posx_c > bdx) posx_c = bdx;
}
