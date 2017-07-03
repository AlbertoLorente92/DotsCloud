#ifndef __GENERATEDOTS_H
#define __GENERATEDOTS_H

#include "Pair.h"

#include <time.h>
#include <cstdlib>
#include <random>

/**
	 This function will fill the list with length num_dots of points (x,y) in range [-range,+range] with number of decimals
	 expressed in the precision param.

	 @return 
	 0  -> Correct.
	 -1 -> Error, num_dots MUST be a value above zero.
	 -2 -> Error, fMin value MUST be a value above fMax value.
*/
int fillListDots(const int& num_dots,const double& fMin,const double& fMax,Pair<double, double> list[]);

#endif // __TEST_H