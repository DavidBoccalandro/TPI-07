/*#include <iostream>
using namespace std;
#include "jugar.h"

bool confirmarSalir(){
            char rta;
            cout<< "¨Realmente desea abandonar el juego? Ingrese S o N"<< endl;
            cin>> rta;
            if( rta== 'S') {
                return true;
                }
             else{
                return false;}
}

void jugar ()
{
    cout<<"Comienza el juego, Fase Inicial (GANA EL QUE FORMA ESCALERA)."<<endl;
    cout<<endl;
    int dadosJ1[3],dadosJ2[3], monedasAcum[2],monedasRonda, resultado;
    stringjugador1,J2;

    cout<<"Jugador 1, ingrese su nombre: "<<endl;
    cin>>J1;
    cout<<endl;

    cout<<"Jugador 2, ingrese su nombre: "<<endl;
    cin>>J2;
    cout<<endl;
    ///Crear pedir nombres

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
        esEscalera(dadosJ1, 3);

        }
        else
        {
        tiradaDados(dadosJ2, 3);
        mostrarTirada(dadosJ2, 3);
        esEscalera(dadosJ2, 3);
        }
     }

    resultado=evaluarResultado(dadosJ1, dadosJ2);
     switch(resultado)
    {
    case 1:
        cout << "Es empate positivo, los dos obtienen 25 monedas de oro"<<endl;

        break;
    case 2:

        cout<< "Victoria de: "<<J1<<", gana 50 monedas de oro."<<endl;
        break;
    case 3:

        cout << "Victoria de: "<<J2<<", gana 50 monedas de oro."<<endl;
        break;
    case 4:

        cout << "Es empate negativo, nadie gana monedas de oro"<<endl;
        break;
    }
            }///FIN DEL VOID JUGAR








bool esEscalera(int vec[],int cant)
{
    int j, k, x, menor;
    for (j=0; j<cant-1; j++)    ///ordena el vector
    {
        menor=vec[j];
        x=j;
        for (k=j; k<cant; k++)
        {
            if (vec[k]<menor)
            {
                menor=vec[k];
                x=k;
            }
        }
        vec[x]=vec[j];
        vec[j]=menor;
    }
    ///luego evalalua si es escalera
    if ((vec[0]==1 && vec[1]==2 && vec[2]==3) ||
            (vec[0]==4 && vec[1]==5 && vec[2]==6) ||
            (vec[0]==2 && vec[1]==4 && vec[2]==6) ||
            (vec[0]==1 && vec[1]==3 && vec[2]==5))
    {
        return true;
    } else {
      return false;
    }
}

int evaluarResultado(int dadosJ1[], int dadosJ2[])
{
int codigoResultado;
bool escalera1=esEscalera(dadosJ1, 3);
bool escalera2=esEscalera(dadosJ2, 3);

            if ((escalera1)&&(escalera2))
        {
            ///empatePositivo
            codigoResultado=1;

                    }
        else
        {
            ///ganaJ1
            if ((escalera1)&&(escalera2)==false)
            {
                codigoResultado=2;
            }
            else {if (escalera1==false&&(escalera2))

            {
                /// ganaJ2
                codigoResultado=3;
            }
            else
            {
                ///empateNegativo
                codigoResultado=4;
            }

}}
    return codigoResultado;
}

 int tiradaDados(int vec[], int cant)
{ int j;
    for (j=0; j<cant; j++)
    {
        vec[j]=tirarDado();
    } return vec[j];
}

int tirarDado() {
    return rand() % 6 + 1;
}

///Ver el resultado
///Posibles resultados ganaJ1, ganaJ2, empatePositivo, empateNegativo

 */






