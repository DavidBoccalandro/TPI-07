#include <iostream>
using namespace std;

#include "fase-final.h"

void calcularPDVSegunMonedasFI(int monedasFase1J1, int monedasFase1J2, int &pdvJ1, int &pdvJ2){
    if(monedasFase1J1 > monedasFase1J2) {
        pdvJ1 += 50;
    } else if (monedasFase1J1 < monedasFase1J2) {
        pdvJ2 += 50;
    } else {
        pdvJ1 += 50;
        pdvJ2 += 50;
    }
}

int calcularPDVPaquetesMonedas(int monedasTotales, int &pdvJugador, int &monedasSobrantes) {
    const int VALOR_PAQUETE = 30;
    int paquetes;

    paquetes = monedasTotales / VALOR_PAQUETE;
    monedasSobrantes = monedasTotales % VALOR_PAQUETE;
    pdvJugador += paquetes * 50;
    pdvJugador += monedasSobrantes;

    return paquetes;
}
