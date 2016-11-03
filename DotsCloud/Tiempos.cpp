#include "Tiempos.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool muestraTiempos(float tiempo,int tamano,int opcion,double distancia){
	ofstream archivo;
	bool b = true;

	switch(opcion){
		case 1:											//Cuadratico
			archivo.open("TiemposCuadratico.txt",fstream::out | fstream::app);
		break;

		case 2:											//Logaritmico
			archivo.open("TiemposLogaritmico.txt",fstream::out | fstream::app);
		break;

		default:
			b=false;
		break;
	}
		
	if(b){
		archivo << tamano << "\t" << tiempo  << "\t" << distancia << endl;
	}

	archivo.close();

	return b;
}