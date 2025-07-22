#ifndef AVATAR_TESTABLE_H
#define AVATAR_TESTABLE_H

// Classe per il movimento sulla mappa
class Movement {
public:
    Movement()
        : pos_x(907.0f), pos_y(439.0f), step(1.0f),
        clone_y(330.0f), c_y(764.0f),
        clone_x(1768.0f), c_x(-60.0f),
        max_heightchngd(330.0f), min_heightchngd(764.0f),
        max_widhtchngd(1768.0f), min_widhtchngd(-60.0f),
        recintos_y(370.0f), corner1_x(770.0f), corner2_x(990.0f),
        clones_x(770.0f), clones_y(370.0f) {
    }

    void up(bool pressed);
    void down(bool pressed);
    void left(bool pressed);
    void right(bool pressed);

    float pos_x, pos_y, step;
    float clone_y, c_y, clone_x, c_x;
    float max_heightchngd, min_heightchngd;
    float max_widhtchngd, min_widhtchngd;
    float recintos_y, corner1_x, corner2_x;
    float clones_x, clones_y;
};

class MovInt {
public:
    MovInt()
        : pos_xr(500.0f), pos_yr(650.0f), stepr(1.0f),
        max_widht(1768.0f), corner2r(990.0f),
        clone_maxw(1768.0f), clone_crn2(990.0f) {
    }

    void left(bool pressed);
    void right(bool pressed);

    float pos_xr, pos_yr, stepr;
    float max_widht, clone_maxw, corner2r, clone_crn2;
};

class MovGame {
public:
    MovGame();

    void up(bool pressed);
    void down(bool pressed);
    void left(bool pressed);
    void right(bool pressed);

    void gateFienile();
    void gateLaghetto();
    void gateGirasoli();
    void gateCampo();
    void gateMagazzino();
    void gateBosco();
    void gateZoo();

    float posx_g, posy_g, offset;
    float cx1, cx2, cx22, cx3, cx33, cx4, cx44, cx5, cx6, cx62, cx7, cx8, cx9, cx10, cx11;
    float cy1, clonecy1, cy2, cy3, clonecy3, cy4, cy44, cy5, clonecy5, cy3N;
    float bsx, zoy, clonezoy, gy1, gy2, GY1;
    float lx, ly, gx, gy;
    bool gatef, gatel, gateg, gatec, gatem, gateb, gatez;
};

class MovF {
public:
    MovF()
        : posx_f(455.0f), posy_f(625.0f), offsetf(1.0f),
        fy(390.0f), ry(435.0f), cxf(430.0f) {
    }

    void up(bool pressed);
    void down(bool pressed);

    float posx_f, posy_f, offsetf;
    float fy, ry, cxf;
};

class MovR {
public:
    MovR()
        : rx1(960.0f), rx2(1630.0f), stepr(1.0f),
        posx_r(1515.0f), posy_r(800.0f) {
    }

    void left(bool pressed);
    void right(bool pressed);

    float rx1, rx2;
    float stepr, posx_r, posy_r;
};

class MovC {
public:
    MovC()
        : posx_c(750.0f), posy_c(800.0f), stepc(1.0f),
        bsx(23.0f), bdx(776.0f) {
    }

    void left(bool pressed);
    void right(bool pressed);

    float posx_c, posy_c, stepc;
    float bsx, bdx;
};

class JoinCmdMenu {
public:
    JoinCmdMenu() : cmdjoined(false) {}

    void join(bool pressed) {
        if (pressed) cmdjoined = true;
    }

    bool cmdjoined;
};

#endif // AVATAR_TESTABLE_H
