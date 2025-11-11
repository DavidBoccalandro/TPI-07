//#ifndef FASE2_H_INCLUDED
//#define FASE2_H_INCLUDED
//#endif // FASE2_H_INCLUDED
#pragma once
#include <string>


void jugar();
int tirarDado();
void tiradaDados(int vec[], int cant);
void mostrarTirada(int vec[], int cant);
bool esEscalera(int vec[], int cant);
int evaluarResultado(int vec[], int cant);
int dados [5];
//--------Fase 2 especificas
void Obteneritem(int vec);
bool Obtenerllave = false;

