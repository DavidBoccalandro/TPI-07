#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include "fase1.h"
#include "Fase2.h"
#include "fase-final.h"

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
    int monedasRondaJ1;
    int monedasRondaJ2;



    int opcion;

    do
    {
        cout << endl;
        cout << "===========================" << endl;
        cout << "    ROLL AND RETURN        " << endl;
        cout << "===========================" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "0 - SALIR" << endl;
        //estas opciones son de entorno desarrollo
        cout << "4 - JUGAR FASE #1" << endl;
        cout << "6 - Fase 2" << endl;
        cout << "7 - PROBAR FASE 3" << endl;
        cout << "5 - Fase 2" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Selecciona una opcion para continuar... "<<endl;
        cout <<endl;
        cin >> opcion;
        system("cls");

        string J1, J2;

        switch (opcion)
        {
        case 1: {
            jugarFase1(monedasAcumJ1, monedasAcumJ2);
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

        case 0: {
            if( confirmarSalir() ==true){
                  cout << endl << "Gracias por jugar!" << endl;
                  system("pause");
                  return 0;}
             system("cls");
             break;
        }
        //4 y 5 y 6 son opciones de desarrollo
        case 4: {
            jugarFase1(monedasAcumJ1, monedasAcumJ2);
            cout <<endl;
            system("pause");
            system("cls");
            break;
        }
            /*case 1:
                jugarFase1(monedasAcumJ1, monedasAcumJ2);
                system("pause");
                system("cls");

                jugarFase2(J1, J2, monedasAcumJ1, monedasAcumJ2);
                system("pause");
                system("cls");
                break;

            case 2:
                cout << endl << "--- ESTADISTICAS ---" << endl;
                cout << "Jugador 1: " << monedasAcumJ1 << " monedas" << endl;
                cout << "Jugador 2: " << monedasAcumJ2<< " monedas" << endl;
                cout <<endl;
                system("pause");
                system("cls");
                break;

            case 3:
                mostrarCreditos();
                cout <<endl;
                system("pause");
                system("cls");
                break;
                */
        }
    } while (opcion != '0' );// la idea es seguir repitiendo el menu hasta que se acabe el juego

    return 0;
}
            /* case 6:
            stringjugador1 = "gise";
            string j2 = "laura";
            JugarBusqueda(j1, j2, monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;
        } */
        /* switch (opcion) {
            case 0:
                if( confirmarSalir() ==true){
                      cout << endl << "Gracias por jugar!" << endl;
                      system("pause");
                      return 0;}
                 system("cls");
                 break;
            //4 y 5 son opciones de desarrollo
            case 4:
                jugarFase1(monedasAcumJ1, monedasAcumJ2);
                cout <<endl;
                system("pause");
                system("cls");
                break;

            case 5:
                jugarFase2(J1, J2, monedasAcumJ1, monedasAcumJ2);
                break;
        }

        }
        while (opcion != '0' );// la idea es seguir repitiendo el menu hasta que se acabe el juego
        return 0;
    }





/* switch (opcion) {
            case 1:
                jugar();
                break;

            case 2:
                competenciaDos(monedas);
                break;

            case 3:
                cout << endl << "--- ESTADISTICAS ---" << endl;
                cout << "Jugador 1: " << monedas[0] << " monedas" << endl;
                cout << "Jugador 2: " << monedas[1] << " monedas" << endl;
                break;

            case 4:
                mostrarCreditos();
                break;

            case 0:
                cout << endl << "Saliendo del juego..." << endl;
                break;

            default:
                cout << endl << "Opcion incorrecta. Intenta otra vez." << endl;
        }
        */
