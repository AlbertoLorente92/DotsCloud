#ifndef __DOTSINOUT_H
#define __DOTSINOUT_H

#include "Pair.h"

#include <string>
#include <fstream>

/**
	 This function write the list of points with length num_dots in the file fileName.
*/
void writeFile(const std::string& fileName,const Pair<double, double> list[],const int& num_dots);

/**
	 This function will read the file fileName and will return the list of points in it and his length if correct.

	 @return 
	 0  -> Correct.
	 -1 -> Error, wrong fileName.
	 -2 -> Error, file ends before this function can read all num_dots indicated in the file.
*/
int readFile(const std::string& fileName,Pair<double, double>* &list,int& num_dots);

#endif // __DOTSINOUT_H