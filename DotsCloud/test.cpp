#include "Tiempos.h"
#include "test.h"
#include "ordenacion.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>

using namespace std;

void busca(int i,int tipo,Lista<Pareja<double,double> > &listaPuntos){
	float tiempo;
	clock_t tIni=0;		
	clock_t tFin=0;	
	bool b = true;
	double distancia;
	Lista<Pareja<double,double> > L;

	switch(tipo){
		case 1:											//Cuadratico
			tIni = clock();	
			cout << "Cuadratica - " << " N.ptos = " << i;
			distancia = solucionDirecta(listaPuntos);
			tFin = clock();
			cout << " Distancia = " << distancia;			
		break;

		case 2:											//Logaritmico
			tIni = clock();	
			cout << "Logaritmica - " << " N.ptos = " << i;
			ordenaPorEjeX(listaPuntos);
			distancia = solucionLogaritmica(listaPuntos,listaPuntos.numElems());
			tFin = clock();
			cout << " Distancia = " << distancia; //SolucionLogaritmica
			cout << endl;	
		break;

		case 3:											//Mezcla
			tIni = clock();	
			cout << "Logaritmica - " << " N.ptos = " << i;
			cout << " Distancia = " << solucionDirecta(listaPuntos); //SolucionMezclada
			tFin = clock();
		break;

		default:
			b=false;
		break;
	}

	if(b){
		tiempo = ((float) (tFin - tIni)) / CLOCKS_PER_SEC;
		cout << " Tiempo = " << tiempo << endl;
	
		if(!muestraTiempos(tiempo,i,tipo,distancia)){
			cout << "ERROR EN LOS FICHEROS TXT" << endl;
		}
	} else{
		cout << "ERROR: codigo de ejecucion no valido " << endl;
	}
}

void ordenaPorEjeX(Lista<Pareja<double,double> > &puntos){
	Pareja<double,double> *a = new Pareja<double,double>[puntos.numElems()];
	Lista<Pareja<double,double> >::Iterador it = puntos.principio();
	int N = puntos.numElems();
	int i = 0;
	while(it!=puntos.final()){
		a[i]=it.elem();
		it.avanza();
		puntos.resto();
		i++;
	}

	quickSort(a,N);
	
	for(int j = 0; j < N;j++){
		puntos.ponDr(a[j]);
	}
	
	delete[] a;
}

void ordenaPorEjeY(Lista<Pareja<double,double> > &puntos){
	Pareja<double,double> *a = new Pareja<double,double>[puntos.numElems()];
	Lista<Pareja<double,double> >::Iterador it = puntos.principio();
	int N = puntos.numElems();
	int i = 0;
	while(it!=puntos.final()){
		a[i]=it.elem();
		it.avanza();
		puntos.resto();
		i++;
	}
	
	quickSortY(a,N);
	
	for(int j = 0; j < N;j++){
		puntos.ponDr(a[j]);
	}
	
	delete[] a;
}

Lista<Pareja<double,double> > generaPuntos(int n){
	Lista<Pareja<double,double> > listaPuntos;

	for(int i = 0; i < n; i++){
		double n1 = (rand() % 20000)/100.00 -100;
		double n2 = (rand() % 20000)/100.00 -100;
		Pareja<double,double> a(n1,n2);

		listaPuntos.ponDr(a);
	}

	return listaPuntos;
}

double distanciaEntrePuntos(Pareja<double,double> p1,Pareja<double,double> p2){
	return sqrt(pow(p1.primero()-p2.primero(),2) + pow(p1.segundo()-p2.segundo(),2));
}

double solucionDirecta(Lista<Pareja<double,double> > &puntos){
	double distancia=285;

	Lista<Pareja<double,double> >::Iterador itPunto = puntos.principio();// puntos.principio();

	while(itPunto != puntos.final()){
		Lista<Pareja<double,double> >::Iterador itCompara = itPunto;
		itCompara.avanza();

		while(itCompara != puntos.final()){
				double distanciaNueva = distanciaEntrePuntos(itPunto.elem(),itCompara.elem());

				if(distanciaNueva<distancia)
					distancia=distanciaNueva;

			itCompara.avanza();
		}

		itPunto.avanza();
	}

	return distancia;
}

