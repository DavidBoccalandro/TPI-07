#pragma once
#include <string>
using namespace std;


/// Funcion PRINCIPAL
void jugarFase1(int &monedasAcumJ1, int &monedasAcumJ2);

// Función que va a devuelver un número aleatorio del 1 al 6
int tirarDado();

void mostrarTirada();

///Funcion que analiza repetidos

bool tieneRepetidos(int dados[2]);

// Función que realiza la competencia del juego

void competenciaUno(int &monedasAcumJ1, int &monedasAcumJ2); // Guarda los resultados de los jugadores
 // Función que realiza la competencia 2 del juego
void competenciaDos(int &monedasAcumJ1, int &monedasAcumJ2);

void competenciaTres(int &monedasAcumJ1, int &monedasAcumJ2);


// monedasAcumJ1, monedasAcumJ2, monedasRondaJ1, monedasRondaJ2

///Funcion que genera la tirada;
int tiradaDados(int vec[], int cant);
///Funcion que ordena y evalua si el vector es una escalera
bool esEscalera(int vec[], int cant);
///Funcion que evalua resultados de la competencia 3
void evaluarResultado(int dadosJ1[], int dadosJ2[],int &monedasAcumJ1,int &monedasAcumJ2,int &monedasRondaJ1,int &monedasRondaJ2, string jugador1, string jugador2);

bool confirmarSalir();

