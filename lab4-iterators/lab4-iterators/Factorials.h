#include <vector>

using namespace std;

#pragma once
class Factorials
{

private:
	class iter: public iterator<input_iterator_tag,int>
	{
	public:
		/*typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef ptrdiff_t distance_typ;*/
		iter(vector<int>::iterator it): cur_n(it) {};
		int operator*();
		iter operator++();
		iter operator++(int);
		//override operator++();
		iter operator--(int);
		bool operator==(iter other);
		bool operator!=(iter other);

	private:
		vector<int>::iterator cur_n;
	};


public:
	Factorials();

	size_t size();
	iter begin();
	iter end();
private:
	vector<int> n;
};