Pareja<Lista<Pareja<double,double> >,Lista<Pareja<double,double> > > divideLista(Lista<Pareja<double,double> > &puntos,int m1){
	Lista<Pareja<double,double> > izquierda;
	Lista<Pareja<double,double> > derecha;
	
	Lista<Pareja<double,double> >::Iterador it = puntos.principio();
	int i=0;
	while(i<m1){
		izquierda.ponDr(it.elem());
		it.avanza();
		i++;
	}
	while(i<puntos.numElems()){
		derecha.ponDr(it.elem());
		it.avanza();
		i++;
	}

	Pareja<Lista<Pareja<double,double> >,Lista<Pareja<double,double> > > P(izquierda,derecha);

	return P;
}

Lista<Pareja<double,double> > filtraBanda(Lista<Pareja<double,double> > &l, double distanciaMaspequenaHastaAhora, double x1){
	//eje 0 delta delta x otro 
	Lista<Pareja<double,double> > listaDeltas;
	Lista<Pareja<double,double> >::Iterador it = l.principio();
	double menosDelta = x1-distanciaMaspequenaHastaAhora;
	double masDelta = x1+distanciaMaspequenaHastaAhora;

	while(it != l.final()){
		if((it.elem().primero() >= menosDelta) && (it.elem().primero() <= masDelta)){
			listaDeltas.ponDr(it.elem());
		}
		it.avanza();
	}

	return listaDeltas;
}

double recorreBanda(Lista<Pareja<double,double> > &l,double delta){
	double distancia=delta;
	Lista<Pareja<double,double> > ::Iterador it = l.principio();
	
	while(it!=l.final()){
		Pareja<double,double> P1 = it.elem();
		Lista<Pareja<double,double> > ::Iterador it2 = it;
		it2.avanza();
		int i = 0;
		while(i<7 && (it2!=l.final())){// <= para que lo haga 7 veces 
				Pareja<double,double> P2 = it2.elem();

				if(distanciaEntrePuntos(P1,P2)<distancia)
					distancia = distanciaEntrePuntos(P1,P2);
			it2.avanza();
			i++;
		}
		it.avanza();
	}

	return distancia;
}

Lista<Pareja<double,double> > concatenaLista(Lista<Pareja<double,double> > &listaA, Lista<Pareja<double,double> > &listaB){
	Lista<Pareja<double,double> >::Iterador it = listaA.principio();
	Lista<Pareja<double,double> >::Iterador it2 = listaB.principio();
	Lista<Pareja<double,double> > listaUnion;
	
	while ((it != listaA.final()) && (it2 != listaB.final())) {
		if (it.elem().segundo() <= it2.elem().segundo()) {
			listaUnion.ponDr(it.elem());
			it.avanza();
		} else {
			listaUnion.ponDr(it2.elem());
			it2.avanza();
		}
	}
		   
	while (it != listaA.final()) {
		listaUnion.ponDr(it.elem());
		it.avanza();
	}

	while (it2 != listaB.final()) {
		   listaUnion.ponDr(it2.elem());
		   it2.avanza();
	 }
		   
	return listaUnion;
}

double solucionLogaritmica(Lista<Pareja<double,double> > &puntos,int n){
	double sol;
	Pareja<double,double> p1;
	Pareja<double,double> p2;

	double dist;
	if (n <= 3) { // Casos base
		sol = solucionDirecta(puntos);
		ordenaPorEjeY(puntos);
	}else{ // Dividimos la nube en dos n >= 4 
		int m1 = n / 2;
		int m2 = n - m1;
		Pareja<Lista<Pareja<double,double> >,Lista<Pareja<double,double> > > par = divideLista(puntos,m1);	

		Lista<Pareja<double,double> > I = par.primero();	
		Lista<Pareja<double,double> > D = par.segundo();

		double xMinima = I.ultimo().primero();
		double xMaxima = D.primero().primero();

		double xl = (xMinima + xMaxima) / 2;

		// Resolvemos recursivamente la s dos nubes
		double sol1 = solucionLogaritmica(I,m1);
		double sol2 = solucionLogaritmica(D,m2);

		// Ordenamos por la coordenada y la nube de puntos		
		double delta = min(sol1, sol2);

		//Unimos las dos listas de numeros ordenadas por la Y
		Lista<Pareja<double,double> > unionListas = concatenaLista(I,D);
		// Filtramos los puntos segun un delta dado
		Lista<Pareja<double,double> > B = filtraBanda(unionListas,delta,xl);

		dist=recorreBanda(B,delta);

		// Elegimos la mejor solucion de la s t re s
		sol = min (delta,dist);
	}
		
	return sol;
}