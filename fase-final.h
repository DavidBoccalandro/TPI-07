#ifndef FASE-FINAL_H_INCLUDED
#define FASE-FINAL_H_INCLUDED

void sumarPDVPorFase1(int monedasJ1, int monedasJ2, int &pdvJ1, int &pdvJ2);

void sumarPDVPorPaquetes(int monedasTotales, int &pdv);

void sumarPDVPorSobrantes(int monedasTotales, int &pdv);

void sumarPDVPorCofresAbiertos(bool cofresAbiertos[], int &pdv);

void sumarPDVPorGemasVendidas(bool gemasVendidas[], int &pdv);

void sumarPDVPorLlaveGuardada(bool abrioConLlaveGuardada, int &pdv);

#endif // FASE-FINAL_H_INCLUDED
