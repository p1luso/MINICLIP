#include "textoGato.h"
#ifndef FUNCIONES_MOVIMIENTO_INCLUDED
#define FUNCIONES_MOVIMIENTO_INCLUDED


/// MOVER PERSONAJE PRIMERA ESCENA

void moverPersonaje()
{
    char moverPj = rlutil::getkey();

    switch (moverPj)
    {
    case 119:                                                           ///MOVER ARRIBA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= filas - 1 && VariablesGlobales::mapa[VariablesGlobales::posy - 1][VariablesGlobales::posx] == 0)
        {
            VariablesGlobales::posy--;
        }
        break;
    case 97:                                                            /// MOVER IZQUIERDA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= columnas - 1 && VariablesGlobales::mapa[VariablesGlobales::posy][VariablesGlobales::posx - 1] == 0)
        {
            VariablesGlobales::posx--;
        }
        break;
    case 100:                                                           ///MOVER DERECHA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= columnas - 1 && VariablesGlobales::mapa[VariablesGlobales::posy][VariablesGlobales::posx + 1] == 0)
        {
            VariablesGlobales::posx++;
        }
        break;
    case 115:                                                           /// MOVER ABAJO
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= filas - 1 && VariablesGlobales::mapa[VariablesGlobales::posy + 1][VariablesGlobales::posx] == 0)
        {
            VariablesGlobales::posy++;
        }
        break;
    }
}

///MOVER PERSONAJE SEGUNDA ESCENA


void moverPersonaje2()
{
    int posx_antes;
    int posy_antes;
    char moverPj = rlutil::getkey();
    switch (moverPj)
    {
    case 119:                                                           ///MOVER ARRIBA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= filas - 1 && VariablesGlobales::mapa2[VariablesGlobales::posy - 1][VariablesGlobales::posx] == 0)
        {
            VariablesGlobales::posy--;
        }
        break;
    case 97:                                                            /// MOVER IZQUIERDA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= columnas - 1 && VariablesGlobales::mapa2[VariablesGlobales::posy][VariablesGlobales::posx - 1] == 0)
        {
            VariablesGlobales::posx--;
        }
        break;
    case 100:                                                           ///MOVER DERECHA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= columnas - 1 && VariablesGlobales::mapa2[VariablesGlobales::posy][VariablesGlobales::posx + 1] == 0)
        {
            VariablesGlobales::posx++;
        }
        break;
    case 115:                                                           /// MOVER ABAJO
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= filas - 1 && VariablesGlobales::mapa2[VariablesGlobales::posy + 1][VariablesGlobales::posx] == 0)
        {
            VariablesGlobales::posy++;
        }
        break;
    }

    if (VariablesGlobales::mapa2[VariablesGlobales::posy + 1][VariablesGlobales::posx] == 6 || VariablesGlobales::mapa2[VariablesGlobales::posy][VariablesGlobales::posx + 1] == 6 || VariablesGlobales::mapa2[VariablesGlobales::posy - 1][VariablesGlobales::posx] == 6 || VariablesGlobales::mapa2[VariablesGlobales::posy][VariablesGlobales::posx - 1] == 6)
    {
        VariablesGlobales::decisionGato = 0;
        posx_antes = VariablesGlobales::posx;
        posy_antes = VariablesGlobales::posy;
    }

}

void moverPersonaje3()
{
    char moverPj = rlutil::getkey();
    int posx_antes;
    int posy_antes;

    switch (moverPj)
    {
    case 119:                                                           ///MOVER ARRIBA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= filas - 1 && VariablesGlobales::mapa3[VariablesGlobales::posy - 1][VariablesGlobales::posx] == 0)
        {
            VariablesGlobales::posy--;
        }
        break;
    case 97:                                                            /// MOVER IZQUIERDA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= columnas - 1 && VariablesGlobales::mapa3[VariablesGlobales::posy][VariablesGlobales::posx - 1] == 0)
        {
            VariablesGlobales::posx--;
        }
        break;
    case 100:                                                           ///MOVER DERECHA
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= columnas - 1 && VariablesGlobales::mapa3[VariablesGlobales::posy][VariablesGlobales::posx + 1] == 0)
        {
            VariablesGlobales::posx++;
        }
        break;
    case 115:                                                           /// MOVER ABAJO
        if (VariablesGlobales::posy > 0 && VariablesGlobales::posy <= filas - 1 && VariablesGlobales::mapa3[VariablesGlobales::posy + 1][VariablesGlobales::posx] == 0)
        {
            VariablesGlobales::posy++;
        }
        break;
    }
    if (VariablesGlobales::mapa3[VariablesGlobales::posy + 1][VariablesGlobales::posx] == 6 || VariablesGlobales::mapa3[VariablesGlobales::posy][VariablesGlobales::posx + 1] == 6 || VariablesGlobales::mapa3[VariablesGlobales::posy - 1][VariablesGlobales::posx] == 6 || VariablesGlobales::mapa3[VariablesGlobales::posy][VariablesGlobales::posx - 1] == 6)
    {
        textoGatoDespues();
    }

}






#endif //FUNCIONES_MOVIMIENTO_INCLUDED