#include "Factorials.h"

Factorials::Factorials() {
	n = vector<int>({ 1,2,3,4,5,6,7,8,9,10 });
}

Factorials::iter Factorials::begin() {
	//iter it;
	//it.begin(n);
	return iter(n.begin());
}

Factorials::iter Factorials::end() {
	//iter it;
	//it.end(n);
	return iter(n.end());
}

size_t Factorials::size() {
	return n.size();
}

Factorials::iter Factorials::iter::operator++() {
	cur_n++;
	return *this;
}

Factorials::iter Factorials::iter::operator++(int) {
	iter tmp(*this);
	++(*this);
	return tmp;
}


Factorials::iter Factorials::iter::operator--(int) {
	iter tmp(*this);
	cur_n--;
	return tmp;
}

int Factorials::iter::operator*() {
	int factorial = 1;
	for (int i = 1; i <= *cur_n; i++)
		factorial *= i;
	return factorial;
}

bool Factorials::iter::operator==(Factorials::iter other) {
	return cur_n == other.cur_n;
}

bool Factorials::iter::operator!=(Factorials::iter other) {
	return cur_n != other.cur_n;
}