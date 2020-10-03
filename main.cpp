#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Juego.h"
#include <conio2.h>
using namespace std;

int main (int argc, char *argv[]) {
	Juego *J = new Juego;				//se crea un objeto J desde la clase Juego
	J -> play();						//se instancia el método play de la del objeto J
	return 0;
	
}

