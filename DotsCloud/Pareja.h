#ifndef __PAREJA_H
#define __PAREJA_H
#include "Lista.h"

template<class T,class E>
class Pareja {
public:
	Pareja(const T a,const E b){
		_A=a;
		_B=b;
	}

	Pareja(){}

	T primero() const{
		return _A;
	}

	E segundo() const{
		return _B;
	}

private:
	T _A;
	E _B;
};

#endif // __PAREJA_H