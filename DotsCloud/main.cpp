///#include "test.h"
#include "GenerateDots.h"
#include "DotsInOut.h"
#include "CSVInOut.h"
#include "Test.h"
/**
	argv[0] -> ".exe"
	argv[1] -> "Num dots || Readfile.txt (list)"
	argv[2] -> "Execution type [{0,CreateDotsCloud},{1,quadratic},{2,log}]"
	argv[3] -> "Writefile.txt (list) || Writefile.txt (result)"
	argv[4] -> "Precision"
	argv[5] -> "Range of dots {-argv[5],+argv[5]}"
*/
char* getType(const int& type);

int main(int argc, const char* argv[]){
	if(argc == 6 && (atoi(argv[2]))==0){
		// Create list of dots
		// DotsCloud.exe 15000 0 exit.txt 100 100
		Pair<double, double>* list = new Pair<double, double>[atoi(argv[1])];
		if(fillListDots(atoi(argv[1]),atoi(argv[4]),atoi(argv[5]),list)==0){
			writeFile(argv[3],list,atoi(argv[1]));
		}
	}else if(argc == 4){
		// Execute program
		// DotsCloud.exe exit.txt 1 salida.csv 
		int num_dots;
		Pair<double, double>* list; 
		if(readFile(argv[1],list,num_dots)==0){
			double timeSpend,dist;
			if(find(num_dots,atoi(argv[2]),list,timeSpend,dist)==0){
				printf(getType(atoi(argv[2])));
				printf(" Dots N = %i",num_dots);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV(argv[3],getType(atoi(argv[2])),num_dots,timeSpend,dist);
			}else{
				printf("err");
			}
		}
	}

	return 0;
}

char* getType(const int& type){
	switch(type){
		case 1:													
			return "n^2";
		break;

		case 2:											
			return "log";
		break;

		default:
			return "err";
		break;
	}
	return "err";
}