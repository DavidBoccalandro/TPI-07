#pragma once
#include <string>
#include "utilidades.h"
using namespace std;

void mostrarItems(int dados[5]);

bool obtuvoLlave(int p, int &ronda);

void consultarLlaveGuardada( int &llaveGuardada);

int venderTesoros(int dados[5], int &monedasAcum);

int venderLlaves(int dados[5], int &monedasAcum);

void conseguirTesoro(int &monedasAcum, int dados[]);

void buscarTesoros (int &monedasAcum, int &llaveGuardada, int &ronda);

void jugarFase2(string &J1, string &J2, int &monedasAcumJ1, int &monedasAcumJ2);
