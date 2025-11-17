#include <iostream>
#include "utilidades.h"

int tirarDado() {
    return rand() % 6 + 1;
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

void mostrarTirada(int vec[], int cant) {
    cout<<"Tirada: [ ";
    for (int j=0; j<cant; j++) {
        cout<<vec[j]<<" ";
    }
    cout<<" ]"<<endl;
    cout<<endl;
}

void evaluarResultado(int dadosJ1[], int dadosJ2[],int &monedasAcumJ1,int &monedasAcumJ2,int &monedasRondaJ1,int &monedasRondaJ2, string jugador1, string jugador2) {
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
            cout<< "Victoria de: ¡¡¡"<<jugador1<<"!!!, GANA 50 monedas de oro."<<endl;
            monedasAcumJ1+=50;
        } else {
            if (escalera1==false&&(escalera2)) {
                /// ganaJ2
                cout << "Victoria de: ¡¡¡"<<jugador2<<"!!!, GANA 50 monedas de oro."<<endl;
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
