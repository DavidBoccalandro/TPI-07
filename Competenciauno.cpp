#include "competenciauno.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función que devuelve un número aleatorio del 1 al 6
int tirarDado() {
    return rand() % 6 + 1;
}

// Función que realiza la competencia del juego
void competencia(vector<int> &monedas) {
    vector<int> dados(2); // Guarda los resultados de los dos jugadores

    cout << "--- COMPETENCIA #1 ---" << endl;

    // Cada jugador tira el dado
    for (int i = 0; i < 2; i++) {
        dados[i] = tirarDado();
        cout << "Jugador " << i + 1 << " tira el dado y obtiene: " << dados[i] << endl;
    }

    // Determinar el ganador
    if (dados[0] > dados[1]) {
        cout << "Jugador 1 gana la competencia y recibe 50 monedas" << endl;
        monedas[0] += 50;
    }
    else if (dados[1] > dados[0]) {
        cout << "Jugador 2 gana la competencia y recibe 50 monedas" << endl;
        monedas[1] += 50;
    }
    else {
        cout << "Empate! Ambos jugadores reciben 25 monedas" << endl;
        monedas[0] += 25;
        monedas[1] += 25;
    }
}
