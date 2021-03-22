#include "Factorials.h"

Factorials::Factorials() {
	for (int i = 1; i <= 10; i++) {
		n.push_back(i);
	}
}

Factorials::iter Factorials::begin() {
	iter it;
	it.begin(n);
	return it;
}

Factorials::iter Factorials::end() {
	iter it;
	it.end(n);
	return it;
}

void Factorials::iter::begin(vector<int>& v) {
	cur_n = v.begin();
}

void Factorials::iter::end(vector<int>& v) {
	cur_n = v.end();
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

int& Factorials::iter::operator*() {
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