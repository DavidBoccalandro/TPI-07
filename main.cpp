#include <iostream>
using namespace std;
#include <ctime>
#include "jugar.h"
#include <vector>
#include <cstdlib>

#include "competencia-uno.h"
#include "competencia-dos.h"
#include "Fase2.h"
#include "fase-final.h"

/*

int main (){
    srand(time(0));
    int inicio=1;

    if (inicio==1){
    jugar();
    };

return 0;
}*/




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

    vector<int> monedas(2, 150); // Cada jugador empieza con 150 monedas

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
        cout << "4 - COMPETENCIA #1" << endl;
        cout << "5 - COMPETENCIA #2" << endl;
        cout << "6 - Fase 2" << endl;
        cout << "7 - PROBAR FASE 3" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Selecciona una opcion para continuar... "<<endl;
        cout <<endl;
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1: {
            system("pause");
            system("cls");
            break;
        }

        case 2: {
            cout << endl << "--- ESTADISTICAS ---" << endl;
            cout << "Jugador 1: " << monedas[0] << " monedas" << endl;
            cout << "Jugador 2: " << monedas[1] << " monedas" << endl;
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
            competencia(monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;
        }

        case 5: {
            competenciaDos(monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;
        }

        case 6: {
            string j1 = "gise";
            string j2 = "laura";
            JugarBusqueda(j1, j2, monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;
        }


        case 7: {
            cout << "PRUEBA FASE 3 - CALCULO PDV" << endl;
            cout << endl;

            int monedasFase1J1 = 300;
            int monedasFase1J2 = 250;
            int monedasTotalesJ1 = 890;
            int monedasTotalesJ2 = 725;

            int pdvJ1 = 0;
            int pdvJ2 = 0;

            bool cofresJ1[3] = {true, true, true};
            bool cofresJ2[3] = {true, false, true};

            bool gemasJ1[3] = {true, true, true};
            bool gemasJ2[3] = {true, false, true};

            bool abrioConLlaveJ1 = true;
            bool abrioConLlaveJ2 = false;

            cout << "J1: " << monedasFase1J1 << " monedas fase 1" << endl;
            cout << "J2: " << monedasFase1J2 << " monedas fase 1" << endl;
            sumarPDVPorFase1(monedasFase1J1, monedasFase1J2, pdvJ1, pdvJ2);
            cout << "PDV: J1=" << pdvJ1 << " J2=" << pdvJ2 << endl;
            cout << endl;

            cout << "J1: " << monedasTotalesJ1 << " monedas totales" << endl;
            sumarPDVPorPaquetes(monedasTotalesJ1, pdvJ1);
            sumarPDVPorSobrantes(monedasTotalesJ1, pdvJ1);

            cout << "J2: " << monedasTotalesJ2 << " monedas totales" << endl;
            sumarPDVPorPaquetes(monedasTotalesJ2, pdvJ2);
            sumarPDVPorSobrantes(monedasTotalesJ2, pdvJ2);
            cout << "PDV: J1=" << pdvJ1 << " J2=" << pdvJ2 << endl;
            cout << endl;

            cout << "J1 cofres: " << cofresJ1[0] << cofresJ1[1] << cofresJ1[2] << endl;
            sumarPDVPorCofresAbiertos(cofresJ1, pdvJ1);

            cout << "J2 cofres: " << cofresJ2[0] << cofresJ2[1] << cofresJ2[2] << endl;
            sumarPDVPorCofresAbiertos(cofresJ2, pdvJ2);
            cout << "PDV: J1=" << pdvJ1 << " J2=" << pdvJ2 << endl;
            cout << endl;

            cout << "J1 gemas: " << gemasJ1[0] << gemasJ1[1] << gemasJ1[2] << endl;
            sumarPDVPorGemasVendidas(gemasJ1, pdvJ1);

            cout << "J2 gemas: " << gemasJ2[0] << gemasJ2[1] << gemasJ2[2] << endl;
            sumarPDVPorGemasVendidas(gemasJ2, pdvJ2);
            cout << "PDV: J1=" << pdvJ1 << " J2=" << pdvJ2 << endl;
            cout << endl;

            cout << "J1 uso llave guardada: " << abrioConLlaveJ1 << endl;
            sumarPDVPorLlaveGuardada(abrioConLlaveJ1, pdvJ1);

            cout << "J2 uso llave guardada: " << abrioConLlaveJ2 << endl;
            sumarPDVPorLlaveGuardada(abrioConLlaveJ2, pdvJ2);
            cout << endl;

            cout << "RESULTADO:" << endl;
            cout << "J1: " << pdvJ1 << " PDV" << endl;
            cout << "J2: " << pdvJ2 << " PDV" << endl;
            cout << endl;

            system("pause");
            system("cls");
            break;
        }

        default: {
                cout << endl << "Opcion incorrecta. Intenta otra vez." << endl;
            }
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

    }
    while (opcion != '0' );// la idea es seguir repitiendo el menu hasta que se acabe el juego
}

