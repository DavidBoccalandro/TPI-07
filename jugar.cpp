#include <iostream>
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
    int dados [3], monedasAcum[2],monedasRonda, resultado;
    string J1,J2;

    cout<<"Jugador 1, ingrese su nombre: "<<endl;
    cin>>J1;
    cout<<endl;

    cout<<"Jugador 2, ingrese su nombre: "<<endl;
    cin>>J2;
    cout<<endl;

    for(int i=0; i<2; i++)
    {
        if (i==0)
        {
            cout<<"Tirando "<<J1<<endl;
        }
        else
        {
            cout<<"Tirando "<<J2<<endl;
        }
        tiradaDados(dados, 3);
        mostrarTirada(dados, 3);
        esEscalera(dados,3);
        resultado=evaluarResultado(dados, 3);
    }
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

 /*   if (tipoResultado==1)
    {
        {

        }
        }else
        {
            if
            (tipoResultado==2)
            {

            }
            else if
            (tipoResultado==3){
                {


                }
            }
                else
                {

                }

            }*/ ///FIN DE LOS IF ANIDADOS PARA COMENTAR EL RESULTADO

        }///FIN DEL VOID JUGAR












bool esEscalera(int vec[], int cant)
{
    int i, j, x, menor;
    for (i=0; i<cant-1; i++)    ///ordena el vector
    {
        menor=vec[i];
        x=i;
        for (j=i; j<cant; j++)
        {
            if (vec[j]<menor)
            {
                menor=vec[j];
                x=j;
            }
        }
        vec[x]=vec[i];
        vec[i]=menor;
    }
    ///luego evalalua si es escalera
    if ((vec[0]==1 && vec[1]==2 && vec[2]==3) ||
            (vec[0]==4 && vec[1]==5 && vec[2]==6) ||
            (vec[0]==2 && vec[1]==4 && vec[2]==6) ||
            (vec[0]==1 && vec[1]==3 && vec[2]==5))
    {
        cout<<"Es Escalera."<<endl<<endl;
        return true;
    }
    cout<<"No hay escalera."<<endl<<endl;
    return false;
}


void mostrarTirada(int vec[], int cant)
{
    cout<<"Tirada:[ ";
    for (int i=0; i<cant; i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<" ]"<<endl;
    cout<<endl;
}

void tiradaDados(int vec[], int cant)
{
    for (int i=0; i<cant; i++)
    {
        vec[i]=tirarDado();
    }
}


int evaluarResultado(int vec[], int cant)
{
int resultado;
bool escalera=esEscalera(vec, cant);

    for (int i=0; i<cant; i++)
    {
        if ((i==0)&&(escalera)&&((i==1)&&(escalera)))
        {
            ///empatePositivo
            resultado=1;

        }
        else
        {
            ///ganaJ1
            if ((i==1)&&(escalera)==false)
            {
                resultado=2;
            }
            else {if ((i==1)&&(escalera)==true)

            {
                /// ganaJ2
                resultado=3;
            }
            else
            {
                ///empateNegativo
                resultado=4;
            }

}}}
    return resultado;
}


///Ver el resultado
///Posibles resultados ganaJ1, ganaJ2, empatePositivo, empateNegativo


//Fase 2
void Obteneritem(int vdado){

  switch( vdado)
    {
    case 1:
        cout << "Obtuviste una llave de madera"<<endl;
        break;
    case 2:
        cout<< "Obtuviste una llave de piedra"<<endl;
        break;
    case 3:
        cout << "Obtuviste una llave de metal"<<endl;
        break;
    case 4:
        cout << "Obtuviste un tesoro de esmeraldas"<<endl;
        break;
    case 5:
        cout << "Obtuviste un tesoro de rubies"<<endl;
        break;
    case 6:
        cout << "Obtuviste un tesoro de diamantes"<<endl;
        break;
    }


}





