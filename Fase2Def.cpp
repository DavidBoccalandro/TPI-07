#include <iostream>
using namespace std;
#include "Fase2.h"
#include "jugar.h"

//definiciones

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


void JugarRonda1(string &J1,string &J2,vector<int> &monedas){
    int item, p, SumarNum;
    bool Obtenerllave = false;
    cout<<"Comienza la Fase de BUSQUEDA DE TESOROS"<<endl;
    system("pause");
    system("cls");
    cout<<"­Encuentra el cofre de Madera!"<<endl;
    cout<<"Tira tus dados y consigue un 1 para obtener la llave de madera"<<endl;
    cout<<endl;
    int dados [5], monedasAcum[2],monedasRonda, resultado;
    char Opcion;

    for(int i=0; i<2; i++)
    {
        if (i==0)
        {
            cout<<"Tirando "<<J1<< ".." <<endl;
        }
        else
        {
            cout<<"Tirando "<<J2<< ".." <<endl;
        }
       //1ERA TIRADA
        tiradaDados(dados, 5);
        mostrarTirada(dados, 5);
        for (p=0; p<5; p++){
            Obteneritem(dados[p]);
            if (dados[p] == 1){
                Obtenerllave = true;
            }
        }

        if(Obtenerllave){
          cout<<"­Felicitaciones! ­Obtuviste la llave para abrir el cofre!" <<endl;
          //JugarRondaDos();
        }
        else{
                cout<<" ­Lastima! No obtuviste la llave requerida."<<endl;
                 cout<< endl;
                do{
                cout<<" Puede vender las llaves o guardar solo una. ¨Desea VENDER o GUARDAR?  Ingrese V o G"<<endl;
                cout<< endl;
                cin>> Opcion;
                system("cls");

                }
                while (Opcion != 'V' && Opcion != 'G' ); // NECESITA DE AMBAS PARA SER TRUE, POR LO que es false si se ingresa una
                    if(Opcion == 'V'){
}
//informo
        }
    }

}

void JugarBusqueda(string &J1,string &J2,vector<int> &monedas){
      JugarRonda1(J1, J2, monedas);
}













