#include <iostream>
using namespace std;
#include <ctime>
#include "jugar.h"
#include <vector>
#include <cstdlib>

#include "competencia-uno.h"
#include "competencia-dos.h"
#include "Fase2.h"

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
        cout << "-----------------------------------------------" << endl;
        cout << "Selecciona una opcion para continuar... "<<endl;
        cout <<endl;
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:

            system("pause");
            system("cls");
            break;

        case 2:
            cout << endl << "--- ESTADISTICAS ---" << endl;
            cout << "Jugador 1: " << monedas[0] << " monedas" << endl;
            cout << "Jugador 2: " << monedas[1] << " monedas" << endl;
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

        case 0:
            if( confirmarSalir() ==true){
                  cout << endl << "Gracias por jugar!" << endl;
                  system("pause");
                  return 0;}
             system("cls");
             break;
        //4 y 5 y 6 son opciones de desarrollo
        case 4:
            competencia(monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;

        case 5:
            competenciaDos(monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;

        case 6:
            string j1 = "gise";
            string j2 = "laura";
            JugarBusqueda(j1, j2, monedas);
            cout <<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while (opcion != '0' );// la idea es seguir repitiendo el men£ hasta que se acabe el juego
}

