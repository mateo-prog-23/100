#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void asignacion(int vectorDados[], bool activar);
void muestraDados(int vectorDados[]);

void burbujeOrdena(int vectorDados[]);

void validarEscalera(int vectorDados[], int &escalera);
void validarSexteto(int vectorDados[], int &sexteto);

void asignacionPuntajes(int escalera, int &puntajeDeLanzamiento, int &nroDeLanzamiento, int sexteto, int vectorDados[], int &puntajeTotal);

void calculaPuntajeMaximoDeLaRonda(int puntajeDeLanzamiento, int &puntajeMaximoDeLaRonda);

// SECCION LANZAMIENTOS.
void sumaYRestablece(int &nroDeLanzamiento, int &ronda, int &puntajeMaximoDeLaRonda);

void calculaPuntajeTotal(int nroDeLanzamiento,int &puntajeTotal, int puntajeMaximoDeLaRonda);

#endif // FUNCIONES_H_INCLUDED
