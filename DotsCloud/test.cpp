#include "test.h"

double distBetweenDots(Pair<double,double> dot1,Pair<double,double> dot2){
	return sqrt(pow(dot1.first()-dot2.first(),2) + pow(dot1.second()-dot2.second(),2));
}

double quadraticSolution(const Pair<double, double> list[],const int& num_dots){
	double dist = DBL_MAX;

	omp_set_dynamic(0);
	omp_set_num_threads(8); 
	#pragma omp parallel
	{
		#pragma omp for schedule(static)
		for(int i = 0; i < num_dots; i++){
			for(int j = i+1; j < num_dots; j++){
				if(distBetweenDots(list[i],list[j]) < dist){
					dist = distBetweenDots(list[i],list[j]);
					
				}
			}
		}
	}

	if(dist == DBL_MAX){
		return 0;
	}else{
		return dist;
	}
}


/////WORK HERE

double runBand(list<Pair<double,double>>& l, double delta){
	double distancia=delta;
	list<Pair<double, double>>::iterator it = l.begin();
	
	while(it!=l.end()){
		Pair<double,double> P1 = *it;
		list<Pair<double, double>>::iterator it2 = it;
		it2++;
		int i = 0;
		while(i<7 && (it2!=l.end())){// <= para que lo haga 7 veces 
				Pair<double,double> P2 = *it2;

				if (distBetweenDots(P1, P2) < distancia){
					distancia = distBetweenDots(P1, P2);
				}
			it2++;
			i++;
		}
		it++;
	}

	return distancia;
}

list<Pair<double, double>> filterBand(Pair<double, double> list_dots[],const int& num_dots,const double& less_dist,const double& pointer){
	list<Pair<double, double>> list_band;

	double plusDelta = pointer-less_dist;
	double lessDelta = pointer+less_dist;

	for(int i = 0; i < num_dots;i++){
		if((list_dots[i].first() >= lessDelta) && (list_dots[i].first() <= plusDelta)){
			list_band.push_back(list_dots[i]);
		}
	}

	return list_band;
}

double logarithmicallySolution(Pair<double,double> list_dots[],const int& num_dots){
	double dist;

	if (num_dots <= 3) {
		quadraticSolution(list_dots,num_dots);
		orderYAxis(list_dots,num_dots);
	}else{ 

		int mid = num_dots / 2;
		double aux = (list_dots[mid].first() + list_dots[mid+1].first()) / 2;
	
		double delta = min(logarithmicallySolution(list_dots,mid), logarithmicallySolution(list_dots,num_dots-mid));

		list<Pair<double, double>> band = filterBand(list_dots,num_dots, delta, aux);

		dist = min (delta,runBand(band,delta));
	}
		
	return dist;
}

int find(const int& num_dots,const int& type,Pair<double,double> list[],double& timeSpend,double& dist){	
	clock_t tClk;	
 
	if(num_dots<=0){
		return -2;
	}

	switch(type){
		case 1:													
			tClk = clock();
			dist = quadraticSolution(list,num_dots);
			timeSpend = ((double) (clock() - tClk)) / CLOCKS_PER_SEC;	
		break;

		case 2:											
			tClk = clock();
			dist = logarithmicallySolution(list,num_dots);
			timeSpend = ((double) (clock() - tClk)) / CLOCKS_PER_SEC;
		break;

		default:
			return -1;
		break;
	}

	if(dist < 0){
		return -1;
	}else{
		return 0;
	}
}