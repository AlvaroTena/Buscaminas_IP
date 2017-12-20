/*
=======================================================
Name : Buscaminas_Practica_IP
Author : Tena
Created on: 12 dic. 2017
Description : 
=======================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "ajustes.h"

int * Dificultad(char ** argv){
	char difficult = '/';
	int * opciones = (int *) malloc(3 * sizeof(int));
	if(opciones == NULL){
		fprintf(stderr, "Sin memoria.");
		fflush(0);
		exit(-1);
	}

	while(difficult == 'F' || difficult == 'M' || difficult == 'A' || difficult == 'P' || difficult == '/'){
		printf("Escoja su modo de juego:\n"
				"(F)acil.(8x8/10 minas)\n"
				"(M)edio.(16x16/40 minas)\n"
				"(A)vanzado(16x30/99 minas).\n"
				"(P)ersonalizado.\n");
		fflush(0);
		scanf("%c", &difficult);
		fflush(stdin);

		if(difficult == 'F'){
			opciones[0] = 8;
			opciones[1] = 8;
			opciones[2] = 10;
			difficult = '0';
		}else if(difficult == 'M'){
			opciones[0] = 16;
			opciones[1] = 16;
			opciones[2] = 40;
			difficult = '0';
		}else if(difficult == 'A'){
			opciones[0] = 16;
			opciones[1] = 30;
			opciones[2] = 99;
			difficult = '0';
		}else if(difficult == 'P'){
			int i;
			for(i=1; i<4; i++){
				opciones[i-1] = atoi(argv[i]);
			}
			difficult = '0';
		}else{
			fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
			fflush(0);
		}
	}
	return opciones;
}
