#include "GenerateDots.h"

int fillListDots(const int& num_dots,const int& precision,const int& range,Pair<double, double> list[]){
	if(num_dots <= 0)
		return -1;
	if(precision <= 0)
		return -2;
	if((precision % 10) != 0)
		return -3;
	if(range <= 0)
		return -4;


	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(-range, range); // define the range

	//((double)((double)distr(eng))/((double)precision));
	//srand((unsigned int)time(NULL));

	for(int i = 0; i < num_dots; i++){
		//list[i] = (Pair<double,double> (((rand() % (precision*range))/(double)precision) -(double)range,((rand() % (precision*range))/(double)precision) -(double)range));
		list[i] = (Pair<double,double>(((double)((double)distr(eng))/((double)precision)),((double)((double)distr(eng))/((double)precision))));
	}

	return 0;
}