#include "Auto.h"
#include <cstdlib>
#include <conio2.h>
#include <iostream>
#include <cstdio>
using namespace std;

void Auto::dibujar(){						//metodo para dibujar
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);
			gotoxy(x+i,y+k);
			cout<<(char) matriz[i][k];
			
		}
	}
}

void Auto::borrar(){						//metodo para borrar
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);	
			gotoxy(x+i,y+k);
			cout<<" ";
		}
	}
}

void Auto::setLimit(int x0, int x1,int y0, int y1){	//metodo para setear los límites de movimiento
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
}

