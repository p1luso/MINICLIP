#include <iostream>
#include "rlutil.h"
#include "variables.h"


#ifndef FUNCIONES_MAPS_INCLUDED
#define FUNCIONES_MAPS_INCLUDED

///CARACTER DEL PERSONAJE
const char pj = (char)2;

///TAMAÑO MAPA
const int filas=29;
const int columnas=89;


///FUNCION PARA IMPRIMIR EL MAPA CON LOS COLORES
void imprimirMapa()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;

    int colores[] = { 0, 11, 3, 5, 9, 15 }; // Array de colores correspondientes a los valores de las celdas
    int condicionColor = -1;                  //PARA QUE ENTRE SI O SI AL IF PARA PINTAR LOS COLORES

    for (int f = 0; f < filas; f++)
    {
        coord.Y = f;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        for (int c = 0; c < columnas; c++)
        {
            int valorMatriz = VariablesGlobales::mapa[f][c]; // Obtener el valor de la celda
            int color = colores[valorMatriz]; // Obtener el color correspondiente al valor de la celda

            if (condicionColor != color)
            {
                rlutil::setBackgroundColor(color); // Establecer el color de fondo
                condicionColor = color;
            }

            if (f == VariablesGlobales::posy && c == VariablesGlobales::posx)
            {
                std::cout << pj; // Imprimir el personaje
            }
            else
            {
                std::cout << " "; // Imprimir un espacio en blanco
            }
        }
    }
}


void imprimirMapa2()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    int  color;
    int colores[] = { 0, 11, 3, 5, 9, 15 }; // Array de colores correspondientes a los valores de las celdas
    int condicionColor = -1;                  //PARA QUE ENTRE SI O SI AL IF PARA PINTAR LOS COLORES

    for (int f = 0; f < filas; f++)
    {
        coord.Y = f;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        for (int c = 0; c < columnas; c++)
        {

            int valorMatriz = VariablesGlobales::mapa2[f][c]; // Obtener el valor de la celda

            if (valorMatriz < 6)
            {
                color = colores[valorMatriz]; // Obtener el color correspondiente al valor de la celda
            }
            if (condicionColor !=color)
            {
                rlutil::setBackgroundColor(color); // Establecer el color de fondo
                condicionColor = color;
            }

            if (f == VariablesGlobales::posy && c == VariablesGlobales::posx)
            {
                std::cout << pj; // Imprimir el personaje
            }
            else if (VariablesGlobales::mapa2[f][c] == 6)
            {
                std::cout << '?';
            }
            else
            {
                std::cout << " "; // Imprimir un espacio en blanco
            }
        }
    }
}



void imprimirMapa3()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    int  color;
    int colores[] = { 0, 11, 3, 5, 9, 15 }; // Array de colores correspondientes a los valores de las celdas
    int condicionColor = -1;                  //PARA QUE ENTRE SI O SI AL IF PARA PINTAR LOS COLORES

    for (int f = 0; f < filas; f++)
    {
        coord.Y = f;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        for (int c = 0; c < columnas; c++)
        {

            int valorMatriz = VariablesGlobales::mapa3[f][c]; // Obtener el valor de la celda

            if (valorMatriz < 6)
            {
                color = colores[valorMatriz]; // Obtener el color correspondiente al valor de la celda
            }
            if (condicionColor != color)
            {
                rlutil::setBackgroundColor(color); // Establecer el color de fondo
                condicionColor = color;
            }

            if (f == VariablesGlobales::posy && c == VariablesGlobales::posx)
            {
                std::cout << pj; // Imprimir el personaje
            }
            else if (VariablesGlobales::mapa3[f][c] == 6)
            {
                std::cout << '?';
            }
            else
            {
                std::cout << " "; // Imprimir un espacio en blanco
            }
        }
    }

}


#endif //FUNCIONES_MAPS_INCLUDED
