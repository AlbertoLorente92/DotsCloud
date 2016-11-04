#include "Order.h"

int compareY(const void * a, const void * b){
	if ((*(Pair<double, double>*) a).second() < (*(Pair<double, double>*) b).second()) return -1;
	if ((*(Pair<double, double>*) a).second() > (*(Pair<double, double>*) b).second()) return  1;
	return 0;
}

int compareX(const void * a, const void * b){
	if ((*(Pair<double, double>*) a).first() < (*(Pair<double, double>*) b).first()) return -1;
	if ((*(Pair<double, double>*) a).first() > (*(Pair<double, double>*) b).first()) return  1;
	return 0;
}

void quickSortY(Pair<double, double> v[], int num){
	qsort(v, num, sizeof(Pair<double, double>), compareY);

}

void quickSortX (Pair<double,double> v[],int num){
	qsort(v, num, sizeof(Pair<double, double>), compareX);
}

void orderYAxis(Pair<double, double> list[],const int& num_dots){
	quickSortY(list,num_dots);
}

void orderXAxis(Pair<double, double> list[],const int& num_dots){
	quickSortX(list,num_dots);
}