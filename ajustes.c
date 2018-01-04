/*
=======================================================
Name : Buscaminas_IP
Author : Alvaro Tena
Created on: 12 dic. 2017
Description :
=======================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "ajustes.h"

int * Dificultad(int argc, char ** argv) {
	int difficult = 0;
	int * opciones = (int *)malloc(3 * sizeof(int));
	if (opciones == NULL) {
		fprintf(stderr, "Sin memoria.");
		fflush(0);
		exit(-1);
	}

	while (difficult == 1 || difficult == 2 || difficult == 3 || difficult == 4 || difficult == 0) {
		printf("Escoja su modo de juego:\n"
			"1.Facil.(8x8/10 minas)\n"
			"2.Medio.(16x16/40 minas)\n"
			"3.Avanzado(16x30/99 minas).\n"
			"4.Personalizado.\n");
		fflush(0);
		scanf("%d", &difficult);

		if (difficult == 1) {
			opciones[0] = 8;
			opciones[1] = 8;
			opciones[2] = 10;
			difficult = '0';
		}
		else if (difficult == 2) {
			opciones[0] = 16;
			opciones[1] = 16;
			opciones[2] = 40;
			difficult = '0';
		}
		else if (difficult == 3) {
			opciones[0] = 16;
			opciones[1] = 30;
			opciones[2] = 99;
			difficult = '0';
		}
		else if (difficult == 4) {
			if (argc != 4) {
				printf("USO: %s Numero_Filas Numero_Columnas Numero_Minas\n", argv[0]);
				fflush(0);
				system("PAUSE");
				exit(-1);
			}
			int i;
			for (i = 1; i<4; i++) {
				opciones[i - 1] = atoi(argv[i]);
			}
			difficult = '0';
		}
		else {
			fprintf(stderr, "Seleccione una de las opciones, por favor.\n");
			fflush(0);
		}
	}
	return opciones;
}
