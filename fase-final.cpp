#include <iostream>
using namespace std;
#include "fase-final.h"

/// mostramos las reglas de la fase final
void mostrarReglasFaseFinal(){
    cout << "Reglas: " << endl<<endl;
    cout << "Los Puntos de Victoria (PDV) se calculan asi:" << endl;
    cout << endl;
    cout << ">>> Sobre monedas:" << endl;
    cout << "---> Mas monedas en Fase Inicial: +100 PDV" << endl;
    cout << "---> Paquetes de 30 monedas sobre el total acumulado: +50 PDV cada paquete" << endl;
    cout << "---> Del cálculo de paquetes, cada moneda sobrante suma +1 PDV directamente" << endl;

    cout << endl << endl;
    cout << ">>> Sobre llaves, gemas y cofres:" << endl;
    cout << "---> Abrir TODOS los cofres: +200 PDV" << endl;
    cout << "---> Vender TODOS los tipos de gemas: +200 PDV" << endl;
    cout << "---> Abrir al menos UN cofre con llave guardada: +300 PDV" << endl << endl << endl;
    cout << "Quien tenga mas PDV acumulados, en base a estos cálculos, gana la partida!" << endl << endl;

        system("pause");
        system("cls");
}

void sumarPDVPorFase1(string J1, string J2, int monedasJ1, int monedasJ2, int &pdvJ1, int &pdvJ2) {
    const int PDV_GANADOR_FASE1 = 100;

    if (monedasJ1 > monedasJ2) {
        pdvJ1 += PDV_GANADOR_FASE1;
        cout << J1 << " gana +100 PDV" << endl;
    } else if (monedasJ2 > monedasJ1) {
        pdvJ2 += PDV_GANADOR_FASE1;
        cout << J2 << " gana +100 PDV" << endl;
    } else {
        pdvJ1 += PDV_GANADOR_FASE1;
        pdvJ2 += PDV_GANADOR_FASE1;
        cout << "Empate! Ambos ganan +100 PDV" << endl;
    }
}

const int VALOR_PAQUETE = 30;

void sumarPDVPorPaquetes(int monedasTotales, int &pdv) {
    const int PDV_POR_PAQUETE = 50;
    int paquetes = monedasTotales / VALOR_PAQUETE;
    int pdvPaquetes = paquetes * PDV_POR_PAQUETE;

    pdv += pdvPaquetes;

    cout << "  - " << paquetes << " paquetes x 50 = " << pdvPaquetes << " PDV" << endl;
}

void sumarPDVPorSobrantes(int monedasTotales, int &pdv) {
    int sobrantes = monedasTotales % VALOR_PAQUETE;

    pdv += sobrantes;

    cout << "  - " << sobrantes << " sueltas x 1 = " << sobrantes << " PDV" << endl;
}

void sumarPDVPorCofresAbiertos(string nombreJugador, bool cofresAbiertos[], int &pdv) {
    const int PDV_COFRES_COMPLETOS = 200;
    bool abrioTodos = true;
    int i = 0;

    while (i < 3 && abrioTodos) {
        abrioTodos = cofresAbiertos[i];
        i++;
    }

    if (abrioTodos) {
        pdv += PDV_COFRES_COMPLETOS;
        cout << nombreJugador << ": Abrio los 3 cofres = +200 PDV" << endl;
    } else {
        cout << nombreJugador << ": No abrio todos los cofres = +0 PDV" << endl;
    }
}

void sumarPDVPorGemasVendidas(string nombreJugador, bool gemasVendidas[], int &pdv) {
    const int PDV_GEMAS_COMPLETAS = 200;
    bool vendioTodas = true;
    int i = 0;

    while (i < 3 && vendioTodas) {
        vendioTodas = gemasVendidas[i];
        i++;
    }

    if (vendioTodas) {
        pdv += PDV_GEMAS_COMPLETAS;
        cout << nombreJugador << ": Vendio todos los tipos de gemas = +200 PDV" << endl;
    } else {
        cout << nombreJugador << ": No vendio todos los tipos de gemas = +0 PDV" << endl;
    }
}

void sumarPDVPorLlaveGuardada(string nombreJugador, bool abrioConLlaveGuardada, int &pdv) {
    const int PDV_LLAVE_GUARDADA = 300;

    if (abrioConLlaveGuardada) {
        pdv += PDV_LLAVE_GUARDADA;
        cout << nombreJugador << ": Abrio cofre con llave guardada = +300 PDV" << endl;
    } else {
        cout << nombreJugador << ": No abrio cofre con llave guardada = +0 PDV" << endl;
    }
}


