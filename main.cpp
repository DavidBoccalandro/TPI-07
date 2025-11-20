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
            jugarFase2(J1, J2, monedasAcumJ1, monedasAcumJ2);
            system("pause");
            system("cls");
            break;
        }

        case 2: {
            cout << endl << "--- ESTADISTICAS ---" << endl;
            cout << "Jugador 1: " << monedasAcumJ1 << " monedas" << endl;
            cout << "Jugador 2: " << monedasAcumJ2<< " monedas" << endl;
            cout <<endl;
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


