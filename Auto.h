#ifndef AUTO_H
#define AUTO_H
#include <ctime>

//Auto es la clase madre que da origen al auto del jugador (auto azul o Auto1)
//al auto amariillo (Auto2) y al auto rojo (Auto3).

class Auto {
protected:				//atributos protegidos para que puedan ser accedidos desde las clases hijas
	// hago matrices lo suficientemente grandes
	int matriz[5][4];
	int color[5][4]; // matriz de colores
	int ancho;
	int alto;
	int pasoX;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	clock_t tempo; //variable para ajustar la velocidad de movimiento del auto
		
public:				//metodos y atributos publicos para que puedan ser accedidos desde la clase Juego
	clock_t paso; //variable para ajustar la velocidad de movimiento del auto
	int x;			//x e y variables de posición, para dejrlas en "protected" podría agregar un método get y otro set	
	int y;			// para obtener la posición y modificarlas
	int velocidad;		//velocidad de movimiento de los autos
	void dibujar();		//método para dibujar los autos
	void borrar(); // para dibujar, antes debemor borrar
	void setLimit(int x0, int x1,int y0, int y1);		//limites por donde puden desplazarse los autos
	Auto(){};
	
};									

#endif

