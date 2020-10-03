#include "Juego.h"
#include <iostream>
#include <conio2.h>
#include <climits>
#include "Auto3.h"
#include "Auto1.h"
#include "Auto2.h"

using namespace std;

Juego::Juego(){					//constructor
	
	x0auto2 = rand()%38+3;		//se crean las posiciones en x iniciales para auto2, auto3 y el obstaculo
	x0auto3 = rand()%33+3;
	x0obst = rand()%38+3;
	puntaje = 0;				//se inicia el juego con puntaje cero
	vidas = 5;					//se inicia el juego con 5 vidas
	factor_velocidad = 1;		//el factor de velocidad al inicio es 1
	
	auto1 = Auto1(25,30);			//se pasa la posición inicial del auto del jugador. 
									//si lo expreso en puntero deja de reconocer la accion de teclado
	auto1.setLimit(1,45,0,45);		//se ajustan los limites de desplazamiento del auto 1
	
	auto2 = new Auto2(5,x0auto2,1);		//posicion inicial y velocidad auto amarillo
	auto2 -> setLimit(1,45,0,45);
	
	auto3 = new Auto3(3,x0auto3,1);		//posicion inicial y velocidad auto rojo
	auto3 -> setLimit(1,40,0,45);
	obst = new Obstaculo(2,x0obst,1);	//posicion inicial y velocidad obstaculo
	obst -> setLimit(3,47,0,45);
}

int Juego::checkCollision(){		//metodo que verifica si hay choques entre el auto del jugador 
									//los demas autos y el obstaculo. dependiendo del choque retorna un entero
	int x1 = auto1.x;
	int y1 = auto1.y;
	
	int x2 = auto2 -> x;
	int y2 = auto2 -> y;
	
	int x3 = auto3 -> x;
	int y3 = auto3 -> y;
	
	int x4 = obst -> x;
	int y4 = obst -> y;
	int ancho = 3;
	int alto = 4;
	
	
	if(x1 > (x2 - ancho) && x1 < (x2 + ancho) && 
	   y1 > (y2 - alto) && y1 < (y2 + alto))
	{auto2 -> borrar();return 2;}
	   
	if(x1 > (x3 - ancho) && x1 < (x3 + ancho) && 
		y1 > (y3 - alto) && y1 < (y3 + alto))
	{auto3 -> borrar();return 3;}
		  
	if(x1 > (x4 - ancho) && x1 < (x4 + ancho) && 
		y1 > (y4 - alto) && y1 < (y4 + alto))
	{obst -> borrar();return 4;}	  
		  
}

void Juego::dibujar_pista()					//metodo que dibuja los bordes de la pista
{
	for (int i = 0 ; i<4 ; i++)
	{
		for (int j = 0 ; j<46 ; j++)
		{
			bordeIzq [i][j] = 178;
			bordeDer [i][j] = 178;
		}
	}
	
	for (int i= 0; i<3; i++){
		for (int k= 0; k<40; k++){
			textcolor(2);
			gotoxy(1+i,1+k);
			cout<<(char) bordeIzq [i][k];
		}
	}
	
	for (int i= 0; i<3; i++){
		for (int k= 0; k<40; k++){
			textcolor(2);
			gotoxy(47+i,1+k);
			cout<<(char) bordeDer [i][k];
			
		}
	}	
}

void Juego::actualizar_velocidad()						//metodo que actualiza la velocidad de los autos amarillo y rojo y el obstaculo
{														//cada 20 puntos
	if (puntaje%20 == 0)
	{
		factor_velocidad = factor_velocidad + 2;
		
		auto2 -> velocidad = auto2 -> velocidad*factor_velocidad;
		auto3 -> velocidad = auto3 -> velocidad*factor_velocidad;
		obst -> velocidad = obst -> velocidad*factor_velocidad	;
			
		auto2 -> paso=CLOCKS_PER_SEC/auto2 -> velocidad;
		auto3 -> paso=CLOCKS_PER_SEC/auto3 -> velocidad;
		obst -> paso=CLOCKS_PER_SEC/obst -> velocidad;
	}
}

