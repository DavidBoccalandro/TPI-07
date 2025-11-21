#pragma once
#include <string>
using namespace std;

void sumarPDVPorFase1(int monedasJ1, int monedasJ2, int &pdvJ1, int &pdvJ2);

void sumarPDVPorPaquetes(int monedasTotales, int &pdv);

void sumarPDVPorSobrantes(int monedasTotales, int &pdv);

void sumarPDVPorCofresAbiertos(bool cofresAbiertos[], int &pdv);

void sumarPDVPorGemasVendidas(bool gemasVendidas[], int &pdv);

void sumarPDVPorLlaveGuardada(bool abrioConLlaveGuardada, int &pdv);

void jugarFase3(string J1, string J2, int monedasFaseUnoJ1, int monedasFaseUnoJ2,
                int monedasAcumJ1, int monedasAcumJ2);
