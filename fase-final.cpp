#include <iostream>
using namespace std;

#include "fase-final.h"

void calcularPDVSegunMonedas(int monedasJ1, int monedasJ2, int &pdvJ1, int &pdvJ2){
    if(monedasJ1 > monedasJ2) {
        pdvJ1 += 50;
    } else if (monedasJ1 < monedasJ2) {
        pdvJ2 += 50;
    } else {
        pdvJ1 += 50;
        pdvJ2 += 50;
    }
}

void calcularPDVPaquetesMonedas(int monedasTotales, int &pdvJugador, int &monedasSobrantes) {
    const int VALOR_PAQUETE = 30;
    int paquetes;

    paquetes = monedasTotales / VALOR_PAQUETE;
    monedasSobrantes = monedasTotales % VALOR_PAQUETE;
    pdvJugador += paquetes * 50;
    pdvJugador += monedasSobrantes;
}
