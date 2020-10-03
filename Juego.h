#ifndef JUEGO_H
#define JUEGO_H
#include "Auto.h"
#include "Auto1.h"
#include "Auto2.h"
#include "Auto3.h"
#include "obstaculo.h"

class Juego{
private:
	int teclas[2];
	Auto1 auto1;			//se crean los autos y el obstaculo
	Auto2 *auto2;
	Auto3 *auto3;
	Obstaculo *obst;
	int x0auto2;			//posiciones iniciales en x para los autos amarillo y rojo
	int x0auto3;			//y el obstaculo
	int x0obst;
	int puntaje;				//variable puntaje del juego
	int vidas;					//vidas del jugador
	int bordeIzq [3][45];		//matrices para dibujar los bordes de la pista
	int bordeDer [3][45];
	float factor_velocidad;		//se usa un valor real (no solo enteros)
	
	int checkCollision();			//metodo que verifica si hay choques entre el auto del jugador y los demas objetos
	void dibujar_pista();			//metodo que dibuja los bordes de la pista
	void actualizar_velocidad();	//metodo que actualiza la velocidad del juego cada 20 puntos
	
public:	
	Juego();						//constructor
	void play();					//metodo que ejecuta al juego
	
};


#endif
