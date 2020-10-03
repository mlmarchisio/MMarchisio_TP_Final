#ifndef AUTO3_H
#define AUTO3_H
#include "Auto.h"
#include <ctime>
#include "Auto3.h"

class Auto3 : public Auto {
private:
	int colorAuto;					//color rojo
public:
	int a; 							//variables para hacer aleatorio el desplazamiento del auto rojo
	int b;
	int c;
	int d;
	Auto3(int v, int x0,int y0);	//contructor que recibe la posición inicial y la velocidad de desplazamiento del auto3
	Auto3(){};
	void update();					//método que permite el movimiento del auto
};

#endif

