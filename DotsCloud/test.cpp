#include "test.h"

double distBetweenDots(Pair<double,double> dot1,Pair<double,double> dot2){
	return sqrt(pow(dot1.first()-dot2.first(),2) + pow(dot1.second()-dot2.second(),2));
}

double quadraticSolution(const Pair<double, double> list[],const int& num_dots,const int& num_threads){
	double dist = DBL_MAX;

	omp_set_dynamic(0);
	omp_set_num_threads(num_threads); 
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

double runBand(list<Pair<double,double>> l, const double& delta){
	double distancia=delta;
	int i;
	list<Pair<double, double>>::iterator it1 = l.begin();
	list<Pair<double, double>>::iterator it2;
	while(it1 != l.end()){
		it2 = it1;
		it2++;
		i = 0;
		while(/*i < 7 &&*/ (it2 != l.end())){
			if (distBetweenDots(*it1, *it2) < distancia){
				distancia = distBetweenDots(*it1, *it2);
			}
			it2++;
			i++;
		}
		it1++;
	}

	/*while(it!=l.end()){
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
	}*/

	return distancia;
}

list<Pair<double, double>> filterBand(Pair<double, double> list_dots[],const int& total_num_dots,const double& less_dist,const double& pointer){
	list<Pair<double, double>> list_band;

	double plusDelta = pointer-less_dist-(pointer*1.0);
	double lessDelta = pointer+less_dist+(pointer*1.0);

	for(int i = 0; i < total_num_dots;i++){
		if((list_dots[i].first() >= lessDelta) && (list_dots[i].first() <= plusDelta)){
			list_band.push_back(list_dots[i]);
		}
	}

	return list_band;
}

double quadraticSolutionForLog(const Pair<double, double> list[],const int& num_start,const int& num_dots){
	double dist = DBL_MAX;
	
	for(int i = num_start; i < num_dots; i++){
		for(int j = i+1; j < num_dots; j++){
			if(distBetweenDots(list[i],list[j]) < dist){
				dist = distBetweenDots(list[i],list[j]);		
			}
		}
	}
	
	return dist;
}

double logarithmicallySolution(Pair<double,double> list_dots[],int num_start,int num_dots,const int& total_num_dots){
	/*for(int i = num_start; i < num_dots; i++){
		printf("%lf ",list_dots[i].first());
	}*/
	double dist,delta,x1,aux;
	int mid;
	if (num_dots-num_start <= 3) {
		dist = quadraticSolutionForLog(list_dots,num_start,num_dots);
		//printf("\nPruieba =%lf\n",(list_dots+1)[0].first());

		//qsort(list_dots+num_start, num_dots-num_start, sizeof(Pair<double, double>), compareY);

		/*for(int i = num_start; i < num_dots; i++){
			printf("%lf ",list_dots[i].second());
		}*/
		//orderYAxis((list_dots+(sizeof(Pair<double, double>)*num_start)),num_dots-num_start);
	}else{ 

		mid = abs(num_dots+num_start) / 2;
		//printf("\nMid - %i\n",mid);
		//printf("\nX - %lf %lf\n",list_dots[mid].first() , list_dots[mid+1].first());
		x1 = (list_dots[mid].first() + list_dots[mid+1].first()) / 2;
		//printf("\naux - %lf\n",aux);
		delta = min(logarithmicallySolution(list_dots,num_start,mid,total_num_dots), logarithmicallySolution(list_dots,mid,num_dots,total_num_dots));
		//printf("\ndelta - %lf\n",delta);
		list<Pair<double, double>> band = filterBand(list_dots,total_num_dots, delta, x1);

		//dist = min(logarithmicallySolution(list_dots,num_start,mid), logarithmicallySolution(list_dots,mid,num_dots));
		dist = min (delta,runBand(band,delta));
	}
		
	return dist;
}

int findAux(const int& num_dots,const int& type,Pair<double,double> list[],const int& num_threads,double& timeSpend,double& dist){	
	clock_t tClk;	
 
	if(num_dots<=0){
		return -2;
	}

	if(type==1 && num_threads <= 0){
		return -3;
	}

	switch(type){
		case 1:													
			tClk = clock();
			dist = quadraticSolution(list,num_dots,num_threads);
			timeSpend = ((double) (clock() - tClk)) / CLOCKS_PER_SEC;	
		break;

		case 2:											
			tClk = clock();
			orderXAxis(list,num_dots);			
			/*for(int i = 0; i < num_dots; i++){
				printf("%lf ",list[i].first());
			}
			printf("\n%i\n",list);
			printf("\n%i\n",sizeof(Pair<double, double>));*/
			dist = logarithmicallySolution(list,0,num_dots,num_dots);
			timeSpend = ((double) (clock() - tClk)) / CLOCKS_PER_SEC;
		break;

		default:
			return -1;
		break;
	}

	if(dist < 0){
		return -4;
	}else{
		return 0;
	}
}

int find(const int& num_dots,const int& type,Pair<double,double> list[],const int& num_threads,double& timeSpend,double& dist){	
	return findAux(num_dots, type,list,num_threads,timeSpend,dist);
}

int find(const int& num_dots,const int& type,Pair<double,double> list[],double& timeSpend,double& dist){	
	return findAux(num_dots, type,list,1,timeSpend,dist);
}

