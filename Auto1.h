#ifndef AUTO1_H
#define AUTO1_H
#include "Auto.h"
#include <ctime>

class Auto1 : public Auto {
public:
	Auto1(int x0,int y0);		//contructor que recibe la posición inicial del auto del jugador y dibuja al auto1
	Auto1(){};
	void update();				//método que permite el movimiento del auto
	
};

#endif

