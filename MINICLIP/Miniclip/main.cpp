#include <iostream>
///LIBRERIA PARA UBICAR EN PANTALLA Y DEMAS COSAS
#include "rlutil.h"
#include <cstdlib>

///LIBRERIA --- LA USO PARA MODIFICAR EL CMD Y SACAR EL DELAY CUANDO RE IMPRIME LAS MATRICES
#include <windows.h>

///LA UTILIZO PARA EL SNAKE
#include <time.h>

///PARA LA CLASE STRING
#include <string>

///REMARCA LOS SELECTORES EN LAS OPCIONES
#include "showItem.h"

///INCLUYE EL MENU
#include "menu.h"

///INCLUYE LOS MAPAS
#include "maps.h"

///INCLUYE EL MOVIMIENTO DEL JUGADOR EN LOS MAPAS
#include "movimiento.h"

///INCLUYE EL MINIJUEGO SNAKE
#include "fight.h"

///INCLUYE LAS MATRICES Y PARA IMPRIMIR LOS GATOS
#include "gato_guia.h"

///INCLUYE LOS TEXTOS DE LOS GATOS
#include "textoGato.h"

///INCLUYE LAS VARIABLES GLOBALES
#include "variables.h"

///PONER MUSICA
#pragma comment(lib, "winmm.lib")

void setVolume(WORD left, WORD right)
{
    DWORD volume = MAKELPARAM(left, right);
    waveOutSetVolume(0, volume); // 0 representa el dispositivo de audio predeterminado
}
void setMusic()
{
    // MUSICA
    setVolume(0x1000, 0x1000);
    char soundfile[] = "C:\musica.wav";
    PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);
}

void setMusic2()
{
    // MUSICA
    setVolume(0x1000, 0x1000);
    char soundfile[] = "C:\musica2.wav";
    PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);
}

void gato()
{
     char soundfile[] = "C:\gato.wav";
    PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);

}

void arbolSound()
{
    char soundfile[] = "C:\caido.wav";
    PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);

}



///EMPIEZA

int main()
{

    ///MUSICA

    setMusic();


    // PARA EL TAMAÑO DE LA CONSOLA
    HWND hwnd = GetConsoleWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, 0, 0, 1410, 620, TRUE);

    // Obtener los estilos actuales de la ventana
    LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        return 1;
    }

    ///ELIJE EL TAMAÑO Y ESTILO DE FUENTE
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 10;                   // Ancho de la fuente
    cfi.dwFontSize.Y = 18;                  // Alto de la fuente
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Terminal");

    if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi))
    {
        return 1;
    }

    // ELIMINA LA POSIBILIDAD DE REDIMENSIONAR EL CMD
    lStyle = lStyle & ~(WS_SIZEBOX | WS_MAXIMIZEBOX);
    SetWindowLong(hwnd, GWL_STYLE, lStyle);

    // REDIBUJA LA CMD APLICANDO LOS ESTILOS
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);

    rlutil::hidecursor();
    menu();

    //PRIMER NIVEL/ESCENA

    int escena1 = 0;
    do
    {
        rlutil::hidecursor();

        imprimirMapa();

        moverPersonaje();

        if (VariablesGlobales::posy == filas - 1)       //TERMINA LA ESCENA CUANDO BAJA AL FINAL DEL PASILLO
        {
            escena1 = 1;
        }

        rlutil::msleep(1);

    }
    while (escena1 == 0);

    //TERMINA PRIMER ESCENA




    ////SEGUNDA ESCENA

    ///REINICIO LA POSICION EN X Y Y PARA LA SIGUIENTE ESCENA
    VariablesGlobales::posy = 1;
    VariablesGlobales::posx = 43;
    do
    {
        rlutil::hidecursor();
        imprimirMapa2();          ///IMPRIME MAPA 2

        moverPersonaje2();


        decisionGato_inicial();
        if (VariablesGlobales::posy == 3 && VariablesGlobales::arbolcaido==false)
        {
            arbolSound();
            VariablesGlobales::mapa2[1][44] = 3;
            VariablesGlobales::mapa2[1][43] = 3;
            VariablesGlobales::mapa2[1][42] = 3;
            VariablesGlobales::mapa2[1][41] = 3;
            VariablesGlobales::mapa2[2][40] = 4;
            VariablesGlobales::mapa2[1][40] = 4;
            VariablesGlobales::mapa2[1][39] = 4;
            VariablesGlobales::mapa2[0][39] = 4;
            VariablesGlobales::mapa2[1][38] = 4;
            VariablesGlobales::arbolcaido = true;
            Sleep(4000);
            setMusic();
            VariablesGlobales::arbolCaidoSound==false;
        }


        else if(VariablesGlobales::posy == 2 && VariablesGlobales::arbolcaido==true)
        {
            rlutil::locate(95, 14);
            std::cout << "Parece que se cayo un arbol y no puedes pasar...";

        }
        else
        {
            rlutil::locate(95, 14);
            std::cout << "                                                ";
        }


        rlutil::msleep(1);

    }
    while (VariablesGlobales::escena2 == 0);

    rlutil::hidecursor();
    rlutil::cls();

    ////ESCENA PRIMER DIALOGO CON EL GATO

    for (int i = 0; i < 1; i++)

    {
        imprimirGato_guia(VariablesGlobales::gato_guia, filas, columnas);
        rlutil::hidecursor();
        gato();

        do
        {
            primerTextoGato();

        }
        while (VariablesGlobales::escenagato == 0);
        rlutil::cls();
    }
    ////TERMINA ESCENA PRIMER DIALOGO CON EL GATO



    ////ESCENA PEELEA CON EL GATO
    do
    {
        imprimirGato_guia(VariablesGlobales::gato_guia2, filas, columnas);
        rlutil::hidecursor();
        textGato();
        ///TERMINA PARTE DE TEXTO, EMPIEZA EL MINIJUEGO
        while (VariablesGlobales::primer_pelea == true)
        {
            rlutil::hidecursor();
            imprimirGato_guiaPelea(VariablesGlobales::gato_guia2,filas,columnas);
            setMusic2();
            pelea();

        }




    }
    while (VariablesGlobales::escenagato_pelea == 1);
    ///TERMINA ESCENA GATO


    ///ESCENA SI GANASTE
    while (VariablesGlobales::escena_ganaPP == 0)
    {
        gato();
        imprimirGato_guia(VariablesGlobales::gato_guia_happy, filas, columnas);
        textoGana();
    }

    ///ESCENA SI PERDES
    while (VariablesGlobales::escena_pierde == 0)
    {
        gato();
        imprimirGato_guia(VariablesGlobales::gato_guia, filas, columnas);
        textoPerdiste();
    }


    ///TERCER ESCENA
    while (VariablesGlobales::escena3 == 1)
    {

        imprimirMapa3();
        setMusic();
        moverPersonaje3();

        if(VariablesGlobales::posy == 2)
        {
            rlutil::locate(95, 14);
            std::cout << "Parece que se cayo un arbol y no puedes pasar...";

        }
        else
        {
            rlutil::locate(95, 14);
            std::cout << "                                                ";
        }

        if (VariablesGlobales::posy == filas - 1)
        {
            VariablesGlobales::escena3 = 0;
            rlutil::cls();
            VariablesGlobales::gana=1;
        }
    }
    ///TERMINA 3ER ESCENA

    ///CONTINUARA
    if(VariablesGlobales::gana==1)
    {
        continuara();
    }

    rlutil::locate(1, 29);
    system("pause");

    rlutil::locate(1, 30);

    return 0;
}
