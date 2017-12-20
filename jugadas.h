/*
=======================================================
Name : Buscaminas_Practica_IP
Author : Tena
Created on: 14 dic. 2017
Description : 
=======================================================
*/
#ifndef JUGADAS_H_
#define JUGADAS_H_

void detectarMina(char ** tableroJugador, char ** tablero, int * NumMinas, int * NumMinasDetectadas);
void probarCasilla(char ** tableroJugador, char ** tablero, int * dificultad, int * juego, int NumMinas);
void destaparCasillas(int Fila, int Columna, char ** tableroJugador, char ** tablero, int * dificultad);

#endif /* JUGADAS_H_ */
