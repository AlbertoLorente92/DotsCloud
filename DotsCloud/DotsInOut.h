#ifndef __DOTSINOUT_H
#define __DOTSINOUT_H

#include "Pair.h"

#include <string>
#include <fstream>

void writeFile(const std::string& fileName,const Pair<double, double> list[],const int& num_dots);

int readFile(const std::string& fileName,Pair<double, double>* &list,int& num_dots);

#endif // __DOTSINOUT_H