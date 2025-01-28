#include <iostream>
#include "funciones.h"
#include "modoUnJugador.h"
#include "modoMultijugador.h"

using namespace std;

int main()
{
    int opcion;
    bool continuar = true;

    while(continuar)
    {
        cout << "Ingrese un numero segun la opcion que desee." << endl;
        cout << "1 - 1 jugador " << endl;
        cout << "2 - 2 jugadores" << endl;
        cout << "3 - Salir" <<endl;
        cin >> opcion;
        system("cls");


        switch(opcion)
        {
        case 1:
            modoUnJugador();
            system("cls");
            break;
        case 2:
            modoMultijugador();
            system("cls");

            break;
        case 3:
            cout << "Saliendo..." << endl;
            continuar = false;
            break;
        default:
            cout << "Opcion invalida...";
        }
    }

    return 0;
}