void Juego::play(){					//metodo de juego, inicia con el tutorial del juego
	gotoxy(1,1);
	textcolor(14);
	cout<<"							Street Racer"<<endl<<endl;;
	textcolor(7);
	cout<<"							El usuario contrala el auto azul"<<endl;
	cout<<"							El auto es controlado con las teclas de direccion (<- y ->)"<<endl;
	cout<<"							El auto solo puede desplazarse a la izquierda o a la derecha"<<endl;
	cout<<"							Debe esquivar al auto rojo, al auto amarillo y el obstaculo"<<endl;
	cout<<"							Al esquivar a los vehiculos y el obstaculo se suma 1 punto"<<endl;
	cout<<"							Cada 20 puntos se incrementa la velocidad de los vehiculos"<<endl;
	cout<<"							y el obstaculo"<<endl;
	cout<<"							El juego inicia con 5 vidas"<<endl;
	cout<<"							Cada choque resta 1 vida"<<endl;
	cout<<"							Al quedarse sin vidas el jugador pierde"<<endl;
		
	bool flag = true;
		
	while(flag == true) {				//bucle que se mantiene activo miestras el jugador tenga vidas
				
		dibujar_pista();				//se dibuja la pista
		auto1.update();					//se mueve el auto del jugador
		auto2 -> update();				//se mueven los autos y el obstaculo
		auto3 -> update();
		obst -> update();
		
		if (auto2 -> y == 36)			//cuando el auto amarillo llega a la y=36, se suma 1 punto,se reinicia su posición
		{								//se actualiza e informa el puntaje y las vidas
			puntaje = puntaje + 1;		//ademas se llama al método que actualiza la velocidad
			gotoxy(60,15);				//si el puntaje es 20 a multiplo de 20 se actualiza la velocidad
			cout<<"Puntaje: "<<puntaje<<endl;
			gotoxy(60,16);
			cout<<"Vidas restantes: "<<vidas<<endl;
			auto2 -> borrar();
			auto2 -> y = 1;
			auto2 -> x = rand()%38+3;
			actualizar_velocidad();
		}
		if (auto3 -> y == 36)				//idem al anterior, solo que tambien se reinician las variables aleatorias
		{									//que gobiernan el movimiento del auto rojo
			puntaje = puntaje + 1;
			gotoxy(60,15);
			cout<<"Puntaje: "<<puntaje<<endl;
			gotoxy(60,16);
			cout<<"Vidas restantes: "<<vidas<<endl;
			auto3 -> borrar();
			auto3 -> y = 1;
			auto3 -> a = rand()%12+1;
			auto3 -> b = rand()%24+12;
			auto3 -> c = rand()%36+24;
			auto3 -> d = rand()%45+36;
			auto3 -> x = rand()%38+3;
			actualizar_velocidad();
		}
		if (obst -> y == 36)					//idem al auto amarillo
		{
			puntaje = puntaje + 1;
			gotoxy(60,15);
			cout<<"Puntaje: "<<puntaje<<endl;
			gotoxy(60,16);
			cout<<"Vidas restantes: "<<vidas<<endl;
			obst -> borrar();
			obst -> y = 1;
			obst -> x = rand()%38+3;
			actualizar_velocidad();
		}
		if (checkCollision() == 2){						//si hay choque, se borra al auto u obstaculo
			auto2 -> y = 0;								//y se reinicia su posición
			auto2 -> x = rand()%38+3;
			textcolor(15);
			vidas = vidas - 1;
			gotoxy(22,30);
			cout<<"CHOQUE"<<endl;
			gotoxy(60,16);
			cout<<"Vidas restantes: "<<vidas<<endl;
		}
		if (checkCollision() == 3){
			auto3 -> y = 0;
			auto3 -> x = rand()%38+3;
			textcolor(15);
			vidas = vidas - 1;
			gotoxy(22,30);
			cout<<"CHOQUE"<<endl;
			gotoxy(60,16);
			cout<<"Vidas restantes: "<<vidas<<endl;
		}	
		if (checkCollision() == 4){
			obst -> y = 1;
			obst -> x = rand()%38+3;
			textcolor(15);
			vidas = vidas - 1;
			gotoxy(22,30);
			cout<<"CHOQUE"<<endl;
			gotoxy(60,16);
			cout<<"Vidas restantes: "<<vidas<<endl;
		}
		
		if (vidas == 0)				//cuando se producen 5 choques, el jugador no tiene mas vidas 
		{							//y pierde, game over
			flag = false;
			gotoxy(20,15);
			cout<<"GAME OVER";
		}
	}
}

