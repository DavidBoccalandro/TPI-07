#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fase1.h"
#include <string>

/// ------------ FUNCION PRINCIPAL ------------
void jugarFase1(int &monedasAcumJ1, int &monedasAcumJ2) {
    competenciaUno(monedasAcumJ1, monedasAcumJ2);
    competenciaDos( monedasAcumJ1, monedasAcumJ2);
    competenciaTres( monedasAcumJ1, monedasAcumJ2);
}



/// ------------ DEFINICIONES GENERALES ------------
int tirarDado() {
    return rand() % 6 + 1;
}

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

void mostrarTirada(int vec[], int cant) {
    cout<<"Tirada: [ ";
    for (int j=0; j<cant; j++) {
        cout<<vec[j]<<" ";
    }
    cout<<" ]"<<endl;
    cout<<endl;
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

bool esEscalera(int vec[],int cant) {
    int j, k, x, menor;

    ///ordena el vector
    for (j=0; j<cant-1; j++) {
        menor=vec[j];
        x=j;
        for (k=j; k<cant; k++) {
            if (vec[k]<menor) {
                menor=vec[k];
                x=k;
            }
        }
        vec[x]=vec[j];
        vec[j]=menor;
    }

    ///luego evalua si es escalera
    if ((vec[0]==1 && vec[1]==2 && vec[2]==3) ||
            (vec[0]==4 && vec[1]==5 && vec[2]==6) ||
            (vec[0]==2 && vec[1]==4 && vec[2]==6) ||
            (vec[0]==1 && vec[1]==3 && vec[2]==5)) {
        return true;
    } else {
        return false;
    }
}

void evaluarResultado(int dadosJ1[], int dadosJ2[],int &monedasAcumJ1,int &monedasAcumJ2,int &monedasRondaJ1,int &monedasRondaJ2, string J1, string J2) {
    bool escalera1=esEscalera(dadosJ1, 3);
    bool escalera2=esEscalera(dadosJ2, 3);

    if ((escalera1)&&(escalera2)) {
        ///empatePositivo
        cout << "Es empate!!! los dos obtienen 25 monedas de oro"<<endl;
        monedasAcumJ1+=25;
        monedasAcumJ2+=25;
    } else {
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
            monedasRondaJ1=monedasAcumJ1;
            monedasRondaJ2=monedasAcumJ2;
        }
    }
}


/// ------------ COMPETENCIA 1 ------------
void competenciaUno(int &monedasAcumJ1, int &monedasAcumJ2) {
    string jugador1, jugador2;
    int dados[2];  // Guarda los resultados de los dos jugadores

    cout << "Comienza el jugo - Fase Inicial" << endl;
    cout << "--- COMPETENCIA #1 ---" << endl << endl;

    cout <<"Ingrese el nombre del jugador 1: ";
    cin >> jugador1;
    cout <<"Ingrese el nombre del jugador 2: ";
    cin >> jugador2;
    cout <<endl;


    // Cada jugador tira el dado

    dados[0] = tirarDado();
    cout << jugador1 << " tira el dado y obtiene: " << dados[0] << endl;
    dados[1] = tirarDado();
    cout << jugador2 << " tira el dado y obtiene: " << dados[1] << endl;

    cout << endl;

    // Determinar al ganador
    if (dados[0] > dados[1]) {
        cout << jugador1 <<" gana la competencia y recibe 50 monedas." << endl;
        monedasAcumJ1 += 50;
    } else if (dados[1] > dados[0]) {
        cout << jugador2 << "gana la competencia y recibe 50 monedas." << endl;
        monedasAcumJ2 += 50;
    } else {
        cout << "Empate! Ambos jugadores reciben 25 monedas" << endl;
        monedasAcumJ1 += 25;
        monedasAcumJ2 += 25;
    }
    cout << endl <<"Resultados Fase Inicial" <<endl;
    cout << jugador1 <<":" <<monedasAcumJ1 <<"monedas" <<endl;
    cout << jugador2 <<":" <<monedasAcumJ2 <<"monedas" <<endl;
}



/// ------------ COMPETENCIA 2 ------------

void competenciaDos(int &monedasAcumJ1, int &monedasAcumJ2) {
    string J1, J2;   // Nombres de los jugadores
    int dadosJ1[3], dadosJ2[3];

    int i;
    for(i=0; i<2; i++) {
        if (i==0) {
            cout<<"Tirando "<<J1<<endl;
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
        monedasAcumJ1 += 50;
    } else if (rep1 && !rep2) {
        cout << endl << "Jugador 2 tiene todos diferentes y gana 50 monedas!" << endl;
        monedasAcumJ2 += 50;
    } else if (!rep1 && !rep2) {
        cout << endl << "Ambos tienen todos diferentes, ganan 25 monedas cada uno!" << endl;
        monedasAcumJ1 += 25;
        monedasAcumJ2 += 25;
    } else {
        cout << endl << "Ambos tienen dados repetidos, nadie gana." << endl;
    }

    // Se muestra el resultado
    cout << endl << "- Fin de la competencia #2 -" << endl;
}



/// ------------ COMPETENCIA 3 ------------

void competenciaTres(int &monedasAcumJ1, int &monedasAcumJ2) {
    cout<<"Comienza el juego, Fase Inicial (GANA EL QUE FORMA ESCALERA)."<<endl;
    cout<<endl;
    int dadosJ1[3],dadosJ2[3], monedasAcum[2],monedasRonda, resultado;
    string J1,J2;

    cout<<"Jugador 1, ingrese su nombre: "<<endl;
    cin>>J1;
    cout<<endl;

    cout<<"Jugador 2, ingrese su nombre: "<<endl;
    cin>>J2;
    cout<<endl;
    ///Crear pedir nombres

    int i;
    for(i=0; i<2; i++) {
        if (i==0) {
            cout<<"Tirando "<<J1<<endl;
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

    // evaluarResultado(dadosJ1, dadosJ2, monedasAcumJ1, monedasAcumJ2, monedasRondaJ1, monedasRondaJ2, J1, J2);

    cout << "Monedas Acumuladas J1; " << monedasAcumJ1 << endl;
    cout << "Monedas Acumuladas J2; " << monedasAcumJ2 << endl;
    // cout << "Monedas Ronda J1; " << monedasRondaJ1 << endl;
    // cout << "Monedas Ronda J2; " << monedasRondaJ2 << endl;
}





///Ver el resultado
///Posibles resultados ganaJ1, ganaJ2, empatePositivo, empateNegativo

