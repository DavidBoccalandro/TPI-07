#pragma once
#include <string>
#include <vector>
using namespace std;


void jugar();
int tirarDado();
void mostrarTirada(int vec[], int cant);
bool esEscalera(int vec[], int cant);
int evaluarResultado(int vec[], int cant);

//--------Fase 2 especificas
void Obteneritem(int vec);

void JugarBusqueda(string &J1,string &J2,vector<int> &monedas);
void JugarRonda1(string &J1,string &J2,vector<int> &monedas);
