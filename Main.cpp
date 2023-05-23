#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "Enemigo.h"

using namespace std;

const int FILAS = 10;
const int COLUMNAS = 10;

// Función para mostrar el tablero y el personaje
void mostrarTablero(int filaPersonaje, int columnaPersonaje, Enemigo& Carmen)
{
    system("cls"); // Limpiar la pantalla

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Dibujar el tablero
    for (int fila = 0; fila < FILAS; ++fila)
    {
        for (int columna = 0; columna < COLUMNAS; ++columna)
        {
            if (fila == filaPersonaje && columna == columnaPersonaje) {
                SetConsoleTextAttribute(hConsole, 10); // Color verde para el personaje
                cout << "A "; // Alejandro
            }
            else if (fila == Carmen.getPosX() && columna == Carmen.getPosY()) {
                SetConsoleTextAttribute(hConsole, 12); // Color rojo para Carmen (enemigo final)
                cout << "C "; // Carmen 
                if (Carmen.getPosX() == FILAS - 1 && Carmen.getPosY() == COLUMNAS - 1) {
                    SetConsoleTextAttribute(hConsole, 14); // Color amarillo para el mensaje "ENEMIGO FINAL"
                    cout << "ENEMIGO FINAL ";
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, 7); // Color blanco para espacios vacíos
                cout << "- "; // Espacio vacío
            }
        }
        cout << endl;
    }
}

void pelea(Jugador& personaje, Enemigo& enemigo, const string& nombreEnemigo) {
    bool esEnemigoFinal = (nombreEnemigo == "Carmen");

    if (esEnemigoFinal) {
        cout << "¡ENEMIGO FINAL!" << endl;
    }

    while (personaje.getVida() > 0 && enemigo.getVida() > 0) {
        personaje.setAtaque(rand() % 20 + 1);    // Genera un número aleatorio entre 1 y 20
        enemigo.setAtaque(rand() % 10 + 1);      // Genera un número aleatorio entre 1 y 10
        
        // Combate
        enemigo.setVida(enemigo.getVida() - personaje.getAtaque());
        personaje.setVida(personaje.getVida() - enemigo.getAtaque());

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); 
        cout << "Has infligido " << personaje.getAtaque() << " de danyo a " << nombreEnemigo << "!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); 
        cout << "Has recibido " << enemigo.getAtaque() << " de danyo!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "Vida restante de " << nombreEnemigo << ": " << enemigo.getVida() << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "Tu vida restante: " << personaje.getVida() << endl;
        cout << endl;
    }

    if (personaje.getVida() <= 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Has sido derrotado! Game Over." << endl;
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "Has derrotado a " << nombreEnemigo << " Ganaste la pelea!" << endl;
    }
}

int main(){
    std::cout << "El jugador Alejandro tiene que llegar hasta el enemigo final Carmen para poder llegar a la Salida, el jugador se mueve con las teclas w, a, s y d.\n" << std::endl;

    int filaPersonaje = 0;
    int columnaPersonaje = 0;
    char tecla;
    bool gameOver = false;

    // Creo el jugador
    Jugador Alejandro(100, 30, 0, 0);

    // Generar posiciones aleatorias para los enemigos
    const int numEnemigos = 6;
    Enemigo enemigos[numEnemigos];
    bool enemigoActivo[numEnemigos] = { true, true, true };

    for (int i = 0; i < numEnemigos; ++i) {
        int filaEnemigo = rand() % FILAS;
        int columnaEnemigo = rand() % COLUMNAS;
        enemigos[i] = Enemigo(50, 10, filaEnemigo, columnaEnemigo, 0, 0);
    }

    // Dentro del bucle principal del juego
    while (!gameOver)
    {

        // Declarar y generar posición aleatoria para Carmen
        int columnaCarmen = rand() % COLUMNAS;
        Enemigo Carmen(80, 10, FILAS - 1, columnaCarmen, 25, 20);
        mostrarTablero(filaPersonaje, columnaPersonaje, Carmen);

        // Verificar si me encuentro en la posición de un enemigo
        for (int i = 0; i < numEnemigos; ++i) {
            if (filaPersonaje == enemigos[i].getPosX() && columnaPersonaje == enemigos[i].getPosY() && enemigoActivo[i]) {
                // Iniciar la pelea entre el jugador y el enemigo
                pelea(Alejandro, enemigos[i], "Enemigo");
                enemigoActivo[i] = false; // Desactivar el enemigo después de la pelea
                break;
            }
        }

        // Verificar me encuentro en la posición de Carmen
        if (filaPersonaje == Carmen.getPosX() && columnaPersonaje == Carmen.getPosY()) {
            // Iniciar la pelea contra Carmen
            pelea(Alejandro, Carmen, "Carmen");
            gameOver = true; // Terminar después de la pelea contra Carmen
        }

        cin >> tecla;

        // Mover el personaje según la tecla presionada
        switch (tecla)
        {
        case 'w': 
            if (filaPersonaje > 0)
            {
                --filaPersonaje;
            }
            break;
        case 's': 
            if (filaPersonaje < FILAS - 1)
            {
                ++filaPersonaje;
            }
            break;
        case 'a': 
            if (columnaPersonaje > 0)
            {
                --columnaPersonaje;
            }
            break;
        case 'd': 
            if (columnaPersonaje < COLUMNAS - 1)
            {
                ++columnaPersonaje;
            }
            break;
        case 'q': // Salir
            gameOver = true;
            break;
        }

        mostrarTablero(filaPersonaje, columnaPersonaje, Carmen);
    }

    cout << "Juego terminado. Presiona cualquier tecla para salir...";
    cin >> tecla; // Esperar a presionar una tecla antes de salir

    return 0;
}
 