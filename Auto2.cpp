#include "Auto2.h"
#include <cstdlib>
#include <conio2.h>
#include <iostream>
using namespace std;

Auto2::Auto2(int vel, int x0, int y0){			//constructor que recibe la velocidad y la posición del auto amarillo
												//además se crea la matriz para dibujar al auto
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //fps
	tempo=clock(); //inicializamos tempo con el reloj
	
	colorAuto = 10;								//color amarillo
	
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = colorAuto;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = colorAuto;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = colorAuto;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = colorAuto;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = colorAuto;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = colorAuto;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	
	ancho = 5;
	alto = 4;
	x = x0;
	y = y0;
	
	dibujar();
}

void Auto2::update(){		//método para desplazar al auto amarillo y el obstaculo desde arriba hasta abajo
	
	if (y<37){
		
		if(tempo+paso<clock()){
			
			// borro
			borrar();
			// muevo
			y++;
			// dibujo
			dibujar();
			
			tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos al auto
		}
	}
}
	


