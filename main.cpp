#include <iostream>
/*using namespace std;

#include <ctime>


int main (){
    srand(time(0));
    int inicio=1;

    if (inicio==1){
    jugar();
    };

return 0;
}*/
#include "jugar.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "competencia-uno.h"
#include "competencia-dos.h"

using namespace std;

void mostrarCreditos() {
    cout << endl;
    cout << "=== CREDITOS ===" << endl;
    cout << "David Bocalandro" << endl;
    cout << "Giselle Specht" << endl;
    cout << "Cristian Bassi" << endl;
    cout << "Cardenas Gustavo" << endl;
}

int main() {
    srand(time(0)); // Inicializa el generador aleatorio

    vector<int> monedas(2, 150); // Cada jugador empieza con 150 monedas
    int opcion;

    do {
        cout << endl;
        cout << "===========================" << endl;
        cout << "    ROLL AND RETURN        " << endl;
        cout << "===========================" << endl;
        cout << "1 - COMPETENCIA #1" << endl;
        cout << "2 - COMPETENCIA #2" << endl;
        cout << "3 - ESTADISTICAS" << endl;
        cout << "4 - CREDITOS" << endl;
        cout << "-----------------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                competencia(monedas);
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

    } while (opcion != 0);

    cout << endl << "Gracias por jugar!" << endl;
    system("pause");
    return 0;
}

