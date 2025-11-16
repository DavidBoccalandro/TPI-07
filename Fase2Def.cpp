#include <iostream>
using namespace std;
#include "Fase2.h"
#include "jugar.h"

//definiciones
/*
void MostrarDatosJugada(string J1, string J2, int Monedas[2], string &Fase, int &Ronda,string &LlavesG1,string &LlavesG2){
  Fase= "Busqueda de tesoros";
  Ronda= 1;
  cout <<  Fase<< endl;
  cout <<  Ronda<< endl;
  int i;
  if ( i==0){
        cout <<  J1<< endl;
        cout << "Monedas: "<< Monedas[0]<< endl;
        cout << "Inventario: "<< LlavesG1<< endl;
    }
  else{
        cout <<  J2<< endl;
        cout << "Monedas: "<< Monedas[1]<< endl;
        cout << "Inventario: "<< LlavesG2<< endl;
     }
  }

*/


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


void funcion() {
    int monedas[2] = {0, 0};
    int llavesGuardadas[2] = {0 ,0};
    string nombres[2] = {"J1", "J2"};

    for(int ronda=1; ronda<=3; ronda++) {

        for(int jugador=0; jugador<2; jugador++) {

            cout << "Ronda " << ronda << " del jugador " << nombres[jugador];
            int dados[5];
            tiradaDados(dados, 5);
            mostrarTirada(dados, 5);

            int items[6] = {0, 0, 0, 0, 0, 0};
            contarItems(items, dados, 5);


            if(items[ronda - 1] > 0) {// si en esta ronda tenga mas de una llave

            }



        }
    }

}

void contarItems(int items[], int dados[], int cantDados) {
    // Esta funcion cuenta todos los dados, y te dice cuantos items de cada tipo obtuviste con los dados
    for(int i=0; i<cantDados; i++) {
        int valorDado = dados[i];
        items[valorDado -1] ++;
    }gg
}


for(int i=0; i<2; i++){}

void obtenerLlave(int vLlave, &monedasAcumJ1, &monedasAcumJ2, &llaveGuJ1, &llaveGuJ2){
   int monedasMa = 0;
   int monedasPi = 0;
   int monedasMe = 0;

  switch( vLlave)
    {
    case 1:
        cout <<"Puede vender cada llave de MADERA por 10 monedas de oro"<<endl;
         llavesMaJ1[0]++;
        monedasMa = llavesMa * 10;
        cout<< "Obtuvo "<< monedasMa <<" monedas de oro"<< endl;
        break;

    case 2:
        cout <<"Puede vender cada llave de PIEDRA por 20 monedas de oro"<<endl;

        monedasPi = llavesPi * 20;
        cout<< "Obtuvo "<< monedasPi <<" monedas de oro"<< endl;
        break;

    case 3:
        cout <<"Puede vender cada llave de METAL por 30 monedas de oro"<<endl;
        monedasMe = llavesMe * 30;
        cout<< "Obtuvo "<< monedasMe <<" monedas de oro"<< endl;
        break;
        }
}






void JugarRonda1(string &J1,string &J2,vector<int> monedas){
    int item, p, sumarItems;
    bool Obtenerllave = false;
    cout<<"Comienza la Fase de BUSQUEDA DE TESOROS"<<endl;
    system("pause");
    system("cls");
    cout<<"Ronda 1:"<<endl;
    cout<<"­Encuentra el cofre de Madera!"<<endl;
    cout<<endl <<"Tira tus dados y consigue un 1 para obtener la llave de madera"<<endl;
    system("pause");
    system("cls");
    //MostrarDatosJugada(&J1, &J2, Monedas[2], &Fase, &Ronda, &LlavesG1, &LlavesG2);

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
                 system("pause");
                 system("cls");
                do{
                cout<<" Puede vender las llaves o guardar solo una. ¨Desea VENDER o GUARDAR?  Ingrese V o G"<<endl;
                cout<< endl;
                cin>> Opcion;
                }

                while (Opcion != 'V' && Opcion != 'G' ); // NECESITA DE AMBAS PARA SER TRUE, POR LO que es false si se ingresa una
                    if(Opcion == 'V'){
                        int llavesMa= 0;
                        int llavesPi= 0;
                        int llavesMae= 0;
                        obtenerLlave( vLlave);

                        }
                    else{

                    }
            //JugarRondaDos();
        }
    }
            system("pause");
            system("cls");
}

void JugarBusqueda(string &J1,string &J2,vector<int> &monedas){
      JugarRonda1( J1, J2, monedas);
}













