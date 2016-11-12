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
Pair<double, double>* copyList(Pair<double, double>* list,int num_dots_max);

void fullExecution();

bool checkIsInteger(const string& str,int& value);

char* getType(const int& type);


int main(int argc, char* argv[]){
	
	if(argc == 1){
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
	}

	return 0;
}

Pair<double, double>* copyList(Pair<double, double>* list,int num_dots){
	Pair<double, double>* copy = new Pair<double, double>[num_dots];
	for(int i = 0; i < num_dots; i++){
		copy[i]  = list[i];
	}
	return copy;
}

void fullExecution(){
	int num_dots_min, num_dots_max, increment, num_repetitions, precision, range;
	string fileDotsExit,fileResExit;

	string read;
	bool ok;
	int number;
	cout << "Welcome to the full execution of DotsCloud" << endl;
	cout << "This version will execute the n^2 and the log solution to the problem" << endl;
	cout << "Please enter the following params" << endl;

	ok = false;
	number = 0;
	do{
		cout << "Min number of dots in the cloud  (positive integer): ";
		cin >> read;
		if(checkIsInteger(read,number) && number>0){
			ok = true;
			num_dots_min = number;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);

	ok = false;
	number = 0;
	do{
		cout << "Number of dots to increment in the cloud  (positive integer): ";
		cin >> read;
		if(checkIsInteger(read,number) && number>0){
			ok = true;
			increment = number;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);

	ok = false;
	number = 0;
	do{
		cout << "Max number of dots in the cloud  (positive integer): ";
		cin >> read;
		if(checkIsInteger(read,number) && number>0){
			ok = true;
			num_dots_max = number;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);

	ok = false;
	number = 0;
	do{
		cout << "Repetitions of the execution  (positive integer): ";
		cin >> read;
		if(checkIsInteger(read,number) && number>0){
			ok = true;
			num_repetitions = number;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);

	number = 0;
	ok = false;
	do{
		cout << "Range of dots in the cloud (positive integer): ";
		cin >> read;
		if(checkIsInteger(read,number) && number>0){
			range = number;
			ok = true;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);

	number = 0;
	ok = false;
	do{
		cout << "Precision, number of decimals in the dots (positive integer [0,10,100,1000,...)): ";
		cin >> read;
		if(checkIsInteger(read,number) && number>=0){
			precision = number;
			ok = true;
		}else{
			cout << "Input incorrect." << endl;
		}
	}while(!ok);

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

	;

	cout << "Starting..." << endl;
	double timeSpend,dist;

	ok = true;
	number = num_dots_min;

	while(number <= num_dots_max && ok){
		for(int i = 0; i < num_repetitions && ok; i++){
			Pair<double, double>* copy = copyList(list,number);
		
			if(find(number,1,copy,8,timeSpend,dist)==0){
				printf(getType(1));
				printf(" Dots N = %i",number);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV(fileResExit,getType(1),number,timeSpend,dist);
			}else{
				printf("n^2 - Execution error");
				ok = false;
			}
		}
		number = number + increment;
	}

	number = num_dots_min;
	while(number <= num_dots_max && ok){
		for(int i = 0; i < num_repetitions && ok; i++){
			Pair<double, double>* copy = copyList(list,number);

			if(ok && find(number,2,copy,8,timeSpend,dist)==0){
				printf(getType(2));
				printf(" Dots N = %i",number);
				printf(" Dist = %lf",dist);	
				printf(" Time = %lf\n",timeSpend);	
				writeCSV(fileResExit,getType(2),number,timeSpend,dist);
			}else{
				printf("log - Execution error");
				ok = false;
			}
		}
		number = number + increment;
	}


	

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
