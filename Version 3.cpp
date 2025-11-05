#include <iostream>
using namespace std;

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
void ingresarOpciones (){
                cout<< endl<< "1- Jugar\n2- Estad¡sticas\n3- Cr‚ditos\n0- Salir"<< endl;
}
 bool repetirOpciones(char opcion){ // true = repite
                string nombreJ1, nombreJ2;
                switch (opcion){ // false= ejecuta algo
                    case '1': ///los case tendrán funciones dentro para simplificar repetirOpciones y tener código más legible. 16/10
                        cout<< "Ingrese el nombre del jugador 1: ";
                        cin>> nombreJ1;
                        cout<< endl<< "Ingrese el nombre del jugador 2: ";
                        cin>> nombreJ2;
                        //competencia1();
                        return false;
                        break;   ///este break no va a entrar
                    case '2':
                        //cout maxjugador;
                        return false;
                        break;
                    case '3':
                        cout<< "Equipo 07"<< endl;
                        cout<< "Bassi, Cristian Hern n- legajo: 32409"<< endl;
                        cout<< "Boccalandro, David Ismael- legajo: 32382"<< endl;
                        cout<< "C rdenas, Gustavo- legajo: 34269"<< endl;
                        cout<< "Specht, Giselle Mailen- legajo: 33101"<< endl;
                        return false;
                        break;
                    case '0':
                   if( confirmarSalir() ==true){
                            return false;
                            } else {return true;
                            }

                       break;
                    default:
                        //while (opcion != '1'| opcion !='2'| opcion != '3'| opcion !='0' )
                        //{
                            //cout<< "Ingrese el n£mero de la opci¢n que desea seleccionar"<< endl;
                            //cin>> opcion;
                        return true;
                        break;
                        }  ///Los break luego de los return no se ejecutarían por lo tanto podriamos suprimirlos para que no queden como código redundante.16/10
                }
void menu(){
    char opcion;
    cout << "Roll & Return" << endl;

    do {
        ingresarOpciones();
        cin >> opcion;
    } while(repetirOpciones(opcion));
}


int main() {
        menu();
        return 0;
}


