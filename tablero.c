/*
=======================================================
Name : Buscaminas_IP
Author : Alvaro Tena
Created on: 11 dic. 2017
Description : 
=======================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tablero.h"

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)


char ** crearTablero(int * dificultad){
	int NumFilas = dificultad[0];
	int NumColumnas = dificultad[1];
	int NumMinas = dificultad[2];
	char ** tablero;
	tablero = (char **) malloc(NumFilas * sizeof(char *));
	if(tablero == NULL){
		fprintf(stderr, "Sin memoria.");
		fflush(0);
		exit(-1);
	}
	int i;
	for(i=0; i<NumFilas; i++){
		tablero[i] = (char *) malloc(NumColumnas * sizeof(char));
		if(tablero[i] == NULL){
			fprintf(stderr, "Sin memoria.");
			fflush(0);
			exit(-1);
		}
	}

	rellenarTablero(tablero, NumColumnas, NumFilas, NumMinas);

	return tablero;
}

char ** crearTableroJugador(int * dificultad){
	int NumFilas = dificultad[0];
	int NumColumnas = dificultad[1];
	char ** tableroJugador;
	tableroJugador = (char **) malloc(NumFilas * sizeof(char *));
	if(tableroJugador == NULL){
		fprintf(stderr, "Sin memoria.");
		fflush(0);
		exit(-1);
	}
	int i,j;
	for(i=0; i<NumFilas; i++){
		tableroJugador[i] = (char *) malloc(NumColumnas * sizeof(char));
		if(tableroJugador[i] == NULL){
			fprintf(stderr, "Sin memoria.");
			fflush(0);
			exit(-1);
		}
	}


	for(i=0; i<NumFilas; i++){
		for(j=0; j<NumColumnas; j++){
			tableroJugador[i][j] = ' ';
		}
	}

	return tableroJugador;
}


void rellenarTablero(char ** tablero, int NumColumnas, int NumFilas, int NumMinas){
	int i,j;
	for(i=0; i<NumFilas; i++){
		for(j=0; j<NumColumnas; j++){
			tablero[i][j] = '0';
		}
	}

	srand(time(NULL));
	int Fila, Columna;
	for(i=0; i<NumMinas; i++){
		Fila = rand() % NumFilas;
		Columna = rand() % NumColumnas;
		if(tablero[Fila][Columna] == '0'){
			tablero[Fila][Columna] = 'X';
		}else{
			i--;
		}
	}

	for(i=0; i<NumFilas; i++){
		for(j=0; j<NumColumnas; j++){
			if(tablero[i][j] == 'X'){
				int k, s;
				for(k=MAX(0, i-1); k<=MIN(NumFilas-1, i+1); k++){
					for(s=MAX(0, j-1); s<=MIN(NumColumnas-1, j+1); s++){
						int minasCerca = tablero[k][s] - '0';
						if(tablero[k][s] != 'X'){
							minasCerca++;
							tablero[k][s] = minasCerca + '0';
						}
					}
				}
			}
		}
	}
}

void limpiarTableros(char ** tablero, char ** tableroJugador, int * dificultad){
	int NumFilas = dificultad[0];

	int i;
	for(i=0; i<NumFilas; i++){
		free(tablero[i]);
	}
	free(tablero);

	for(i=0; i<NumFilas; i++){
		free(tableroJugador[i]);
	}
	free(tableroJugador);

	free(dificultad);

}
