#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#ifndef AVATAR_H
#define AVATAR_H


// Classe per rappresentare un muro o area invalicabile
class Muro {
public:
    Muro(float x1, float y1, float x2, float y2); // rettangolo delimitante
    bool contiene(float x, float y) const;

private:
    float x_min, y_min, x_max, y_max;
};

// Classe Mappa che contiene i muri
class Mappa {
public:
    Mappa();
    void aggiungiMuro(const Muro& muro);
    bool posizioneValida(float x, float y) const;

private:
    std::vector<Muro> muri;
};

// Classe Personaggio che si muove nella mappa
class Personaggio {
public:
    Personaggio(float x, float y, const Mappa& mappa);

    float getVelocita() const { return velocita; }

    void muoviSu();
    void muoviGiu();
    void muoviSinistra();
    void muoviDestra();

    float getX() const;
    float getY() const;

    //metodo test
	void setPos(float x, float y) {
        posX = x;
        posY = y;
    }

private:
    float posX, posY;
    float velocita;
    const Mappa& mappa;
};


#endif // !X