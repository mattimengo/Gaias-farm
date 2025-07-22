#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <avatar.h>

class Movement {
protected:
    float pos_x, pos_y;
    float step;
    float max_heightchngd, min_heightchngd, max_widhtchngd, min_widhtchngd;
    float clone_x, clone_y, c_x, c_y;
    float recintos_y, corner1_x, corner2_x;
    float clones_x, clones_y;

public:
    Movement(float start_x, float start_y, float step_size) :
        pos_x(start_x), pos_y(start_y), step(step_size) {}

    void up(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            pos_y -= step;
            std::cout << "W pressed: New pos_y = " << pos_y << std::endl;
        }
        if (pos_y < max_heightchngd) {
            pos_y = clone_y;
        }
    }

    void down(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
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

    void left(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
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

    void right(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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

    float getX() const { return pos_x; }
    float getY() const { return pos_y; }

    // Setter per parametri (opzionale)
    void setBounds(float maxH, float minH, float maxW, float minW) {
        max_heightchngd = maxH;
        min_heightchngd = minH;
        max_widhtchngd = maxW;
        min_widhtchngd = minW;
    }

    void setClonePositions(float cx, float cy, float cxx, float cyy) {
        clone_x = cx;
        clone_y = cy;
        c_x = cxx;
        c_y = cyy;
    }

    void setRecinto(float rec_y, float c1_x, float c2_x, float cl_x, float cl_y) {
        recintos_y = rec_y;
        corner1_x = c1_x;
        corner2_x = c2_x;
        clones_x = cl_x;
        clones_y = cl_y;
    }
};

class MovInt {
private:
    float pos_xr;
    float stepr;
    float max_widht;
    float clone_maxw;
    float corner2r;
    float clone_crn2;

public:
    MovInt(float start_xr, float step_r) : pos_xr(start_xr), stepr(step_r) {}

    void right_i(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            pos_xr += stepr;
            std::cout << "D pressed: New pos_x = " << pos_xr << std::endl;
        }
        if (pos_xr > max_widht) {
            pos_xr = clone_maxw;
        }
    }

    void left_i(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            pos_xr -= stepr;
            std::cout << "A pressed: New pos_x = " << pos_xr << std::endl;
        }
        if (pos_xr < corner2r) {
            pos_xr = clone_crn2;
        }
    }

    void setBounds(float maxW, float cloneMax, float corner2, float cloneC2) {
        max_widht = maxW;
        clone_maxw = cloneMax;
        corner2r = corner2;
        clone_crn2 = cloneC2;
    }

    float getXr() const { return pos_xr; }
};

// Classe per movimenti di gioco più complessi
class MovGame {
private:
    float posx_g, posy_g;
    float offset;
    // Limiti e coordinate varie
    float zoy, clonezoy;
    float cy1, cy2, cy3, cy4, cy3N, clonecy1, clonecy3, clonecy5;
    float cx1, cx2, cx3, cx4, cx5, cx6, cx7, cx9;
    float cx10, cx11, cx33, cx44;
    float GY1;
    float bsx;
    bool gatef, gatel, gateg, gatec, gatem, gateb, gatez;

    float cx62; // per limite specifico

public:
    MovGame(float start_x, float start_y, float move_offset) :
        posx_g(start_x), posy_g(start_y), offset(move_offset),
        gatef(false), gatel(false), gateg(false), gatec(false),
        gatem(false), gateb(false), gatez(false) {}

    void up_g(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
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

    void down_g(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            posy_g += offset;
            std::cout << "S pressed: New pos_y = " << posy_g << std::endl;
        }
        if (posy_g > cy2) posy_g = cy2;
        if (posy_g > cy1 && posx_g < cx1) posy_g = clonecy1;

        if (posx_g > cx2 && posx_g < cx6) {
            if (posy_g > cy3 && posy_g < cy1) posy_g = clonecy3;
        }

        if (posx_g > cx6 && posx_g < cx7) {
            if (posy_g > cy3 && posy_g < cy1) posy_g = clonecy3;
        }

        if (posx_g > cx7 && posx_g < cx3) {
            if (posy_g > cy3 && posy_g < cy1) posy_g = clonecy3;
        }

        if (posx_g > cx9 && posx_g < cx6) {
            if (posy_g > cy4 && posy_g < cy3) posy_g = clonecy5;
        }

        if (posy_g < cy4 && posy_g > zoy && posx_g > cx2 && posx_g < cx6) {
            posy_g = zoy;
        }

        if (posy_g > cy1 && posy_g < cy2 && posx_g > cx3 && posx_g < cx4) {
            posy_g = cy1;
        }
    }

