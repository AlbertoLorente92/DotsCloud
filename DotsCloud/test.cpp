#include "test.h"

void busca(int i,int tipo,list<Pareja<double,double> > &listaPuntos){
	float tiempo;
	clock_t tIni=0;		
	clock_t tFin=0;	
	bool b = true;
	double distancia;
	list<Pareja<double, double> > L;

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
			distancia = solucionLogaritmica(listaPuntos,listaPuntos.size());
			tFin = clock();
			cout << " Distancia = " << distancia; //SolucionLogaritmica
			cout << endl;	
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

void ordenaPorEjeX(list<Pareja<double, double> > &puntos){
	Pareja<double,double> *a = new Pareja<double,double>[puntos.size()];
	list<Pareja<double, double>>::iterator it = puntos.begin();
	int N = puntos.size();
	int i = 0;
	while(it!=puntos.end()){
		a[i]=*it;
		it++;
		puntos.pop_front();
		i++;
	}

	quickSort(a,N);
	
	for(int j = 0; j < N;j++){
		puntos.push_back(a[j]);
	}
	
	delete[] a;
}

void ordenaPorEjeY(list<Pareja<double,double>> &puntos){
	Pareja<double,double> *a = new Pareja<double,double>[puntos.size()];
	list<Pareja<double, double>>::iterator it = puntos.begin();
	int N = puntos.size();
	int i = 0;
	while(it!=puntos.end()){
		a[i]=*it;
		it++;
		puntos.pop_front();
		i++;
	}
	
	quickSortY(a,N);
	
	for(int j = 0; j < N;j++){
		puntos.push_back(a[j]);
	}
	
	delete[] a;
}

list<Pareja<double, double>> generaPuntos(int n){
	list<Pareja<double, double>> listaPuntos;

	for(int i = 0; i < n; i++){
		double n1 = (rand() % 20000)/100.00 -100;
		double n2 = (rand() % 20000)/100.00 -100;
		Pareja<double,double> a(n1,n2);

		listaPuntos.push_back(a);
	}

	return listaPuntos;
}

double distanciaEntrePuntos(Pareja<double,double> p1,Pareja<double,double> p2){
	return sqrt(pow(p1.primero()-p2.primero(),2) + pow(p1.segundo()-p2.segundo(),2));
}

double solucionDirecta(list<Pareja<double, double> > &puntos){
	double distancia=285;

	list<Pareja<double, double> >::iterator itPunto = puntos.begin();// puntos.principio();

	while(itPunto != puntos.end()){
		list<Pareja<double, double> >::iterator itCompara = itPunto;
		itCompara++;

		while(itCompara != puntos.end()){
				double distanciaNueva = distanciaEntrePuntos(*itPunto,*itCompara);

				if (distanciaNueva < distancia){
					distancia = distanciaNueva;
				}
			itCompara++;
		}

		itPunto++;
	}

	return distancia;
}

Pareja<list<Pareja<double, double>>, list<Pareja<double, double>>> divideLista(list<Pareja<double, double>> &puntos, int m1){
	list<Pareja<double, double> > izquierda;
	list<Pareja<double, double> > derecha;
	
	list<Pareja<double, double> >::iterator it = puntos.begin();
	int i=0;
	while(i<m1){
		izquierda.push_back(*it);
		it++;
		i++;
	}
	while(i<(int)puntos.size()){
		derecha.push_back(*it);
		it++;
		i++;
	}

	Pareja<list<Pareja<double, double> >, list<Pareja<double, double> > > P(izquierda, derecha);

	return P;
}

list<Pareja<double, double>> filtraBanda(list<Pareja<double, double>> &l, double distanciaMaspequenaHastaAhora, double x1){
	//eje 0 delta delta x otro 
	list<Pareja<double, double> > listaDeltas;
	list<Pareja<double, double> >::iterator it = l.begin();
	double menosDelta = x1-distanciaMaspequenaHastaAhora;
	double masDelta = x1+distanciaMaspequenaHastaAhora;

	while(it != l.end()){
		if((it->primero() >= menosDelta) && (it->primero() <= masDelta)){
			listaDeltas.push_back(*it);
		}
		it++;
	}

	return listaDeltas;
}

double recorreBanda(list<Pareja<double,double>> &l, double delta){
	double distancia=delta;
	list<Pareja<double, double>>::iterator it = l.begin();
	
	while(it!=l.end()){
		Pareja<double,double> P1 = *it;
		list<Pareja<double, double>>::iterator it2 = it;
		it2++;
		int i = 0;
		while(i<7 && (it2!=l.end())){// <= para que lo haga 7 veces 
				Pareja<double,double> P2 = *it2;

				if (distanciaEntrePuntos(P1, P2) < distancia){
					distancia = distanciaEntrePuntos(P1, P2);
				}
			it2++;
			i++;
		}
		it++;
	}

	return distancia;
}

list<Pareja<double, double>> concatenaLista(list<Pareja<double, double>> &listaA, list<Pareja<double, double>> &listaB){
	list<Pareja<double, double>>::iterator it = listaA.begin();
	list<Pareja<double, double>>::iterator it2 = listaB.begin();
	list<Pareja<double, double>> listaUnion;
	
	while ((it != listaA.end()) && (it2 != listaB.end())) {
		if (it->segundo() <= it2->segundo()) {
			listaUnion.push_back(*it);
			it++;
		} else {
			listaUnion.push_back(*it2);
			it2++;
		}
	}
		   
	while (it != listaA.end()) {
		listaUnion.push_back(*it);
		it++;
	}

	while (it2 != listaB.end()) {
		listaUnion.push_back(*it2);
		   it2++;
	 }
		   
	return listaUnion;
}

double solucionLogaritmica(list<Pareja<double,double>> &puntos, int n){
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
		Pareja<list<Pareja<double, double> >, list<Pareja<double, double> > > par = divideLista(puntos, m1);

		list<Pareja<double, double> > I = par.primero();
		list<Pareja<double, double> > D = par.segundo();

		double xMinima = I.back().primero();
		double xMaxima = D.front().primero();

		double xl = (xMinima + xMaxima) / 2;

		// Resolvemos recursivamente la s dos nubes
		double sol1 = solucionLogaritmica(I,m1);
		double sol2 = solucionLogaritmica(D,m2);

		// Ordenamos por la coordenada y la nube de puntos		
		double delta = min(sol1, sol2);

		//Unimos las dos listas de numeros ordenadas por la Y
		list<Pareja<double, double> > unionListas = concatenaLista(I, D);
		// Filtramos los puntos segun un delta dado
		list<Pareja<double, double> > B = filtraBanda(unionListas, delta, xl);

		dist=recorreBanda(B,delta);

		// Elegimos la mejor solucion de la s t re s
		sol = min (delta,dist);
	}
		
	return sol;
}