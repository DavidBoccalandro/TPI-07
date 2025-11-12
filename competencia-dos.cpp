#include "competencia-dos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int tirarDadoDos() {
    return rand() % 6 + 1;
}

bool tieneRepetidos(int dados[3]) {
    // Para ver si hay repetidos
    if (dados[0] == dados[1] || dados[0] == dados[2] || dados[1] == dados[2]) {
        return true;
    } else {
        return false;
    }
}



void competenciaDos(int (&monedas)[2]) {
    string jugador1, jugador2;   // Nombres de los jugadores
    int dados[2][3];

    cout << endl << "--- COMPETENCIA #2 ---" << endl;
    cout << "Regla: Si tienes dados repetidos, no ganas nada." << endl << endl;

    cout <<"Ingrese el nombre del jugador 1: ";
    cin >>jugador1;
    cout <<"Ingrese el nombre del jugador 2: ";
    cin >>jugador2;
    cout << endl;


    //Cada jugador tira 3 dados

    for  (int i = 0; i < 2; i++) {
        cout << "Jugador " << i + 1 << " ("
             << (i == 0 ? jugador1 : jugador2) << ") tira: ";
        for (int j = 0; j < 3; j++) {
            dados[i][j] = tirarDadoDos();   // Tira un dado
            cout << dados[i][j] << " ";     // Muestra el valor
        }
        cout << endl;
    }


    //Para verificar si hay repetidos
bool rep1 = tieneRepetidos(dados[0]);
bool rep2 = tieneRepetidos(dados[1]);

if (!rep1 && rep2) {
        cout << endl << "Jugador 1 tiene todos diferentes y gana 50 monedas!" << endl;
        monedas[0] += 50;
    }
    else if (rep1 && !rep2) {
        cout << endl << "Jugador 2 tiene todos diferentes y gana 50 monedas!" << endl;
        monedas[1] += 50;
        }
    else if (!rep1 && !rep2) {
        cout << endl << "Ambos tienen todos diferentes, ganan 25 monedas cada uno!" << endl;
        monedas[0] += 25;
        monedas[1] += 25;
    }
    else{
        cout << endl << "Ambos tienen dados repetidos, nadie gana." << endl;
    }

    // Se muestra el resultado
    cout << endl << "- Fin de la competencia #2 -" << endl;
}
