#include "Auto1.h"
#include <cstdlib>
#include <cstdlib>
#include <conio2.h>
#include <iostream>
#include <cstdio>
using namespace std;

Auto1::Auto1(int x0, int y0){
		
	int Color = 13;				//color del auto del jugador (azul)
	
	matriz[0][0]=0;  color[0][0] = 8;			//se completa la matriz para dibujar el auto
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = Color;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = Color;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = Color;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = Color;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = Color;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = Color;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	
	ancho = 5;								//alto y ancho del dibujo
	alto = 4;
	pasoX = 5;								//tamaño del dezplzamiento
	x = x0;									//posicion inicial, se recibe por parametro
	y = y0;
	
	dibujar();
}

void Auto1::update(){			//método para desplazar al auto a la derecha y a la izaquierda 
								//mediante acción de teclado. Ante el movimiento se borra
	if (_kbhit()){				//al auto en la vieja posición y se lo dibuja en la actual
		int tecla = getch();
		bool moves = false;
		
		switch(tecla){
			case (77):{ 
				if (x + ancho < maxLimitX)		//desplazamiento derecha
				{
				borrar(); 
				x = x + pasoX; 
				moves = true;} 
				break;
			}					// derecha
			case (75):{ 
				if (x - ancho > minLimitX)		//desplazamiento izquierda
				{
				borrar(); 
				x = x - pasoX; 
				moves = true;} 
				break;
			}					// izquierda
		}
		
		if(moves) {
			
			dibujar();
		}
	}	
	
}




