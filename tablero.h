/*
=======================================================
Name : Buscaminas_IP
Author : Alvaro Tena
Created on: 11 dic. 2017
Description :
=======================================================
*/
#ifndef TABLERO_H_
#define TABLERO_H_

char ** crearTablero(int * dificultad);
char ** crearTableroJugador(int * dificultad);
void rellenarTablero(char ** tablero, int NumColumnas, int NumFilas, int NumMinas);
void limpiarTableros(char ** tablero, char ** tableroJugador, int * dificultad);

#endif /* TABLERO_H_ */
