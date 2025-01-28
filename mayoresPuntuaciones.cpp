#include "mayoresPuntuaciones.h"
#include "modoMultijugador.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "modoUnJugador.h"
#include "funciones.h"
#include ""

void mayoresPuntuaciones(int puntuacionProvisional, int &antPuntuacion,std::string nombreProvisional,std::string &antNombre){


    std::cout << "-----Puntuacion mas alta-----" << std::endl;

    if(puntuacionProvisional > antPuntuacion){
        antPuntuacion = puntuacionProvisional;
        antNombre = nombreProvisional;
        std::cout << " TOP 1 | Nombre : " << antNombre << " | Puntuacion : " << antPuntuacion<< std::endl;
    }else{
        std::cout << " TOP 1 | Nombre : " << antNombre << " | Puntuacion : " << antPuntuacion << std::endl;
    }

    system("pause");

}
