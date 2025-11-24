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
    cout<<"Los dados obtenidos son: [ ";
    for (int j=0; j<cant; j++) {
        cout<<vec[j]<<" ";
    }
    cout<<"]"<<endl;
    cout<<endl;
}


