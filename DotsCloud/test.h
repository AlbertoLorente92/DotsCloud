#ifndef __TEST_H
#define __TEST_H

#include "Order.h"
#include "GenerateDots.h"
#include "DotsInOut.h"
#include "CSVInOut.h"

#include <list>
#include <time.h>
#include <omp.h>
using namespace std;

/**
	 This function will find the less distance between two point in all points indicated in list with length num_dots. 
	 
	 You could execute this wiht 2 differents forms
	 1 -> Quadratic solution (n^2). This will take a long time to get it done. If you use this option you MUST especified the number of threads.
	 2 -> Logarithmically solution (n*log(n)). Way less time. If you use this option num_threads value will be ignored.

	 Both types will give the distance and the execution time.

	 @return 
	 0  -> Correct.
	 -1 -> Error, execution error.
	 -2 -> Error, num_dots value MUST be above zero.
	 -3 -> Error, using Quadratic solution num_threads value MUST be above zero.
*/
int find(const int& num_dots,const int& type,Pair<double,double> list[],const int& num_threads,double& timeSpend,double& dist);

#endif // __TEST_H