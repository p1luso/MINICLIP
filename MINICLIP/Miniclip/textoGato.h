#ifndef FUNCIONES_TEXTGATO_INCLUDED
#define FUNCIONES_TEXTGATO_INCLUDED



///FUNCIONES QUE ENGLOBA EL TEXTO DEL GATO ANTES DE LA PELEA
void textGato()
{
    ///VARIABLES PARA EL TEXTO QUE EXPLICA LA PELEA
    bool band_primerTexto = true, band_segundoTexto = true, band_terceroTexto = true, band_borrartexto = true, band_cuartoTexto = true, band_quintoTexto = true;

    rlutil::locate(92, 13);

    std::cout << "Deberas de ir superando minijuegos para ganar" << std::endl;
    int opGatoSkip = rlutil::getkey();

    if (opGatoSkip == 1)
    {
        rlutil::locate(92, 13);
        std::cout << "                                             " << std::endl;
    }


    int keyPlayer = rlutil::getkey();

    if(keyPlayer == 1)
    {
        ///TEXTO CUANDO PRESIONA EL "ENTER"
        if (band_primerTexto == true)
        {
            rlutil::locate(98, 13);
            std::cout << "El primer minijuego es un SNAKE" << std::endl;

            rlutil::locate(99, 17);
            std::cout << "Presiona Enter para continuar..." << std::endl;
            keyPlayer = rlutil::getkey();
            band_primerTexto = false;
        }
        if (keyPlayer == 1 && band_segundoTexto == true)
        {
            rlutil::locate(98, 13);
            std::cout << "                               " << std::endl;

            rlutil::locate(98, 13);
            std::cout << "Basicamente deberas de ir comiendo" << std::endl;

            rlutil::locate(100, 14);
            std::cout << " las manzanas que aparecen" << std::endl;

            keyPlayer = rlutil::getkey();
            band_segundoTexto = false;
        }

        if (keyPlayer == 1 && band_cuartoTexto == true)
        {
            rlutil::locate(98, 13);
            std::cout << "                                  " << std::endl;

            rlutil::locate(100, 14);
            std::cout << "                          " << std::endl;

            rlutil::locate(97, 13);
            std::cout << "Lo que aumentara la longitud de la SNAKE" << std::endl;

            rlutil::locate(101, 14);
            std::cout << " y la velocidad de movimiento" << std::endl;

            keyPlayer = rlutil::getkey();
            band_cuartoTexto = false;
        }

        if (keyPlayer == 1 && band_quintoTexto == true)
        {
            rlutil::locate(97, 13);
            std::cout << "                                        " << std::endl;

            rlutil::locate(101, 14);
            std::cout << "                             " << std::endl;

            rlutil::locate(97, 13);
            std::cout << "Y no puede chocarte con las paredes" << std::endl;

            rlutil::locate(98, 14);
            std::cout << " ni tampoco con tu propio cuerpo" << std::endl;

            keyPlayer = rlutil::getkey();
            band_quintoTexto = false;
        }

        if (keyPlayer == 1 && band_terceroTexto == true)
        {
            rlutil::locate(97, 13);
            std::cout << "                                   " << std::endl;
            rlutil::locate(98, 14);
            std::cout << "                                " << std::endl;
            rlutil::locate(110, 13);
            std::cout << "Suerte..." << std::endl;
            band_terceroTexto = false;
            keyPlayer = rlutil::getkey();
        }

        if (keyPlayer == 1 && band_borrartexto == true)
        {
            rlutil::cls();
        }
    }
    VariablesGlobales::primer_pelea = true;
}

void decisionGato_inicial()
{
    while (VariablesGlobales::decisionGato == 0)
    {
        rlutil::locate(91, 10);
        std::cout << "Ups... Te has encontrado con algo que parece...";
        rlutil::locate(91, 11);
        std::cout << "UN GATO?";
        rlutil::locate(91, 12);
        std::cout << "Deseas hablar con el?";

        showItem(" Si ", 95, 14, VariablesGlobales::opx == 0);
        showItem(" No ", 120, 14, VariablesGlobales::opx == 26);


        VariablesGlobales::opGato = rlutil::getkey();
        switch (VariablesGlobales::opGato)
        {
        case 17:                            ///MUEVE LA SELECCION EN EL MENU HACIA LA IZQUIERDA
            rlutil::locate(93 + VariablesGlobales::opx, 14);
            std::cout << " " << std::endl;
            if (VariablesGlobales::opx < 0)
            {
                VariablesGlobales::opx = 0;
            }
            rlutil::locate(102 + VariablesGlobales::opx, 14);
            std::cout << " " << std::endl;
            VariablesGlobales::opx = VariablesGlobales::opx + 26;
            break;

        case 16:                                ///MUEVE LA SELECCION EN EL MENU HACIA LA DERECHA

            if (VariablesGlobales::opx > 26)
            {
                VariablesGlobales::opx = 26;
            }

            VariablesGlobales::opx = VariablesGlobales::opx - 26;
            break;


        case 1:                                 ///CUANDO EL USUARIO PRESIONA "ENTER"
            if (VariablesGlobales::opx == 0)                           ///PRESIONA SI EMPIEZA A HABLAR CON EL GATO
            {
                rlutil::cls();
                VariablesGlobales::decisionGato = 1;
                VariablesGlobales::escena2 = 1;
            }
            else if (VariablesGlobales::opx == 26)

            {
                VariablesGlobales::decisionGato = 1;
                rlutil::locate(91, 10);
                std::cout << "                                               ";
                rlutil::locate(91, 11);
                std::cout << "        ";
                rlutil::locate(91, 12);
                std::cout << "                     ";
                rlutil::locate(93, 14);
                std::cout << "                     ";
                rlutil::locate(119, 14);
                std::cout << "                     ";


            }

            break;
        default:

            break;
        }
    }
}

