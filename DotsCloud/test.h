#ifndef __TEST_H
#define __TEST_H

#include "Tiempos.h"
#include "ordenacion.h"

#include <list>

#include <time.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>

#include <iostream>
using namespace std;

void busca(int i, int tipo, list<Pareja<double, double> > &listaPuntos);

void ordenaPorEjeX(list<Pareja<double, double> > &puntos);

void ordenaPorEjeY(list<Pareja<double, double> > &puntos);

list<Pareja<double, double>> generaPuntos(int n);

double distanciaEntrePuntos(Pareja<double,double> p1,Pareja<double,double> p2);


/**
	Métodos para la resolucion del problema en tiempo cuadratico. O(n^2)

*/
double solucionDirecta(list<Pareja<double, double> > &puntos);

/**
	Métodos para la resolucion del problema en tiempo logaritmico. O(n*log(n))

*/
Pareja<list<Pareja<double, double> >, list<Pareja<double, double> > > divideLista(list<Pareja<double, double> > &puntos, int m1);

list<Pareja<double, double> > filtraBanda(list<Pareja<double, double> > &l, double distanciaMaspequenaHastaAhora, double x1);

double recorreBanda(list<Pareja<double, double> > &l, double delta);

list<Pareja<double, double> > concatenaLista(list<Pareja<double, double> > &listaA, list<Pareja<double, double> > &listaB);

double solucionLogaritmica(list<Pareja<double, double> > &puntos, int n);

#endif // __TEST_H