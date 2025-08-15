#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "avatar.h"


// Implementazione Muro
Muro::Muro(float x1, float y1, float x2, float y2)
    : x_min(x1), y_min(y1), x_max(x2), y_max(y2) {}

bool Muro::contiene(float x, float y) const {
    return x >= x_min && x <= x_max && y >= y_min && y <= y_max;
}

// Implementazione Mappa
Mappa::Mappa() {}

void Mappa::aggiungiMuro(const Muro& muro) {
    muri.push_back(muro);
}

bool Mappa::posizioneValida(float x, float y) const {
    for (const auto& muro : muri) {
        if (muro.contiene(x, y)) {
            return false;
        }
    }
    return true;
}

// Implementazione Personaggio
Personaggio::Personaggio(float x, float y, const Mappa& m)
    : posX(x), posY(y), velocita(1.0f), mappa(m) {}

void Personaggio::muoviSu() {
    float nuovaY = posY - velocita;
    if (mappa.posizioneValida(posX, nuovaY)) {
        posY = nuovaY;
    }

    //bordo superiore
    if (posY < 330.0f) {
        posY = 330.0f;
    }
}

void Personaggio::muoviGiu() {
    float nuovaY = posY + velocita;
    if (mappa.posizioneValida(posX, nuovaY)) {
        posY = nuovaY;
    }

     //bordo inferiore
    if (posY > 764.0f) {
        posY = 764.0f;
    }

    //recinto alto sx
    if (posY > 370.0f && posX < 770.0f) {
        posY = 370.0f;
    }

    //recinto alto dx
    if (posY > 370.0f && posX > 990.0f) {
        posY = 370.0f;
    }
}

void Personaggio::muoviSinistra() {
    float nuovaX = posX - velocita;
    if (mappa.posizioneValida(nuovaX, posY)) {
        posX = nuovaX;
    }

    //bordo sinistro
    if (posX < 764.0f) {
        posX = -60.0f;
    }


    //recinto verticale sx
    if (posX < 770.0f && posY > 370.0f) {
        posX = 770.0f;
    }
}

void Personaggio::muoviDestra() {
    float nuovaX = posX + velocita;
    if (mappa.posizioneValida(nuovaX, posY)) {
        posX = nuovaX;
    }

    //bordo destro
    if (posX> 1768.0f) {
        posX = 1769.0f;
    }


    //recinto verticale dx
    if (posX > 990.0f && posY > 370.0f) {
        posX = 990.0f;

    }
}

float Personaggio::getX() const { return posX; }
float Personaggio::getY() const { return posY; }













