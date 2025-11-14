#pragma once
#include <string>

using namespace std;

// Función que va a devuelver un número aleatorio del 1 al 6
int tirarDado();

void mostrarTirada();

///Funcion que analiza repetidos

bool tieneRepetidos(int dados[2]);

void jugarFase1(int monedas[]);

// Función que realiza la competencia del juego

void competencia(int monedas[2]); // Guarda los resultados de los jugadores
 // Función que realiza la competencia 2 del juego
void competenciaDos(int monedas[2]);

void jugar ();


// monedasAcumJ1, monedasAcumJ2, monedasRondaJ1, monedasRondaJ2

///Funcion que genera la tirada;
int tiradaDados(int vec[], int cant);
///Funcion que ordena y evalua si el vector es una escalera
bool esEscalera(int vec[], int cant);
///Funcion que evalua resultados de la competencia 3
int evaluarResultado(int vec[], int vec1[]);

bool confirmarSalir();

