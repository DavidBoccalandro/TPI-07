#pragma once
using namespace std;
#include <string>

int tirarDado();

bool esEscalera(int vec[], int cant);

void jugarFase1(int &monedasAcumJ1, int &monedasAcumJ2);

void mostrarTirada(int vec[], int cant);

void evaluarResultado(int dadosJ1[], int dadosJ2[],int &monedasAcumJ1,int &monedasAcumJ2,int &monedasRondaJ1,int &monedasRondaJ2, string jugador1, string jugador2);
