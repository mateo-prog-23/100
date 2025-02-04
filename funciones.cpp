#include "funciones.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "modoUnJugador.h"


void asignacion(int vectorDados[], bool activar)
{
    std::srand(std::time(0));

    int valorDado;

    if(activar == false)
    {
        for (int x = 0; x < 6 ; x++)
        {
            vectorDados[x]= (std::rand() %6)+ 1 ;
        }
    }
    else
    {
        std::cout << "Ingrese los valores de los dados por favor..." << std::endl;
        for (int x = 0; x < 6 ; x++)
        {
            std::cin >> valorDado;
            vectorDados[x]= valorDado ;
        }
    }

}

void muestraDados(int vectorDados[])
{
    for (int x = 0; x < 6 ; x++)
    {
        std::cout << vectorDados[x] << "  ";
    }
}

void burbujeOrdena(int vectorDados[])
{
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
}

void validarEscalera(int vectorDados[], int &escalera)
{
    for (int x = 1; x < 6; x++)
    {
        // RECONOCE ESCALERA.
        if(vectorDados[x -1 ] < vectorDados[x] /*&& vectorDados[x] != */ )
        {
            escalera++;
        }
    }
}

void validarSexteto(int vectorDados[], int &sexteto)
{
    for (int x = 1; x < 6; x++)
    {
        // RECONOCE SEXTETO.
        if(vectorDados[x] == vectorDados[x-1])
        {
            sexteto++;
        }
    }
}

void asignacionPuntajes(int escalera, int &puntajeDeLanzamiento, int &nroDeLanzamiento, int sexteto, int vectorDados[], int &puntajeTotal)
{
    if(escalera == 5)
    {
        // CALCULA ESCALERA.
        puntajeDeLanzamiento = 100;
        nroDeLanzamiento = 3;
        std::cout << "Escalera ! Ganaste la partida ! ";
    }
    else if(sexteto == 5)
    {
        // CALCULA SEXTETO.

        if(vectorDados[1] == 6)
        {
            puntajeTotal = 0;
            nroDeLanzamiento = 3;
        }
        else
        {
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
}

void calculaPuntajeMaximoDeLaRonda(int puntajeDeLanzamiento, int &puntajeMaximoDeLaRonda)
{
    if(puntajeDeLanzamiento >= puntajeMaximoDeLaRonda )
    {
        puntajeMaximoDeLaRonda = puntajeDeLanzamiento;
    }
}

void sumaYRestablece(int &nroDeLanzamiento, int &ronda, int &puntajeMaximoDeLaRonda)
{


    if( nroDeLanzamiento == 4)
    {
        nroDeLanzamiento = 1;

        //
        puntajeMaximoDeLaRonda = 0;

        // SE SUMAN LAS RONDAS.
        ronda++;
    }
}

void calculaPuntajeTotal(int nroDeLanzamiento, int &puntajeTotal, int puntajeMaximoDeLaRonda)
{
    if(nroDeLanzamiento == 4)
    {
        // ASIGNAR PUNTAJE TOTAL.
        puntajeTotal = puntajeTotal + puntajeMaximoDeLaRonda;
    }
}

/// MODO SIMULADO FUNCIONES


