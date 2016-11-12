#ifndef __CSVINOUT_H
#define __CSVINOUT_H

#include <string>
#include <fstream>

/**
	 This function write the results of the find function in fileName with the following style:
	 type[n^2,log],num_dots,timeSpend,dist
*/
void writeCSV(const std::string& fileName,const std::string& type,const int& num_dots,const double& timeSpend,const double& dist);

#endif // __CSVINOUT_H