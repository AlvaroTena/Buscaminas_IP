/*
=======================================================
Name : Buscaminas_IP
Author : Alvaro Tena
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
	if (NumFilas <= 9 || NumColumnas <= 9) {
		for (i = 0; i <= NumColumnas; i++) {
			printf("----");
			fflush(0);
		}
		printf("\n");
		fflush(0);
		for (i = 0; i <= NumColumnas; i++) {
			printf(" %d |", i);
			fflush(0);
		}
		printf("\n");
		for (i = 0; i <= NumColumnas; i++) {
			printf("----");
			fflush(0);
		}
		printf("\n");
		for (i = 0; i < NumFilas; i++) {
			printf(" %d |", i + 1);
			for (j = 0; j < NumColumnas; j++) {
				printf(" %c |", tablero[i][j]);
				fflush(0);
			}
			printf("\n");
			fflush(0);
			for (j = 0; j <= NumColumnas; j++) {
				printf("----");
				fflush(0);
			}
			printf("\n");
			fflush(0);
		}
	}
	else {
		for (i = 0; i <= NumColumnas; i++) {
			printf("-----");
			fflush(0);
		}
		printf("\n");
		fflush(0);
		for (i = 0; i <= NumColumnas; i++) {
			if (i <= 9) {
				printf("  %d |", i);
				fflush(0);
			}
			else {
				printf(" %d |", i);
				fflush(0);
			}
		}
		printf("\n");
		for (i = 0; i <= NumColumnas; i++) {
			printf("-----");
			fflush(0);
		}
		printf("\n");
		for (i = 0; i < NumFilas; i++) {
			if (i < 9) {
				printf("  %d |", i + 1);
				fflush(0);
			}
			else {
				printf(" %d |", i + 1);

			}
			for (j = 0; j < NumColumnas; j++) {
				printf("  %c |", tablero[i][j]);
				fflush(0);
			}
			printf("\n");
			fflush(0);
			for (j = 0; j <= NumColumnas; j++) {
				printf("-----");
				fflush(0);
			}
			printf("\n");
			fflush(0);
		}
	}
}
