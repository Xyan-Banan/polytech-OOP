#include <functional>

#pragma once
using namespace std;
class Stat: public unary_function<int,void>
{
public:
	Stat(int first) :max(INT_MIN), min(INT_MAX), count(0), summ(0), pos(0), neg(0), evens(0), odds(0), eqFL(false) { this->first = first; }

	void operator() (int arg) {
		if (arg > max)
			max = arg;

		if (arg < min)
			min = arg;

		summ += arg;
		count++;

		if (arg % 2 == 0) {
			evens++;
		}
		else {
			odds++;
		}

		if (arg > 0) {
			pos++;
		}
		else if (arg < 0) {
			neg++;
		}
		
		eqFL = first == arg;
	}

	double mid() {
		return (double)summ / count;
	}


	int max;
	int min;
	int pos;
	int neg;
	int evens;
	int odds;
	bool eqFL;

private:
	int count;
	int summ;
	int first;
};

