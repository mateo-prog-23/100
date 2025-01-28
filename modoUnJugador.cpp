#include <iostream>
#include <ctime>
#include <cstdlib>
#include "modoUnJugador.h"
#include "funciones.h"



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

        asignacion(vectorDados); // ASIGNACION DE EL NUMERO DE DADO AL VECTOR.

        muestraDados(vectorDados); // MUESTRA DADOS.

        // CALCULAR PUNTAJE DE LANZAMIENTO.

        puntajeDeLanzamiento = 0 ;

        burbujeOrdena(vectorDados); // BURBUJEO, PARA ORDENAR LA ESCALERA.

        /// CALCULA COMBINACIONES.
        int escalera = 0;
        int sexteto = 0;

        validarEscalera(vectorDados, escalera);
        validarSexteto(vectorDados, sexteto);

        asignacionPuntajes(escalera, puntajeDeLanzamiento, nroDeLanzamiento, sexteto, vectorDados, puntajeTotal);


        std::cout << " " << std::endl;
        std::cout << "Puntos obtenidos en este lanzamiento = " << puntajeDeLanzamiento << std::endl;
        std::cout << " " << std::endl;

        system("pause");
        system("cls");

        // CALCULAR PUNTAJE MAXIMO DE LA RONDA.

        calculaPuntajeMaximoDeLaRonda(puntajeDeLanzamiento, puntajeMaximoDeLaRonda);

        nroDeLanzamiento++;

        calculaPuntajeTotal(nroDeLanzamiento,puntajeTotal, puntajeMaximoDeLaRonda);

        if(nroDeLanzamiento == 4)
        {
            system("cls");

            std::cout << "Ronda " << ronda <<std::endl;
            std::cout << "Turno de " << nombre << std::endl;
            std::cout << "Puntaje : " << puntajeTotal << std::endl;

            system("pause");

            system("cls");

        }

        // LANZAMIENTOS.

        sumaYRestablece(nroDeLanzamiento, ronda, puntajeMaximoDeLaRonda);



    }

    std::cout <<nombre << " haz finalizado !" << std::endl;
    std::cout << "Puntaje obtenido : " << puntajeTotal << " | En " << ronda << " rondas." << std::endl;
    system("pause");

}


