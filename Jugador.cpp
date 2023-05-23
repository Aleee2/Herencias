#include <iostream>
#include "Jugador.h"


// Constructor
Jugador::Jugador(int vidaInicial, int AtaqueInicial, int posXInicial, int posYInicial) :
    vida(vidaInicial), Ataque(AtaqueInicial), posX(posXInicial), posY(posYInicial) {}

// Métodos para obtener los atributos del personaje
int Jugador::getVida() {
    return vida;
}

int Jugador::getAtaque() {
    return Ataque;
}

int Jugador::getPosX() {
    return posX;
}

int Jugador::getPosY() {
    return posY;
}

// Métodos para modificar los atributos del personaje
void Jugador::setVida(int nuevaVida) {
    vida = nuevaVida;
}

void Jugador::setAtaque(int nuevoAtaque) {
    Ataque = nuevoAtaque;
}

void Jugador::setPosX(int nuevaPosX) {
    posX = nuevaPosX;
}

void Jugador::setPosY(int nuevaPosY) {
    posY = nuevaPosY;
}

