///#include "test.h"
#include "GenerateDots.h"
#include "DotsInOut.h"

/**
	argv[0] -> ".exe"
	argv[1] -> "Num dots"
	argv[2] -> "Execution type [{0,CreateDotsCloud},{1,quadratic},{2,log}]"
	argv[3] -> "file.txt (list)"
	argv[4] -> "Precision"
	argv[5] -> "Range of dots {-argv[5],+argv[5]}"
*/
int main(int argc, const char* argv[]){
	/*Pair<double, double>* list = new Pair<double, double>[100];
	Pair<double, double>* list2; 
	if(fillListDots(100,100,100,list)==0){
		writeFile("hola.txt",list,100);
		
		int n;
		if(readFile("hola.txt",list2,n)==0){
			writeFile("hola2.txt",list2,n);
		}
	}*/

	if(argc == 6 && (atoi(argv[2]))==0){
		// Create list of dots
		Pair<double, double>* list = new Pair<double, double>[atoi(argv[1])];
		if(fillListDots(atoi(argv[1]),atoi(argv[4]),atoi(argv[5]),list)==0){
			writeFile(argv[3],list,atoi(argv[1]));
		}
	}else if(argc == 6){
		// Execute program
		int n;
		Pair<double, double>* list; 
		if(readFile(argv[3],list,n)==0){
			
		}
	}

	/*for(int i = 1 ; i <= 15; i++){
		list<Pareja<double,double>> listaPuntos = generaPuntos(i*1000);

 		busca(i*1000,1,listaPuntos);
		busca(i*1000,2,listaPuntos);		
	}*/
	system("pause");
	return 0;
}
