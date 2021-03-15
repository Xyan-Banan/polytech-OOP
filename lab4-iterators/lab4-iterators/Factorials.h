#include <vector>

using namespace std;

#pragma once
class Factorials
{

private:
	class iter
	{
	public:
		int& operator*();
		void operator++(int);
		//override operator++();
		void operator--(int);
		bool operator==(iter other);
		bool operator!=(iter other);
		void begin(vector<int>& v);
		void end(vector<int>& v);
	private:
		vector<int>::iterator cur_n;
	};


public:
	Factorials();

	iter begin();
	iter end();
private:
	vector<int> n;
};

