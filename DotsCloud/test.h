#ifndef __TEST_H
#define __TEST_H
#include <iostream>
#include <list>
#include "Pareja.h"
#include <iostream>
//using namespace std;
void busca(int i, int tipo, list<Pareja<double, double> > &listaPuntos);

void ordenaPorEjeX(std::list<Pareja<double, double> > &puntos);

void ordenaPorEjeY(std::list<Pareja<double, double> > &puntos);

std::list<Pareja<double, double>> generaPuntos(int n);

double distanciaEntrePuntos(Pareja<double,double> p1,Pareja<double,double> p2);


/**
	Métodos para la resolucion del problema en tiempo cuadratico. O(n^2)

*/
double solucionDirecta(std::list<Pareja<double, double> > &puntos);

/**
	Métodos para la resolucion del problema en tiempo logaritmico. O(n*log(n))

*/
Pareja<std::list<Pareja<double, double> >, std::list<Pareja<double, double> > > divideLista(std::list<Pareja<double, double> > &puntos, int m1);

std::list<Pareja<double, double> > filtraBanda(std::list<Pareja<double, double> > &l, double distanciaMaspequenaHastaAhora, double x1);

double recorreBanda(std::list<Pareja<double, double> > &l, double delta);

std::list<Pareja<double, double> > concatenaLista(std::list<Pareja<double, double> > &listaA, std::list<Pareja<double, double> > &listaB);

double solucionLogaritmica(std::list<Pareja<double, double> > &puntos, int n);

#endif // __TEST_H