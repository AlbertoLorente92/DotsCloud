#include "Tiempos.h"

bool muestraTiempos(float tiempo,int tamano,int opcion,double distancia){
	std::ofstream archivo;
	bool b = true;

	switch(opcion){
		case 1:											//Cuadratico
			archivo.open("TiemposCuadratico.txt", std::fstream::out | std::fstream::app);
		break;

		case 2:											//Logaritmico
			archivo.open("TiemposLogaritmico.txt", std::fstream::out | std::fstream::app);
		break;

		default:
			b=false;
		break;
	}
		
	if(b){
		archivo << tamano << "\t" << tiempo << "\t" << distancia << std::endl;
	}

	archivo.close();

	return b;
}