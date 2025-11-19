#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fase1.h"
#include "utilidades.h"
#include <string>

/// ------------ FUNCION PRINCIPAL ------------
void jugarFase1(int &monedasAcumJ1, int &monedasAcumJ2, string J1, string J2, int &monedasFaseUnoJ1, int &monedasFaseUnoJ2) {
    competenciaUno( monedasAcumJ1, monedasAcumJ2, J1, J2);
    competenciaDos( monedasAcumJ1, monedasAcumJ2);
    competenciaTres(monedasAcumJ1, monedasAcumJ2,  monedasFaseUnoJ1, monedasFaseUnoJ2);
}

/// ------------ DEFINICIONES GENERALES ------------

int tiradaDados(int vec[], int cant) {
    int j;
    for (j=0; j<cant; j++) {
        vec[j]=tirarDado();
    }
    return vec[j];
}

bool tieneRepetidos(int dados[3]) {
    if (dados[0] == dados[1] || dados[0] == dados[2] || dados[1] == dados[2]) {
        return true;
    } else {
        return false;
    }
}

bool confirmarSalir() {
    char rta;
    cout<< "Realmente desea abandonar el juego? Ingrese S o N"<< endl;
    cin>> rta;
    if( rta == 'S' || rta == 's') {
        return true;
    } else {
        return false;
    }
}

/// ------------ COMPETENCIA 1 ------------
void competenciaUno(int &monedasAcumJ1, int &monedasAcumJ2, string J1, string J2 ) {
    int dados[2];  // Guarda los resultados de los dos jugadores

    cout <<"Ingrese el nombre del jugador 1: " <<endl;
    cin >> J1;
    cout <<"Ingrese el nombre del jugador 2: " <<endl;
    cin >> J2;
    cout <<endl;

    system("pause");
    system("cls");

    cout << "Comienza el juego - Fase Inicial" << endl <<endl;
    cout << "--- COMPETENCIA #1 ---" << endl << endl;

    cout << "Regla: el jugador que saque el dado de más alto valor gana."<< endl <<endl;

    system("pause");

    /// Cada jugador tira el dado

    dados[0] = tirarDado();
    cout << endl << endl << J1 << " tira el dado y obtiene: " << dados[0] << endl;
    dados[1] = tirarDado();
    cout << J2 << " tira el dado y obtiene: " << dados[1] << endl;

    cout << endl;

    /// Determinar al ganador
    if (dados[0] > dados[1]) {
        cout << J1 << " gana la competencia y recibe 50 monedas." << endl << endl;
        monedasAcumJ1 += 50;
    } else if (dados[1] > dados[0]) {
        cout << J2 << " gana la competencia y recibe 50 monedas." << endl << endl;
        monedasAcumJ2 += 50;
    } else {
        cout << "Empate! Ambos jugadores reciben 25 monedas" << endl << endl;
        monedasAcumJ1 += 25;
        monedasAcumJ2 += 25;
    }
    cout << endl <<"Resultados Competencia #1" <<endl << endl;
    cout << J1 <<": " <<monedasAcumJ1 <<" monedas" <<endl << endl;
    cout << J2 <<": " <<monedasAcumJ2 <<" monedas" <<endl << endl;

    system("pause");
    system("cls");
}

/// ------------ COMPETENCIA 2 ------------

