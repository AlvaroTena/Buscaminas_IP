/*
=======================================================
Name : Buscaminas_IP
Author : Alvaro Tena
Created on: 14 dic. 2017
Description :
=======================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "saves.h"

void guardarPartida(char ** tableroJugador, char ** tablero, int * dificultad, int  *NumMinas, int * NumMinasDetectadas) {
	FILE * guardado = fopen("partidaGuardada.ip", "wb");
	if (guardado == NULL) {
		fprintf(stderr, "Error al guardar la partida");
	}
	fwrite(dificultad, sizeof(int *), 3, guardado);
	fwrite(NumMinas, sizeof(int), 1, guardado);
	fwrite(NumMinasDetectadas, sizeof(int), 1, guardado);
	int i, j;
	for (i = 0; i<dificultad[0]; i++) {
		for (j = 0; j<dificultad[1]; j++) {
			fwrite(&tableroJugador[i][j], sizeof(char**), 1, guardado);
		}
	}
	for (i = 0; i<dificultad[0]; i++) {
		for (j = 0; j<dificultad[1]; j++) {
			fwrite(&tablero[i][j], sizeof(char**), 1, guardado);
		}
	}
	fclose(guardado);
}

void cargarPartida(FILE * cargado, char ** tableroJugador, char ** tablero, int * dificultad, int  *NumMinas, int * NumMinasDetectadas) {
	fread(NumMinas, sizeof(int), 1, cargado);
	fread(NumMinasDetectadas, sizeof(int), 1, cargado);
	int i, j;
	for (i = 0; i<dificultad[0]; i++) {
		for (j = 0; j<dificultad[1]; j++) {
			fread(&tableroJugador[i][j], sizeof(char**), 1, cargado);
		}
	}
	for (i = 0; i<dificultad[0]; i++) {
		for (j = 0; j<dificultad[1]; j++) {
			fread(&tablero[i][j], sizeof(char**), 1, cargado);
		}
	}
	fclose(cargado);
}

int * cargaDificultad(FILE * cargado) {
	int * dificultad = (int *)malloc(3 * sizeof(int));
	if (dificultad == NULL) {
		fprintf(stderr, "Sin memoria.");
		fflush(0);
		exit(-1);
	}
	fread(dificultad, sizeof(int *), 3, cargado);
	return dificultad;
}

char ** tableroCarga(int * dificultad) {
	int NumFilas = dificultad[0];
	int NumColumnas = dificultad[1];
	char ** tablero;
	tablero = (char **)malloc(NumFilas * sizeof(char *));
	if (tablero == NULL) {
		fprintf(stderr, "Sin memoria.");
		fflush(0);
		exit(-1);
	}
	int i;
	for (i = 0; i<NumFilas; i++) {
		tablero[i] = (char *)malloc(NumColumnas * sizeof(char));
		if (tablero[i] == NULL) {
			fprintf(stderr, "Sin memoria.");
			fflush(0);
			exit(-1);
		}
	}
	return tablero;
}
