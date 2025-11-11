#include <iostream>
using namespace std;

int main(){
    int item, SumarNum;
    cout<<"Comienza la Fase de BUSQUEDA DE TESOROS"<<endl;
    system("pause");
    system("cls");
    cout<<"­Encuentra el cofre de Madera!"<<endl;
    cout<<"Tira tus dados y consigue un 1 para obtener la llave de madera"<<endl;
    cout<<endl;
    int dados [5], monedasAcum[2],monedasRonda, resultado;
    string J1,J2;
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
       bool Obtenerllave = false;
        tiradaDados(dados, 5);
        mostrarTirada(dados, 5);
        for (i=0; i<5; i++){
            Obteneritem(dados[i]);
            if (i == 1){
                Obtenerllave = true;
            }}
            if(Obtenerllave){
              cout<<"­Felicitaciones! ­Obtuviste la llave para abrir el cofre!" <<endl;
            }
            else{
                do{
                cout<<" ­Lastima! No obtuviste la llave requerida."<<endl;
                cout<<" Puede vender las llaves o guardar solo una. Desea VENDER o GUARDAR?  Ingrese V o G"<<endl;
                 system("pause");
                 system("cls");
                cin>> Opcion;
                }
                while (Opcion != 'V' | Opcion != 'G' );
                    if(Opcion == 'V'){

                    }
            }
         //informo

    return 0;
}
