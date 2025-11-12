#include <iostream>
#include <cstdlib>
#include <ctime>
#include "competencia-uno.h"
#include <string>

// Función que devuelve un número aleatorio del 1 al 6
int tirarDado() {
    return rand() % 6 + 1;
}

// Función que realiza la competencia del juego
void competencia(int monedas[2]) {
    string jugador1, jugador2;
    int dados[2];  // Guarda los resultados de los dos jugadores

    cout << "Comienza el jugo - Fase Inicial";
    cout << "--- COMPETENCIA #1 ---" << endl;

    cout <<"Ingrese el nombre del jugador 1:";
    cin >> jugador1;
    cout <<"Ingrese el nombre del jugador 2:";
    cin >> jugador2;
    cout <<endl;


    // Cada jugador tira el dado

    dados[1] = tirarDado();
    cout << jugador1 << " tira el dado y obtiene: " << dados[1] << endl;
    dados[2] = tirarDado();
    cout << jugador2 << " tira el dado y obtiene: " << dados[2] << endl;

    cout << endl;

    // Determinar al ganador
    if (dados[0] > dados[1]) {
        cout << jugador1 <<"Gana la competencia y recibe 50 monedas" << endl;
        monedas[0] += 50;
    }
    else if (dados[1] > dados[0]) {
        cout << jugador2 << "Gana la competencia y recibe 50 monedas" << endl;
        monedas[1] += 50;
    }
    else {
        cout << "Empate! Ambos jugadores reciben 25 monedas" << endl;
        monedas[0] += 25;
        monedas[1] += 25;
    }
    cout << endl <<"Resultados Fase Inicial" <<endl;
    cout << jugador1 <<":" <<monedas[0] <<"monedas" <<endl;
    cout << jugador2 <<":" <<monedas[1] <<"monedas" <<endl;

}


