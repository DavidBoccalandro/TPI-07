#pragma once
#include <string>

void jugarFase1(int &monedasAcumJ1, int &monedasAcumJ2, std::string &J1, std::string &J2, int &monedasFaseUnoJ1, int &monedasFaseUnoJ2);

bool tieneRepetidos(int dados[3]);

void competenciaUno(int &monedasAcumJ1, int &monedasAcumJ2, std::string &J1, std::string &J2 );

void competenciaDos(int &monedasAcumJ1, int &monedasAcumJ2, std::string J1, std::string J2);

void competenciaTres(int &monedasAcumJ1, int &monedasAcumJ2,  int &monedasFaseUnoJ1, int &monedasFaseUnoJ2, std::string J1, std::string J2);

void tiradaDados(int vec[], int cant);

bool confirmarSalir();
