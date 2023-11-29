#pragma once
#include <string>

#ifndef MAPA_VARIABLES_H
#define MAPA_VARIABLES_H


namespace VariablesGlobales
{

///TAMAÑO MAPA
const int filas = 29;
const int columnas = 89;

///VARIABLES POSICION JUGADOR
extern int posx;
extern int posy;

///MATRICES DE LOS MAPAS
extern int mapa[filas][columnas];
extern int mapa2[filas][columnas];
extern int mapa3[filas][columnas];

///MATRICES DE LOS GATOS
extern int gato_guia[filas][columnas];
extern int gato_guia2[filas][columnas];
extern int gato_guia_happy[filas][columnas];

/// POSICION MANZANA
extern int manzanaX, manzanaY;

/// TAMAÑO DEL JUEGO SNAKE
extern int ancho;
extern int alto;

/// POSICION DE LA SNAKE
extern int snakeX, snakeY;

/// CONDICION BUCLE
extern int tamano;

/// TAMAÑO DE LA TAIL DE LA SNAKE --- ESPACIO EN MEMORIA PARA GUARDAR LAS POSICIONES Y VALORES
extern int snakeTailX[100], snakeTailY[100];

/// TAMAÑO DE LA TAIL --- PARA SABER HASTA DONDE TIENE QUE EJECUTARSE EL BUCLE QUE PINTA EL ARRAY DE LA COLA
extern int tamanoTail;

/// AUMENTA LA VELOCIDAD EN EL JUEGO
extern int speed;

///PUNTUACION
extern int score;

/// VIDAS
extern int pjVida;

///VARIABLES ESCENA PELEA
extern int escenagato_pelea;
extern bool primer_pelea;

///VARIABLES ESCENA GATO --> OPCION PELEA
extern int opx;
extern int opGato;
extern int decisionGato;
extern int escena2;

///VARIABLES PARA PRIMER TEXTO DEL GATO
extern int escenagato, escenaGato_pelea, opcionGato_pelea;
extern std::string nombreJugador;

///VARIABLE ESCENA 3
extern int escena3;

///PARA CUANDO GANA EL MINIJUEGO
extern int escena_ganaPP ;

///VARIABLE PARA CUANDO PIERDE EL MINIJUEGO
extern int escena_pierde;

///VARIABLE PARA EL ARBOL CAIDO EN ESCENA 2
extern bool arbolcaido;

///VARIABLE PARA CUADNO GANA --> EJECUTA CONTINUARA ()
extern int gana;

///VARIABLE PARA ARBOL CAIDO SONIDO
extern bool arbolCaidoSound;

///REANUDAR MUSICA
extern bool music;
}

#endif  ///MAPA_VARIABLES_H
