#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include "fase1.h"
#include "Fase2.h"
#include "fase-final.h"

//definiciones
void mostrarCreditos() {
    cout << endl;
    cout << "======== CREDITOS ==========" << endl;
    cout<< "========Equipo 07==========="<< endl;
    cout<< endl;
    cout<< " * Bassi, Cristian Hernan ---------> legajo: 32409"<< endl;
    cout<< " * Boccalandro, David Ismael ----> legajo: 32382"<< endl;
    cout<< " * Cardenas, Gustavo -------------> legajo: 34269"<< endl;
    cout<< " * Specht, Giselle Mailen --------> legajo: 33101"<< endl;
}

int main() {
    srand(time(0)); // Inicializa el generador aleatorio

    int monedas[2] = {150, 150}; // Cada jugador empieza con 150 monedas
    int monedasAcumJ1 = 150;
    int monedasAcumJ2 = 150;
    int monedasFaseUnoJ1= 0;
    int monedasFaseUnoJ2=0;
    int opcion;
    string J1, J2;
    bool cofresAbiertosJ1[3] = {false, false, false};
    bool cofresAbiertosJ2[3] = {false, false, false};
    // esmeralda (4) ,,rubies ,(5) diamantes (6)
    bool gemasVendidasJ1[3] = {false, false, false};
    bool gemasVendidasJ2[3] = {false, false, false};
    bool abrioConLlaveGuardadaJ1 = false;
    bool abrioConLlaveGuardadaJ2 = false;
    // estadisticas
    string nombreMayorPDVHistorico = "";
    int puntajeMayorPDVHistorico = 0;

    do //se ejecuta hasta el usuario seleccione una opcion distinta a salir
    {
        cout << endl;
        cout << "===========================" << endl;
        cout << "    ROLL AND RETURN        " << endl;
        cout << "===========================" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "0 - SALIR" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Selecciona una opcion para continuar... "<<endl;
        cout <<endl;
        cin >> opcion;
        system("cls");



        switch (opcion)
        {
        case 0: {
            if( confirmarSalir() ==true){
             cout << endl << "Gracias por jugar!" << endl;
             system("pause");
             system("cls");
             return 0;
            }
            system("cls");
             break;
        }
        case 1: {
            jugarFase1(monedasAcumJ1, monedasAcumJ2, J1, J2, monedasFaseUnoJ1, monedasFaseUnoJ2);
            jugarFase2(J1, J2, monedasAcumJ1, monedasAcumJ2, cofresAbiertosJ1, cofresAbiertosJ2, gemasVendidasJ1, gemasVendidasJ2, abrioConLlaveGuardadaJ1, abrioConLlaveGuardadaJ2);
            jugarFase3(J1, J2, monedasFaseUnoJ1, monedasFaseUnoJ2, monedasAcumJ1, monedasAcumJ2,cofresAbiertosJ1, cofresAbiertosJ2, gemasVendidasJ1, gemasVendidasJ2, abrioConLlaveGuardadaJ1, abrioConLlaveGuardadaJ2, nombreMayorPDVHistorico, puntajeMayorPDVHistorico);
            system("pause");
            system("cls");
            break;
        }

        case 2: {
            cout << endl << "--- ESTADISTICAS ---" << endl << endl;
            cout << "Regla: Jugador con mayor PDV historico" << endl << endl;
            if (puntajeMayorPDVHistorico > 0) {
                cout << "Jugador: " << nombreMayorPDVHistorico << endl;
                cout << "Puntaje: " << puntajeMayorPDVHistorico << " PDV" << endl;
            } else {
                cout << "Aun no se han registrado partidas." << endl;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
        }

        case 3: {
            mostrarCreditos();
            cout <<endl;
            system("pause");
            system("cls");
            break;
         }
       }

        }
    while (opcion != 0 );   // la idea es seguir repitiendo el menu hasta que se acabe el juego

    return 0;
}