void primerTextoGato()
{
    rlutil::locate(97, 13);
    std::cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZ" << std::endl;
    int opGatoSkip = rlutil::getkey();
    bool textoGato = true;
    while (textoGato == true)
    {
        if (opGatoSkip == 1)                                                       ////TOCAR ENTER PARA PASAR DE DIALOGO
        {
            rlutil::locate(97, 13);
            std::cout << "                              " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Oh, Hola! Me despertaste!" << std::endl;
        }

        opGatoSkip = rlutil::getkey();

        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                                 " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Veo que te encuentras perdido..." << std::endl;
        }

        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                                " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Decime tu nombre" << std::endl;

            rlutil::locate(97, 14);

            std::cout << "Ingrese su nombre ----> ";

            rlutil::locate(121, 14);
            std::cin >> VariablesGlobales::nombreJugador;
        }
        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 14);
            std::cout << "                                 " << std::endl;

            rlutil::locate(97, 13);
            std::cout << "                                 " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Que lindo nombre " << VariablesGlobales::nombreJugador << "!" << std::endl;


        }
        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                            " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Aparentemente no sabes donde estas";
        }
        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                                        " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Estas en una zona peligrosa... " << std::endl;

        }
        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                                 " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Tendre que explicarte como jugar" << std::endl;

        }
        opGatoSkip = rlutil::getkey();
        textoGato = false;
    }
}

///TEXTO PARA CUANDO PERDES EL MINIJUEGO

void textoPerdiste()
{
    bool textoGato = true;
    rlutil::locate(97, 13);
    std::cout<< "Presione enter";
    while (textoGato == true)
    {
        int opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)                                                       ////TOCAR ENTER PARA PASAR DE DIALOGO
        {
            rlutil::locate(97, 13);
            std::cout << "                              " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Oooh nooo!" << std::endl;
        }

        opGatoSkip = rlutil::getkey();

        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                                 " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Veo que has perdido..." << std::endl;
        }

        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                      " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Espero verte de nuevo por aqui!" << std::endl;

            rlutil::locate(97, 16);
            std::cout << "Mucha suerte ----> "<< VariablesGlobales::nombreJugador<<"!";


        }

        opGatoSkip = rlutil::getkey();
        textoGato = false;

    }
    rlutil::cls();
    system("exit");
    VariablesGlobales::escena_pierde = 1;
}

void textoGana()
{
    bool textoGato = true;
    rlutil::locate(97, 13);
    std::cout << "Presione enter";
    while (textoGato == true)
    {
        int opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)                                                       ////TOCAR ENTER PARA PASAR DE DIALOGO
        {
            rlutil::locate(97, 13);
            std::cout << "                              " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Oooh muy bien!" << std::endl;
        }

        opGatoSkip = rlutil::getkey();

        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                                 " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Veo que has ganado..." << std::endl;
        }

        opGatoSkip = rlutil::getkey();
        if (opGatoSkip == 1)
        {
            rlutil::locate(97, 13);
            std::cout << "                      " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Sigue el camino y veras lo que te espera!" << std::endl;

            rlutil::locate(97, 16);
            std::cout << "Mucha suerte ----> " << VariablesGlobales::nombreJugador << "!";


        }
        opGatoSkip = rlutil::getkey();
        textoGato = false;

    }
    rlutil::cls();
    VariablesGlobales::escena3 = 1;
    VariablesGlobales::escena_ganaPP = 1;


}


///TEXTO PARA EL GATO LUEGO DE HABER JUGADO EL PRIMER MINIJUEGO
void textoGatoDespues()
{
    bool textoGato = true;
    while (textoGato == true)
    {
        int opGatoSkip = rlutil::getkey();
        if (opGatoSkip != 97)
        {
            rlutil::locate(97, 13);
            std::cout << "                      " << std::endl;
            rlutil::locate(97, 13);
            std::cout << "Ya estuviste aqui" << std::endl;
            rlutil::locate(97, 16);
            std::cout << "Sigue tu camino " << VariablesGlobales::nombreJugador << "!";
            opGatoSkip = rlutil::getkey();
            if (opGatoSkip != 97)
            {
                rlutil::locate(97, 13);
                std::cout << "                 ";
                rlutil::locate(97, 16);
                std::cout << "                             ";
                textoGato = false;
            }
        }
    }
}

#endif ///FUNCIONES_TEXTOGATO_INCLUDED
