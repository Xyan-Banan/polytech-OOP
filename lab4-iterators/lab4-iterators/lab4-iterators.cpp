#include <iostream>
#include <algorithm>
#include <vector>
#include "Factorials.h"

using namespace std;

int main()
{
	cout << "Hello World!\n";
	cout << "Direct order" << endl;
	Factorials f;
	for (auto it = f.begin(); it != f.end(); ++it) {
		cout << *it << endl;
	}

	cout << endl << "Reverse order" << endl;
	auto it = f.end();
	for (it--; it != f.begin(); it--) {
		cout << *it << endl;
	}
	cout << *(f.begin()) << endl;

	vector<int> v(10);
	copy(f.begin(), f.end(), v.begin());
	cout << endl << "Copied to vector" << endl;
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

}
