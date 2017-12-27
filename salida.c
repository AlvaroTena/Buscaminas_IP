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

void mostrarTablero(char ** tablero, int * dificultad, int NumMinas) {
	int NumFilas = dificultad[0];
	int NumColumnas = dificultad[1];
	int  i, j;
	printf("\n\nQUEDAN %d MINAS\n", NumMinas);
	fflush(0);
	for (i = 0; i<NumColumnas; i++) {
		printf("----");
		fflush(0);
	}
	printf("\n");
	fflush(0);
	for (i = 0; i<NumFilas; i++) {
		for (j = 0; j<NumColumnas; j++) {
			printf(" %c |", tablero[i][j]);
			fflush(0);
		}
		printf("\n");
		fflush(0);
		for (j = 0; j<NumColumnas; j++) {
			printf("----");
			fflush(0);
		}
		printf("\n");
		fflush(0);
	}
}
