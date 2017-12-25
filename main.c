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
	int init = 0;
	while (init != 3){
		printf("Bienvenido! Que desea hacer?\n"
				"1.Juego Nuevo.\n"
				"2.Cargar Partida.\n"
				"3.Exit.\n");
		fflush(0);
		scanf("%d", &init);

		if(init == 1){
			int * dificultad = Dificultad(argc, argv);
			char ** tablero = crearTablero(dificultad);
			char ** tableroJugador = crearTableroJugador(dificultad);
			int NumMinas = dificultad[2];
			int NumMinasDetectadas = 0;
			int juego = 1;
			while(juego == 1){
				int jugada = 0;

				mostrarTablero(tableroJugador, dificultad, NumMinas);

				printf("Que desea hacer?\n"
						"1.Detectar una mina.\n"
						"2.Mostrar una casilla.\n"
						"3.Guardar partida.\n"
						"4.Exit.\n");
				fflush(0);
				scanf("%d", &jugada);
				if(jugada == 1){
					detectarMina(tableroJugador, tablero, &NumMinas, &NumMinasDetectadas);
					if(NumMinas == 0 && NumMinasDetectadas == dificultad[2]){
						printf("Enhorabuena!! Has ganado!");
						mostrarTablero(tablero, dificultad, dificultad[2]);
						printf("\n\n\n");
						juego = 0;
					}
				}else if(jugada == 2){
					probarCasilla(tableroJugador, tablero, dificultad, &juego, NumMinas);
				}else if(jugada == 3){
					guardarPartida(tableroJugador, tablero, dificultad, &NumMinas, &NumMinasDetectadas);
				}else if(jugada == 4){
					printf("Hasta pronto!\n");
					fflush(0);
					exit(0);
				}else if(jugada != 1 && jugada != 2 && jugada != 3){
					fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
					fflush(0);
				}

			}
			if(juego == 0){
				limpiarTableros(tablero, tableroJugador, dificultad);
			}

		}else if(init == 2){
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
				int jugada = 0;

				mostrarTablero(tableroJugador, dificultad, NumMinas);

				printf("Que desea hacer?\n"
						"1.Detectar una mina.\n"
						"2.Mostrar una casilla.\n"
						"3.Guardar partida.\n"
						"4.Exit.\n");
				fflush(0);
				scanf("%d", &jugada);
				if(jugada == 1){
					detectarMina(tableroJugador, tablero, &NumMinas, &NumMinasDetectadas);
					if(NumMinas == 0 && NumMinasDetectadas == dificultad[2]){
						printf("Enhorabuena!! Has ganado!");
						mostrarTablero(tablero, dificultad, dificultad[2]);
						printf("\n\n\n");
						juego = 0;
					}
				}else if(jugada == 2){
					probarCasilla(tableroJugador, tablero, dificultad, &juego, NumMinas);
				}else if(jugada == 3){
					guardarPartida(tableroJugador, tablero, dificultad, &NumMinas, &NumMinasDetectadas);
				}else if(jugada == 4){
					printf("Hasta pronto!\n");
					fflush(0);
					exit(0);
				}else if(jugada != 1 && jugada != 2 && jugada != 3 && jugada != 4){
					fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
					fflush(0);
				}

			}
			if(juego == 0){
				limpiarTableros(tablero, tableroJugador, dificultad);
			}


		}else if(init != 1 && init != 2 && init != 3){
			fprintf(stderr, "Selecciona una de las opciones, por favor.\n");
			fflush(0);
		}
	}
	if(init == 3){
		printf("Hasta pronto!\n");
		fflush(0);
	}
	return 0;
}

