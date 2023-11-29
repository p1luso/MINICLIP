#ifndef FUNCIONES_FIGHTMAP_INCLUDED
#define FUNCIONES_FIGHTMAP_INCLUDED
#include "textoGato.h"


/// LAS DIRECCIONES HACIA DONDE SE MUEVE LA SERPIENTE
enum direccion { STOP = 0, ARRIBA, ABAJO, IZQUIERDA, DERECHA };
direccion dir;

/// UBICA LAS COSAS EN EL MAPA, CON UN STOP INICIAL PARA QUE LA SERPIENTE NO ARRANQUE EN MOVIMIENTO.
void Setup()
{
    dir = STOP;
    VariablesGlobales::snakeX = VariablesGlobales::ancho / 2;
    VariablesGlobales::snakeY = VariablesGlobales::alto / 2;
    VariablesGlobales::manzanaX = rand() % VariablesGlobales::ancho;
    VariablesGlobales::manzanaY = rand() % VariablesGlobales::alto;
}

/// DIBUJA EL MAPA CON LA SERPIENTE Y MANZANA
void Dibujar()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < VariablesGlobales::ancho + 2; i++)
    {
        rlutil::locate(10+i, 4);                                                        ///DIBUJA LA LINEA INICIAL

        rlutil::setBackgroundColor(15);
        std::cout << " ";
        rlutil::setBackgroundColor(0);
    }
    std::cout << std::endl;

    for (int i = 0; i < VariablesGlobales::alto; i++)
    {
        for (int j = 0; j < VariablesGlobales::ancho; j++)
        {
            if (j == 0)
            {
                rlutil::setBackgroundColor(15);                                         ///DIBUJA LA LINEA INICIAL IZQUIERDA
                rlutil::locate(10, 5 + i);
                std::cout << ' ';
            }
            if (i == VariablesGlobales::snakeY && j == VariablesGlobales::snakeX)
            {
                rlutil::locate(11 + j, 5 + i);                                          ///DIBUJA LA CABEZA DE LA SERPIENTE

                rlutil::setBackgroundColor(9);
                std::cout << " ";
            }
            else if (i == VariablesGlobales::manzanaY && j == VariablesGlobales::manzanaX)
            {
                ///DIBUJA LA MANZANA
                rlutil::locate(11 + j, 5 + i);
                rlutil::setBackgroundColor(4);
                std::cout << " ";
            }
            else
            {
                bool printTail = false;                                                 ////DIBUJA LA COLA
                for (int k = 0; k < VariablesGlobales::tamanoTail; k++)
                {
                    if (VariablesGlobales::snakeTailX[k] == j && VariablesGlobales::snakeTailY[k] == i)
                    {
                        rlutil::locate(11 + j, 5 + i);

                        rlutil::setBackgroundColor(1);
                        std::cout << " ";
                        printTail = true;
                        break;
                    }
                }
                if (!printTail)
                {
                    rlutil::locate(11 + j, 5 + i);                              ///DIBUJA TODO EL RESTO (ESPACIO)
                    rlutil::setBackgroundColor(2);
                    std::cout << " ";
                    rlutil::setBackgroundColor(2);

                }
            }
            if (j == VariablesGlobales::ancho - 1)
            {
                ///DIBUJA LA LINEA FINAL DERECHA
                rlutil::locate(12 + j, 5 + i);
                rlutil::setBackgroundColor(15);
                std::cout << " ";
                rlutil::setBackgroundColor(0);

            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < VariablesGlobales::ancho + 2; i++)
    {
        rlutil::locate(10+i, 25);                                               ///DIBUJA LA LINEA FINAL
        rlutil::setBackgroundColor(15);
        std::cout << " ";
        rlutil::setBackgroundColor(0);
    }
    std::cout << std::endl;
}


/// ES PARA LOS CAMBIOS DE DIRECCION DE LA SERPIENTE
void Input()
{
    if (kbhit())
    {
        switch (getch())                                                   ///MOVIMIENTO DE LA SERPIENTE
        {
        case 'w':
            dir = ARRIBA;
            break;
        case 's':
            dir = ABAJO;
            break;
        case 'a':
            dir = IZQUIERDA;
            break;
        case 'd':
            dir = DERECHA;
            break;
        case 'x':
            dir = STOP;
            break;
        }
    }
}

/*  ACA ESTA EL CODIGO PARA EL MOVIMIENTO DE LA COLA DE LA SERPIENTE, DONDE VA GUARDANDO SUS POSICIONES PREVIAS

    PARA EJECUTAR EL INPUT(CAMBIOS DE DIRECCIONES)

    COLISION CON LA COLA

    COME LA MANZANA ---> LO QUE HACE CUANDO COME LA MANZANA

    AUMENTA EL TAMAÑO DE LA SERPIENTE, AGREGANDO LA POSICION A LA COLA DE LA SERPIENTE

* */
void Algoritmo()
{
    int prevX = VariablesGlobales::snakeTailX[0];                                      ///ALGORITMO PARA EL MOVIMIENTO DE LA COLA
    int prevY = VariablesGlobales::snakeTailY[0];
    int prev2X, prev2Y;                                             ///VA GUARDANDO LAS POSICIONES DE LA COLA EN PREV Y PREV2
    VariablesGlobales::snakeTailX[0] = VariablesGlobales::snakeX;
    VariablesGlobales::snakeTailY[0] = VariablesGlobales::snakeY;
    for (int i = 1; i < VariablesGlobales::tamanoTail; i++)
    {
        prev2X = VariablesGlobales::snakeTailX[i];
        prev2Y = VariablesGlobales::snakeTailY[i];
        VariablesGlobales::snakeTailX[i] = prevX;
        VariablesGlobales::snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case ARRIBA:
        VariablesGlobales::snakeY--;
        break;                                                      ///CAMBIA DE DIRECCION --- OTRA PARTE DEL MOVIMIENTO
    case ABAJO:
        VariablesGlobales::snakeY++;
        break;
    case IZQUIERDA:
        VariablesGlobales::snakeX--;
        break;
    case DERECHA:
        VariablesGlobales::snakeX++;
        break;
    default:
        break;
    }

    if (VariablesGlobales::snakeX >= VariablesGlobales::ancho)VariablesGlobales::tamano = 0;
    else if (VariablesGlobales::snakeX < 0) VariablesGlobales::tamano = 0;

    if (VariablesGlobales::snakeY >= VariablesGlobales::alto) VariablesGlobales::tamano = 0;
    else if (VariablesGlobales::snakeY < 0) VariablesGlobales::tamano = 0;

    for (int i = 0; i < VariablesGlobales::tamanoTail; i++)
        if (VariablesGlobales::snakeTailX[i] == VariablesGlobales::snakeX && VariablesGlobales::snakeTailY[i] == VariablesGlobales::snakeY)
        {
            VariablesGlobales::tamano = 0;                                                         ///COLISIÓN CON LA COLA
        }

    if (VariablesGlobales::snakeX == VariablesGlobales::manzanaX && VariablesGlobales::snakeY == VariablesGlobales::manzanaY)
    {
        VariablesGlobales::tamano++;
        VariablesGlobales::speed += 5;                                                              ///COME LA MANZANA
        VariablesGlobales::score++;
        if (VariablesGlobales::speed == 100)
        {
            VariablesGlobales::speed = 95;
        }
        VariablesGlobales::manzanaX = rand() % VariablesGlobales::ancho;                                              ///DIBUJA NUEVA POSICION DE LA MANZANA CUANDO LA COME
        VariablesGlobales::manzanaY = rand() % VariablesGlobales::alto;
        VariablesGlobales::tamanoTail++;                                                           /// AUMENTA EL TAMAÑO DE LA SERPIENTE
        VariablesGlobales::snakeTailX[VariablesGlobales::tamanoTail - 1] = VariablesGlobales::snakeTailX[VariablesGlobales::tamanoTail - 2];                /// AGREGA UNA NUEVA POSICION A LA COLA
        VariablesGlobales::snakeTailY[VariablesGlobales::tamanoTail - 1] = VariablesGlobales::snakeTailY[VariablesGlobales::tamanoTail - 2];                /// AGREGA UNA NUEVA POSICION A LA COLA

    }
}


/// FUNCION PARA LA PELEA QUE INCLUYE TODOS LOS ALGORITMOS HECHOS ---> VA AL .cpp
int pelea()
{
    rlutil::hidecursor();
    Setup();

    /// BUCLE PARA EL INICIO DEL SNAKE
    for (int i = 0; i < 3; i++)
    {
        if (VariablesGlobales::pjVida == 0)
        {
            rlutil::cls();

            VariablesGlobales::primer_pelea = false;
            VariablesGlobales::escenagato_pelea = 0;
            VariablesGlobales::escena_pierde = 0;
            break;
        }
        while (VariablesGlobales::tamano != 0)
        {
            Dibujar();
            Input();
            Algoritmo();
            rlutil::locate(12, 27);
            std::cout << "TU PUNTAJE ES: " << VariablesGlobales::score;
            rlutil::locate(15, 28);

            std::cout << "VIDAS --> " << VariablesGlobales::pjVida;
            rlutil::msleep(100 - VariablesGlobales::speed);                                            ///PARA LA VELOCIDAD DE LA SERPIENTE


            /// CUANDO EL JUGADOR GANA
            if (VariablesGlobales::score == 30)
            {
                rlutil::locate(12, 28);
                std::cout << "                  ";
                rlutil::locate(8, 28);
                std::cout << "MUY BIEN GANASTE!";
                VariablesGlobales::primer_pelea = false;
                VariablesGlobales::escenagato_pelea = 0;
                rlutil::cls();
                VariablesGlobales::escena_ganaPP = 0;
                break;
            }

        }

        /// CUANDO PIERDE
        if (VariablesGlobales::tamano == 0)
        {
            rlutil::locate(1, 29);
            std::cout << "Perdiste, presiona 'e' para volver a intentar";
            char newTry = getch();
            if (newTry == 'e')
            {
                VariablesGlobales::tamano = 1;
                VariablesGlobales::pjVida--;
                VariablesGlobales::tamanoTail = 0;
                VariablesGlobales::speed = 0;
                VariablesGlobales::score = 0;
                rlutil::locate(1, 29);
                std::cout << "                                             ";
                break;
            }

        }

    }
    return 0;
}



#endif
