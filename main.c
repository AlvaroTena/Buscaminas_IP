/*
=======================================================
Name : Buscaminas_Practica_IP
Author : Tena
Created on: 11 dic. 2017
Description : 
=======================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ajustes.h"
#include "tablero.h"
#include "jugadas.h"
#include "salida.h"
#include "saves.h"

int main(int argc, char ** argv){
	if (argc != 4) {
		printf("USO: %s Numero_Filas Numero_Columnas Numero_Minas\n", argv[0]);
		fflush(0);
		return -1;
	}
	char init = 'A';
	while (init != 'E'){
		printf("Bienvenido! Que desea hacer?\n"
				"(J)uego Nuevo.\n"
				"(C)argar Partida.\n"
				"(E)xit.\n");
		fflush(0);
		scanf("%c", &init);
		fflush(stdin);
		if(init == 'J'){
			int * dificultad = Dificultad(argv);
			char ** tablero = crearTablero(dificultad);
			char ** tableroJugador = crearTableroJugador(dificultad);
			int NumMinas = dificultad[2];
			int NumMinasDetectadas = 0;
			int juego = 1;
			while(juego == 1){
				char jugada = 'A';

				mostrarTablero(tableroJugador, dificultad, NumMinas);

				printf("Que desea hacer?\n"
						"(D)etectar una mina.\n"
						"(M)ostrar una casilla.\n"
						"(G)uardar partida.\n"
						"(E)xit.\n");
				fflush(0);
				scanf("%c", &jugada);
				fflush(stdin);
				if(jugada == 'D'){
					detectarMina(tableroJugador, tablero, &NumMinas, &NumMinasDetectadas);
					if(NumMinas == 0 && NumMinasDetectadas == dificultad[2]){
						printf("Enhorabuena!! Has ganado!");
						mostrarTablero(tablero, dificultad, dificultad[2]);
						printf("\n\n\n");
						juego = 0;
					}
				}else if(jugada == 'M'){
					probarCasilla(tableroJugador, tablero, dificultad, &juego, NumMinas);
				}else if(jugada == 'G'){
					guardarPartida(tableroJugador, tablero, dificultad, &NumMinas, &NumMinasDetectadas);
				}else if(jugada == 'E'){
					juego = 0;
					init = 'E';
				}else if(jugada != 'D' && jugada != 'M' && jugada != 'G'){
					fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
					fflush(0);
				}

			}
			if(juego == 0){
				limpiarTableros(tablero, tableroJugador, dificultad);
			}

		}else if(init == 'C'){
			FILE * cargado = fopen("partidaGuardada.ip", "rb");
			if(cargado == NULL){
				fprintf(stderr, "Error al cargar la partida");
				exit(-1);
			}
			int * dificultad = cargaDificultad(cargado);
			char ** tablero = tableroCarga(dificultad);
			char ** tableroJugador = tableroCarga(dificultad);
			int NumMinas;
			int NumMinasDetectadas;
			cargarPartida(cargado, tableroJugador, tablero, dificultad, &NumMinas, &NumMinasDetectadas);

			int juego = 1;
			while(juego == 1){
				char jugada = 'A';

				mostrarTablero(tableroJugador, dificultad, NumMinas);

				printf("Que desea hacer?\n"
						"(D)etectar una mina.\n"
						"(M)ostrar una casilla.\n"
						"(G)uardar partida.\n"
						"(E)xit.\n");
				fflush(0);
				scanf("%c", &jugada);
				fflush(stdin);
				if(jugada == 'D'){
					detectarMina(tableroJugador, tablero, &NumMinas, &NumMinasDetectadas);
					if(NumMinas == 0 && NumMinasDetectadas == dificultad[2]){
						printf("Enhorabuena!! Has ganado!");
						mostrarTablero(tablero, dificultad, dificultad[2]);
						printf("\n\n\n");
						juego = 0;
					}
				}else if(jugada == 'M'){
					probarCasilla(tableroJugador, tablero, dificultad, &juego, NumMinas);
				}else if(jugada == 'G'){
					guardarPartida(tableroJugador, tablero, dificultad, &NumMinas, &NumMinasDetectadas);
				}else if(jugada == 'E'){
					juego = 0;
					init = 'E';
				}else if(jugada != 'D' && jugada != 'M' && jugada != 'G' && jugada != 'E'){
					fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
					fflush(0);
				}

			}
			if(juego == 0){
				limpiarTableros(tablero, tableroJugador, dificultad);
			}


		}else if(init != 'J' && init != 'C' && init != 'E'){
			fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
			fflush(0);
		}
	}
	if(init == 'E'){
		printf("Hasta pronto!\n");
		fflush(0);
	}

	return 0;
}

