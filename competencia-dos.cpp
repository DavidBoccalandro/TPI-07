/*#include "competencia-dos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


bool tieneRepetidos(int dados[3]) {
    // Para ver si hay repetidos
    if (dados[0] == dados[1] || dados[0] == dados[2] || dados[1] == dados[2]) {
        return true;
    } else {
        return false;
    }
}

 int tiradaDados(int vec[], int cant)
{ int j;
    for (j=0; j<cant; j++)
    {
        vec[j]=tiradaDados();
    } return vec[j];
}
void mostrarTirada(int vec[], int cant)

{    cout<<"Tirada:[ ";
    for (int j=0; j<cant; j++)
    {
        cout<<vec[j]<<" ";
    }
    cout<<" ]"<<endl;
    cout<<endl;
}



void competenciaDos(int (&monedas)[2]) {
    stringjugador1, J2;   // Nombres de los jugadores
    int dadosJ1[3], dadosJ2[3];

    int i;
    for(i=0; i<2; i++)
    {
        if (i==0)
        {
            cout<<"Tirando "<<J1<<endl;
        }
        else
        {
            cout<<"Tirando "<<J2<<endl;
        }

        if (i==0){
        tiradaDados(dadosJ1, 3);
        mostrarTirada(dadosJ1, 3);
        tieneRepetidos(dadosJ1);

        }
        else
        {
        tiradaDados(dadosJ2, 3);
        mostrarTirada(dadosJ2, 3);
        tieneRepetidos(dadosJ2);
        }
     }

    cout << endl << "--- COMPETENCIA #2 ---" << endl;
    cout << "Regla: Si tienes dados repetidos, no ganas nada." << endl << endl;

    cout <<"Ingrese el nombre del jugador 1: ";
    cin >>J1;
    cout <<"Ingrese el nombre del jugador 2: ";
    cin >>J2;
    cout << endl;




    //Para verificar si hay repetidos
bool rep1 = tieneRepetidos(dadosJ1);
bool rep2 = tieneRepetidos(dadosJ2);

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
*/
