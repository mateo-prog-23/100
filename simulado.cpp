#include "simulado.h"
#include "modoMultijugadorSimulado.h"
#include "ModoUnJugadorSimulado.h"
#include "rlutil.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

void simulado(bool &activar)
{
    if (activar == false){
        activar = true;
    }else if (activar == true)
    {
        activar = false;
    }
}
