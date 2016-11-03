#include <time.h>
#include <list>
#include "Pareja.h"
#include "test.h"

#include <iostream>
using namespace std;

int main(){
	srand((int)time(NULL));

	for(int i = 1 ; i <= 15; i++){
		list<Pareja<double,double>> listaPuntos = generaPuntos(i*1000);

 		busca(i*1000,1,listaPuntos);
		busca(i*1000,2,listaPuntos);		
	}

	return 0;
}