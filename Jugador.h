#include <iostream>


class Jugador {
    private:
        int vida;
        int Ataque;
        int posX;
        int posY;

    public:
        // Constructor
        Jugador(int vidaInicial, int ataqueInicial, int posXInicial, int posYInicial);

        // M�todos para obtener los atributos del personaje
        int getVida();
        int getAtaque();
        int getPosX();
        int getPosY();

        // M�todos para modificar los atributos del personaje
        void setVida(int nuevaVida);
        void setAtaque (int nuevoAtaque);
        void setPosX(int nuevaPosX);
        void setPosY(int nuevaPosY);

};