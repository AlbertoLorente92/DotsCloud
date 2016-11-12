#include "CSVInOut.h"

void writeCSV(const std::string& fileName,const std::string& type,const int& num_dots,const double& timeSpend,const double& dist){
	std::ofstream file;
	file.open(fileName, std::fstream::out | std::fstream::app);
	file << type << "," << num_dots << "," << timeSpend << "," << dist << std::endl;
	file.close();
}