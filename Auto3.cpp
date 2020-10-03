#include "Auto3.h"
#include <cstdlib>
#include <conio2.h>
#include <iostream>
using namespace std;

Auto3::Auto3(int vel, int x0, int y0){		//constructor para auto rojo
		
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //fps
	tempo=clock(); //inicializamos tempo con el reloj
	
	colorAuto = 4;
	a = rand()%12+1;			//variables para hacer aleatorio el desplazamiento del auto rojo
	b = rand()%24+12;			//de esta manera el movimiento no presenta patrones
	c = rand()%36+24;
	d = rand()%45+36;
		
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

void Auto3::update()		//método para desplazar al auto rojo en forma de zig-zag
{							//el movimiento no tiene patrones y es diferente en cada ciclo
	if (y<37){
		
		if(tempo+paso<clock()){
			
			// borro
			borrar();
			// muevo
			y++;
			if(y<a && x<38)			//a = rand()%12+1   12
			{
				x=x+3;	
			}
			if (y>a && y<b && x>5)	//b = rand()%24+12   12    24
			{
				x=x-3;
			}
			if(y>b && y<c && x<38)	//c = rand()%36+24   24   36
			{
				x=x+3;	
			}
			if (y>c && y<d && x>3)	//d = rand()%45+36   36   45
			{
				x=x-3;
			}
			// dibujo
			dibujar();
			
			tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos el auto
		}
	}
}

