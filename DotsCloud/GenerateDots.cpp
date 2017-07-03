#include "GenerateDots.h"

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int fillListDots(const int& num_dots,const double& fMin,const double& fMax,Pair<double, double> list[]){
	if(num_dots <= 0)
		return -1;
	if(fMin > fMax)
		return -2;

	srand((unsigned int)time(NULL));
	for(int i = 0; i < num_dots; i++){
		list[i] = (Pair<double,double>(fRand(fMin,fMax),fRand(fMin,fMax)));
	}

	return 0;
}