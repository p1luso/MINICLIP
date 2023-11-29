#include "funciones.h"
#ifndef FUNCIONES_MENU_INCLUDED
#define FUNCIONES_MENU_INCLUDED


void menu()
{
    int opy = 0, op = 1;

    recuadro(23, 4, 70, 20, 15, 0);      ///RECUADRO

    ///MENU
    do
    {
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);


        showItem("  JUGAR   ", 55, 11, opy == 0);
        rlutil::locate(55, 12);
        std::cout << "----------" << std::endl;

        showItem(" CONTROLS ", 55, 13, opy == 2);

        rlutil::locate(55, 14);
        std::cout << "----------" << std::endl;

        showItem(" EXIT ", 57, 15, opy == 4);



        rlutil::locate(53, 11 + opy);
        std::cout << (char)175 << std::endl;

        rlutil::locate(66, 11 + opy);

        std::cout << (char)174 << std::endl;


        ///ELEGIR OPCIONES
        int key = rlutil::getkey();
        switch (key)
        {
        case 14:                            ///MUEVE LA SELECCION EN EL MENU HACIA ARRIBA
            rlutil::locate(53, 11 + opy);
            std::cout << " " << std::endl;

            if (opy < 0)
            {
                opy = 0;
            }
            rlutil::locate(66, 11 + opy);
            std::cout << " " << std::endl;
            opy = opy - 2;
            if (opy < 0)
            {
                opy = 0;
            }
            break;
        case 15:                                ///MUEVE LA SELECCION EN EL MENU HACIA ABAJO
            rlutil::locate(53, 11 + opy);
            std::cout << " " << std::endl;
            if (opy > 2)
            {
                opy = 2;
            }


            rlutil::locate(66, 11 + opy);
            std::cout << " " << std::endl;
            if (opy > 2)
            {
                opy = 2;
            }
            opy = opy + 2;
            break;
        case 1:                                 ///CUANDO EL USUARIO PRESIONA "ENTER"
            if (opy == 4)
            {
                ///SI LO PRESIONA EN LA OPCION EXIT --> SALE DEL JUEGO
                rlutil::cls();
                exit(EXIT_SUCCESS);
            }
            else if (opy == 0)                           ///SI LO PRESIONA EN LA OPCION JUGAR --->RESETEA LA PANTALLA Y SALE DEL BUCLE A LA SIGUIENTE FASE
            {
                rlutil::cls();
                op = 0;
            }
            break;
        default:

            break;
        }

    }
    while (op != 0);
}
#endif
////TERMINA MENU