    void left_g(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            posx_g -= offset;
            std::cout << "A pressed: New pos_x = " << posx_g << std::endl;
        }
        if (posx_g < cx1 && posy_g > cy1) posx_g = cx1;
        if (posx_g < cx1 && posy_g < cy3) posx_g = cx1;
        if (posx_g > cx6 && posx_g < cx7 && posy_g < cy3) posx_g = cx62;
        if (posx_g < bsx) posx_g = bsx;
    }

    void right_g(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            posx_g += offset;
            std::cout << "D pressed: New pos_x = " << posx_g << std::endl;
        }
        if (posx_g > cx2 && posy_g > cy1) posx_g = cx2;
        if (posx_g > cx5) posx_g = cx5;
        if (posx_g > cx2 && posx_g < cx6 && posy_g < cy3 && posy_g > cy4) posx_g = cx2;
    }

    void gate_fienile() {
        gatef = (posx_g > cx10 && posx_g < cx11);
    }

    void gate_laghetto() {
        gatel = (posx_g > cx33 && posx_g < cx44);
    }

    void gate_girasoli() {
        gateg = (posx_g > cx1 && posx_g < cx2 && posy_g < cy3N && posy_g > cy4);
    }

    void gate_campo() {
        gatec = (posx_g > cx1 && posx_g < cx2 && posy_g > GY1);
    }

    void gate_magazzino() {
        gatem = (posx_g > 1345 && posx_g <= 1461 && posy_g <= 222);
    }

    void gate_bosco() {
        gateb = (posx_g < bsx);
    }

    void gate_zoo() {
        gatez = (posy_g < zoy);
    }

    // Getters per posizioni e gate
    float getX() const { return posx_g; }
    float getY() const { return posy_g; }
    bool isGateF() const { return gatef; }
    bool isGateL() const { return gatel; }
    bool isGateG() const { return gateg; }
    bool isGateC() const { return gatec; }
    bool isGateM() const { return gatem; }
    bool isGateB() const { return gateb; }
    bool isGateZ() const { return gatez; }

    // Setter per parametri (da implementare se serve)
    void setLimits(/* parametri */) {
        // ...
    }
};

class MovF {
private:
    float posy_f;
    float offsetf;
    float fy, ry;

public:
    MovF(float start_y, float offset_f) : posy_f(start_y), offsetf(offset_f) {}

    void up_f(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            posy_f -= offsetf;
            std::cout << "W pressed: New pos_y = " << posy_f << std::endl;
        }
        if (posy_f < fy) posy_f = fy;
    }

    void down_f(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            posy_f += offsetf;
            std::cout << "S pressed: New pos_y = " << posy_f << std::endl;
        }
        if (posy_f > ry) posy_f = ry;
    }

    float getY() const { return posy_f; }
};

class MovR {
private:
    float posx_r;
    float stepr;
    float rx1, rx2;

public:
    MovR(float start_x, float step_r) : posx_r(start_x), stepr(step_r) {}

    void left_r(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            posx_r -= stepr;
            std::cout << "A pressed: New pos_x = " << posx_r << std::endl;
        }
        if (posx_r < rx1) posx_r = rx1;
    }

    void right_r(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            posx_r += stepr;
            std::cout << "D pressed: New pos_x = " << posx_r << std::endl;
        }
        if (posx_r > rx2) posx_r = rx2;
    }

    float getX() const { return posx_r; }
};

class JoinCmdMenu {
private:
    bool cmdjoined;

public:
    JoinCmdMenu() : cmdjoined(false) {}

    void join() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            cmdjoined = true;
        }
    }

    bool isJoined() const { return cmdjoined; }
};

class MovC {
private:
    float posx_c;
    float stepc;
    float bsx, bdx;

public:
    MovC(float start_x, float step_c) : posx_c(start_x), stepc(step_c) {}

    void left_c(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            posx_c -= stepc;
            std::cout << "C pressed: New pos_x = " << posx_c << std::endl;
        }
        if (posx_c < bsx) posx_c = bsx;
    }

    void right_c(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
            posx_c += stepc;
            std::cout << "V pressed: New pos_x = " << posx_c << std::endl;
        }
        if (posx_c > bdx) posx_c = bdx;
    }

    float getX() const { return posx_c; }
};