//funcion principal de la fase final
void jugarFase3(string J1, string J2, int monedasFaseUnoJ1, int monedasFaseUnoJ2,int monedasAcumJ1, int monedasAcumJ2,bool cofresAbiertosJ1[3],bool cofresAbiertosJ2[3],bool gemasVendidasJ1[3], bool gemasVendidasJ2[3],bool abrioConLlaveGuardadaJ1, bool abrioConLlaveGuardadaJ2,string &nombreMayorPDVHistorico, int &puntajeMayorPDVHistorico) {

    // empezamos con 0 puntos
    int pdvJ1 = 0;
    int pdvJ2 = 0;

    cout << endl << endl;
    cout << "========================================" << endl;
    cout << "  FASE FINAL - PUNTOS DE VICTORIA (PDV) " << endl;
    cout << "========================================" << endl;
    cout << endl;

/// mostramos las reglas completas antes de empezar
            mostrarReglasFaseFinal();


        /// *************** CALCULO 1 DE pdV
    /// mostramos cuantas monedas tenian al final de la fase inicial
    cout << "--- Monedas al final de Fase Inicial ---" << endl;
    cout << J1 << ": " << monedasFaseUnoJ1 << " monedas" << endl;
    cout << J2 << ": " << monedasFaseUnoJ2 << " monedas" << endl;
    cout << endl;

    /// llamamos funcion encargada de calcular los PDV por fase 1
    sumarPDVPorFase1(J1, J2, monedasFaseUnoJ1, monedasFaseUnoJ2, pdvJ1, pdvJ2);
    cout << endl;

    system("pause");
    system("cls");

    /// *************** CALCULO 2 y 3 DE PDVv - paquetes vs sueltas
    cout << "--- Calculo por Paquetes y Monedas Sueltas ---" << endl;
    cout << endl;
    
    // para J1
    cout << J1 << " (" << monedasAcumJ1 << " monedas totales):" << endl;
    sumarPDVPorPaquetes(monedasAcumJ1, pdvJ1);
    sumarPDVPorSobrantes(monedasAcumJ1, pdvJ1);
    
    // para J2
    cout << endl << J2 << " (" << monedasAcumJ2 << " monedas totales):" << endl;
    sumarPDVPorPaquetes(monedasAcumJ2, pdvJ2);
    sumarPDVPorSobrantes(monedasAcumJ2, pdvJ2);
    cout << endl << endl;

    system("pause");
    system("cls");

    /// *************** CALCULO 4 DE PDV - cofres
    cout << "--- Calculo por Cofres Abiertos ---" << endl << endl;
    sumarPDVPorCofresAbiertos(J1, cofresAbiertosJ1, pdvJ1);
    sumarPDVPorCofresAbiertos(J2, cofresAbiertosJ2, pdvJ2);
    cout <<endl;
    system("pause");
    system("cls");

    /// *************** CALCULO 5 DE PDV - gemas vendidas
    cout << "--- Calculo por Tipos de Gemas Vendidas ---" << endl << endl;
    sumarPDVPorGemasVendidas(J1, gemasVendidasJ1, pdvJ1);
    sumarPDVPorGemasVendidas(J2, gemasVendidasJ2, pdvJ2);
    cout << endl;
    system("pause");
    system("cls");

    /// *************** CALCULO 6 DE PDV - llave guardada
    cout << "--- Calculo por Llave Guardada ---" << endl << endl;
    sumarPDVPorLlaveGuardada(J1, abrioConLlaveGuardadaJ1, pdvJ1);
    sumarPDVPorLlaveGuardada(J2, abrioConLlaveGuardadaJ2, pdvJ2);
    cout << endl;
    system("pause");
    system("cls");

    /// aca vemos cuantos puntos tiene cada uno por ahora
    cout << "--- Puntos de Victoria FINALES ---" << endl;
    cout << J1 << ": " << pdvJ1 << " PDV" << endl;
      cout << J2 << ": " << pdvJ2 << " PDV" << endl  << endl;

    cout << "--------------------------------" << endl;
    cout << "Y EL GANADOR ES..... " << endl << endl << endl;
    system("pause");

    /// determinamos el ganador
    string ganadorFinal="";
    int pdvGanador =0;
    bool esEmpate=false;

    if (pdvJ1 > pdvJ2) 
    {
        ganadorFinal = J1;
        pdvGanador = pdvJ1;
    } else 
    if (pdvJ2 > pdvJ1){
        ganadorFinal = J2;
        pdvGanador = pdvJ2;
    } else {
        // empate en PDV asiq hay desempate por cofres abiertos
        cout << endl << endl;
        cout << "HAN EMPATADO EN PDV!!!" << endl;
        cout << "Haremos un desempate..." << endl << endl;

        cout << "Regla:" << endl;
        cout << "- Aquel quien haya abierto TODOS los cofres sera el ganador" << endl;
        cout << "- Si ninguno o ambos abrieron todos los cofres, el resultado es empate oficial" << endl << endl;
        system("pause");

        // contamos cofres abiertos
        int cofresJ1 = 0;
        int cofresJ2 = 0;
        for (int i = 0;i < 3;i++){
            if (cofresAbiertosJ1[i])
            {
               cofresJ1++;
            } 
            if(cofresAbiertosJ2[i]) {
                cofresJ2++;
            } 
        }

        cout << J1 << ": Abrio " << cofresJ1 << " cofres" << endl;
        cout << J2 << ": Abrio " << cofresJ2 << " cofres" << endl << endl;
        system("pause");

        if ((cofresJ1 == 3) && !(cofresJ2 == 3)) {
            ganadorFinal = J1;
            pdvGanador = pdvJ1;
        } else if ((cofresJ2 == 3) && !(cofresJ1 == 3)) {
            ganadorFinal = J2;
            pdvGanador = pdvJ2;
        } else {
            // no se pudo desempatar
            esEmpate = true;
        }
    }

    // guardamos mayor PDV historico para las estadisticas
    if (pdvJ1 > puntajeMayorPDVHistorico) {
        nombreMayorPDVHistorico = J1;
        puntajeMayorPDVHistorico = pdvJ1;
    }
    if (pdvJ2 > puntajeMayorPDVHistorico) {
        nombreMayorPDVHistorico = J2;
        puntajeMayorPDVHistorico = pdvJ2;
    }

    // mostramos ganador final
    cout << endl;
    cout << "========================================" << endl;
    if (esEmpate) {
        cout << "      EMPATE OFICIAL" << endl;
    } else {
        cout << "      GANADOR: " << ganadorFinal << " (" << pdvGanador << " PDV)" << endl;
    }
    cout << "========================================" << endl;
    cout << endl << endl;
}
