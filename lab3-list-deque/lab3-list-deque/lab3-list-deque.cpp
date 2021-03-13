#include <iostream>
#include <list>
#include <vector>
#include "QueueWithPriority.h"

using namespace std;

list<int> fillList(int size);
void printList(list<int> l);

int main()
{
	srand(time(0));
	cout << "Hello World!\n";
	QueueWithPriority queue;
	queue.PutElementToQueue(QueueElement{ "hello" }, ElementPriority::HIGH);
	queue.PutElementToQueue(QueueElement{ "world" }, ElementPriority::LOW);
	queue.PutElementToQueue(QueueElement{ "forest" }, ElementPriority::LOW);
	queue.PutElementToQueue(QueueElement{ "gump" }, ElementPriority::LOW);
	queue.PutElementToQueue(QueueElement{ "cup" }, ElementPriority::HIGH);
	queue.PutElementToQueue(QueueElement{ "speaker" }, ElementPriority::NORMAL);
	queue.PutElementToQueue(QueueElement{ "brush" }, ElementPriority::LOW);
	auto el = queue.GetElementFromQueue();
	cout << el.name << endl;
	el = queue.GetElementFromQueue();
	cout << el.name << endl;
	queue.Accelerate();
	el = queue.GetElementFromQueue();
	cout << el.name << endl;

	vector<int> sizes({ 0,1,2,3,4,5,7,14 });
	for (auto i = sizes.begin(); i != sizes.end(); i++) {
		list<int> l = fillList(*i);
		cout << "size: " << *i << endl;
		for (auto j = l.begin(); j != l.end(); j++)
			cout << *j << " ";
		cout << endl;
		printList(l);
		cout << endl;
	}
}

list<int> fillList(int size) {
	list<int> l;
	for (int i = 0; i < size; i++) {
		l.push_back(rand() % 21);
	}
	return l;
}

void printList(list<int> l) {
	if (l.size()) {
		auto itB = l.begin();
		auto itE = l.end();
		while (itB != itE && itB != --itE) {
			cout << *itB << " " << *itE << " ";
			itB++;
		}
		if (l.size() % 2 != 0) {
			cout << *itB << " ";
		}
	}
}

