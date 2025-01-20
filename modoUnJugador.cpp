#include <iostream>
#include <ctime>
#include <cstdlib>
#include "modoUnJugador.h"


void modoUnJugador()
{

    std::string nombre;
    int ronda = 1;
    int puntajeTotal = 0;
    int puntajeMaximoDeLaRonda =0;

    // DECLARACION DE LANZAMIENTOS.
    int nroDeLanzamiento = 1;

    // USADO EN LA COMPARACION DE LANZAMIENTOS.
    int puntajeDeLanzamiento = 0;

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

        // CALCULAR PUNTAJE DE LANZAMIENTO.

        puntajeDeLanzamiento = 0 ;

        //Ordena en forma de escalera, con el "metodo de burbujeo".
        for (int i = 0; i < 6 - 1; i++)
        {
            for (int j = 0; j < 6 - i - 1; j++)
            {
                if (vectorDados[j] > vectorDados[j + 1])
                {
                    int temporal = vectorDados[j];
                    vectorDados[j] = vectorDados[j + 1];
                    vectorDados[j + 1] = temporal;
                }
            }
        }

        /// CALCULA COMBINACIONES.
        int escalera = 0;
        int sexteto = 0;
        int normal = 0;

        for (int x = 1; x < 6; x++)
        {
            // RECONOCE ESCALERA.
            if(vectorDados[x -1 ] < vectorDados[x] /*&& vectorDados[x] != */ )
            {
                escalera++;
            }
        }

        for (int x = 1; x < 6; x++){
            // RECONOCE SEXTETO.
            if(vectorDados[x] == vectorDados[x-1])
            {
                sexteto++;
            }
        }

        if(escalera == 5)
        {
            // CALCULA ESCALERA.
            puntajeDeLanzamiento = 100;
            nroDeLanzamiento = 3;
        }
        else if(sexteto == 5)
        {
            // CALCULA SEXTETO.

            if(vectorDados[1] == 6){
                puntajeTotal = 0;
                nroDeLanzamiento = 3;
            }else{
                 puntajeDeLanzamiento = vectorDados[1] * 10;
            }
        }
        else
        {
            // CALCULA PUNTAJE NORMAL.
            for (int x = 0; x < 6; x++)
            {
                puntajeDeLanzamiento = puntajeDeLanzamiento + vectorDados[x];
            }
        }


        std::cout << " " << std::endl;
        std::cout << "Puntos obtenidos en este lanzamiento = " << puntajeDeLanzamiento << std::endl;
        std::cout << " " << std::endl;

        system("pause");
        system("cls");

        // CALCULAR PUNTAJE MAXIMO DE LA RONDA.

        if(puntajeDeLanzamiento >= puntajeMaximoDeLaRonda )
        {
            puntajeMaximoDeLaRonda = puntajeDeLanzamiento;
        }

        // LANZAMIENTOS.

        nroDeLanzamiento++;

        if( nroDeLanzamiento == 4)
        {
            nroDeLanzamiento = 1;

            // ASIGNAR PUNTAJE TOTAL.

            puntajeTotal = puntajeTotal + puntajeMaximoDeLaRonda;
            //
            puntajeMaximoDeLaRonda = 0;

            // SE SUMAN LAS RONDAS.
            ronda++;
        }
    }

    std::cout <<nombre << " has finalizado !" << std::endl;
    std::cout << "Puntaje obtenido : " << puntajeTotal << " | En " << ronda << " rondas." << std::endl;
    system("pause");

}
