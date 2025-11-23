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
    for (p=0; p<5; p++){ // [1-6, 1-6, 1-6, 1-6, 1-6]...
       switch( dados[p])
        {
        case 1:
            cout << "Obtuvo una llave de madera (1)"<<endl;
            break;
        case 2:
            cout<< "Obtuvo una llave de piedra (2)"<<endl;
            break;
        case 3:
            cout << "Obtuvo una llave de metal (3)"<<endl;
            break;
        case 4:
            cout << "Obtuvo una gema de esmeralda (4)"<<endl;
            break;
        case 5:
            cout << "Obtuvo una gema de rubi (5)"<<endl;
            break;
        case 6:
            cout << "Obtuvo una gema de diamante (6)"<<endl;
            break;
        }
    }
}

bool obtuvoLlave(int dados[5], int ronda){
    int p;

    for(p=0; p<5; p++){
        if (dados[p] == ronda){
            return true;
        }
    }
    return false;
}


 void mostrarInventarioSegunLlave( int &llaveGuardada){
     cout << "Inventario:"<<endl;

    switch(llaveGuardada)
        {
            case 1:
                cout << "Una llave de madera"<<endl;
            break;
            case 2:
                cout<< "Una llave de piedra"<<endl;
            break;
            case 3:
                cout << "Una llave de metal"<<endl;
            break;
         }
}


 int venderGemas(int dados[5], int &monedasAcum){
     int p;
     int cantDado4 = 0;
     int cantDado5 = 0;
     int cantDado6 = 0;
     int totalDado4 = 0;
     int totalDado5 = 0;
     int totalDado6 = 0;
     int totalMonedasTesoros = 0;
     cout << "Valor de los tesoros obtenidos:"<<endl;
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


int venderLlaves(int dados[5], int &monedasAcum, bool descontarLlave, int llaveUsada){ // llaveUsada es la llave que se uso para abrir el cofre, si se uso alguna
     int p;
     int cantDado1 = 0;
     int cantDado2 = 0;
     int cantDado3 = 0;
     int totalDado1 = 0;
     int totalDado2 = 0;
     int totalDado3 = 0;
     int totalMonedasLlaves = 0;
    cout << "Valor de las llaves obtenidas:"<<endl;
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

    if(descontarLlave){
        if(llaveUsada==1){
            cantDado1--;
        }
        if(llaveUsada==2){
            cantDado2--;
        }
        if(llaveUsada==3){
            cantDado3--;
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




 void abrirCofre(int &monedasAcum, int dados[], int ronda){
    // vende las gemas por un lado
    int monedasObtenidasPorTesoros = venderGemas(dados, monedasAcum);
    cout<<endl;

    // vende las llaves
    int monedasObtenidasPorLlaves = venderLlaves(dados, monedasAcum, true, ronda); // le decimos que descuente la llave usada para abrir el cofre

    // vendimos todo y acumulamos monedas
    monedasAcum = monedasAcum +  monedasObtenidasPorTesoros + monedasObtenidasPorLlaves;
     cout<< "El total acumulado es "<< monedasAcum <<" monedas"<< endl;
 }






void buscarTesoros (int &monedasAcum, int &llaveGuardada, int ronda){
     int dados[5]; // aca no lo inicio porque abajo lo cargo
     char opcionVender;
     tiradaDados(dados, 5);
     mostrarTirada(dados, 5);
     system("pause");
     mostrarItems(dados);
     system("pause");

     // caso 1: tenes la llave necesaria dentro los dados que tiramos

     // caso 2: no tenemos la llave, pero sí tengo una llave guardada compatible

     // caso 3: si no pudimos abrir un cofre



     if (obtuvoLlave(dados, ronda) ){
            // entra al caso 1
            cout<<endl<< endl<< endl<< "Felicitaciones! Obtuviste la llave para abrir el cofre de ";
            if(ronda == 1){
                cout<<"MADERA!" <<endl;
            }
            if(ronda == 2){
                cout<<"PIEDRA!" <<endl;
            }
            if(ronda == 3){
                cout<<"METAL!" <<endl;
            }
            cout << " Se venderá su contenido automaticamente." <<endl << endl;
            abrirCofre(monedasAcum, dados, ronda); // vendemos gemas + llaves
     system("pause");
            system("cls");
     }

     else{
            // no obtuvimos llave y puede entrar en caso 2 o 3
            cout<<"Lastima! No obtuviste la llave requerida para abrir el cofre, no sacaste un "<< ronda <<"."<<endl;
            cout<< endl;
            system("pause");

            if( llaveGuardada!=0 && llaveGuardada == ronda){
                // entra al caso 2
                cout<<"Felicidades! Tienes una llave guardada compatible"<< endl;
                mostrarInventarioSegunLlave( llaveGuardada);

                    cout<<"Se hace uso de la llave guardada para abrir el cofre!" <<endl;
                    abrirCofre(monedasAcum, dados, ronda); /// abrimos core con la llave guardada
                    llaveGuardada = 0; // como usamos la llave, la reseteamos
     system("pause");
            system("cls");
            } else {
                // entra al caso 3
                do{
                        cout<<" Puede vender TODAS las llaves o guardar solo UNA llave para usarla en la proxima ronda." << endl;
                        cout << "Desea VENDER o GUARDAR? Ingrese V o G."<<endl;
                        cout<< endl;
                        cin>> opcionVender;
                    }

                while (opcionVender != 'V' && opcionVender != 'G' ); // NECESITA DE AMBAS PARA SER TRUE, POR LO que es false si se ingresa una


                if(opcionVender == 'V'){
                    // entramos en la opcion de vender todas las llaves (no las gemas)
                            int monedasObtenidasPorLlaves2 = venderLlaves(dados, monedasAcum, false, 0); // no descontamos ninguna llave porque no se uso ninguna
                            monedasAcum += monedasObtenidasPorLlaves2;
                            cout<< "El total obtenido por las llaves vendidas es "<< monedasObtenidasPorLlaves2 <<" monedas"<< endl;
                            system("pause");
                            system("cls");
                }
                else{
                    // entramos en la opcion de guardar una llave

                    // validamos que la llave a guardar exista entre los dados (las opciones)
                    bool tieneLlave1 = false, tieneLlave2 = false, tieneLlave3 = false;
                    for(int i = 0; i < 5; i++) {
                        if(dados[i] == 1) {
                            tieneLlave1 = true;
                        }
                        if(dados[i] == 2) {
                            tieneLlave2 = true;
                        }
                        if(dados[i] == 3) {
                            tieneLlave3 = true;
                        }
                    }

                    if(!tieneLlave1 && !tieneLlave2 && !tieneLlave3 ) {
                        cout << "No tiene llaves disponibles para guardar" << endl;
                    } else {
                        cout<<"Que llave desea guardar?"<<endl;
                        if(llaveGuardada != 0) {
                            cout<<"Ya tiene una llave guardada. Al elegir otra, la anterior se perdera sin vender."<<endl;
                        }
                        cout<<"Considere que solo puede tener una llave guardada, por lo que al elegir otra sobreescribiria la anterior"<<endl;

                        if(tieneLlave1) {
                            cout<<"Ingrese '1' en caso de elegir la llave de Madera"<<endl;
                        }
                        if(tieneLlave2) {
                            cout<<"Ingrese '2' en caso de elegir la llave de Piedra"<<endl;
                        }
                        if(tieneLlave3) {
                            cout<<"Ingrese '3' en caso de elegir la llave de Metal"<<endl;
                        }
                    }

                    cin>> llaveGuardada;
                    cout << "Usted ha guardado la llave de ";
                    switch(llaveGuardada)
                    {
                        case 1:
                            cout << "Madera"<<endl;
                        break;
                        case 2:
                            cout<< "Piedra"<<endl;
                        break;
                        case 3:
                            cout << "Metal"<<endl;
                        break;
                        }
                }
        }

     }


}


//funcion principal
void jugarFase2(string &J1, string &J2, int &monedasAcumJ1, int &monedasAcumJ2)
 {
    int j;
    int llaveGuardadaJ1=0;
    int llaveGuardadaJ2=0;

    cout << "###########################################"<< endl;
    cout<<"# Comienza la Fase de BUSQUEDA DE TESOROS #"<<endl;
    cout << "###########################################"<< endl << endl << endl;

    for (j = 0; j<2; j++){
        int ronda;
        string jugadorActual;

        if(j==0){
            jugadorActual = J1;
        } else{
            jugadorActual = J2;
        }

        for(ronda=1; ronda<4; ronda++){
             if (ronda ==1){
                    system("pause");
                    system("cls");
                    cout << "BUSQUEDA DE TESOROS | Ronda 1"<< endl;
                    cout<<"Turno de "<< jugadorActual <<endl;
                    cout<<"Encuentra el cofre de MADERA!"<<endl;
                    cout<<endl <<"Regla: Tira tus dados y consigue un 1 para obtener la llave de madera y abrir el cofre."<<endl;
                    cout << "Si abres el cofre, se intercambiaran las llaves y gemas por monedas de acuerdo a su valor automaticamente." << endl <<endl <<endl;
                    system("pause");
                }
            if (ronda ==2){
                    system("pause");
                    system("cls");
                    cout << "BUSQUEDA DE TESOROS | Ronda 2"<< endl;
                    cout<<"Turno de "<< jugadorActual <<endl;
                    cout<<"Encuentra el cofre de PIEDRA!"<<endl;
                    cout<<endl <<"Regla: Tira tus dados y consigue un 2 para obtener la llave de piedra y abrir el cofre."<<endl;
                    cout << "Si abres el cofre, se intercambiaran las llaves y gemas por monedas de acuerdo a su valor automaticamente." << endl <<endl <<endl;
                    system("pause");
                }

             if (ronda ==3){
                    system("pause");
                    system("cls");
                    cout << "BUSQUEDA DE TESOROS | Ronda 3"<< endl;
                    cout<<"Turno de "<< jugadorActual <<endl;
                    cout<<"Encuentra el cofre de METAL!"<<endl;
                    cout<<endl <<"Regla: Tira tus dados y consigue un 3 para obtener la llave de metal y abrir el cofre."<<endl;
                    cout << "Si abres el cofre, se intercambiaran las llaves y gemas por monedas de acuerdo a su valor automaticamente." << endl <<endl <<endl;
                    system("pause");
            }


            if(j==0){
                cout<< "Las monedas acumuladas de " << jugadorActual << " son: "<< monedasAcumJ1<< endl << endl;
                buscarTesoros(monedasAcumJ1, llaveGuardadaJ1, ronda);
            } else{
                cout<< "Las monedas acumuladas de " << jugadorActual << " son: "<< monedasAcumJ2<<endl << endl;
                buscarTesoros( monedasAcumJ2, llaveGuardadaJ2, ronda);
            }
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








