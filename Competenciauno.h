#pragma once

#include "competenciauno.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Función que va a devuelver un número aleatorio del 1 al 6
int tirarDado();

// Función que realiza la competencia del juego

void competencia(vector<int> &monedas); // Guarda los resultados de los jugadores
