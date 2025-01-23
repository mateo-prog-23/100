#include <iostream>
#include "funciones.h"
#include "modoUnJugador.h"
#include "modoMultijugador.h"

using namespace std;

int main()
{
    int opcion;
    cout << "Ingrese un numero segun la opcion que desee." << endl;
    cout << "1 - 1 jugador " << endl;
    cout << "2 - 2 jugadores" << endl;
    cin >> opcion;
    system("cls");


    switch(opcion){
        case 1: modoUnJugador();
        break;
        case 2: modoMultijugador();
        break;
    }
    return 0;
}
