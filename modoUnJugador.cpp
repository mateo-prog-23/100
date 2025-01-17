#include <iostream>
#include <ctime>
#include <cstdlib>
#include "multijugador.h"


void modoUnJugador()
{

    std::string nombre;
    int ronda = 1;
    int puntajeTotal = 0;
    int puntajeMaximoDeLaRonda =0;

    // DECLARACION DE LANZAMIENTOS
    int nroDeLanzamiento = 1;

    std::cout << "Bienvenido al modo un jugador." << std::endl;
    std::cout << "Ingrese su nombre : ";
    std::cin >> nombre;

    system("cls");

    while(puntajeTotal < 100)
    {


        std::cout << "Turno de " << nombre << " | Ronda " << ronda << " | Puntaje total " << puntajeTotal << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
        std::cout << "Puntaje maximo de la ronda : " << puntajeMaximoDeLaRonda << " pts" << std::endl;
        std::cout << "Lanzamiento nro : " << nroDeLanzamiento << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;

        // TIENEN QUE APARECER LOS DADOS.

        system("pause");

        int vectorDados[6];
        std::srand(std::time(0));

        for (int x = 0; x < 6 ; x++)
        {
            vectorDados[x]= (std::rand() %6)+ 1;
        }

        for (int x = 0; x < 6 ; x++)
        {
            std::cout << vectorDados[x] << "  ";

        }
        std::cout << " " << std::endl;
        system("pause");
        system("cls");

        // SE SUMAN LAS RONDAS.
        ronda++;

        // CALCULAR PUNTAJE MAXIMO DE LA RONDA.

        puntajeMaximoDeLaRonda = 0 ;

        for (int x = 0; x < 6 ; x++)
        {
            puntajeMaximoDeLaRonda = puntajeMaximoDeLaRonda + vectorDados[x];
        }

        // LANZAMIENTOS.

        nroDeLanzamiento++;

        if( nroDeLanzamiento == 4){
            nroDeLanzamiento = 1;
        }

        // COMPARAR LOS 3 LANZAMIENTOS.

    }
}
