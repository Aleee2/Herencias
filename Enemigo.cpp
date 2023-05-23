#include <iostream>
#include "Enemigo.h"


Enemigo::Enemigo(int vidaInicial, int ataqueInicial, int posXInicial, int posYInicial, int AtaqueFisicoInicial, int AtaqueMagicoInicial) :
    Jugador(vidaInicial,ataqueInicial, posXInicial, posYInicial) {   AtaqueFisico = AtaqueFisicoInicial;
                                                                     AtaqueMagico = AtaqueMagicoInicial;
}

int Enemigo::getAtaqueFisico() {
    return AtaqueFisico;
}

int Enemigo::getAtaqueMagico() {
    return AtaqueMagico;
}

void Enemigo::setAtaqueFisico(int nuevoAtaqueFisico) {
    AtaqueFisico = nuevoAtaqueFisico;
}

void Enemigo::setAtaqueMagico(int nuevoAtaqueMagico) {
    AtaqueMagico = nuevoAtaqueMagico;
}

Enemigo::Enemigo() : Jugador(0, 0, 0, 0), AtaqueFisico(0), AtaqueMagico(0) {

}
