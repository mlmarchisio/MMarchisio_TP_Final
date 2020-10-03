#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Auto2.h"

class Obstaculo : public Auto2 {	//hereda de Auto2 (y asu vez de Auto), el comportamiento es el mismo,
public:								//lo que cambia es el dibujo
	Obstaculo(){};
	Obstaculo(int v, int x0,int y0);	//el constructor recibe la posición y la velocidad
};										//y se setea la matriz para el dibujo
	


#endif