void competenciaDos(int &monedasAcumJ1, int &monedasAcumJ2) {
    string J1, J2;   // Nombres de los jugadores
    int dadosJ1[3], dadosJ2[3];

    cout <<"--- COMPETENCIA #2 ---" << endl <<endl;
    cout << "Regla: Si tienes dados repetidos, no ganas nada." << endl << endl;

    system("pause");

    int i;
    for(i=0; i<2; i++) {
        if (i==0) {
            cout <<endl <<endl <<"Tirando "<<J1<<endl;
        } else {
            cout<<"Tirando "<<J2<<endl;
        }

        if (i==0) {
            tiradaDados(dadosJ1, 3);
            mostrarTirada(dadosJ1, 3);
            tieneRepetidos(dadosJ1);
        } else {
            tiradaDados(dadosJ2, 3);
            mostrarTirada(dadosJ2, 3);
            tieneRepetidos(dadosJ2);
        }
    }



    /*cout <<"Ingrese el nombre del jugador 1: ";
    cin >>J1;
    cout <<"Ingrese el nombre del jugador 2: ";
    cin >>J2;
    cout << endl; */
    ///Borrar


    //Para verificar si hay repetidos
    bool rep1 = tieneRepetidos(dadosJ1);
    bool rep2 = tieneRepetidos(dadosJ2);

    if (!rep1 && rep2) {
        cout << endl << J1 <<" tiene todos diferentes y gana 50 monedas!" << endl;
        monedasAcumJ1 += 50;
    } else if (rep1 && !rep2) {
        cout << endl << J2 <<" tiene todos diferentes y gana 50 monedas!" << endl;
        monedasAcumJ2 += 50;
    } else if (!rep1 && !rep2) {
        cout << endl << "Ambos tienen todos diferentes, ganan 25 monedas cada uno!" << endl;
        monedasAcumJ1 += 25;
        monedasAcumJ2 += 25;
    } else {
        cout << endl << "Ambos tienen dados repetidos, nadie gana." << endl;
    }

    /// Se muestra el resultado
    cout << endl <<"Resultados Competencia #2" <<endl << endl;
    cout << J1 <<": " <<monedasAcumJ1 <<" monedas" <<endl << endl;
    cout << J2 <<": " <<monedasAcumJ2 <<" monedas" <<endl << endl;

    system("pause");
    system("cls");
}



/// ------------ COMPETENCIA 3 ------------

void competenciaTres(int &monedasAcumJ1, int &monedasAcumJ2,  int &monedasFaseUnoJ1, int &monedasFaseUnoJ2) {
    cout << "--- COMPETENCIA #3 ---" << endl << endl;
    cout << "Regla: Si formas escalera ganas." << endl << endl;
    cout << "Escaleras válidas: {1,2,3} {4,5,6} {2,4,6} {1,3,5}" << endl <<endl;

    system("pause");

    int dadosJ1[3],dadosJ2[3], monedasRonda;
    string J1,J2;

    /*cout<<"Jugador 1, ingrese su nombre: "<<endl;
    cin>>J1;
    cout<<endl;

    cout<<"Jugador 2, ingrese su nombre: "<<endl;
    cin>>jJ2;
    cout<<endl;*/

    ///Crear pedir nombres

    int i;
    for(i=0; i<2; i++) {
        if (i==0) {
            cout <<endl <<endl<< "Tirando "<<J1<<endl;
        } else {
            cout<<"Tirando "<<J2<<endl;
        }

        if (i==0) {
            tiradaDados(dadosJ1, 3);
            mostrarTirada(dadosJ1, 3);
            esEscalera(dadosJ1, 3);
        } else {
            tiradaDados(dadosJ2, 3);
            mostrarTirada(dadosJ2, 3);
            esEscalera(dadosJ2, 3);
        }
    }


    bool escalera1=esEscalera(dadosJ1, 3);
    bool escalera2=esEscalera(dadosJ2, 3);

    if ((escalera1)&&(escalera2)) {
        ///empatePositivo
        cout << "Es empate!!! los dos obtienen 25 monedas de oro"<<endl;
        monedasAcumJ1+=25;
        monedasAcumJ2+=25;
    }
    else {
        ///ganaJ1
        if ((escalera1)&&(escalera2)==false) {
            cout<< "Victoria de: ¡¡¡"<<J1<<"!!!, GANA 50 monedas de oro."<<endl;
            monedasAcumJ1+=50;
        } else {
            if (escalera1==false&&(escalera2)) {
                /// ganaJ2
                cout << "Victoria de: ¡¡¡"<<J2<<"!!!, GANA 50 monedas de oro."<<endl;
                monedasAcumJ2+=50;
            } else {
                ///empateNegativo
                cout << "Es empate, ninguno obtuvo escalera. Por lo tanto nadie obtiene monedas de oro."<<endl;
            }
            monedasFaseUnoJ1 =monedasAcumJ1;
            monedasFaseUnoJ2 =monedasAcumJ2;
        }
    }

}


///Ver el resultado
///Posibles resultados ganaJ1, ganaJ2, empatePositivo, empateNegativo

