#include "Obstaculo.h"
#include "Auto.h"
#include <iostream>
#include <conio2.h>
using namespace std;
Obstaculo::Obstaculo(int v, int x0,int y0)
{
	velocidad = v;
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj
		
	for (int i = 0 ; i<5 ; i++)
	{
		for (int j = 0 ; j<4 ; j++)
		{
			matriz[i][j]=178;
			color[i][j] = 8;
		}
	}
	
	ancho = 5;
	alto = 4;
	x = x0;
	y = y0;
		
	dibujar();
}

