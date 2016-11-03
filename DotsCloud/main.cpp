#include <iostream>
#include <time.h>
#include "Lista.h"
#include "Pareja.h"
#include "test.h"
using namespace std;

int main(){
	srand(time(NULL));
	char c;

	cout << "Estructura de Datos y algoritmos (EDA)." << endl;
	cout << "Practica opcional 3." << endl;
	cout << "Alumnos: Juan Deltell y Alberto Lorente." << endl;
	cout << "Grado en Ingenieria del Software curso 2." << endl;
	cout << "Medicion de tiempos para las diferentes formas de encontrar el par de puntos" << endl;
	cout << "mas cercanos en una nube dada." << endl << endl;
	cout << "Este programa ejecutara busquedas desde 2 a 5000 puntos y mostrara:"  << endl;
	cout << "Tipo de busqueda - Num. de ptos -  Distancia - Tiempo de espera" << endl;
	cout << "Ademas almacenara los tiempos en ficheros de texto" << endl;
	cout << "Pulse enter para la ejecución automatica y completa del programa" << endl << endl;
	//cin.get(c);

	for(int i = 1 ; i <= 15; i++){
		Lista<Pareja<double,double> > listaPuntos = generaPuntos(i*1000);

 		busca(i*1000,1,listaPuntos);
		busca(i*1000,2,listaPuntos);		
	}

	cout << endl;
	cout << "Ficheros de texto generados. Programa finalizado" << endl;

	return 0;
}