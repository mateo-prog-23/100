#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
    int opcion;
    cout << "Ingrese un numero segun la opcion que desee." << endl;
    cout << "1 - Modo 1 jugador " << endl;
    cin >> opcion;
    system("cls");


    switch(opcion){
        case 1: modoUnJugador();
        break;
    }
    return 0;
}
