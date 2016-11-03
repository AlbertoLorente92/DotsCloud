#ifndef __TEST_H
#define __TEST_H
#include <iostream>
#include "Lista.h"
#include "Pareja.h"

void busca(int i,int tipo,Lista<Pareja<double,double> > &listaPuntos);

void ordenaPorEjeX(Lista<Pareja<double,double> > &puntos);

void ordenaPorEjeY(Lista<Pareja<double,double> > &puntos);

Lista<Pareja<double,double> > generaPuntos(int n);

double distanciaEntrePuntos(Pareja<double,double> p1,Pareja<double,double> p2);


/**
	Métodos para la resolucion del problema en tiempo cuadratico. O(n^2)

*/
double solucionDirecta(Lista<Pareja<double,double> > &puntos);

/**
	Métodos para la resolucion del problema en tiempo logaritmico. O(n*log(n))

*/
Pareja<Lista<Pareja<double,double> >,Lista<Pareja<double,double> > > divideLista(Lista<Pareja<double,double> > &puntos,int m1);

Lista<Pareja<double,double> > filtraBanda(Lista<Pareja<double,double> > &l, double distanciaMaspequenaHastaAhora, double x1);

double recorreBanda(Lista<Pareja<double,double> > &l,double delta);

Lista<Pareja<double,double> > concatenaLista(Lista<Pareja<double,double> > &listaA, Lista<Pareja<double,double> > &listaB);

double solucionLogaritmica(Lista<Pareja<double,double> > &puntos,int n);

#endif // __TEST_H