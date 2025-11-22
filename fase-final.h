#pragma once
#include <string>
using namespace std;

void sumarPDVPorFase1(string J1, string J2, int monedasJ1, int monedasJ2, int &pdvJ1, int &pdvJ2);

void sumarPDVPorPaquetes(int monedasTotales, int &pdv);

void sumarPDVPorSobrantes(int monedasTotales, int &pdv);

void sumarPDVPorCofresAbiertos(string nombreJugador, bool cofresAbiertos[], int &pdv);

void sumarPDVPorGemasVendidas(string nombreJugador, bool gemasVendidas[], int &pdv);

void sumarPDVPorLlaveGuardada(string nombreJugador, bool abrioConLlaveGuardada, int &pdv);

void jugarFase3(string J1, string J2, int monedasFaseUnoJ1, int monedasFaseUnoJ2,int monedasAcumJ1, int monedasAcumJ2,bool cofresAbiertosJ1[3], bool cofresAbiertosJ2[3],bool gemasVendidasJ1[3], bool gemasVendidasJ2[3],bool abrioConLlaveGuardadaJ1, bool abrioConLlaveGuardadaJ2);
