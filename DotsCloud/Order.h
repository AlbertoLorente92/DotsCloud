#ifndef __ORDER_H
#define __ORDER_H
#include <stdlib.h>
#include "Pair.h"

/**
	 This function will order the list of points with length num_dots by the X axis.
*/
void orderXAxis(Pair<double, double> list[],const int& num_dots);

/**
	 This function will order the list of points with length num_dots by the Y axis.
*/
void orderYAxis(Pair<double, double> list[],const int& num_dots);

#endif // __ORDER_H