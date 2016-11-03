#include "GenerateDots.h"

int fillListDots(const int& num_dots,const int& precision,const int& range,Pair<double, double> list[]){
	if(num_dots<=0)
		return -1;
	if((precision % 10) !=0)
		return -2;
	if(range <= 0)
		return -3;
	srand((int)time(NULL));

	for(int i = 0; i < num_dots; i++){
		list[i] = (Pair<double,double> (((rand() % (precision*range*2))/(double)precision) -(double)range,((rand() % (precision*range*2))/(double)precision) -(double)range));
	}

	return 0;
}