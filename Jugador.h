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

        // Métodos para obtener los atributos del personaje
        int getVida();
        int getAtaque();
        int getPosX();
        int getPosY();

        // Métodos para modificar los atributos del personaje
        void setVida(int nuevaVida);
        void setAtaque (int nuevoAtaque);
        void setPosX(int nuevaPosX);
        void setPosY(int nuevaPosY);

};