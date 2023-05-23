#include <iostream>
#include "Jugador.h"


class Enemigo : public Jugador {
private:
    int AtaqueFisico;
    int AtaqueMagico;


public:
    // Constructor
    Enemigo(int vidaInicial, int ataqueInicial, int posXInicial, int posYInicial, int AtaqueFisicoInicial, int AtaqueMagicoInicial);

    // Métodos para obtener los atributos del enemigo
    int getAtaqueFisico();
    int getAtaqueMagico();

    // Métodos para modificar los atributos del enemigo
    void setAtaqueFisico(int nuevoAtaqueFisico);
    void setAtaqueMagico(int nuevoAtaqueMagico);

    Enemigo();

};


