#include <iostream>
#include "funciones.h"
#include "modoUnJugador.h"
#include "modoMultijugador.h"
#include "mayoresPuntuaciones.h"

using namespace std;

int main()
{
    int opcion;
    bool continuar = true;

    

    int puntuacionProvisional{};
    string nombreProvisional{};
    int antPuntuacion{};
    string antNombre{};

    while(continuar)
    {
        cout << "Ingrese un numero segun la opcion que desee." << endl;
        cout << "1 - 1 jugador " << endl;
        cout << "2 - 2 jugadores" << endl;
        cout << "3 - Mayores puntuaciones"<< endl;
        cout << "4 - Salir" <<endl;
        cin >> opcion;
        system("cls");


        switch(opcion)
        {
        case 1:
            modoUnJugador(puntuacionProvisional, nombreProvisional);
            system("cls");
            break;
        case 2:
            modoMultijugador(puntuacionProvisional, nombreProvisional);
            system("cls");

            break;

        case 3:
            mayoresPuntuaciones(puntuacionProvisional, antPuntuacion, nombreProvisional, antNombre);
            system("cls");
            break;
        case 4:
            cout << "Saliendo..." << endl;
            continuar = false;
            break;
        default:
            cout << "Opcion invalida...";
        }
    }

    return 0;
}
