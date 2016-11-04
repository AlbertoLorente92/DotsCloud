#include "CSVInOut.h"

void writeCSV(const std::string& fileName,const std::string& type,const int& num_dots,const double& timeSpend,const double& dist){
	std::ofstream file;
	file.open(fileName, std::fstream::out | std::fstream::app);
	file << type << "," << num_dots << "," << timeSpend << "," << dist << std::endl;
	file.close();
}

/*int readFile(const std::string& fileName,Pair<double, double>* &list,int& num_dots){
	std::ifstream file;
	file.open(fileName);

	if(!file.is_open())
		return -1;

	double x,y;
	file >> num_dots;
	list = new Pair<double, double>[num_dots];

	for(int i = 0; i < num_dots;i++){		
		file >> x;
		file >> y;
		list[i] = Pair<double,double> (x,y);
	}
	file.close();

	return 0;
}*/