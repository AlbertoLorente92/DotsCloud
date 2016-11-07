#include "DotsInOut.h"

void writeFile(const std::string& fileName,const Pair<double, double> list[],const int& num_dots){
	std::ofstream file;
	file.open("aux.txt");
	file << num_dots << std::endl;
	for(int i = 0; i < num_dots;i++){
		file << list[i].first() << " " << list[i].second() << std::endl;
	}
	file.close();
}

int readFile(const std::string& fileName,Pair<double, double>* &list,int& num_dots){
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
}