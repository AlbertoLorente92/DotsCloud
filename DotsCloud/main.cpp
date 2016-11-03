#include "test.h"

void writeFile(const string& file,const Pareja<double, double> list[],const int& num_dots);
/**
	argv[0] -> ".exe"
	argv[1] -> "Num dots"
	argv[2] -> "Execution type [{0,CreateDotsCloud},{1,quadratic},{2,log}]"
	argv[3] -> "file.txt (list)"
	argv[4] -> "Precision"
	argv[5] -> "Range of dots {-argv[5],+argv[5]}"
*/
int main(int argc, const char* argv[]){
	srand((int)time(NULL));
	
	if(argc == 6){
		// Create list of dots
		Pareja<double, double>* list = new Pareja<double, double>[atoi(argv[1])];
		if(generaPuntos(atoi(argv[1]),atoi(argv[4]),atoi(argv[5]),list)==0){
			writeFile(argv[3],list,atoi(argv[1]));
		}
	}else if(argc == 6){
		// Execute program
	}

	//system("dir");
	//system("DotsCloud.exe");
	//system("dir");
	/*for(int i = 1 ; i <= 15; i++){
		list<Pareja<double,double>> listaPuntos = generaPuntos(i*1000);

 		busca(i*1000,1,listaPuntos);
		busca(i*1000,2,listaPuntos);		
	}*/
	system("pause");
	return 0;
}

void writeFile(const string& fileName,const Pareja<double, double> list[],const int& num_dots){
	std::ofstream file;
	file.open(fileName);
	file << num_dots << endl;
	for(int i = 0; i < num_dots;i++){
		file << list[i].primero() << " " << list[i].segundo() << endl;
	}
	file.close();
}