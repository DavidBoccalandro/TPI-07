#include <iostream>
using namespace std;
#include "jugar.h"

void jugar ()
{
    cout<<"Fase 1, Competencia 3 (GANA EL QUE FORMA ESCALERA)."<<endl;
    cout<<endl;
    int dadosJ1[3],dadosJ2[3], monedasAcumJ1=200, monedasAcumJ2=210, monedasRondaJ1=200, monedasRondaJ2=210;


    string J1,J2;

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
    evaluarResultado(dadosJ1,dadosJ2,monedasAcumJ1,monedasAcumJ2,monedasRondaJ1,monedasRondaJ2,J1,J2);

    cout<<"Monedas Acumuladas J1; "<<monedasAcumJ1<<endl;
    cout<<"Monedas Acumuladas J2; "<<monedasAcumJ2<<endl;
    cout<<"Monedas Ronda J1; "<<monedasRondaJ1<<endl;
    cout<<"Monedas Ronda J2; "<<monedasRondaJ2<<endl;



    }
            ///FIN DEL VOID JUGAR

int tiradaDados(int vec[], int cant)
{ int j;
    for (j=0; j<cant; j++)
    {
        vec[j]=tirarDado();
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

void evaluarResultado(int dadosJ1[], int dadosJ2[],int &monedasAcumJ1,int &monedasAcumJ2,int &monedasRondaJ1,int &monedasRondaJ2, string J1, string J2)
{
bool escalera1=esEscalera(dadosJ1, 3);
bool escalera2=esEscalera(dadosJ2, 3);

            if ((escalera1)&&(escalera2))
        {
            ///empatePositivo
            cout << "Es empate!!! los dos obtienen 25 monedas de oro"<<endl;
            monedasAcumJ1+=25;
            monedasAcumJ2+=25;
                    }
        else
        {
            ///ganaJ1
            if ((escalera1)&&(escalera2)==false)
            {
               cout<< "Victoria de: ¡¡¡"<<J1<<"!!!, GANA 50 monedas de oro."<<endl;
               monedasAcumJ1+=50;
            }
            else {if (escalera1==false&&(escalera2))

            {
                /// ganaJ2
               cout << "Victoria de: ¡¡¡"<<J2<<"!!!, GANA 50 monedas de oro."<<endl;
               monedasAcumJ2+=50;
            }
            else
            {
                ///empateNegativo
               cout << "Es empate, ninguno obtuvo escalera. Por lo tanto nadie obtiene monedas de oro."<<endl;
            }
            monedasRondaJ1=monedasAcumJ1;
            monedasRondaJ2=monedasAcumJ2;

}}

}


///Ver el resultado
///Posibles resultados ganaJ1, ganaJ2, empatePositivo, empateNegativo
