#pragma once
#include <string>

void jugar();
int tirarDado();
int tiradaDados(int vec[], int cant);
void mostrarTirada(int vec[], int cant);
bool esEscalera(int vec[], int cant);
void evaluarResultado(int vec[], int vec1[], int &monedasAcumJ1,int &monedasAcumJ2,int &monedasRondaJ1,int &monedasRondaJ2,std::string J1,std::string J2);
