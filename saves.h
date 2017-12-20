/*
=======================================================
Name : Buscaminas_Practica_IP
Author : Tena
Created on: 14 dic. 2017
Description : 
=======================================================
*/
#ifndef SAVES_H_
#define SAVES_H_

void guardarPartida(char ** tableroJugador, char ** tablero, int * dificultad, int * NumMinas, int * NumMinasDetectadas);
void cargarPartida(FILE * cargado, char ** tableroJugador, char ** tablero, int * dificultad, int  *NumMinas, int * NumMinasDetectadas);
char ** tableroCarga(int * dificultad);
int * cargaDificultad(FILE * cargado);

#endif /* SAVES_H_ */
