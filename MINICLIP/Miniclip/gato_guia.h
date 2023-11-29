#include "maps.h"
#include <iostream>
#include "rlutil.h"

#ifndef FUNCIONES_GATOGUIA_INCLUDED
#define FUNCIONES_GATOGUIA_INCLUDED


///FUNCION PARA IMPRIMIR GATO GUIA
void imprimirGato_guia(int m[filas][columnas], int filas, int columnas)
{
    int colores[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            int color = m[f][c];
            rlutil::setBackgroundColor(colores[color]);
            std::cout << " ";
            rlutil::setBackgroundColor(0);
        }
        std::cout << std::endl;
    }
}


///FUNCION PARA IMPRIMIR GATO GUIA
void imprimirGato_guiaPelea(int m[filas][columnas], int filas, int columnas)
{
    int colores[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            int color = m[f][c];
            rlutil::setBackgroundColor(colores[color]);
            rlutil::locate(51 + c, 1 + f);
            std::cout << " ";
            rlutil::setBackgroundColor(0);
        }
        std::cout << std::endl;
    }
}


#endif //FUNCIONES_GATOGUIA_INCLUDED