#ifndef __CSVINOUT_H
#define __CSVINOUT_H

#include <string>
#include <fstream>

void writeCSV(const std::string& fileName,const std::string& type,const int& num_dots,const double& timeSpend,const double& dist);

//int readFile(const std::string& fileName,Pair<double, double>* &list,int& num_dots);

#endif // __CSVINOUT_H