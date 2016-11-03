#include "ordenacion.h"

void particion (Pareja<double,double> v[],int a,int b,int& p) {
	int i, j;
	Pareja<double,double> aux;
	i = a+1;
	j = b;
	while ( i <= j ) {
		if ( (v[i].primero() > v[a].primero()) && (v[j].primero() < v[a].primero()) ) {
			aux = v[i];
			v[i] = v[j]; 
			v[j] = aux;
			i = i + 1;
			j = j - 1;
		}else {
			if ( v[i].primero() <= v[a].primero() ) 
				i = i + 1;
			if ( v[j].primero() >= v[a].primero() ) 
				j = j - 1;
		}
	}
	p = j;
	aux = v[a]; 
	v[a] = v[p]; 
	v[p] = aux;
}
void quickSort1(Pareja<double,double> v[],int a,int b) {
	int p;
	if ( a <= b ) {
		particion(v, a, b, p);
		quickSort1(v, a, p-1);
		quickSort1(v, p+1, b);
	}
}
/*void quickSort (Pareja<double,double> v[],int num){	
	quickSort1(v, 0, num-1);
}*/

void particionY (Pareja<double,double> v[],int a,int b,int& p) {
	int i, j;
	Pareja<double,double> aux;
	i = a+1;
	j = b;
	while ( i <= j ) {
		if ( (v[i].segundo() > v[a].segundo()) && (v[j].segundo() < v[a].segundo()) ) {
			aux = v[i];
			v[i] = v[j]; 
			v[j] = aux;
			i = i + 1;
			j = j - 1;
		}else {
			if ( v[i].segundo() <= v[a].segundo() ) 
				i = i + 1;
			if ( v[j].segundo() >= v[a].segundo() ) 
				j = j - 1;
		}
	}
	p = j;
	aux = v[a]; 
	v[a] = v[p]; 
	v[p] = aux;
}
void quickSort1Y(Pareja<double,double> v[],int a,int b) {
	int p;
	if ( a <= b ) {
		particionY(v, a, b, p);
		quickSort1Y(v, a, p-1);
		quickSort1Y(v, p+1, b);
	}
}
/*void quickSortY (Pareja<double,double> v[],int num){	
	quickSort1Y(v, 0, num-1);
}*/

int compareY(const void * a, const void * b){
	if ((*(Pareja<double, double>*) a).segundo() < (*(Pareja<double, double>*) b).segundo()) return -1;
	if ((*(Pareja<double, double>*) a).segundo() > (*(Pareja<double, double>*) b).segundo()) return  1;
	return 0;
}

void quickSortY(Pareja<double, double> v[], int num){
	qsort(v, num, sizeof(Pareja<double, double>), compareY);

}

int compareX(const void * a, const void * b){
	if ((*(Pareja<double, double>*) a).primero() < (*(Pareja<double, double>*) b).primero()) return -1;
	if ((*(Pareja<double, double>*) a).primero() > (*(Pareja<double, double>*) b).primero()) return  1;
	return 0;
}

void quickSort (Pareja<double,double> v[],int num){
	qsort(v, num, sizeof(Pareja<double, double>), compareX);
}
