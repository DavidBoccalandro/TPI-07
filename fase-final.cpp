#include <iostream>
using namespace std;
#include "fase-final.h"

void sumarPDVPorFase1(int monedasJ1, int monedasJ2, int &pdvJ1, int &pdvJ2) {
    const int PDV_GANADOR_FASE1 = 50;

    if (monedasJ1 > monedasJ2) {
        pdvJ1 += PDV_GANADOR_FASE1;
    } else if (monedasJ2 > monedasJ1) {
        pdvJ2 += PDV_GANADOR_FASE1;
    } else {
        pdvJ1 += PDV_GANADOR_FASE1;
        pdvJ2 += PDV_GANADOR_FASE1;
    }
}

const int VALOR_PAQUETE = 30;

void sumarPDVPorPaquetes(int monedasTotales, int &pdv) {
    const int PDV_POR_PAQUETE = 50;
    int paquetes = monedasTotales / VALOR_PAQUETE;

    pdv += paquetes * PDV_POR_PAQUETE;

    cout << "  Paquetes: " << paquetes << endl;
}

void sumarPDVPorSobrantes(int monedasTotales, int &pdv) {
    int sobrantes = monedasTotales % VALOR_PAQUETE;

    pdv += sobrantes;

    cout << "  Sobrantes: " << sobrantes << endl;
}

void sumarPDVPorCofresAbiertos(bool cofresAbiertos[], int &pdv) {
    const int PDV_COFRES_COMPLETOS = 200;
    bool abrioTodos = true;
    int i = 0;

    while (i < 3 && abrioTodos) {
        abrioTodos = cofresAbiertos[i];
        i++;
    }

    if (abrioTodos) {
        pdv += PDV_COFRES_COMPLETOS;
        cout << "  +200 PDV (Abrio todos los cofres)" << endl;
    } else {
        cout << "  +0 PDV (No abrio todos los cofres)" << endl;
    }
}

void sumarPDVPorGemasVendidas(bool gemasVendidas[], int &pdv) {
    const int PDV_GEMAS_COMPLETAS = 200;
    bool vendioTodas = true;
    int i = 0;

    while (i < 3 && vendioTodas) {
        vendioTodas = gemasVendidas[i];
        i++;
    }

    if (vendioTodas) {
        pdv += PDV_GEMAS_COMPLETAS;
        cout << "  +200 PDV (Vendio todos los tipos de gemas)" << endl;
    } else {
        cout << "  +0 PDV (No vendio todos los tipos de gemas)" << endl;
    }
}

void sumarPDVPorLlaveGuardada(bool abrioConLlaveGuardada, int &pdv) {
    const int PDV_LLAVE_GUARDADA = 300;

    if (abrioConLlaveGuardada) {
        pdv += PDV_LLAVE_GUARDADA;
        cout << "  +300 PDV (Abrio cofre con llave guardada)" << endl;
    } else {
        cout << "  +0 PDV (No abrio cofre con llave guardada)" << endl;
    }
}
