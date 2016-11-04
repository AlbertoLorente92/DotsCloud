#ifndef __PAIR_H
#define __PAIR_H

template<class T,class E>
class Pair {
public:
	Pair(const T a,const E b){
		_A=a;
		_B=b;
	}

	Pair(){}

	T first() const{
		return _A;
	}

	E second() const{
		return _B;
	}

	Pair<T,E> &operator =(const Pair<T,E>& other) {
		_A = other.first();
		_B = other.second();
		return *this;
	}

private:
	T _A;
	E _B;

};

#endif // __PAIR_H