#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Función que va a devuelver un número aleatorio del 1 al 6
int tirarDado();

void mostrarTirada();

///Funcion que analiza repetidos

bool tieneRepetidos(int dados[2]);


// Función que realiza la competencia del juego

void competencia(int monedas[2]); // Guarda los resultados de los jugadores

// monedasAcumJ1, monedasAcumJ2, monedasRondaJ1, monedasRondaJ2

int tiradaDados();

