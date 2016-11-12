#include "test.h"

/**
	argv[0] -> ".exe"
	argv[1] -> "Num dots				||	Readfile.txt (list)"
	argv[2] -> "							Execution type [{0,CreateDotsCloud},{1,quadratic},{2,log}]"
	argv[3] -> "Writefile.txt (list)	||	Writefile.txt (result)"
	argv[4] -> "Precision				||	num_threads"
	argv[5] -> "Range of dots {-argv[5],+argv[5]}"
*/


/**
	Check if the string str is a valid Integer. If not, this function will return false. Otherwise will return true and the value of the integer
*/
bool checkIsInteger(const string& str,int& value);

char* getType(const int& type);

int main(int argc, char* argv[]){
	string str = argv[1];
	int x;
	if(checkIsInteger(argv[1],x))
		printf("%i",x);

	if(argc == 6 && (atoi(argv[2]))==0){
		// Create list of dots
		// DotsCloud.exe 15000 0 exit.txt 100 100
		Pair<double, double>* list = new Pair<double, double>[atoi(argv[1])];
		if(fillListDots(atoi(argv[1]),atoi(argv[4]),atoi(argv[5]),list)==0){
			writeFile(argv[3],list,atoi(argv[1]));
		}
	}else if(argc == 5){
		// Execute program
		// DotsCloud.exe salida.txt 1 salida.csv 
		int num_dots;
		Pair<double, double>* list; 
		if(readFile(argv[1],list,num_dots)==0){
			double timeSpend,dist;
			if(find(num_dots,atoi(argv[2]),list,8,timeSpend,dist)==0){
				printf(getType(atoi(argv[2])));
				printf(" Dots N = %i",num_dots);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV(argv[3],getType(atoi(argv[2])),num_dots,timeSpend,dist);
			}else{
				printf("Execution error");
			}
		}else{
			printf("Reading error");
		}
	}

	return 0;
}

bool checkIsInteger(const string& str,int& value){
	for(int i = 0; i < (int)str.length(); i++){
		if(str.at(i)!='-' && (str.at(i) < (int)'0' || str.at(i) > (int)'9')){
			return false;
		}
	}
	value = stoi(str);
	return true;
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
