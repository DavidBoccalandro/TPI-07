#include <iostream>
using namespace std;
#include "fase1.h"
#include "Fase2.h"
#include "utilidades.h"

//en MAIN

//string J1, J2;
//int j= 0;
//jugarFase2(J1, J2, monedasAcumJ1, monedasAcumJ2);





//definiciones
void mostrarItems(int dados[5]){
    int p;
    for (p=0; p<5; p++){
       switch( dados[p])
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
}

bool obtuvoLlave(int p, int &ronda){
    if (ronda ==0 && p==0){
        return true;
        }
    if (ronda==1 && p==1){
        return true;
        }
    if (ronda==2 && p==2){
        return true;
        }
    else{
        return false;
        }
}


 void consultarLlaveGuardada( int &llaveGuardada){
     switch(llaveGuardada)
        {
            case 1:
                cout << "Inventario: una llave de madera"<<endl;
            break;
            case 2:
                cout<< "Inventario: una llave de piedra"<<endl;
            break;
            case 3:
                cout << "Inventario: una llave de metal"<<endl;
            break;
         }
}


 int venderTesoros(int dados[5], int &monedasAcum){
     int p;
     int cantDado4 = 0;
     int cantDado5 = 0;
     int cantDado6 = 0;
     int totalDado4 = 0;
     int totalDado5 = 0;
     int totalDado6 = 0;
     int totalMonedasTesoros = 0;
     cout << "Cada tesoro de esmeraldas vale 40 monedas"<<endl;
     cout << "Cada tesoro de rubies vale 50 monedas"<<endl;
     cout << "Cada tesoro de diamantes vale 60 monedas"<<endl;
     for (p=0; p<5; p++)    //acumuladorItems
    {
        switch(dados[p])
        {
            case 4:
                cantDado4++;
            break;
            case 5:
                cantDado5++;
            break;
            case 6:
                cantDado6++;
            break;
         }
    }
   totalDado4= cantDado4 * 40;
   cout<< "Obtuviste "<< cantDado4<< "x 40 = " << totalDado4<< endl;
   totalDado5= cantDado5 * 50;
   cout<< "Obtuviste "<< cantDado5<< "x 50 = " << totalDado5<< endl;
   totalDado6= cantDado6 * 60;
   cout<< "Obtuviste "<< cantDado6<< "x 60 = " << totalDado6<< endl;
   totalMonedasTesoros =  totalDado4 + totalDado5 + totalDado6;
   cout<< "El total obtenido es "<< totalMonedasTesoros <<" monedas"<< endl;
   return totalMonedasTesoros;
 }


int venderLlaves(int dados[5], int &monedasAcum){
     int p;
     int cantDado1 = 0;
     int cantDado2 = 0;
     int cantDado3 = 0;
     int totalDado1 = 0;
     int totalDado2 = 0;
     int totalDado3 = 0;
     int totalMonedasLlaves = 0;
     cout << "Cada llave de Madera vale 10 monedas"<<endl;
     cout << "Cada  llave de Piedra vale 20 monedas"<<endl;
     cout << "Cada llave de Metal vale 30 monedas"<<endl;
     for (p=0; p<5; p++)    //acumuladorItems
    {
        switch(dados[p])
        {
            case 1:
                cantDado1++;
            break;
            case 2:
                cantDado2++;
            break;
            case 3:
                cantDado3++;
            break;
         }
    }
   totalDado1= cantDado1 * 10;
   cout<< "Obtuviste "<< cantDado1<< "x 10 = " << totalDado1<< endl;
   totalDado2= cantDado2 * 20;
   cout<< "Obtuviste "<< cantDado2<< "x 20 = " << totalDado2<< endl;
   totalDado3= cantDado3 * 30;
   cout<< "Obtuviste "<< cantDado3<< "x 30 = " << totalDado3<< endl;
   totalMonedasLlaves =  totalDado1 + totalDado2 + totalDado3;
   cout<< "El total obtenido es "<< totalMonedasLlaves <<" monedas"<< endl;
   return totalMonedasLlaves;
}




 void conseguirTesoro(int &monedasAcum, int dados[]){    //camino feliz
    int monedasObtenidasPorTesoros = venderTesoros(dados, monedasAcum);
    int monedasObtenidasPorLlaves = venderLlaves(dados, monedasAcum);
    monedasAcum = monedasAcum +  monedasObtenidasPorTesoros + monedasObtenidasPorLlaves;
     cout<< "El total acumulado es "<< &monedasAcum <<" monedas"<< endl;
 }






void buscarTesoros (int &monedasAcum, int &llaveGuardada, int&ronda){
     int p;
     int dados[5]; // ac� no lo inicio porque abajo lo cargo
     char opcionVender, rtaInventario;
     tiradaDados(dados, 5);
     mostrarTirada(dados, 5);
     mostrarItems(dados);
     if (obtuvoLlave( p, ronda) ){    //caso exitoso
            cout<<"�Felicitaciones! �Obtuviste la llave para abrir el cofre!" <<endl;
            conseguirTesoro(monedasAcum, dados);
     }
     else{
            cout<<" �Lastima! No obtuviste la llave requerida."<<endl;
            cout<< endl;
            system("pause");
            system("cls");
            if( llaveGuardada!=0){
                if (ronda == llaveGuardada){
                        cout<<"�Desea consultar si tiene alguna llave guardada que le sea �til? Responda 'S' en caso afirmativo o 'N' en caso negativo"<< endl;
                        cin>>rtaInventario;
                        if(rtaInventario == 'S'){
                            consultarLlaveGuardada( llaveGuardada);
                            cout<<"�Felicitaciones! �Obtuviste la llave para abrir el cofre!" <<endl;
                            llaveGuardada =0;
                            conseguirTesoro(monedasAcum, dados);

                           }
                }

            }

            do{
                    cout<<" Puede vender TODAS las llaves o guardar solo UNA llave para usarla en la pr�xima ronda. �Desea VENDER o GUARDAR?  Ingrese V o G"<<endl;
                    cout<< endl;
                    cin>> opcionVender;
                }

            while (opcionVender != 'V' && opcionVender != 'G' ); // NECESITA DE AMBAS PARA SER TRUE, POR LO que es false si se ingresa una
            if(opcionVender == 'V'){
                       int monedasObtenidasPorLlaves2 = venderLlaves(dados, monedasAcum);
                       cout<< "El total obtenido por las llaves vendidas es "<< monedasObtenidasPorLlaves2 <<" monedas"<< endl;
                       system("pause");
                       system("cls");
            }
            else{
                cout<<"�Que llave desea guardar?"<<endl;
                cout<<"Ingrese '1' en caso de elegir la llave de Madera"<<endl;
                cout<<"Ingrese '2' en caso de elegir la llave de Piedra"<<endl;
                cout<<"Ingrese '3' en caso de elegir la llave de Metal"<<endl;
                cout<<"Considere que solo puede tener una llave guardada, por lo que al elegir otra sobreescribir� la anterior"<<endl;
                cin>> llaveGuardada;
            }

     }


}


//funci�n principal
void jugarFase2(string J1, string J2, int monedasAcumJ1, int monedasAcumJ2)
 {
    int j= 0;
    for (j=0; j<2; j++){
        cout<<"Comienza la Fase de BUSQUEDA DE TESOROS"<<endl;
        int ronda=0;
        int llaveGuardada=0;
        for(ronda=0; ronda<3; ronda++){
             if (ronda ==0){
                    system("cls");
                    cout<<"Ronda 1:"<<endl;
                    cout<<"�Encuentra el cofre de Madera!"<<endl;
                    cout<<endl <<"Tira tus dados y consigue un 1 para obtener la llave de madera y abrir el cofre"<<endl;
             }
            if (ronda ==1){
                    system("cls");
                    cout<<"Ronda 2:"<<endl;
                    cout<<"�Encuentra el cofre de Piedra!"<<endl;
                    cout<<endl <<"Tira tus dados y consigue un 2 para obtener la llave de piedra y abrir el cofre"<<endl;
             }
            if (ronda ==2){
                    system("cls");
                    cout<<"Ronda 3:"<<endl;
                    cout<<"�Encuentra el cofre de Metal!"<<endl;
                    cout<<endl <<"Tira tus dados y consigue un 3 para obtener la llave de metal y abrir el cofre"<<endl;
             }
        }

        if(j==0){
            cout<<"El es turno de "<<J1 <<endl;
            cout<< "Monedas: "<< &monedasAcumJ1;
            buscarTesoros(monedasAcumJ1, llaveGuardada, ronda);
        }
        else{
            cout<<"El es turno de "<<J2 <<endl;
            cout<< "Monedas: "<< &monedasAcumJ2;
            buscarTesoros( monedasAcumJ2, llaveGuardada, ronda);
        }

        system("cls");
    }

}
/*
void JugarBusqueda(string &J1,string &J2,vector<int> &monedas){
      JugarRonda1(J1, J2, monedas);
}*/












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








