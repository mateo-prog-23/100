#include "modoMultijugador.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "modoUnJugador.h"
#include "funciones.h"

void modoMultijugador()
{

    std::string jugadorNro1;
    std::string jugadorNro2;


    std::cout << "Ingrese el nombre del jugador 1" << std::endl;
    std::cin >> jugadorNro1;
    system("cls");

    std::cout << "Ingrese el nombre del jugador 2" << std::endl;
    std::cin >> jugadorNro2;
    system("cls");

    ///JUGADOR 1
    int rondaNro1 = 1;
    int puntajeTotalNro1 = 0;
    int puntajeMaximoDeLaRondaNro1 = 0;
    int nroDeLanzamientoNro1 = 1;
    // USADO EN LA COMPARACION DE LANZAMIENTOS.
    int puntajeDeLanzamientoNro1 = 0;

    ///JUGADOR 2
    int rondaNro2 = 1;
    int puntajeTotalNro2 = 0;
    int puntajeMaximoDeLaRondaNro2 = 0;
    int nroDeLanzamientoNro2 = 1;
    // USADO EN LA COMPARACION DE LANZAMIENTOS.
    int puntajeDeLanzamientoNro2 = 0;

    while(puntajeTotalNro1 < 100 && puntajeTotalNro2 <  100)
    {
        for (int x = 0; x < 3 ; x++)
        {
            ///////////////////////////
            /// JUGADOR 1
            ///////////////////////////

            std::cout << "Turno de " << jugadorNro1 << " | Ronda " << rondaNro1 << " | Puntaje total " << puntajeTotalNro1 << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
            std::cout << "Puntaje maximo de la ronda : " << puntajeMaximoDeLaRondaNro1 << " pts" << std::endl;
            std::cout << "Lanzamiento nro : " << nroDeLanzamientoNro1 << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;

            // TIENEN QUE APARECER LOS DADOS.

            system("pause");

            int vectorDadosNro1[6];

            asignacion(vectorDadosNro1); // ASIGNACION DE EL NUMERO DE DADO AL VECTOR.

            muestraDados(vectorDadosNro1); // MUESTRA DADOS.

            // CALCULAR PUNTAJE DE LANZAMIENTO.

            puntajeDeLanzamientoNro1 = 0 ;

            burbujeOrdena(vectorDadosNro1); // BURBUJEO, PARA ORDENAR LA ESCALERA.

            /// CALCULA COMBINACIONES.
            int escalera = 0;
            int sexteto = 0;

            validarEscalera(vectorDadosNro1, escalera);
            validarSexteto(vectorDadosNro1, sexteto);

            asignacionPuntajes(escalera, puntajeDeLanzamientoNro1, nroDeLanzamientoNro1, sexteto, vectorDadosNro1, puntajeTotalNro1);

            nroDeLanzamientoNro1++;
            calculaPuntajeTotal(nroDeLanzamientoNro1,puntajeTotalNro1, puntajeMaximoDeLaRondaNro1);

            std::cout << " " << std::endl;
            std::cout << "Puntos obtenidos en este lanzamiento = " << puntajeDeLanzamientoNro1 << std::endl;
            std::cout << " " << std::endl;

            system("pause");
            system("cls");

            // CALCULAR PUNTAJE MAXIMO DE LA RONDA.

            calculaPuntajeMaximoDeLaRonda(puntajeDeLanzamientoNro1, puntajeMaximoDeLaRondaNro1);

            // LANZAMIENTOS.

            sumaYRestablece(nroDeLanzamientoNro1, rondaNro1, puntajeMaximoDeLaRondaNro1);

        }

        std::cout << "Ronda N " << rondaNro2 << std::endl;
        std::cout << "Turno de " << jugadorNro2 <<std::endl;
        std::cout << "Puntaje " << jugadorNro1 << " : " << puntajeTotalNro1 << std::endl;
        std::cout << "Puntaje " << jugadorNro2 << " : " << puntajeTotalNro2 << std::endl;

        system("pause");
        system("cls");

        for(int x = 0; x < 3; x++)
        {
            ///////////////////////////
            /// JUGADOR 2
            ///////////////////////////
            std::cout << "Turno de " << jugadorNro2 << " | Ronda " << rondaNro2 << " | Puntaje total " << puntajeTotalNro2 << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
            std::cout << "Puntaje maximo de la ronda : " << puntajeMaximoDeLaRondaNro2 << " pts" << std::endl;
            std::cout << "Lanzamiento nro : " << nroDeLanzamientoNro2 << std::endl;
            std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;

            // TIENEN QUE APARECER LOS DADOS.

            system("pause");

            int vectorDadosNro2[6];

            asignacion(vectorDadosNro2); // ASIGNACION DE EL NUMERO DE DADO AL VECTOR.

            muestraDados(vectorDadosNro2); // MUESTRA DADOS.

            // CALCULAR PUNTAJE DE LANZAMIENTO.

            puntajeDeLanzamientoNro2 = 0 ;

            burbujeOrdena(vectorDadosNro2); // BURBUJEO, PARA ORDENAR LA ESCALERA.

            /// CALCULA COMBINACIONES.
            int escalera = 0;
            int sexteto = 0;

            validarEscalera(vectorDadosNro2, escalera);
            validarSexteto(vectorDadosNro2, sexteto);

            asignacionPuntajes(escalera, puntajeDeLanzamientoNro2, nroDeLanzamientoNro2, sexteto, vectorDadosNro2, puntajeTotalNro2);

            // CALCULAR PUNTAJE MAXIMO DE LA RONDA.
            calculaPuntajeMaximoDeLaRonda(puntajeDeLanzamientoNro2, puntajeMaximoDeLaRondaNro2);

            nroDeLanzamientoNro2++;
            calculaPuntajeTotal(nroDeLanzamientoNro2, puntajeTotalNro2, puntajeMaximoDeLaRondaNro2);

            std::cout << " " << std::endl;
            std::cout << "Puntos obtenidos en este lanzamiento = " << puntajeDeLanzamientoNro2 << std::endl;
            std::cout << " " << std::endl;

            system("pause");
            system("cls");

            // LANZAMIENTOS.

            sumaYRestablece(nroDeLanzamientoNro2, rondaNro2, puntajeMaximoDeLaRondaNro2);

        }



        if(puntajeTotalNro1 < 100 || puntajeDeLanzamientoNro2 < 100)
        {
            std::cout << "Ronda " << rondaNro1 <<std::endl;
            std::cout << "Turno de " << jugadorNro1 << std::endl;
            std::cout << "Puntaje " << jugadorNro2 << " : " << puntajeTotalNro2 << std::endl;
            std::cout << "Puntaje " << jugadorNro1 << " : " << puntajeTotalNro1 << std::endl;

            system("pause");
            system("cls");
        }
        else
        {

        }


    }

    if(puntajeTotalNro1 > puntajeTotalNro2)
    {
        std::cout << "Felicidades " << jugadorNro1 << " !! Haz ganado" << std::endl;
        std::cout << "Puntaje : " << puntajeTotalNro1 << " || Rondas : " << rondaNro1 << std::endl;
    }
    else
    {
        std::cout << "Felicidades " << jugadorNro2 << " !! Haz ganado" << std::endl;
        std::cout << "Puntaje : " << puntajeTotalNro2 << " || Rondas : " << rondaNro2 << std::endl;
    }



}
