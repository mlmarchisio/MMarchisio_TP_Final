#ifndef AUTO2_H
#define AUTO2_H
#include "Auto.h"
#include <ctime>
#include "Auto2.h"

class Auto2 : public Auto {
private:
	int colorAuto;					//color amarillo
public:
	Auto2(int v, int x0,int y0);	//contructor que recibe la posición inicial y la velocidad de desplazamiento del auto2
	Auto2(){};
	void update();					//método que permite el movimiento del auto
	
	
	
};	
	
#endif

