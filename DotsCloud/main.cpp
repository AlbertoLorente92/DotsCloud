#include "test.h"
#include <iostream>
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
void getSomethingByConsole(string ask,int &param);

bool executeWithParams(int num_dots_min,int num_dots_max,int num_repetitions,Pair<double, double>* list,string fileResExit,int increment,int type, int num_proces);

Pair<double, double>* copyList(Pair<double, double>* list,int num_dots_max);

void fullExecution();

bool checkIsInteger(const string& str,int& value);

char* getType(const int& type);

int main(int argc, char* argv[]){

		// Create list of dots
		// DotsCloud.exe 15000 0 exit.txt 100 100

	/*Pair<double, double>* list = new Pair<double, double>[50000];
		if(fillListDots(50000,-100.0,100.0,list)==0){
			writeFile("exit2.txt",list,50000);
		}*/


		int num_dots;
		Pair<double, double>* list; 
		/*if(readFile("exit2.txt",list,num_dots)==0){
			double timeSpend,dist;
			if(find(num_dots,1,list,8,timeSpend,dist)==0){
				printf(getType(1));
				printf(" Dots N = %i",num_dots);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV("resultados.txt",getType(1),num_dots,timeSpend,dist);
			}else{
				printf("Execution error");
			}
		}else{
			printf("Reading error");
		}*/

		if(readFile("exit2.txt",list,num_dots)==0){
			double timeSpend,dist;
			if(find(num_dots,2,list,8,timeSpend,dist)==0){
				printf(getType(1));
				printf(" Dots N = %i",num_dots);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV("resultados.txt",getType(2),num_dots,timeSpend,dist);
			}else{
				printf("Execution error");
			}
		}else{
			printf("Reading error");
		}
	/*if(argc == 1){
		fullExecution();
	}
	
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
	}*/


	system("PAUSE");
	return 0;
}

void getSomethingByConsole(string ask,int &param){
	int number = 0;
	bool ok = false;
	string read;
	do{
		cout << ask;
		cin >> read;
		if(checkIsInteger(read,number) && number>=0){
			param = number;
			ok = true;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);
}

bool executeWithParams(int num_dots_min,int num_dots_max,int num_repetitions,Pair<double, double>* list,string fileResExit,int increment,int type, int num_proces){
	double timeSpend,dist;
	bool ok = true;
	int number = num_dots_min;
	while(number <= num_dots_max && ok){
		for(int i = 0; i < num_repetitions && ok; i++){
			Pair<double, double>* copy = copyList(list,number);

			if(ok && find(number,type,copy,num_proces,timeSpend,dist)==0){
				printf(getType(type));
				printf(" Dots N = %i",number);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV(fileResExit,getType(type),number,timeSpend,dist);
			}else{
				printf("log - Execution error");
				ok = false;
			}
		}
		number = number + increment;
	}

	return ok;
}

Pair<double, double>* copyList(Pair<double, double>* list,int num_dots){
	Pair<double, double>* copy = new Pair<double, double>[num_dots];
	for(int i = 0; i < num_dots; i++){
		copy[i]  = list[i];
	}
	return copy;
}

void fullExecution(){
	int num_dots_min, num_dots_max, increment, num_repetitions, precision, range,num_process;
	string fileDotsExit,fileResExit;

	cout << "Welcome to the full execution of DotsCloud" << endl;
	cout << "This version will execute the n^2 and the log solution to the problem" << endl;
	cout << "Please enter the following params" << endl;

	getSomethingByConsole("Min number of dots in the cloud  (positive integer): ",num_dots_min);
	getSomethingByConsole("Number of dots to increment in the cloud  (positive integer): ",increment);
	getSomethingByConsole("Max number of dots in the cloud  (positive integer): ",num_dots_max);
	getSomethingByConsole("Repetitions of the execution  (positive integer): ",num_repetitions);
	getSomethingByConsole("Range of dots in the cloud (positive integer): ",range);
	getSomethingByConsole("Precision, number of decimals in the dots (positive integer [0,10,100,1000,...)): ",precision);
	getSomethingByConsole("Number of procesors (positive integer): ",num_process);

	cout << "File where to write the biggest dots cloud (string): ";
	cin >> fileDotsExit;
	cout << "File where to write the results of the executions (string): ";
	cin >> fileResExit;

	Pair<double, double>* list = new Pair<double, double>[num_dots_max];
	if(fillListDots(num_dots_max,precision,range,list)==0){
		writeFile(fileDotsExit,list,num_dots_max);
	}else{
		cout << "Error filling the list of dots" << endl;
		return;
	}

	cout << "Starting..." << endl;
	if(executeWithParams(num_dots_min,num_dots_max,num_repetitions,list,fileResExit,increment,1,num_process)){
		executeWithParams(num_dots_min,num_dots_max,num_repetitions,list,fileResExit,increment,2,0);
	}

	cout << "Execution finish" << endl;
	system("pause");
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
