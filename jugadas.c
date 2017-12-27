/*
=======================================================
Name : Buscaminas_IP
Author : Tena
Created on: 14 dic. 2017
Description :
=======================================================
*/

#include <stdio.h>
#include "salida.h"
#include "jugadas.h"

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

void detectarMina(char ** tableroJugador, char ** tablero, int * NumMinas, int * NumMinasDetectadas) {
	int Fila;
	int Columna;
	int elegir = 1;
	while (elegir == 1) {
		printf("Elige la fila de la casilla que quieras marcar como mina: ");
		fflush(0);
		scanf("%d", &Fila);
		printf("Elige la columna de la casilla que quieras marcar como mina: ");
		fflush(0);
		scanf("%d", &Columna);
		Fila--;
		Columna--;

		if (tableroJugador[Fila][Columna] == 'P') {
			tableroJugador[Fila][Columna] = ' ';
			*NumMinas += 1;
			if (tablero[Fila][Columna] == 'X') {
				*NumMinasDetectadas -= 1;
			}
			elegir = 0;
		}
		else if (tableroJugador[Fila][Columna] == ' ') {
			tableroJugador[Fila][Columna] = 'P';
			*NumMinas -= 1;
			if (tablero[Fila][Columna] == 'X') {
				*NumMinasDetectadas += 1;
			}
			elegir = 0;
		}
		else {
			fprintf(stderr, "Selecciona una casilla valida, por favor.\n");
			fflush(0);
		}
	}
}

void probarCasilla(char ** tableroJugador, char ** tablero, int * dificultad, int * juego, int NumMinas) {
	int Fila = 1;
	int Columna = 1;
	int elegir = 1;

	while (elegir == 1) {
		printf("Elige la fila de la casilla que quieras descubrir: ");
		fflush(0);
		scanf("%d", &Fila);
		printf("Elige la columna de la casilla que quieras descubrir: ");
		fflush(0);
		scanf("%d", &Columna);
		Fila--;
		Columna--;
		if (tableroJugador[Fila][Columna] == 'P') {
			printf("No puedes descubrir una casilla que previamente has marcado como mina.\n");
			fflush(0);
		}
		else if (tablero[Fila][Columna] == 'X') {
			printf("\n\nVaya! Una mina exploto...\nHas perdido!!");
			fflush(0);
			mostrarTablero(tablero, dificultad, dificultad[2]);
			printf("\n\n");
			*juego = 0;
			elegir = 0;
		}
		else if (tableroJugador[Fila][Columna] == ' ' && tablero[Fila][Columna] != 'X' && tablero[Fila][Columna] != '0') {
			tableroJugador[Fila][Columna] = tablero[Fila][Columna];
			elegir = 0;
		}
		else {
			destaparCasillas(Fila, Columna, tableroJugador, tablero, dificultad);
			elegir = 0;
		}
	}
}

void destaparCasillas(int Fila, int Columna, char ** tableroJugador, char ** tablero, int * dificultad) {
	int NumFilas = dificultad[0];
	int NumColumnas = dificultad[1];

	tableroJugador[Fila][Columna] = tablero[Fila][Columna];

	int k, s;
	for (k = MAX(0, Fila - 1); k <= MIN(NumFilas - 1, Fila + 1); k++) {
		for (s = MAX(0, Columna - 1); s <= MIN(NumColumnas - 1, Columna + 1); s++) {
			if ((k != Fila || s != Columna) && tableroJugador[k][s] != 'P' && tableroJugador[k][s] == ' ' && tablero[k][s] == '0') {
				destaparCasillas(k, s, tableroJugador, tablero, dificultad);
			}
			else if ((k != Fila || s != Columna) && tableroJugador[k][s] != 'P' && tableroJugador[k][s] == ' ' && tablero[k][s] != '0') {
				tableroJugador[k][s] = tablero[k][s];
			}
		}
	}
}
